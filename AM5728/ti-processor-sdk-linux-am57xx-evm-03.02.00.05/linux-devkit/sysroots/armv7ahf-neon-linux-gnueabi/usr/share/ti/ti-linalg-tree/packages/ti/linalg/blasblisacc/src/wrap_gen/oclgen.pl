#!/usr/bin/perl -sw


my $CTAGS = "/usr/bin/ctags";
my $OFFLOAD_MIN = 100;   # overridden by -offmin arg; constant
my $OFFLOAD_MAX = 10000; # overridden by -offmax arg; constant

#### DO NOT EDIT BELOW THIS ####
my $namespace; # input
my @offloaded; # array of function names to be offloaded, filled in by generate_arm...
my $blas_prefix = 'cblas_';

my $blas_L1 = '.asum|.axpy|.copy|.dot|.sdot|.dotc|.cdotc_sub|.cdotu_sub|.dotu|.nrm2|.rot|.rotg|.rotmg|.scal|.swap|i.amax|i.amin|.cabs1|.csscal|.drotm|.dzasum|.dznrm2|.scasum|.scnrm2|.sdsdot|.srotm|.xerbla|.zdotu_sub|.zdscal|';
my $blas_L2 = '.gbmv|.gemv|.ger|.gerc|.geru|.hbmv|.hemv|.her|.her2|.hpmv|.hpr|.hpr2|.sbmv|.spmv|.spr|.spr2|.symv|.syr|.syr2|.tbmv|.tbsv|.tpmv|.tpsv|.trmv|.trsv|';
my $blas_L3 = '.gemm|.hemm|.herk|.her2k|.symm|.syrk|.syr2k|.trmm|.trsm|';
my $blas_L123 = "${blas_L1}|${blas_L2}|${blas_L3}";

my $source_code_header = 
"/******************************************************************************
 * Copyright (c) 2013-2015, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *       * Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *         notice, this list of conditions and the following disclaimer in the
 *         documentation and/or other materials provided with the distribution.
 *       * Neither the name of Texas Instruments Incorporated nor the
 *         names of its contributors may be used to endorse or promote products
 *         derived from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *   THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
";
### low-level functions ###

# remove leading and trailing spaces and all newlines
sub trim($)
{
    my $string = shift;
    $string =~ s/^\s+//;
    $string =~ s/\s+$//;
    $string =~ s/\s+/ /g;
    $string =~ s/\t+/ /g;
    $string =~ s/\n+//g;
    return $string;
}

# generates the ocl kernel name
sub ocl_munge($)
{
    my $string = shift;
    $string =~ s/(.*)\ +(\**)\ *(.*)$/void\ $2ocl_$3/;
    return $string;
}

# generates the trampoline name
sub trampoline_munge($)
{
    my $string = shift;
    $string =~ s/(.*)\ (.*)$/void\ $2_facade/;
    return $string;
}

# /path/to/libcblas.a => libcblas
sub get_base_libname($)
{
    my $string = shift;
    $string = `basename $string`; chomp $string;
    $string =~ m/([^.]+).*/;
    return $1;
}

### end low-level functons ###


### High-level functions ###

# enums and defines need to be copied into the kernel.cl as otherwise
# the c66x code will not compiled. We can't simply include the header
# in the kernel.cl that breaks the ocl compile.
sub get_enums_and_defines
{
  open(HEADER, "<$header") || die "Could not open $header for reading : $!\n";
  my $code = "";
  while (<HEADER>) {
    chomp;
    $code .= $_ . "\n" if (/^\s*enum\s+/);
    $code .= $_ . "\n" if (/^\s*#define\s+/);
  }
  close(HEADER);
  return $code;
}

sub get_init_code
{
  my $code = "
void ti_bli_init_dsp(global char *l3_buf, local char *l2_buf);
kernel void ocl_bli_init(global char *l3_buf, local char *l2_buf)
{ ti_bli_init_dsp(l3_buf, l2_buf); }
void ti_bli_finalize_dsp(void);
kernel void ocl_bli_finalize(void)
{ ti_bli_finalize_dsp(); }
";
  return $code;
}

# generates the initial portion of the Makefile. This needs to be done
# only once, and not on a per-function basis
sub generate_makefile_prologue
{
  my $package = shift;
  my $libname = shift;
  my $uc_package = uc($package);
  my $NAMESPACE = uc($namespace);

  # TODO: Change default to create fat binary
  my $fatbinary = "0";
  $fatbinary = 1 if ($fatbin);
  my $makecode = <<"END_MAKEFILE_PROLOGUE";
include ./make.inc
\$(eval \$(call FIND_DSP_PKG,FC_DIR,framework_components*,packages))
\$(eval \$(call FIND_DSP_PKG,XDAIS_DIR,xdais*,packages))
\$(eval \$(call FIND_DSP_PKG,${uc_package}_DIR,${package}*,packages))

$uc_package	= \$(${uc_package}_DIR)/packages/ti/$package

# comment below to disable parallel make
MAKEFLAGS += -j4

# Defines
# set below to 1 for creating a fat binary, and 0 to create a .out file
# For large libraries you may want to create a .out as creating a fat binary
# can run out of space in /tmp
${NAMESPACE}_FAT_BINARY = $fatbinary


# INCLUDE Directory
INCDIR := \$(TI_OCL_CGT_INSTALL)/include;\$(LINUX_DEVKIT_ROOT)/usr/include;\$(EDMA3LLD_DIR)/packages;\$(FC_DIR)/packages;\$(XDAIS_DIR)/packages;\$(${uc_package})/inc;\$(${uc_package})/example;\$(${uc_package})/example/Setup_ECPY/alg;\$(${uc_package})//example/Setup_ECPY/alg/ires

INCS = -I. -I\$(strip \$(subst ;, -I,\$(subst \$(space),\$(space),\$(INCDIR))))
OBJS = ${namespace}_initfini.o
HOST_OBJS =

CPP_FLAGS   = -D_LITTLE_ENDIAN -D__ARMv7 -DSOC_K2H
CL6X_FLAGS  = \$(INCS)
CLOCL_FLAGS = 
OBJCOPY     = objcopy
OBJCOPY_ARGS=
DSP_ONLY_LIB= ${libname}_dsponly.a
ARM_PLUS_DSP_LIB= ${libname}_armplusdsp.a

OCL_BIN = ${namespace}_kernel.out

ifeq (\$(${NAMESPACE}_FAT_BINARY), 1)
  CPP_FLAGS += -D${NAMESPACE}_FAT_BINARY
  OCL_BIN = ${namespace}_kernel.dsp_h
endif

# Set the variables so the compiler does not fill up /tmp
TMPDIR = \$(PWD)
TMP = \$(PWD)
export TMPDIR TMP

END_MAKEFILE_PROLOGUE

  $makecode .= "

# setting to a default of empty to override environment settings
${NAMESPACE}_OFFLOAD = 

ifneq (\$(${NAMESPACE}_OFFLOAD),)
  CPP_FLAGS += -D${NAMESPACE}_OFFLOAD=\\\"\$(${NAMESPACE}_OFFLOAD)\\\"
endif
" if ($header =~ /blas/);
  return $makecode;
}

# generate header specific init code
sub generate_header_specific_init_code
{
  my $code = "";
  my $NAMESPACE = uc($namespace);
  if ($header =~ /blas/) {
    $code = "
  /* 3-digit value: 012
   * Left-most digit => L1 (0)
   * Middle-digit    => L2 (1)
   * Right-most      => L3 (2)
   */
  ${NAMESPACE}_L1_OFFLOAD = ${namespace}_offload / 100;
  int tmp_offload = ${namespace}_offload % 100;
  ${NAMESPACE}_L2_OFFLOAD = tmp_offload / 10;
  ${NAMESPACE}_L3_OFFLOAD = tmp_offload % 10;
  ${NAMESPACE}_DEBUG_PRINT(\"BLAS Offload values: L1=%d, L2=%d, L3=%d\\n\",  
      ${NAMESPACE}_L1_OFFLOAD, ${NAMESPACE}_L2_OFFLOAD, ${NAMESPACE}_L3_OFFLOAD);
  if ((${NAMESPACE}_L1_OFFLOAD == ${NAMESPACE}_OFFLOAD_SIZE)) {
    ${NAMESPACE}_ERROR_EXIT(\"Size-based offload NOT supported for BLAS Level 1 yet.\\n\");
  }
  if ((${NAMESPACE}_L2_OFFLOAD == ${NAMESPACE}_OFFLOAD_SIZE)) {
    ${NAMESPACE}_ERROR_EXIT(\"Size-based offload NOT supported for BLAS Level 2 yet.\\n\");
  }
";
  }
  return $code;
}

sub generate_header_specific_global_vars
{
  my $code = "";
  my $NAMESPACE = uc($namespace);
  if ($header =~ /blas/) {
    for (my $lvl=1; $lvl<=3; $lvl++) {
      $code .= "int ${NAMESPACE}_L${lvl}_OFFLOAD = ${NAMESPACE}_OFFLOAD_NONE;\n";
    }
  }
  return $code;
}

# Generates the ARM init/fini code. Do only once, not on a per-function basis.
sub generate_arm_init()
{
  my $NAMESPACE = uc($namespace);
  my $var_code = generate_header_specific_global_vars();
  my $hdr_init = generate_header_specific_init_code();
  my $armcode = <<"END_ARM_INIT";
$source_code_header  
#include "${namespace}_acc.h"

#ifdef ${NAMESPACE}_FAT_BINARY
#include "${namespace}_kernel.dsp_h"
#endif

/* Global variables */
#ifdef __cplusplus
Context 		${namespace}_ocl_context;
std::vector<Device>	${namespace}_ocl_devices;
CommandQueue		${namespace}_ocl_Q;
Program::Binaries	${namespace}_ocl_binary;
Program			${namespace}_ocl_program;
Kernel*			${namespace}_ocl_kernels[${NAMESPACE}_NUM_KERNELS];
#else
cl_context		${namespace}_ocl_context;
cl_command_queue	${namespace}_ocl_Q;
cl_program		${namespace}_ocl_program;
cl_kernel		${namespace}_ocl_kernels[${NAMESPACE}_NUM_KERNELS];
#endif
int ${namespace}_init_done = 0;       /* flag to check if init is complete */
int ${namespace}_disable_debug = 0;   /* runtime toggle to disable debug */
int ${namespace}_offload = ${NAMESPACE}_OFFLOAD_SIZE;  
int ${namespace}_kernel_valid[${NAMESPACE}_NUM_KERNELS];
$var_code

void ${namespace}_error(const char* msg, int code)
{
  fprintf(stderr, "ERROR: (%s,%d)\\n", msg, code);
}

/* This function is invoked exactly once on startup */
/* Its purpose is to parse the environment variables and do OpenCL init */
void ${namespace}_init(void)
{
#pragma omp critical
  {
    /* Add code for interception */
    if (!${namespace}_init_done) 
    {
#ifdef ${NAMESPACE}_DEBUG
      char *no_debug_env = getenv("${NAMESPACE}_NO_DEBUG");
      if (no_debug_env) {
        if (atoi(no_debug_env) > 0) {
          ${namespace}_disable_debug = 1;
        }
      }
#endif

      ${NAMESPACE}_DEBUG_PRINT("${namespace}_init: Initializing OpenCL on first use..\\n");
      ${NAMESPACE}_PROFILE_START();
    
      /* check environment variables */
      const char *offload_env = getenv("${NAMESPACE}_OFFLOAD");
      if (!offload_env)  { 
        ${NAMESPACE}_DEBUG_PRINT("Using build time default for offload: ${NAMESPACE}_OFFLOAD=%s\\n", ${NAMESPACE}_OFFLOAD);
        offload_env = ${NAMESPACE}_OFFLOAD;
      }
      else {
        ${NAMESPACE}_DEBUG_PRINT("Using runtime override for offloads: ${NAMESPACE}_OFFLOAD=%s\\n", offload_env);
      }
      if (offload_env) {
        ${namespace}_offload = atoi(offload_env);
        if (${namespace}_offload == ${NAMESPACE}_OFFLOAD_NONE) {
            ${NAMESPACE}_DEBUG_PRINT("Disabling all offloads\\n");
        }
      }
  $hdr_init


      /*------------------------------------------------------------------------
       * Read the offline compiled kernel module
       *-----------------------------------------------------------------------*/
      const unsigned char* bin;
#ifdef ${NAMESPACE}_FAT_BINARY
      bin = (unsigned char *)${namespace}_kernel_dsp_bin;
      const size_t bin_length = ${namespace}_kernel_dsp_bin_len;
#else
      const char binary[] = "./${namespace}_kernel.out";
      unsigned int bin_length;
#ifdef __cplusplus
      bin_length = ocl_read_binary(binary, (char*&)bin); 
#else
      FILE *fp = fopen(binary, "r");
      if (!fp) {
        ${NAMESPACE}_ERROR_EXIT("Could not open OpenCL pre-compiled binary %s for reading\\n", binary);
      }
      struct stat fileinfo;
      stat(binary, &fileinfo);
      bin_length = fileinfo.st_size;
      bin = (char *)malloc(bin_length);
      if (!bin) {
        ${NAMESPACE}_ERROR_EXIT("Could not malloc of size %d for reading OpenCL binary\\n", bin_length);
      }
      if (fread((char *)bin, bin_length, 1, fp) != 1) {
        ${NAMESPACE}_ERROR_EXIT("Could not read %d bytes of OpenCL binary\\n", bin_length);
      }
      fclose(fp);
#endif /* cplusplus */
#endif /* FAT_BINARY */
    
      /* OpenCL init */
#ifdef __cplusplus
      ${namespace}_ocl_context = Context(CL_DEVICE_TYPE_ACCELERATOR);
      ${namespace}_ocl_devices = ${namespace}_ocl_context.getInfo<CL_CONTEXT_DEVICES>();
      ${namespace}_ocl_binary = Program::Binaries(1, std::make_pair(bin, bin_length));
      ${namespace}_ocl_program = Program(${namespace}_ocl_context, ${namespace}_ocl_devices, ${namespace}_ocl_binary);
      ${namespace}_ocl_program.build(${namespace}_ocl_devices);
      ${namespace}_ocl_Q = CommandQueue(${namespace}_ocl_context, ${namespace}_ocl_devices[0], CL_QUEUE_PROFILING_ENABLE);
#else
      cl_int err;
      cl_device_id device;
      /* Create an in-order command queue by default*/
      int queue_flags = 0;
#ifdef ${NAMESPACE}_PROFILE
      queue_flags |= CL_QUEUE_PROFILING_ENABLE;
#endif
    
      ${namespace}_ocl_context = clCreateContextFromType(0,CL_DEVICE_TYPE_ACCELERATOR,0,0,&err);
      ${NAMESPACE}_OCL_CHKERROR("clCreateContextFromType",err);
      err = clGetDeviceIDs(0,CL_DEVICE_TYPE_ACCELERATOR,1,&device,0);
      ${NAMESPACE}_OCL_CHKERROR("clGetDeviceIDs",err);
      ${namespace}_ocl_Q = clCreateCommandQueue(${namespace}_ocl_context, device, queue_flags, &err);
      ${NAMESPACE}_OCL_CHKERROR("clCreateCommandQueue",err);
      ${namespace}_ocl_program = clCreateProgramWithBinary(${namespace}_ocl_context, 1, &device, &bin_length, &bin, NULL, &err);
      ${NAMESPACE}_OCL_CHKERROR("clCreateProgramWithBinary",err);
      const char *compile_options = "";
      err = clBuildProgram(${namespace}_ocl_program, 1, &device, compile_options, 0, 0);
      ${NAMESPACE}_OCL_CHKERROR("clBuildProgram",err);
    
#endif
    
#ifndef ${NAMESPACE}_FAT_BINARY
#ifdef __cplusplus
      delete [] bin;
#else
      free((char*)bin);
#endif
#endif /* FAT_BINARY */
    
      ${NAMESPACE}_PROFILE_REPORT("  Initialization took %8.2f us\\n", (float) clock_diff);
      ${namespace}_init_done = 1;
      ${NAMESPACE}_DEBUG_PRINT("${namespace}_init: Finished OpenCL initialization\\n");
    } //end of !ti_cblas_init_done
  } // End of critical section
  
  return;
}

/* Returns a handle to the kernel for the specified
 * function with index 'idx'. Initializes the handle if it's
 * not been used before, otherwise returns earlier handle
 */
#ifdef __cplusplus
Kernel*
#else
cl_kernel
#endif
${namespace}_get_kernel(const char *fname)
{
   if (!${namespace}_kernel_valid[idx]) {
#ifdef __cplusplus
     ${namespace}_ocl_kernels[idx] = new Kernel(${namespace}_ocl_program, fname);
#else
     cl_int err;
     ${namespace}_ocl_kernels[idx] = clCreateKernel(${namespace}_ocl_program,fname,&err);
     ${NAMESPACE}_OCL_CHKERROR("clCreateKernel",err);
#endif
     ${namespace}_kernel_valid[idx] = 1;
   }
   return ${namespace}_ocl_kernels[idx];
}

END_ARM_INIT
}


# checks if a function is defined in a library
sub is_func_in_lib
{
  my $func = shift;
  my $lib = shift;
  return (system("nm $lib | grep -w \"$func\" | grep -w T > /dev/null")==0);
}

# For each function prototype seen in the header, this function
# generates the correpsonding Makefile code. This needs to be done
# on a per-function basis.
# Arg: Function prototype string
sub generate_makefile_from_proto
{
    my $string = shift;
    $string =~ s/;//;
    # func decl

    # func return type
    my @tmp = split /[\(\)]/,$string;

    # func name
    my $trampname = $tmp[0]; chomp $trampname;
    $trampname =~ s/.*\ \**(.*)$/$1/;
    my $makecode = "";

    # unless we have $f2cwraplib set, we can simply assume the function is defined
    # in the supplied arm library. If we have f2clib set, then we should check if
    # the arm library actually has the function defined, or should we use the f2c
    # wrapper function name
    my $f2csym = $trampname; $f2csym =~ s/^(.*)_$/f2c_$1/ ;
    if ($::f2cwraplib && is_func_in_lib("$f2csym", "$::f2cwraplib")) {
      print "using $f2csym wrapper for $trampname\n";
      $makecode .= "OBJCOPY_ARGS += --redefine-sym=$f2csym=__real_${trampname}\n";
    }
    else {
      $makecode .= "OBJCOPY_ARGS += --redefine-sym=$trampname=__real_${trampname}\n";
    }
    $makecode   .= "OBJS += ${namespace}_$offloaded[-1].o\n";
    $makecode   .= "HOST_OBJS += ${namespace}_$offloaded[-1].o";
    return $makecode;
}

# returns the ARM condition code for dynamic offload
# based on function name
# Arg 1: function name
# Arg 2: Args array
sub get_func_based_arm_cond
{
  $fname = shift;
  $argsref = shift;

  my $bufsize = "";
  my $type = 0;

  if ($namespace =~ /clapack$/) {
    # saxpy, daxpy, caxpy, zaxpy
    if ($fname =~ /^[sdcz]axpy_$/) {
      $bufsize = "*$$argsref[0]*abs(*$$argsref[5])";
    }
    # scopy, dcopy, ccopy, zcopy
    if ($fname =~ /^[sdcz]copy_$/) {
      $bufsize = "*$$argsref[0]*abs(*$$argsref[4])";
    }
    # [cz]dot[cu]
    if ($fname =~ /^[sdcz]dot[cu]_$/) {
      $bufsize = "*$$argsref[1]*abs(*$$argsref[5])";
    }
    # sgbmv, dgbmv, cgbmv, zgbmv
    if ($fname =~ /^[sdcz]gbmv_$/) {
      $bufsize = "*$$argsref[1]*abs(*$$argsref[2])"; # A: M x N
    }
    # sgemm, dgemm, cgemm, zgemm
    if ($fname =~ /^[sdcz]gemm_$/) {
      $bufsize = "*$$argsref[2]*(*$$argsref[3])";# C: M x N
    }
    # sgemv, dgemv, cgemv, zgemv
    if ($fname =~ /^[sdcz]gemv_$/) {
      $bufsize = "*$$argsref[1]*abs(*$$argsref[2])"; # A : M x N
    }
    # cgeru, zgeru, cgerc, zgerc
    if ($fname =~ /^[cz]ger[uc]_$/) {
      $bufsize = "*$$argsref[0]*abs(*$$argsref[1])"; # A : M x N
    }
    # chbmv, zhbmv
    if ($fname =~ /^[cz]hbmv_$/) {
      $bufsize = "*$$argsref[1]*abs(*$$argsref[1])"; # A : N x N
    }
    # chemm, zhemm
    if ($fname =~ /^[cz]hemm_$/) {
      $bufsize = "*$$argsref[2]*(*$$argsref[3])";# C: MxN
    }
    # chemv, zhemv
    if ($fname =~ /^[cz]hemv_$/) {
      $bufsize = "*$$argsref[1]*abs(*$$argsref[1])"; # A : N x N
    }
    # cher, zher, chpr, zhpr
    if ($fname =~ /^[cz]h[ep]r_$/) {
      $bufsize = "*$$argsref[1]*abs(*$$argsref[1])"; # A : N x N
    }
    # cher2, zher2, chpr2, zhpr2
    if ($fname =~ /^[cz]h[ep]r2_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])"; # A : N x N
    }
    # cher2k, zher2k
    if ($fname =~ /^[cz]her2k_$/) {
      $bufsize = "(*$$argsref[2])*(*$$argsref[2])"; # C: NxN
    }
    # cherk, zherk
    if ($fname =~ /^[cz]herk_$/) {
      $bufsize = "(*$$argsref[2])*(*$$argsref[3])";# C: NxN
    }
    # chpmv, zhpmv
    if ($fname =~ /^[cz]hpmv_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # Ap : N x N
    }
    if ($fname =~ /^[sdcz]gesvd_$/) {
      $bufsize = "(*$$argsref[2])*(*$$argsref[3])" ; # A : M x N
    }
    if ($fname =~ /^[sdcz]gesv_$/) {
      $bufsize = "(*$$argsref[0])*(*$$argsref[0])" ; # A : N x N
    }
    if ($fname =~ /^[sdcz]gesv_$/) {
      $bufsize = "(*$$argsref[0])*(*$$argsref[0])" ; # A : N x N
    }
    # cscal, dscal, zscal, sscal
    if ($fname =~ /^[sdcz]scal_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[-1]))" ;# cx : 1+(N-1)*incx 
    }
    # csscal, zdscal
    if ($fname =~ /^[cz][sd]scal_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[-1]))" ;# cx : 1+(N-1)*incx 
    }
    # srot, crot, drot, zrot
    if ($fname =~ /^[sdcz]rot_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))" ;# cy : 1+(N-1)*incy 
    }
    # srotm, drotm
    if ($fname =~ /^[sd]rotm_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))" ;# cy : 1+(N-1)*incy 
    }
    # csrot, zdrot
    if ($fname =~ /^[cz][sd]rot_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))" ;# cy : 1+(N-1)*incy 
    }
    # cswap, sswap, dswap, zswap
    if ($fname =~ /^[sdcz]swap_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))" ;# cy : 1+(N-1)*incy 
    }
    # sdot, dsdot, ddot
    if ($fname =~ /^d?[sd]dot_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))" ;# cy : 1+(N-1)*incy 
    }
    # sasum, dasum, scasum, dzasum
    if ($fname =~ /^sasum_|dasum_|scasum_|dzasum_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))" ;# sx : 1+(N-1)*incx 
    }
    # snrm2, dnrm2, dznrm2, scnrm2
    if ($fname =~ /^snrm2_|dnrm2_|dznrm2_|scnrm2_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))" ;# sx : 1+(N-1)*incx 
    }
    # sspr, dspr, cspr, zspr
    if ($fname =~ /^[sdcz]spr_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # Ap : N x N
    }
    # sspr2, dspr2
    if ($fname =~ /^[sd]spr2_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # Ap : N x N
    }
    # ssymv, dsymv, csymv, zsymv
    if ($fname =~ /^[sdcz]symv_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # A : N x N
    }
    # ssymm, dsymm, csymm, zsymm
    if ($fname =~ /^[sdcz]symm_$/) {
      $bufsize = "*$$argsref[2]*(*$$argsref[3])" ;# C: MxN
    }
    # ssyr, dsyr, csyr, zsyr
    if ($fname =~ /^[sdcz]syr_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # A : N x N
    }
    # ssyr2, dsyr2, csyr2, zsyr2
    if ($fname =~ /^[sd]syr2_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # A : N x N
    }
    # ssyrk, csyrk, dsyrk, zsyrk
    if ($fname =~ /^[sdcz]syrk_$/) {
      $bufsize = "(*$$argsref[2])*(*$$argsref[2])" ; # C : N x N
    }
    # stbmv, dtbmv, ctbmv, ztbmv, stbsv, dtbsv, ztbsv, ctbsv
    if ($fname =~ /^[sdcz]tb[ms]v_$/) {
      $bufsize = "(*$$argsref[3])*(*$$argsref[3])" ; # A : N x N
    }
    # [sdcz]tpmv, [scdz]tpsv
    if ($fname =~ /^[sdcz]tp[ms]v_$/) {
      $bufsize = "(*$$argsref[3])*(*$$argsref[3])" ; # A : N x N
    }
    # [sdcz]trmv, [sdcz]trsv
    if ($fname =~ /^[sdcz]tr[ms]v_$/) {
      $bufsize = "(*$$argsref[3])*(*$$argsref[3])" ; # A : N x N
    }
    # [scdz]trmm
    if ($fname =~ /^[sdcz]trmm_$/) {
      $bufsize = "*$$argsref[4]*(*$$argsref[5])" ;# B: MxN
    }
    # [scdz]trsm
    if ($fname =~ /^[sdcz]trsm_$/) {
      $bufsize = "*$$argsref[4]*(*$$argsref[5])" ;# B: MxN
    }
    # [sd]ger
    if ($fname =~ /^[sd]ger_$/) {
      $bufsize = "*$$argsref[0]*(*$$argsref[1])" ;# A: MxN
    }
    # [sd]sbmv
    if ($fname =~ /^[sd]sbmv_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])"; # A : N x N
    }
    # [sdcz]spmv
    if ($fname =~ /^[sd]spmv_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # A : N x N
    }
    # [s,d,c,z]syr2k
    if ($fname =~ /^[sdcz]syr2k_$/) {
      $bufsize = "(*$$argsref[2])*(*$$argsref[2])" ; # C : N x N
    }
    if ($fname =~ /^i[sdcz]amax_$/) {
      $bufsize = "(1+ (*$$argsref[0]-1)*abs(*$$argsref[-1]))" ;# x : 1+(N-1)*incx 
    }
    if ($fname =~ /^xerbla_array__$/) {
      $bufsize = "(*$$argsref[1])" ;# srname_array length is srnam_len__
    }
    if ($fname =~ /^[sdcz]bdsqr_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[4])" ; # C : n x ncc
    }
    if ($fname =~ /^[sdcz]gbbrd_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[2])" ; # a : m x n
    }
    if ($fname =~ /^[sdcz]gbcon_$/) {
      $bufsize = "(*$$argsref[1]>*$$argsref[5]?*$$argsref[1]:*$$argsref[5])*(*$$argsref[1])" ; # ab : max(ldab,n) x n
    }
    # scdz/gbequ, scdz/gbequb
    if ($fname =~ /^[sdcz]gbequb?_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[5]?*$$argsref[0]:*$$argsref[5])*(*$$argsref[1])" ; # ab : max(ldab,m) x n
    }
    # scdz/gbrfs
    if ($fname =~ /^[sdcz]gbrfs_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # a : n x n
    }
    # scdz/pbrfs
    if ($fname =~ /^[sdcz]pbrfs_$/) {
      $bufsize = "(*$$argsref[1])*(*$$argsref[1])" ; # a : n x n
    }
    # sdcz/gbsv
    if ($fname =~ /^[sdcz]gbsv_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[5]?*$$argsref[0]:*$$argsref[5])*(*$$argsref[0])" ; # ab : max(ldab,n) x n
    }
    # sdcz/gbtf2
    if ($fname =~ /^[sdcz]gbtf2_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[5]?*$$argsref[0]:*$$argsref[5])*(*$$argsref[1])" ; # ab : max(ldab,m) x n
    }
    # sdcz/gbtrf
    if ($fname =~ /^[sdcz]gbtrf_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[5]?*$$argsref[0]:*$$argsref[5])*(*$$argsref[1])" ; # ab : max(ldab,m) x n
    }
    # sdcz/gbtrs
    if ($fname =~ /^[sdcz]gbtrs_$/) {
      $bufsize = "(*$$argsref[1]>*$$argsref[6]?*$$argsref[1]:*$$argsref[6])*(*$$argsref[1])" ; # ab : max(ldab,n) x n
    }
    # sdcz/gebak
    if ($fname =~ /^[sdcz]gebak_$/) {
      $bufsize = "(*$$argsref[2]>*$$argsref[8]?*$$argsref[2]:*$$argsref[8])*(*$$argsref[6])" ; # v : max(ldv,n) x m
    }
    # sdcz/gebal
    if ($fname =~ /^[sdcz]gebal_$/) {
      $bufsize = "(*$$argsref[1]>*$$argsref[3]?*$$argsref[1]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,n) x n
      $bufsize = "((*$$argsref[1]))" if ($argnum == 6); # scale: array of dimension n
    }
    # sdcz/gebd2
    if ($fname =~ /^[sdcz]gebd2_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gebrd
    if ($fname =~ /^[sdcz]gebrd_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gecon
    if ($fname =~ /^[sdcz]gecon_$/) {
      $bufsize = "(*$$argsref[1]>*$$argsref[3]?*$$argsref[1]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,n) x n
    }
    # sdcz/geequ sdcz/geequb
    if ($fname =~ /^[sdcz]geequb?_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gees
    if ($fname =~ /^[sdcz]gees_$/) {
      $bufsize = "(*$$argsref[3]>*$$argsref[5]?*$$argsref[3]:*$$argsref[5])*(*$$argsref[3])" ; # a : max(lda,n) x n
    }
    # sdcz/geesx
    if ($fname =~ /^[sdcz]geesx_$/) {
      $bufsize = "(*$$argsref[4]>*$$argsref[6]?*$$argsref[4]:*$$argsref[6])*(*$$argsref[4])" ; # a : max(lda,n) x n
    }
    # sdcz/geev
    if ($fname =~ /^[sdcz]geev_$/) {
      $bufsize = "(*$$argsref[2]>*$$argsref[4]?*$$argsref[2]:*$$argsref[4])*(*$$argsref[2])" ; # a : max(lda,n) x n
    }
    # sdcz/geevx
    if ($fname =~ /^[sdcz]geevx_$/) {
      $bufsize = "(*$$argsref[4]>*$$argsref[6]?*$$argsref[4]:*$$argsref[6])*(*$$argsref[4])" ; # a : max(lda,n) x n
    }
    # sdcz/gegs
    if ($fname =~ /^[sdcz]gegs_$/) {
      $bufsize = "(*$$argsref[2]>*$$argsref[6]?*$$argsref[2]:*$$argsref[6])*(*$$argsref[2])" ; # b : max(ldb,n) x n
    }
    # sdcz/gegv
    if ($fname =~ /^[sdcz]gegv_$/) {
      $bufsize = "(*$$argsref[2]>*$$argsref[6]?*$$argsref[2]:*$$argsref[6])*(*$$argsref[2])" ; # b : max(ldb,n) x n
    }
    # sdcz/gehd2
    if ($fname =~ /^[sdcz]gehd2_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[0])" ; # a : max(lda,n) x n
    }
    # sdcz/gehrd
    if ($fname =~ /^[sdcz]gehrd_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[0])" ; # a : max(lda,n) x n
    }
    # sdcz/gelq2
    if ($fname =~ /^[sdcz]gelq2_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gelqf
    if ($fname =~ /^[sdcz]gelqf_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gels
    if ($fname =~ /^[sdcz]gels_$/) {
      $bufsize = "(*$$argsref[1]>*$$argsref[5]?*$$argsref[1]:*$$argsref[5])*(*$$argsref[2])" ; # a : max(lda,m) x n
    }
    # sdcz/gelsd
    if ($fname =~ /^[sdcz]gelsd_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gelss
    if ($fname =~ /^[sdcz]gelss_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gelsx
    if ($fname =~ /^[sdcz]gelsx_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gelsy
    if ($fname =~ /^[sdcz]gelsy_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/geql2
    if ($fname =~ /^[sdcz]geql2_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/geqlf
    if ($fname =~ /^[sdcz]geqlf_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/geqp3
    if ($fname =~ /^[sdcz]geqp3_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/geqpf
    if ($fname =~ /^[sdcz]geqpf_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/geqr2
    if ($fname =~ /^[sdcz]geqr2_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/geqrf
    if ($fname =~ /^[sdcz]geqrf_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gerfs
    if ($fname =~ /^[sdcz]gerfs_$/) {
      $bufsize = "(*$$argsref[1]>*$$argsref[4]?*$$argsref[1]:*$$argsref[4])*(*$$argsref[1])" ; # a : max(lda,n) x n
    }
    # sdcz/gerfsx
    if ($fname =~ /^[sdcz]gerfsx_$/) {
      $bufsize = "(*$$argsref[2]>*$$argsref[5]?*$$argsref[2]:*$$argsref[5])*(*$$argsref[2])" ; # a : max(lda,n) x n
    }
    # sdcz/gerq2
    if ($fname =~ /^[sdcz]gerq2_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gerqf
    if ($fname =~ /^[sdcz]gerqf_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])" ; # a : max(lda,m) x n
    }
    # sdcz/gesc2
    if ($fname =~ /^[sdcz]gesc2_$/) {
      $bufsize = "(*$$argsref[0]>*$$argsref[2]?*$$argsref[0]:*$$argsref[2])*(*$$argsref[0])" ; # a : max(lda,n) x n
    }
  }

  if ($namespace =~ /cblas$/) {
    ### Level 3 BLAS ###
    # sgemm, dgemm, cgemm, zgemm
    if ($fname =~ /^cblas_[sdcz]gemm$/) {
      #$bufsize = "$$argsref[3]*$$argsref[4]";
      $bufsize = "BLAS_ORD($$argsref[0],$$argsref[3],$$argsref[4])*$$argsref[13]";
      $type = 3;
    }
    # ssymm, dsymm, csymm, zsymm
    if ($fname =~ /^cblas_[sdcz]symm$/) {
      $bufsize = "$$argsref[3]*$$argsref[4]";
      $type = 3;
    }
    # ssyrk, dsyrk, csyrk, zsyrk
    if ($fname =~ /^cblas_[sdcz]syrk$/) {
      $bufsize = "$$argsref[3]*$$argsref[4]";
      $type = 3;
    }
    # ssyr2k, dsyr2k, csyr2k, zsyr2k
    if ($fname =~ /^cblas_[sdcz]syr2k$/) {
      $bufsize = "$$argsref[3]*$$argsref[3]";
      $type = 3;
    }
    # strmm, dtrmm, ctrmm, ztrmm, strsm, dtrsm, ctrsm, ztrsm
    if ($fname =~ /^cblas_[sdcz]tr[ms]m$/) {
      $bufsize = "$$argsref[5]*$$argsref[6]";
      $type = 3;
    }
    # chemm, zhemm
    if ($fname =~ /^cblas_[cz]hemm$/) {
      #$bufsize = "$$argsref[3]*$$argsref[4]";
      $bufsize = "BLAS_ORD_S($$argsref[0],$$argsref[1],$$argsref[4],$$argsref[3])*$$argsref[12]"; # C: ldc x (n or m)
      $type = 3;
    }
    # cherk, zherk
    if ($fname =~ /^cblas_[cz]herk$/) {
      $bufsize = "$$argsref[3]*$$argsref[3]";
      $type = 3;
    }
    # cher2k, zher2k
    if ($fname =~ /^cblas_[cz]her2k$/) {
      $bufsize = "$$argsref[3]*$$argsref[3]";
      $type = 3;
    }
  }

  if ($bufsize) {
    $bufsize = "($bufsize)";
    my $min = "";
    my $max = "";
    my $NAMESPACE = uc($namespace);
    $min = "${NAMESPACE}_" . uc($fname) . "_OFFLOAD_MIN";
    $max = "${NAMESPACE}_" . uc($fname) . "_OFFLOAD_MAX";
    return "($bufsize <= $min) || ($bufsize >= $max)" if ($min && $max);
    return "($bufsize <= $min)" if ($min);
    return "($bufsize >= $max)" if ($max);
  }
  return ""; # if control reaches here then no modifier
}
#end of get_func_based_arm_cond

sub get_offload_decision
{
  $fname = shift;
  $argsref = shift;
  $cond_offload = "";
  
  if ($namespace =~ /cblas$/) {
    ### Level 3 BLAS ###
    $func_name = substr($fname, 6);
    # sgemm, dgemm, cgemm, zgemm
    if ($fname =~ /^cblas_[sdcz]gemm$/) {
	  #print "fname is " . $fname. "\n";
      $cond_offload = "!$func_name\_offload_dsp($$argsref[0],$$argsref[3],$$argsref[4],$$argsref[5])";
 	  #print "cond_offload is " . $cond_offload. "\n";
    }
    # ssymm, dsymm, csymm, zsymm
    if ($fname =~ /^cblas_[sdcz]symm$/) {
      $cond_offload = "!$func_name\_offload_dsp($$argsref[0],$$argsref[1],$$argsref[3],$$argsref[4])";
    }
    # ssyrk, dsyrk, csyrk, zsyrk
    if ($fname =~ /^cblas_[sdcz]syrk$/) {
      $cond_offload = "!$func_name\_offload_dsp($$argsref[0],$$argsref[3],$$argsref[4])";
    }
    # ssyr2k, dsyr2k, csyr2k, zsyr2k
    if ($fname =~ /^cblas_[sdcz]syr2k$/) {
      $cond_offload = "!$func_name\_offload_dsp($$argsref[0],$$argsref[3],$$argsref[4])";
    }
    # strmm, dtrmm, ctrmm, ztrmm, strsm, dtrsm, ctrsm, ztrsm
    if ($fname =~ /^cblas_[sdcz]tr[ms]m$/) {
      $cond_offload = "!$func_name\_offload_dsp($$argsref[0],$$argsref[1],$$argsref[5],$$argsref[6])";
    }
    # chemm, zhemm
    if ($fname =~ /^cblas_[cz]hemm$/) {
      $cond_offload = "!$func_name\_offload_dsp($$argsref[0],$$argsref[1],$$argsref[3],$$argsref[4])";
    }
    # cherk, zherk
    if ($fname =~ /^cblas_[cz]herk$/) {
      $cond_offload = "!$func_name\_offload_dsp($$argsref[0],$$argsref[3],$$argsref[4])";
    }
    # cher2k, zher2k
    if ($fname =~ /^cblas_[cz]her2k$/) {
      $cond_offload = "!$func_name\_offload_dsp($$argsref[0],$$argsref[3],$$argsref[4])";
    }
  }

  if ($cond_offload) {
    return "$cond_offload";
  }
  return ""; # if control reaches here then no modifier
}
#end of get_offload_decision

# put this function in a separate file ideally
sub clapack_bufsize_modifier
{
  $fname = shift;
  $argnum = shift;
  $argsref = shift;

  # saxpy, daxpy, caxpy, zaxpy
  if ($fname =~ /^[sdcz]axpy_$/) {
    return "*$$argsref[0]*abs(*$$argsref[3])*" if ($argnum == 2);
    return "*$$argsref[0]*abs(*$$argsref[5])*" if ($argnum == 4);
  }
  # scopy, dcopy, ccopy, zcopy
  if ($fname =~ /^[sdcz]copy_$/) {
    return "*$$argsref[0]*abs(*$$argsref[2])*" if ($argnum == 1);
    return "*$$argsref[0]*abs(*$$argsref[4])*" if ($argnum == 3);
  }
  # [cz]dot[cu]
  if ($fname =~ /^[sdcz]dot[cu]_$/) {
    return "*$$argsref[1]*abs(*$$argsref[3])*" if ($argnum == 2);
    return "*$$argsref[1]*abs(*$$argsref[5])*" if ($argnum == 4);
  }
  # sgbmv, dgbmv, cgbmv, zgbmv
  if ($fname =~ /^[sdcz]gbmv_$/) {
    return "*$$argsref[1]*abs(*$$argsref[2])*" if ($argnum == 6); # A: M x N
    return "(*$$argsref[0] == 'N' ? *$$argsref[1]:*$$argsref[2])*abs(*$$argsref[-4])*" if ($argnum == 8);
    return "(*$$argsref[0] == 'N' ? *$$argsref[2]:*$$argsref[1])*abs(*$$argsref[-1])*" if ($argnum == 11);
  }
  # sgemm, dgemm, cgemm, zgemm
  if ($fname =~ /^[sdcz]gemm_$/) {
    return "*$$argsref[2]*(*$$argsref[4])*" if ($argnum == 6); # A: M x K
    return "*$$argsref[4]*(*$$argsref[3])*" if ($argnum == 8); # B: K x N
    return "*$$argsref[2]*(*$$argsref[3])*" if ($argnum == 11);# C: M x N
  }
  # sgemv, dgemv, cgemv, zgemv
  if ($fname =~ /^[sdcz]gemv_$/) {
    return "*$$argsref[1]*abs(*$$argsref[2])*" if ($argnum == 4); # A : M x N
    return "(1+(*$$argsref[0] == 'N' ? *$$argsref[1]-1:*$$argsref[2]-1)*abs(*$$argsref[-4]))*" if ($argnum == 6);
    return "(1+(*$$argsref[0] == 'N' ? *$$argsref[2]-1:*$$argsref[1]-1)*abs(*$$argsref[-1]))*" if ($argnum == 9);
  }
  # cgeru, zgeru, cgerc, zgerc
  if ($fname =~ /^[cz]ger[uc]_$/) {
    return "*$$argsref[0]*abs(*$$argsref[1])*" if ($argnum == 7); # A : M x N
    return "(1 + (*$$argsref[0] -1)*abs(*$$argsref[4]))*" if ($argnum == 3);# X : 1+ (M-1)*incX
    return "(1 + (*$$argsref[1] -1)*abs(*$$argsref[6]))*" if ($argnum == 5);# Y : 1+ (N-1)*incY
  }
  # chbmv, zhbmv
  if ($fname =~ /^[cz]hbmv_$/) {
    return "*$$argsref[1]*abs(*$$argsref[1])*" if ($argnum == 4); # A : N x N
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[-4]))*" if ($argnum == 6);# X : 1+ (N-1) x incX
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[-1]))*" if ($argnum == 9);# Y : 1+ (N-1) x incX
  }
  # chemm, zhemm
  if ($fname =~ /^[cz]hemm_$/) {
    return "(((*$$argsref[0] == 'L') || (*$$argsref[0] == 'l')) ? *$$argsref[2]*(*$$argsref[2]):*$$argsref[3]*(*$$argsref[3]))*" if ($argnum == 5); # A: MxM or NxN
    return "*$$argsref[2]*(*$$argsref[3])*" if ($argnum == 7);# B: MxN
    return "*$$argsref[2]*(*$$argsref[3])*" if ($argnum == 10);# C: MxN
  }
  # chemv, zhemv
  if ($fname =~ /^[cz]hemv_$/) {
    return "*$$argsref[1]*abs(*$$argsref[1])*" if ($argnum == 3); # A : N x N
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[-4]))*" if ($argnum == 5);# X : 1+(N-1) x incX
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[-1]))*" if ($argnum == 8);# Y : 1+(N-1) x incY
  }
  # cher, zher, chpr, zhpr
  if ($fname =~ /^[cz]h[ep]r_$/) {
    return "*$$argsref[1]*abs(*$$argsref[1])*" if ($argnum == 5); # A : N x N
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# X : 1+(N-1) x incX
  }
  # cher2, zher2, chpr2, zhpr2
  if ($fname =~ /^[cz]h[ep]r2_$/) {
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 7); # A : N x N
    return "(*$$argsref[1])*abs(*$$argsref[4])*" if ($argnum == 3);# X : N x incX
    return "(*$$argsref[1])*abs(*$$argsref[6])*" if ($argnum == 5);# Y : N x incY
  }
  # cher2k, zher2k
  if ($fname =~ /^[cz]her2k_$/) {
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 5); # A: NxK or KxN
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 7); # B: KxN or NxK
    return "(*$$argsref[2])*(*$$argsref[2])*" if ($argnum == 10);# C: NxN
  }
  # cherk, zherk
  if ($fname =~ /^[cz]herk_$/) {
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 5); # A: NxK or KxN
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 8);# C: NxN
  }
  # chpmv, zhpmv
  if ($fname =~ /^[cz]hpmv_$/) {
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 4); # Ap : N x N
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[5]))*" if ($argnum == 4);# X : 1+(N-1) x incX
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[-1]))*" if ($argnum == 7);# Y : 1+(N-1) x incY
  }
  if ($fname =~ /^[sdcz]gesvd_$/) {
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 4); # A : M x N
    return "(*$$argsref[2])*(*$$argsref[2])*" if ($argnum == 7); # U : M x M
    return "(*$$argsref[3])*(*$$argsref[3])*" if ($argnum == 9); # V : N x N
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 6); # S : M x N
    return "(*$$argsref[-2] > 1 ? *$$argsref[-2] : 1)*" if ($argnum == 11); # work: max(1, *lwork)
  }
  if ($fname =~ /^[sdcz]gesv_$/) {
    return "(*$$argsref[0])*(*$$argsref[0])*" if ($argnum == 2); # A : N x N
    return "(*$$argsref[0])*" if ($argnum == 4); # IPIV : N
    return "(*$$argsref[0])*(*$$argsref[1])*" if ($argnum == 5); # B : N x NRHS
  }
  if ($fname =~ /^[sdcz]gesv_$/) {
    return "(*$$argsref[0])*(*$$argsref[0])*" if ($argnum == 2); # A : N x N
    return "(*$$argsref[0])*" if ($argnum == 4); # IPIV : N
    return "(*$$argsref[0])*(*$$argsref[1])*" if ($argnum == 5); # B : N x NRHS
  }
  # cscal, dscal, zscal, sscal
  if ($fname =~ /^[sdcz]scal_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[-1]))*" if ($argnum == 2);# cx : 1+(N-1)*incx 
  }
  # csscal, zdscal
  if ($fname =~ /^[cz][sd]scal_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[-1]))*" if ($argnum == 2);# cx : 1+(N-1)*incx 
  }
  # srot, crot, drot, zrot
  if ($fname =~ /^[sdcz]rot_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))*" if ($argnum == 1);# cx : 1+(N-1)*incx 
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# cy : 1+(N-1)*incy 
  }
  # srotm, drotm
  if ($fname =~ /^[sd]rotm_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))*" if ($argnum == 1);# cx : 1+(N-1)*incx 
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# cy : 1+(N-1)*incy 
  }
  # csrot, zdrot
  if ($fname =~ /^[cz][sd]rot_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))*" if ($argnum == 1);# cx : 1+(N-1)*incx 
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# cy : 1+(N-1)*incy 
  }
  # cswap, sswap, dswap, zswap
  if ($fname =~ /^[sdcz]swap_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))*" if ($argnum == 1);# cx : 1+(N-1)*incx 
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# cy : 1+(N-1)*incy 
  }
  # sdot, dsdot, ddot
  if ($fname =~ /^d?[sd]dot_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))*" if ($argnum == 1);# cx : 1+(N-1)*incx 
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# cy : 1+(N-1)*incy 
  }
  # sasum, dasum, scasum, dzasum
  if ($fname =~ /^sasum_|dasum_|scasum_|dzasum_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))*" if ($argnum == 1);# sx : 1+(N-1)*incx 
  }
  # snrm2, dnrm2, dznrm2, scnrm2
  if ($fname =~ /^snrm2_|dnrm2_|dznrm2_|scnrm2_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[2]))*" if ($argnum == 1);# sx : 1+(N-1)*incx 
  }
  # sspr, dspr, cspr, zspr
  if ($fname =~ /^[sdcz]spr_$/) {
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# x : 1+(N-1)*incx 
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 5); # Ap : N x N
  }
  # sspr2, dspr2
  if ($fname =~ /^[sd]spr2_$/) {
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# x : 1+(N-1)*incx 
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[6]))*" if ($argnum == 5);# y : 1+(N-1)*incy 
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 7); # Ap : N x N
  }
  # ssymv, dsymv, csymv, zsymv
  if ($fname =~ /^[sdcz]symv_$/) {
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[6]))*" if ($argnum == 5);# x : 1+(N-1)*incx 
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[-1]))*" if ($argnum == 8);# y : 1+(N-1)*incy 
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 3); # A : N x N
  }
  # ssymm, dsymm, csymm, zsymm
  if ($fname =~ /^[sdcz]symm_$/) {
    return "(((*$$argsref[0] == 'L') || (*$$argsref[0] == 'l')) ? (*$$argsref[2])*(*$$argsref[2]):(*$$argsref[3])*(*$$argsref[3]))*" if ($argnum == 5); # A: MxM or NxN
    return "*$$argsref[2]*(*$$argsref[3])*" if ($argnum == 7);# B: MxN
    return "*$$argsref[2]*(*$$argsref[3])*" if ($argnum == 10);# C: MxN
  }
  # ssyr, dsyr, csyr, zsyr
  if ($fname =~ /^[sdcz]syr_$/) {
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# x : 1+(N-1)*incx 
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 5); # A : N x N
  }
  # ssyr2, dsyr2, csyr2, zsyr2
  if ($fname =~ /^[sd]syr2_$/) {
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# x : 1+(N-1)*incx 
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[6]))*" if ($argnum == 5);# y : 1+(N-1)*incy
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 7); # A : N x N
  }
  # ssyrk, csyrk, dsyrk, zsyrk
  if ($fname =~ /^[sdcz]syrk_$/) {
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 5); # A : N x K or K x N
    return "(*$$argsref[2])*(*$$argsref[2])*" if ($argnum == 8); # C : N x N
  }
  # stbmv, dtbmv, ctbmv, ztbmv, stbsv, dtbsv, ztbsv, ctbsv
  if ($fname =~ /^[sdcz]tb[ms]v_$/) {
    return "(*$$argsref[3])*(*$$argsref[3])*" if ($argnum == 5); # A : N x N
    return "(1+ (*$$argsref[3]-1)*abs(*$$argsref[-1]))*" if ($argnum == 7);# x : 1+(N-1)*incx 
  }
  # [sdcz]tpmv, [scdz]tpsv
  if ($fname =~ /^[sdcz]tp[ms]v_$/) {
    return "(*$$argsref[3])*(*$$argsref[3])*" if ($argnum == 4); # A : N x N
    return "(1+ (*$$argsref[3]-1)*abs(*$$argsref[-1]))*" if ($argnum == 5);# x : 1+(N-1)*incx 
  }
  # [sdcz]trmv, [sdcz]trsv
  if ($fname =~ /^[sdcz]tr[ms]v_$/) {
    return "(*$$argsref[3])*(*$$argsref[3])*" if ($argnum == 4); # A : N x N
    return "(1+ (*$$argsref[3]-1)*abs(*$$argsref[-1]))*" if ($argnum == 6);# x : 1+(N-1)*incx 
  }
  # [scdz]trmm
  if ($fname =~ /^[sdcz]trmm_$/) {
    return "(((*$$argsref[0] == 'L') || (*$$argsref[0] == 'l')) ? (*$$argsref[4])*(*$$argsref[4]):(*$$argsref[5])*(*$$argsref[5]))*" if ($argnum == 7); # A: MxM or NxN
    return "*$$argsref[4]*(*$$argsref[5])*" if ($argnum == 9);# B: MxN
  }
  # [scdz]trsm
  if ($fname =~ /^[sdcz]trsm_$/) {
    return "*$$argsref[4]*(*$$argsref[4])*" if ($argnum == 7);# A: MxM
    return "*$$argsref[4]*(*$$argsref[5])*" if ($argnum == 9);# B: MxN
  }
  # [sd]ger
  if ($fname =~ /^[sd]ger_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[4]))*" if ($argnum == 3);# x : 1+(M-1)*incx 
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[6]))*" if ($argnum == 5);# x : 1+(N-1)*incy 
    return "*$$argsref[0]*(*$$argsref[1])*" if ($argnum == 7);# A: MxN
  }
  # [sd]sbmv
  if ($fname =~ /^[sd]sbmv_$/) {
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 4); # A : N x N
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[7]))*" if ($argnum == 6);# x : 1+(N-1)*incx 
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[-1]))*" if ($argnum == 9);# y : 1+(N-1)*incy 
  }
  # [sdcz]spmv
  if ($fname =~ /^[sd]spmv_$/) {
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 3); # A : N x N
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[5]))*" if ($argnum == 4);# x : 1+(N-1)*incx 
    return "(1+ (*$$argsref[1]-1)*abs(*$$argsref[-1]))*" if ($argnum == 7);# y : 1+(N-1)*incy 
  }
  # [s,d,c,z]syr2k
  if ($fname =~ /^[sdcz]syr2k_$/) {
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 5); # A : N x K or K x N
    return "(*$$argsref[2])*(*$$argsref[3])*" if ($argnum == 7); # B : N x K or K x N
    return "(*$$argsref[2])*(*$$argsref[2])*" if ($argnum == 10); # C : N x N
  }
  if ($fname =~ /^i[sdcz]amax_$/) {
    return "(1+ (*$$argsref[0]-1)*abs(*$$argsref[-1]))*" if ($argnum == 1);# x : 1+(N-1)*incx 
  }
  if ($fname =~ /^xerbla_array__$/) {
    return "(*$$argsref[1])*" if ($argnum == 0);# srname_array length is srnam_len__
  }
  if ($fname =~ /^[sdcz]bdsqr_$/) {
    return "(*$$argsref[1])*(*$$argsref[4])*" if ($argnum == 11); # C : n x ncc
    return "(*$$argsref[1])*(*$$argsref[3])*" if ($argnum == 9); # U : nru x n
    return "(*$$argsref[1])*(*$$argsref[2])*" if ($argnum == 7); # vt : n x ncvt
    return "((*$$argsref[1])*2)*" if ($argnum == 13); # rwork: array of dimension 2n
    return "((*$$argsref[1]) - 1)*" if ($argnum == 6); # e : array of dimension n-1
    return "(*$$argsref[1])*" if ($argnum == 5); # d : array of dimension n-1
  }
  if ($fname =~ /^[sdcz]gbbrd_$/) {
    return "(*$$argsref[1])*(*$$argsref[2])*" if ($argnum == 6); # a : m x n
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 10); # q: m x m
    return "(*$$argsref[1])*(*$$argsref[3])*" if ($argnum == 14); # C : m x ncc
    return "((*$$argsref[1]) < (*$$argsref[2]) ? (*$$argsref[1]):(*$$argsref[2]))*" if ($argnum == 8); # D : min(m,n)
    return "((*$$argsref[1]) < (*$$argsref[2]) ? (*$$argsref[1] -1):(*$$argsref[2] -1))*" if ($argnum == 9); # e : min(m,n) -1
    return "(*$$argsref[2])*(*$$argsref[2])*" if ($argnum == 12); # pt: n x n
    return "((*$$argsref[1]) > (*$$argsref[2]) ? (*$$argsref[1]):(*$$argsref[2]))*" if ($argnum == 16); # work : max(m,n)
    return "((*$$argsref[1]) > (*$$argsref[2]) ? (*$$argsref[1]):(*$$argsref[2]))*" if ($argnum == 17); # rwork : max(m,n)
  }
  if ($fname =~ /^[sdcz]gbcon_$/) {
    return "(*$$argsref[1]>*$$argsref[5]?*$$argsref[1]:*$$argsref[5])*(*$$argsref[1])*" if ($argnum == 4); # ab : max(ldab,n) x n
    return "((*$$argsref[1])*2)*" if ($argnum == 9); # work: array of dimension 2n
    return "((*$$argsref[1]))*" if ($argnum == 10); # rwork: array of dimension n
    return "(*$$argsref[1])*" if ($argnum == 6); # ipiv : array of dimension n
  }
  # scdz/gbequ, scdz/gbequb
  if ($fname =~ /^[sdcz]gbequb?_$/) {
    return "(*$$argsref[0]>*$$argsref[5]?*$$argsref[0]:*$$argsref[5])*(*$$argsref[1])*" if ($argnum == 4); # ab : max(ldab,m) x n
    return "((*$$argsref[0]))*" if ($argnum == 6); # r: array of dimension m
    return "((*$$argsref[1]))*" if ($argnum == 7); # c: array of dimension n
  }
  # scdz/gbrfs
  if ($fname =~ /^[sdcz]gbrfs_$/) {
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 5); # a : n x n
    return "(*$$argsref[11])*(*$$argsref[4])*" if ($argnum == 10); # b : ldb x nrhs
    return "(*$$argsref[13])*(*$$argsref[4])*" if ($argnum == 12); # x : ldx x nrhs
    return "((*$$argsref[4]))*" if ($argnum == 14); # ferr: array of dimension nrhs
    return "((*$$argsref[4]))*" if ($argnum == 15); # berr: array of dimension nrhs
    return "((*$$argsref[1])*2)*" if ($argnum == 16); # work: array of dimension 2n
    return "((*$$argsref[1]))*" if ($argnum == 17); # rwork: array of dimension n
    return "((*$$argsref[1]))*" if ($argnum == 9); # ipiv: array of dimension n
    return "(*$$argsref[1])*(*$$argsref[8])*" if ($argnum == 7); # afb : ldafb x n
  }
  # scdz/pbrfs
  if ($fname =~ /^[sdcz]pbrfs_$/) {
    return "(*$$argsref[1])*(*$$argsref[1])*" if ($argnum == 4); # a : n x n
    return "(*$$argsref[9])*(*$$argsref[3])*" if ($argnum == 8); # b : ldb x nrhs
    return "(*$$argsref[11])*(*$$argsref[3])*" if ($argnum == 10); # x : ldx x nrhs
    return "((*$$argsref[3]))*" if ($argnum == 12); # ferr: array of dimension nrhs
    return "((*$$argsref[3]))*" if ($argnum == 13); # berr: array of dimension nrhs
    return "((*$$argsref[1])*3)*" if ($argnum == 14); # work: array of dimension 3n
    return "((*$$argsref[1]))*" if ($argnum == 15); # iwork: array of dimension n
    return "(*$$argsref[1])*(*$$argsref[7])*" if ($argnum == 6); # afb : ldafb x n
  }
  # sdcz/gbsv
  if ($fname =~ /^[sdcz]gbsv_$/) {
    return "(*$$argsref[0]>*$$argsref[5]?*$$argsref[0]:*$$argsref[5])*(*$$argsref[0])*" if ($argnum == 4); # ab : max(ldab,n) x n
    return "((*$$argsref[0]))*" if ($argnum == 6); # ipiv: array of dimension n
    return "(*$$argsref[8])*(*$$argsref[3])*" if ($argnum == 7); # b : ldb x nrhs
  }
  # sdcz/gbtf2
  if ($fname =~ /^[sdcz]gbtf2_$/) {
    return "(*$$argsref[0]>*$$argsref[5]?*$$argsref[0]:*$$argsref[5])*(*$$argsref[1])*" if ($argnum == 4); # ab : max(ldab,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 6); # ipiv : min(m,n)
  }
  # sdcz/gbtrf
  if ($fname =~ /^[sdcz]gbtrf_$/) {
    return "(*$$argsref[0]>*$$argsref[5]?*$$argsref[0]:*$$argsref[5])*(*$$argsref[1])*" if ($argnum == 4); # ab : max(ldab,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 6); # ipiv : min(m,n)
  }
  # sdcz/gbtrs
  if ($fname =~ /^[sdcz]gbtrs_$/) {
    return "(*$$argsref[1]>*$$argsref[6]?*$$argsref[1]:*$$argsref[6])*(*$$argsref[1])*" if ($argnum == 5); # ab : max(ldab,n) x n
    return "((*$$argsref[1]))*" if ($argnum == 7); # ipiv: array of dimension n
  }
  # sdcz/gebak
  if ($fname =~ /^[sdcz]gebak_$/) {
    return "(*$$argsref[2]>*$$argsref[8]?*$$argsref[2]:*$$argsref[8])*(*$$argsref[6])*" if ($argnum == 7); # v : max(ldv,n) x m
    return "((*$$argsref[2]))*" if ($argnum == 5); # scale: array of dimension n
  }
  # sdcz/gebal
  if ($fname =~ /^[sdcz]gebal_$/) {
    return "(*$$argsref[1]>*$$argsref[3]?*$$argsref[1]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,n) x n
    return "((*$$argsref[1]))*" if ($argnum == 6); # scale: array of dimension n
  }
  # sdcz/gebd2
  if ($fname =~ /^[sdcz]gebd2_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # d : dimension min(m,n)
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0])-1:(*$$argsref[1])-1)*" if ($argnum == 5); # e : dim min(m,n) -1
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 6); # tauq : dim min(m,n)
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 7); # taup : dim min(m,n)
    return "((*$$argsref[0]) > (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 8); # work : dim max(m,n)
  }
  # sdcz/gebrd
  if ($fname =~ /^[sdcz]gebrd_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # d : dimension min(m,n)
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0])-1:(*$$argsref[1])-1)*" if ($argnum == 5); # e : dim min(m,n) -1
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 6); # tauq : dim min(m,n)
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 7); # taup : dim min(m,n)
    return "((*$$argsref[9]))*" if ($argnum == 8); # work : dim lwork
  }
  # sdcz/gecon
  if ($fname =~ /^[sdcz]gecon_$/) {
    return "(*$$argsref[1]>*$$argsref[3]?*$$argsref[1]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,n) x n
    return "((*$$argsref[1])*2)*" if ($argnum == 6); # work : dim 2n
    return "((*$$argsref[1])*2)*" if ($argnum == 7); # work : dim 2n
  }
  # sdcz/geequ sdcz/geequb
  if ($fname =~ /^[sdcz]geequb?_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]))*" if ($argnum == 4); # r__ : dim m
    return "((*$$argsref[1]))*" if ($argnum == 5); # c__ : dim n
  }
  # sdcz/gees
  if ($fname =~ /^[sdcz]gees_$/) {
    return "(*$$argsref[3]>*$$argsref[5]?*$$argsref[3]:*$$argsref[5])*(*$$argsref[3])*" if ($argnum == 4); # a : max(lda,n) x n
    return "((*$$argsref[3]))*" if ($argnum == 7); # w : dim n
    return "(*$$argsref[3]>*$$argsref[9]?*$$argsref[3]:*$$argsref[9])*(*$$argsref[3])*" if ($argnum == 8); # vs : max(ldvs,n) x n
    return "(1>*$$argsref[11]?1:*$$argsref[11])*" if ($argnum == 10); # work: dim max(1,lwork)
    return "((*$$argsref[3]))*" if ($argnum == 12); # rwork : dim n
    return "((*$$argsref[3]))*" if ($argnum == 13); # bwork : dim n
  }
  # sdcz/geesx
  if ($fname =~ /^[sdcz]geesx_$/) {
    return "(*$$argsref[4]>*$$argsref[6]?*$$argsref[4]:*$$argsref[6])*(*$$argsref[4])*" if ($argnum == 5); # a : max(lda,n) x n
    return "((*$$argsref[4]))*" if ($argnum == 8); # w : dim n
    return "(*$$argsref[4]>*$$argsref[10]?*$$argsref[4]:*$$argsref[10])*(*$$argsref[4])*" if ($argnum == 9); # vs :max(ldvs,n) x n
    return "(1>*$$argsref[14]?1:*$$argsref[14])*" if ($argnum == 13); # work: dim max(1,lwork)
    return "((*$$argsref[4]))*" if ($argnum == 15); # rwork : dim n
    return "((*$$argsref[4]))*" if ($argnum == 16); # bwork : dim n
  }
  # sdcz/geev
  if ($fname =~ /^[sdcz]geev_$/) {
    return "(*$$argsref[2]>*$$argsref[4]?*$$argsref[2]:*$$argsref[4])*(*$$argsref[2])*" if ($argnum == 3); # a : max(lda,n) x n
    return "((*$$argsref[2]))*" if ($argnum == 5); # w : dim n
    return "(*$$argsref[2]>*$$argsref[7]?*$$argsref[2]:*$$argsref[7])*(*$$argsref[2])*" if ($argnum == 6); # vl : max(ldvl,n) x n
    return "(*$$argsref[2]>*$$argsref[9]?*$$argsref[2]:*$$argsref[9])*(*$$argsref[2])*" if ($argnum == 8); # vr : max(ldvr,n) x n
    return "(1>*$$argsref[11]?1:*$$argsref[11])*" if ($argnum == 10); # work: dim max(1,lwork)
    return "((*$$argsref[2])*2)*" if ($argnum == 12); # rwork : dim 2n
  }
  # sdcz/geevx
  if ($fname =~ /^[sdcz]geevx_$/) {
    return "(*$$argsref[4]>*$$argsref[6]?*$$argsref[4]:*$$argsref[6])*(*$$argsref[4])*" if ($argnum == 5); # a : max(lda,n) x n
    return "((*$$argsref[4]))*" if ($argnum == 7); # w : dim n
    return "(*$$argsref[4]>*$$argsref[9]?*$$argsref[4]:*$$argsref[9])*(*$$argsref[4])*" if ($argnum == 8); # vl : max(ldvl,n) x n
    return "(*$$argsref[2]>*$$argsref[11]?*$$argsref[4]:*$$argsref[11])*(*$$argsref[4])*" if ($argnum == 10);#vr : max(ldvr,n) x n
    return "((*$$argsref[4]))*" if ($argnum == 14); # scale : dim n
    return "((*$$argsref[4]))*" if ($argnum == 16); # rconde : dim n
    return "((*$$argsref[4]))*" if ($argnum == 17); # rcondv : dim n
    return "(1>*$$argsref[19]?1:*$$argsref[19])*" if ($argnum == 18); # work: dim max(1,lwork)
    return "((*$$argsref[4])*2)*" if ($argnum == 20); # rwork : dim 2n
  }
  # sdcz/gegs
  if ($fname =~ /^[sdcz]gegs_$/) {
    return "(*$$argsref[2]>*$$argsref[4]?*$$argsref[2]:*$$argsref[4])*(*$$argsref[2])*" if ($argnum == 3); # a : max(lda,n) x n
    return "(*$$argsref[2]>*$$argsref[6]?*$$argsref[2]:*$$argsref[6])*(*$$argsref[2])*" if ($argnum == 5); # b : max(ldb,n) x n
    return "((*$$argsref[2]))*" if ($argnum == 7); # alpha : dim n
    return "((*$$argsref[2]))*" if ($argnum == 8); # beta : dim n
    return "(*$$argsref[2]>*$$argsref[10]?*$$argsref[2]:*$$argsref[10])*(*$$argsref[2])*" if ($argnum == 9);# vsl:max(ldvsl,n) x n
    return "(*$$argsref[2]>*$$argsref[12]?*$$argsref[2]:*$$argsref[12])*(*$$argsref[2])*" if ($argnum == 11);#vsr:max(ldvsr,n) x n
    return "(1>*$$argsref[14]?1:*$$argsref[14])*" if ($argnum == 13); # work: dim max(1,lwork)
    return "((*$$argsref[2])*3)*" if ($argnum == 15); # rwork : dim 3n
  }
  # sdcz/gegv
  if ($fname =~ /^[sdcz]gegv_$/) {
    return "(*$$argsref[2]>*$$argsref[4]?*$$argsref[2]:*$$argsref[4])*(*$$argsref[2])*" if ($argnum == 3); # a : max(lda,n) x n
    return "(*$$argsref[2]>*$$argsref[6]?*$$argsref[2]:*$$argsref[6])*(*$$argsref[2])*" if ($argnum == 5); # b : max(ldb,n) x n
    return "((*$$argsref[2]))*" if ($argnum == 7); # alpha : dim n
    return "((*$$argsref[2]))*" if ($argnum == 8); # beta : dim n
    return "(*$$argsref[2]>*$$argsref[10]?*$$argsref[2]:*$$argsref[10])*(*$$argsref[2])*" if ($argnum == 9);# vl : max(ldvl,n) x n
    return "(*$$argsref[2]>*$$argsref[12]?*$$argsref[2]:*$$argsref[12])*(*$$argsref[2])*" if ($argnum == 11);# vr: max(ldvr,n) x n
    return "(1>*$$argsref[14]?1:*$$argsref[14])*" if ($argnum == 13); # work: dim max(1,lwork)
    return "((*$$argsref[2])*8)*" if ($argnum == 15); # rwork : dim 8n
  }
  # sdcz/gehd2
  if ($fname =~ /^[sdcz]gehd2_$/) {
    return "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[0])*" if ($argnum == 3); # a : max(lda,n) x n
    return "((*$$argsref[0]) -1)*" if ($argnum == 5); # tau: dim n-1
    return "((*$$argsref[0]))*" if ($argnum == 6); # work: dim n
  }
  # sdcz/gehrd
  if ($fname =~ /^[sdcz]gehrd_$/) {
    return "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[0])*" if ($argnum == 3); # a : max(lda,n) x n
    return "((*$$argsref[0]) -1)*" if ($argnum == 5); # tau: dim n-1
    return "((*$$argsref[7]))*" if ($argnum == 6); # work: dim lwork
  }
  # sdcz/gelq2
  if ($fname =~ /^[sdcz]gelq2_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # tau : dim min(m,n)
    return "((*$$argsref[0]))*" if ($argnum == 5); # work: dim m
  }
  # sdcz/gelqf
  if ($fname =~ /^[sdcz]gelqf_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # tau : dim min(m,n)
    return "(1>*$$argsref[6]?1:*$$argsref[6])*" if ($argnum == 5); # work: dim max(1,lwork)
  }
  # sdcz/gels
  if ($fname =~ /^[sdcz]gels_$/) {
    return "(*$$argsref[1]>*$$argsref[5]?*$$argsref[1]:*$$argsref[5])*(*$$argsref[2])*" if ($argnum == 4); # a : max(lda,m) x n
    return "(*$$argsref[1]>*$$argsref[7]?*$$argsref[1]:*$$argsref[7])*(*$$argsref[3])*" if ($argnum == 6); # b : max(ldb,m) x nrhs
    return "(1>*$$argsref[9]?1:*$$argsref[9])*" if ($argnum == 8); # work: dim max(1,lwork)
  }
  # sdcz/gelsd
  if ($fname =~ /^[sdcz]gelsd_$/) {
    return "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[1])*" if ($argnum == 3); # a : max(lda,m) x n
    return "(*$$argsref[0]>*$$argsref[6]?*$$argsref[0]:*$$argsref[6])*(*$$argsref[2])*" if ($argnum == 5); # b : max(ldb,m) x nrhs
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 7); # s : dim min(m,n)
    return "(1>*$$argsref[11]?1:*$$argsref[11])*" if ($argnum == 10); # work: dim max(1,lwork)
    return "(1>*$$argsref[11]?1:*$$argsref[11])*" if ($argnum == 12); # rwork: dim max(1,lwork)
    return "(1>*$$argsref[11]?1:*$$argsref[11])*" if ($argnum == 13); # iwork: dim max(1,lwork)
  }
  # sdcz/gelss
  if ($fname =~ /^[sdcz]gelss_$/) {
    return "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[1])*" if ($argnum == 3); # a : max(lda,m) x n
    return "(*$$argsref[0]>*$$argsref[6]?*$$argsref[0]:*$$argsref[6])*(*$$argsref[2])*" if ($argnum == 5); # b : max(ldb,m) x nrhs
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 7); # s : dim min(m,n)
    return "(1>*$$argsref[11]?1:*$$argsref[11])*" if ($argnum == 10); # work: dim max(1,lwork)
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*5*" if ($argnum == 12); # rwork : 5*dim min(m,n)
  }
  # sdcz/gelsx
  if ($fname =~ /^[sdcz]gelsx_$/) {
    return "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[1])*" if ($argnum == 3); # a : max(lda,m) x n
    return "(*$$argsref[0]>*$$argsref[6]?*$$argsref[0]:*$$argsref[6])*(*$$argsref[2])*" if ($argnum == 5); # b : max(ldb,m) x nrhs
    return "((*$$argsref[1]))*" if ($argnum == 7); # jpvt: dim n
    return "(MIN(*$$argsref[0],*$$argsref[1]) + MAX(*$$argsref[1], (2*MIN(*$$argsref[0],*$$argsref[1])+*$$argsref[2])))*" if ($argnum == 10); # work: dim (min(M,N) + max( N, 2*min(M,N)+NRHS ))
    return "(2*(*$$argsref[1]))*" if ($argnum == 11); # rwork: dim 2n
  }
  # sdcz/gelsy
  if ($fname =~ /^[sdcz]gelsy_$/) {
    return "(*$$argsref[0]>*$$argsref[4]?*$$argsref[0]:*$$argsref[4])*(*$$argsref[1])*" if ($argnum == 3); # a : max(lda,m) x n
    return "(*$$argsref[6])*(*$$argsref[2])*" if ($argnum == 5); # b : ldb x nrhs
    return "((*$$argsref[1]))*" if ($argnum == 7); # jpvt: dim n
    return "(1>*$$argsref[11]?1:*$$argsref[11])*" if ($argnum == 10); # work: dim max(1,lwork)
    return "(2*(*$$argsref[1]))*" if ($argnum == 12); # rwork: dim 2n
  }
  # sdcz/geql2
  if ($fname =~ /^[sdcz]geql2_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # tau : dim min(m,n)
    return "((*$$argsref[1]))*" if ($argnum == 5); # work: dim n
  }
  # sdcz/geqlf
  if ($fname =~ /^[sdcz]geqlf_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # tau : dim min(m,n)
    return "(1>*$$argsref[6]?1:*$$argsref[6])*" if ($argnum == 5); # work: dim max(1,lwork)
  }
  # sdcz/geqp3
  if ($fname =~ /^[sdcz]geqp3_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[1]))*" if ($argnum == 4); # jpvt: dim n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 5); # tau : dim min(m,n)
    return "(1>*$$argsref[7]?1:*$$argsref[7])*" if ($argnum == 6); # work: dim max(1,lwork)
    return "(2*(*$$argsref[1]))*" if ($argnum == 8); # rwork: dim 2n
  }
  # sdcz/geqpf
  if ($fname =~ /^[sdcz]geqpf_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[1]))*" if ($argnum == 4); # jpvt: dim n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 5); # tau : dim min(m,n)
    return "((*$$argsref[1]))*" if ($argnum == 6); # jpvt: dim n
    return "(2*(*$$argsref[1]))*" if ($argnum == 7); # rwork: dim 2n
  }
  # sdcz/geqr2
  if ($fname =~ /^[sdcz]geqr2_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # tau : dim min(m,n)
    return "((*$$argsref[1]))*" if ($argnum == 5); # work: dim n
  }
  # sdcz/geqrf
  if ($fname =~ /^[sdcz]geqrf_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # tau : dim min(m,n)
    return "(1>*$$argsref[6]?1:*$$argsref[6])*" if ($argnum == 5); # work: dim max(1,lwork)
  }
  # sdcz/gerfs
  if ($fname =~ /^[sdcz]gerfs_$/) {
    return "(*$$argsref[1]>*$$argsref[4]?*$$argsref[1]:*$$argsref[4])*(*$$argsref[1])*" if ($argnum == 3); # a : max(lda,n) x n
    return "(*$$argsref[1]>*$$argsref[6]?*$$argsref[1]:*$$argsref[6])*(*$$argsref[1])*" if ($argnum == 5); # af: max(ldaf,n) x n
    return "((*$$argsref[1]))*" if ($argnum == 7); # ipiv: dim n
    return "(*$$argsref[1]>*$$argsref[9]?*$$argsref[1]:*$$argsref[9])*(*$$argsref[2])*" if ($argnum == 8); # b : max(ldb,n) x nrhs
    return "(*$$argsref[1]>*$$argsref[11]?*$$argsref[1]:*$$argsref[11])*(*$$argsref[2])*" if ($argnum == 10);#x:max(ldx,n) x nrhs
    return "((*$$argsref[2]))*" if ($argnum == 12); # ferr: dim nrhs
    return "((*$$argsref[2]))*" if ($argnum == 13); # berr: dim nrhs
    return "((*$$argsref[1])*2)*" if ($argnum == 14); # work: dim 2n
    return "((*$$argsref[1]))*" if ($argnum == 15); # rwork: dim n
  }
  # sdcz/gerfsx
  if ($fname =~ /^[sdcz]gerfsx_$/) {
    return "(*$$argsref[2]>*$$argsref[5]?*$$argsref[2]:*$$argsref[5])*(*$$argsref[2])*" if ($argnum == 4); # a : max(lda,n) x n
    return "(*$$argsref[2]>*$$argsref[7]?*$$argsref[2]:*$$argsref[7])*(*$$argsref[2])*" if ($argnum == 6); # af: max(ldaf,n) x n
    return "((*$$argsref[2]))*" if ($argnum == 8); # ipiv: dim n
    return "((*$$argsref[2]))*" if ($argnum == 9); # r: dim n
    return "((*$$argsref[2]))*" if ($argnum == 10); # c: dim n
    return "(*$$argsref[2]>*$$argsref[12]?*$$argsref[2]:*$$argsref[12])*(*$$argsref[3])*" if ($argnum == 11);# b:max(ldb,n) x nrhs
    return "(*$$argsref[2]>*$$argsref[14]?*$$argsref[2]:*$$argsref[14])*(*$$argsref[3])*" if ($argnum == 13);#x:max(ldx,n) x nrhs
    return "((*$$argsref[3]))*" if ($argnum == 16); # berr: dim nrhs
    return "(*$$argsref[3])*(*$$argsref[17])*" if ($argnum == 18);# err_bnds_norm_: nrhs x n_err_bnds
    return "(*$$argsref[3])*(*$$argsref[17])*" if ($argnum == 19);# err_bnds_comp_: nrhs x n_err_bnds
    return "((*$$argsref[20]))*" if ($argnum == 21); # params: dim nparams
    return "((*$$argsref[2])*2)*" if ($argnum == 22); # work: dim 2n
    return "((*$$argsref[2])*2)*" if ($argnum == 23); # rwork: dim 2n
  }
  # sdcz/gerq2
  if ($fname =~ /^[sdcz]gerq2_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # tau : dim min(m,n)
    return "((*$$argsref[0]))*" if ($argnum == 5); # work: dim m
  }
  # sdcz/gerqf
  if ($fname =~ /^[sdcz]gerqf_$/) {
    return "(*$$argsref[0]>*$$argsref[3]?*$$argsref[0]:*$$argsref[3])*(*$$argsref[1])*" if ($argnum == 2); # a : max(lda,m) x n
    return "((*$$argsref[0]) < (*$$argsref[1]) ? (*$$argsref[0]):(*$$argsref[1]))*" if ($argnum == 4); # tau : dim min(m,n)
    return "(1>*$$argsref[6]?1:*$$argsref[6])*" if ($argnum == 5); # work: dim max(1,lwork)
  }
  # sdcz/gesc2
  if ($fname =~ /^[sdcz]gesc2_$/) {
    return "(*$$argsref[0]>*$$argsref[2]?*$$argsref[0]:*$$argsref[2])*(*$$argsref[0])*" if ($argnum == 2); # a : max(lda,n) x n
    return "((*$$argsref[0]))*" if ($argnum == 3); # rhs: dim n
    return "((*$$argsref[0]))*" if ($argnum == 4); # ipiv: dim n
    return "((*$$argsref[0]))*" if ($argnum == 5); # jpiv: dim n
  }
}


# returns the constant modifier (if any) for the supplied function
# if none, returns an empty string
# $argnum starts from 0 (for first argument)
# This modifier is generated by multiplying constants in the function
# arguments based on the function name. This modifier when multiplied with
# the argument type size, determines the full size of the buffer for
# USE_HOST_PTR
# Arg 1: function name
# Arg 2: the argument number for whom we need to determine the multiplier
# Arg 3: Args array
sub get_bufsize_modifier
{
  $fname = shift;
  $argnum = shift;
  $argsref = shift;

  # clapack
  return clapack_bufsize_modifier($fname, $argnum, $argsref) if ($namespace =~ /_clapack$/);

  # BLAS modifiers below
  my $z_mult = "" ; # set to 2 for all double-complex precisions
  my $c_mult = "" ; # set to 2 for all complex and double-complex precisions

  ### Level 1 ###
  # dsdot, sdot, ddot
  if ($fname =~ /^cblas_d?[sd]dot$/) {
    return "(1+($$argsref[0]-1)*abs($$argsref[-3]))*" if ($argnum == 1);
    return "(1+($$argsref[0]-1)*abs($$argsref[-1]))*" if ($argnum == 3);
  }
  # sdsdot
  if ($fname =~ /^cblas_sdsdot$/) {
    return "(1+($$argsref[0]-1)*abs($$argsref[-3]))*" if ($argnum == 2);
    return "(1+($$argsref[0]-1)*abs($$argsref[-1]))*" if ($argnum == 4);
  }
  # cdotu_sub, cdotc_sub, zdotu_sub, zdotc_sub
  if ($fname =~ /^cblas_[cz]dot[uc]_sub$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[2]))*" if ($argnum == 1);
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[4]))*" if ($argnum == 3);
    return "${z_mult}${c_mult}" if ($argnum == 5);
  }
  # snrm2, dnrm2, scnrm2 dznrm2
  if ($fname =~ /^cblas_[sd][cz]?nrm2$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_.z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_.[cz].*$/) ;
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[2]))*" if ($argnum == 1);
  }
  # sasum, dasum, scasum, dzasum
  if ($fname =~ /^cblas_[sd][cz]?asum$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_.z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_.[cz].*$/) ;
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[2]))*" if ($argnum == 1);
  }
  # isamax, idamax, icamax, izamax
  if ($fname =~ /^cblas_i[sdcz]amax$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_.z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_.[cz].*$/) ;
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[2]))*" if ($argnum == 1);
  }
  # sswap, dswap, cswap, zswap
  if ($fname =~ /^cblas_[sdcz]swap$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[2]))*" if ($argnum == 1);
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[4]))*" if ($argnum == 3);
  }
  # scopy, dcopy, ccopy, zcopy
  if ($fname =~ /^cblas_[sdcz]copy$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[2]))*" if ($argnum == 1);
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[4]))*" if ($argnum == 3);
  }
  # saxpy, daxpy, caxpy, zaxpy
  if ($fname =~ /^cblas_[sdcz]axpy$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}2*" if (($argnum == 1) && ($fname =~ /^cblas_[cz].*$/)) ; # a
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[3]))*" if ($argnum == 2);
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[5]))*" if ($argnum == 4);
  }
  # srot, drot, srotm, drotm
  if ($fname =~ /^cblas_[sd]rotm?$/) {
    return "(1+($$argsref[0]-1)*abs($$argsref[2]))*" if ($argnum == 1);
    return "(1+($$argsref[0]-1)*abs($$argsref[4]))*" if ($argnum == 3);
    return "5*" if ($argnum == 5);
  }
  if ($fname =~ /^cblas_[sd]rotmg$/) {
    return "5*" if ($argnum == 4);
  }
  # sscal, dscal, cscal, zscal, csscal, zdscal
  if ($fname =~ /^cblas_[sdcz][sd]?scal$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}2*" if (($argnum == 1) && ($fname =~ /^cblas_[cz].*$/)) ; # a
    return "${z_mult}${c_mult}(1+($$argsref[0]-1)*abs($$argsref[3]))*" if ($argnum == 2);
  }

  ### Level 2 BLAS ###
  # void cblas_sgemv(const enum CBLAS_ORDER Order,
  #                  const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
  #                  const float alpha, const float *A, const int lda,
  #                  const float *X, const int incX, const float beta,
  #                  float *Y, const int incY);
  # sgemv, dgemv, cgemv, zgemv
  # SGEMV ('T',  4,  9, 1.0, A,  5, X, 1,  .0, Y, 1) 
  if ($fname =~ /^cblas_[sdcz]gemv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}BLAS_ORD($$argsref[0],$$argsref[2],$$argsref[3])*$$argsref[6]*" if ($argnum == 5); # A: lda x (n or m)
    return "${z_mult}${c_mult}(1+(BLAS_TRN($$argsref[1],$$argsref[3],$$argsref[2])-1)*abs($$argsref[8]))*" if ($argnum == 7); # X: incX x (n or m)
    return "${z_mult}${c_mult}(1+(BLAS_TRN($$argsref[1],$$argsref[2],$$argsref[3])-1)*abs($$argsref[11]))*" if ($argnum == 10); # Y: incY x (m or n)
    return "${z_mult}2*" if (($argnum == 4) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 9) && ($fname =~ /^cblas_[cz].*$/)) ; # beta
    #return "$$argsref[2]*abs($$argsref[3])*" if ($argnum == 5);
    #return "($$argsref[1] == CblasNoTrans ? $$argsref[2]:$$argsref[3])*abs($$argsref[-4])*" if ($argnum == 7);
    #return "($$argsref[1] == CblasNoTrans ? $$argsref[3]:$$argsref[2])*abs($$argsref[-1])*" if ($argnum == 10);
  }

  #void cblas_sgbmv(const enum CBLAS_ORDER Order,
  #                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
  #                 const int KL, const int KU,
  #                 const float alpha, const float *A, const int lda,
  #                 const float *X, const int incX, const float beta,
  #                 float *Y, const int incY);
  # sgbmv, dgbmv, cgbmv, zgbmv
  if ($fname =~ /^cblas_[sdcz]gbmv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}BLAS_ORD($$argsref[0],$$argsref[2],$$argsref[3])*$$argsref[8]*" if ($argnum == 7); # A: lda x (n or m)
    return "${z_mult}${c_mult}(1+(BLAS_TRN($$argsref[1],$$argsref[3],$$argsref[2])-1)*abs($$argsref[10]))*" if ($argnum == 9); # X: incX x (n or m)
    return "${z_mult}${c_mult}(1+(BLAS_TRN($$argsref[1],$$argsref[2],$$argsref[3])-1)*abs($$argsref[13]))*" if ($argnum == 12); # Y: incY x (m or n)
    return "${z_mult}2*" if (($argnum == 6) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 11) && ($fname =~ /^cblas_[cz].*$/)) ; # beta
  }

  #void cblas_strmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
  #                 const int N, const float *A, const int lda,
  #                 float *X, const int incX);
  # strmv, dtrmv, ctrmv, ztrmv
  if ($fname =~ /^cblas_[sdcz]trmv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[4]*$$argsref[6]*" if ($argnum == 5); # A : lda x n
    return "${z_mult}${c_mult}(1+($$argsref[4]-1)*abs($$argsref[-1]))*" if ($argnum == 7); # X: 1 + (n-1)*incX
    #return "$$argsref[4]*abs($$argsref[-1])*" if ($argnum == 7);# X : N x incX
  }

  #void cblas_stbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
  #                 const int N, const int K, const float *A, const int lda,
  #                 float *X, const int incX);
  # stbmv, dtbmv, ctbmv, ztbmv
  if ($fname =~ /^cblas_[sdcz]tbmv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[4]*$$argsref[7]*" if ($argnum == 6); # A : lda x n
    return "${z_mult}${c_mult}(1+($$argsref[4]-1)*abs($$argsref[-1]))*" if ($argnum == 8); # X: 1 + (n-1)*incX
    #return "$$argsref[4]*abs($$argsref[4])*" if ($argnum == 6); # A : N x N
    #return "$$argsref[4]*abs($$argsref[-1])*" if ($argnum == 8);# X : N x incX
  }
  #void cblas_strsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
  #                 const int N, const float *A, const int lda, float *X,
  #                 const int incX);
  # strsv, dtrsv, ctrsv, ztrsv
  if ($fname =~ /^cblas_[sdcz]trsv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[4]*$$argsref[6]*" if ($argnum == 5); # A : lda x n
    return "${z_mult}${c_mult}(1+($$argsref[4]-1)*abs($$argsref[-1]))*" if ($argnum == 7); # X: 1 + (n-1)*incX
    #return "$$argsref[4]*abs($$argsref[4])*" if ($argnum == 5); # A : N x N
    #return "$$argsref[4]*abs($$argsref[-1])*" if ($argnum == 7);# X : N x incX
  }
  #void cblas_stbsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #               const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
  #               const int N, const int K, const float *A, const int lda,
  #               float *X, const int incX);
  # stbsv, dtbsv, ctbsv, ztbsv
  if ($fname =~ /^cblas_[sdcz]tbsv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[4]*$$argsref[7]*" if ($argnum == 6); # A : lda x n
    return "${z_mult}${c_mult}(1+($$argsref[4]-1)*abs($$argsref[-1]))*" if ($argnum == 8); # X: 1 + (n-1)*incX
    #return "$$argsref[4]*abs($$argsref[4])*" if ($argnum == 6); # A : N x N
    #return "$$argsref[4]*abs($$argsref[-1])*" if ($argnum == 8);# X : N x incX
  }
  #void cblas_stpsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
  #                 const int N, const float *Ap, float *X, const int incX);
  # stpsv, dtpsv, ctpsv, ztpsv
  if ($fname =~ /^cblas_[sdcz]tpsv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[4]*($$argsref[4]+1)/2*" if ($argnum == 5); # Ap : n(n+1)/2
    return "${z_mult}${c_mult}(1+($$argsref[4]-1)*abs($$argsref[-1]))*" if ($argnum == 6); # X: 1 + (n-1)*incX
    #return "$$argsref[4]*abs($$argsref[4])*" if ($argnum == 5); # Ap : N x N
    #return "$$argsref[4]*abs($$argsref[-1])*" if ($argnum == 6);# X : N x incX
  }

  #void cblas_ssymv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const int N, const float alpha, const float *A,
  #                 const int lda, const float *X, const int incX,
  #                 const float beta, float *Y, const int incY);
  # ssymv, dsymv
  if ($fname =~ /^cblas_[sd]symv$/) {
    return "$$argsref[2]*$$argsref[5]*" if ($argnum == 4); # A : lda x n
    return "(1+($$argsref[2]-1)*abs($$argsref[-4]))*" if ($argnum == 6); # X: 1 + (n-1)*incX
    return "(1+($$argsref[2]-1)*abs($$argsref[-1]))*" if ($argnum == 9); # Y: 1 + (n-1)*incY
    #return "$$argsref[2]*abs($$argsref[-4])*" if ($argnum == 6);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[-1])*" if ($argnum == 9);# Y : N x incY
  }
  #void cblas_ssbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const int N, const int K, const float alpha, const float *A,
  #                 const int lda, const float *X, const int incX,
  #                 const float beta, float *Y, const int incY);
  # ssbmv, dsbmv
  if ($fname =~ /^cblas_[sd]sbmv$/) {
    return "$$argsref[2]*$$argsref[6]*" if ($argnum == 5); # A : lda x n
    return "(1+($$argsref[2]-1)*abs($$argsref[-4]))*" if ($argnum == 7); # X: 1 + (n-1)*incX
    return "(1+($$argsref[2]-1)*abs($$argsref[-1]))*" if ($argnum == 10);# Y: 1 + (n-1)*incY
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 5); # A : N x N
    #return "$$argsref[2]*abs($$argsref[-4])*" if ($argnum == 7);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[-1])*" if ($argnum == 10);# Y : N x incY
  }
  # sspmv, dspmv
  if ($fname =~ /^cblas_[sd]spmv$/) {
    return "$$argsref[2]*($$argsref[2]+1)/2*" if ($argnum == 4); # Ap : n x n
    return "(1+($$argsref[2]-1)*abs($$argsref[-4]))*" if ($argnum == 5); # X: 1 + (n-1)*incX
    return "(1+($$argsref[2]-1)*abs($$argsref[-1]))*" if ($argnum == 8); # Y: 1 + (n-1)*incY
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 4); # Ap : N x N
    #return "$$argsref[2]*abs($$argsref[-4])*" if ($argnum == 5);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[-1])*" if ($argnum == 8);# Y : N x incY
  }
  #void cblas_ssyr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                const int N, const float alpha, const float *X,
  #                const int incX, float *A, const int lda);
  # ssyr, dsyr
  if ($fname =~ /^cblas_[sd]syr$/) {
    return "$$argsref[2]*$$argsref[-1]*" if ($argnum == 6); # A : lda x n
    return "(1+($$argsref[2]-1)*abs($$argsref[5]))*" if ($argnum == 4); # X: 1 + (n-1)*incX
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 6); # A : N x N
    #return "$$argsref[2]*abs($$argsref[5])*" if ($argnum == 4);# X : N x incX
  }

  #void cblas_ssyr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                const int N, const float alpha, const float *X,
  #                const int incX, const float *Y, const int incY, float *A,
  #                const int lda);
  # ssyr2, dsyr2
  if ($fname =~ /^cblas_[sd]syr2$/) {
    return "$$argsref[2]*$$argsref[-1]*" if ($argnum == 8); # A : lda x n
    return "(1+($$argsref[2]-1)*abs($$argsref[5]))*" if ($argnum == 4); # X: 1 + (n-1)*incX
    return "(1+($$argsref[2]-1)*abs($$argsref[7]))*" if ($argnum == 6); # Y: 1 + (n-1)*incY
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 8); # A : N x N
    #return "$$argsref[2]*abs($$argsref[5])*" if ($argnum == 4);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[7])*" if ($argnum == 6);# Y : N x incY
  }

  #void cblas_sspr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #              const int N, const float alpha, const float *X,
  #              const int incX, float *Ap);
  # sspr, dspr
  if ($fname =~ /^cblas_[sd]spr$/) {
    return "$$argsref[2]*($$argsref[2]+1)/2*" if ($argnum == 6); # Ap: N x N
    return "(1+($$argsref[2]-1)*abs($$argsref[5]))*" if ($argnum == 4); # X: 1 + (n-1)*incX
  }

  #void cblas_sspr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                const int N, const float alpha, const float *X,
  #                const int incX, const float *Y, const int incY, float *A);
  # sspr2, dspr2
  if ($fname =~ /^cblas_[sd]spr2$/) {
    return "$$argsref[2]*($$argsref[2]+1)/2*" if ($argnum == 8); # Ap: n x n
    return "(1+($$argsref[2]-1)*abs($$argsref[5]))*" if ($argnum == 4); # X: 1 + (n-1)*incX
    return "(1+($$argsref[2]-1)*abs($$argsref[7]))*" if ($argnum == 6); # Y: 1 + (n-1)*incY
  }

  #void cblas_zhemv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const int N, const void *alpha, const void *A,
  #                 const int lda, const void *X, const int incX,
  #                 const void *beta, void *Y, const int incY);
  # chemv, zhemv
  if ($fname =~ /^cblas_[cz]hemv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[2]*$$argsref[5]*" if ($argnum == 4); # A : lda x n
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[7]))*" if ($argnum == 6); # X: 1 + (n-1)*incX
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[-1]))*" if ($argnum == 9); # Y: 1 + (n-1)*incY
    return "${z_mult}2*" if (($argnum == 3) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 8) && ($fname =~ /^cblas_[cz].*$/)) ; # beta
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 4); # A : N x N
    #return "$$argsref[2]*abs($$argsref[-4])*" if ($argnum == 6);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[-1])*" if ($argnum == 9);# Y : N x incY
  }
  #void cblas_zhbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const int N, const int K, const void *alpha, const void *A,
  #                 const int lda, const void *X, const int incX,
  #                 const void *beta, void *Y, const int incY);
  # chbmv, zhbmv
  if ($fname =~ /^cblas_[cz]hbmv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[2]*$$argsref[6]*" if ($argnum == 5); # A : lda x n
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[8]))*" if ($argnum == 7); # X: 1 + (n-1)*incX
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[-1]))*" if ($argnum == 10); # Y: 1 + (n-1)*incY
    return "${z_mult}2*" if (($argnum == 4) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 9) && ($fname =~ /^cblas_[cz].*$/)) ; # beta
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 5); # A : N x N
    #return "$$argsref[2]*abs($$argsref[-4])*" if ($argnum == 7);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[-1])*" if ($argnum == 10);# Y : N x incY
  }
  #void cblas_ztpmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
  #                 const int N, const void *Ap, void *X, const int incX);
  # ctpmv, ztpmv
  if ($fname =~ /^cblas_[scdz]tpmv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[4]*($$argsref[4]+1)/2*" if ($argnum == 5); # Ap : n x (n+1)/2
    return "${z_mult}${c_mult}(1+($$argsref[4]-1)*abs($$argsref[-1]))*" if ($argnum == 6); # X: 1 + (n-1)*incX
  }

  #void cblas_zhpmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                 const int N, const void *alpha, const void *Ap,
  #                 const void *X, const int incX,
  #                 const void *beta, void *Y, const int incY);
  # chpmv, zhpmv
  if ($fname =~ /^cblas_[cz]hpmv$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[2]*($$argsref[2]+1)/2*" if ($argnum == 4); # Ap : n x n
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[6]))*" if ($argnum == 5); # X: 1 + (n-1)*incX
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[-1]))*" if ($argnum == 8); # Y: 1 + (n-1)*incY
    return "${z_mult}2*" if (($argnum == 3) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 7) && ($fname =~ /^cblas_[cz].*$/)) ; # beta
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 4); # Ap : N x N
    #return "$$argsref[2]*abs($$argsref[-4])*" if ($argnum == 5);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[-1])*" if ($argnum == 8);# Y : N x incY
  }
  #void cblas_sger(const enum CBLAS_ORDER Order, const int M, const int N,
  #                const float alpha, const float *X, const int incX,
  #                const float *Y, const int incY, float *A, const int lda);
  # sger, dger
  if ($fname =~ /^cblas_[sd]ger$/) {
    return "BLAS_ORD($$argsref[0],$$argsref[1],$$argsref[2])*$$argsref[-1]*" if($argnum== 8);#A:lda x (n or m)
    return "(1+($$argsref[1]-1)*abs($$argsref[5]))*" if ($argnum == 4);# X: 1 + (m-1)*incX 
    return "(1+($$argsref[2]-1)*abs($$argsref[7]))*" if ($argnum == 6);# Y: 1 + (n-1)*incX 
    #return "$$argsref[1]*abs($$argsref[2])*" if ($argnum == 8); # A : M x N
    #return "$$argsref[1]*abs($$argsref[-5])*" if ($argnum == 4);# X : M x incX
    #return "$$argsref[2]*abs($$argsref[-3])*" if ($argnum == 6);# Y : N x incY
  }
  #void cblas_zgeru(const enum CBLAS_ORDER Order, const int M, const int N,
  #                 const void *alpha, const void *X, const int incX,
  #                 const void *Y, const int incY, void *A, const int lda);
  #void cblas_zgerc(const enum CBLAS_ORDER Order, const int M, const int N,
  #                 const void *alpha, const void *X, const int incX,
  #                 const void *Y, const int incY, void *A, const int lda);
  # cgeru, zgeru, cgerc, zgerc
  if ($fname =~ /^cblas_[cz]ger[uc]$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}BLAS_ORD($$argsref[0],$$argsref[1],$$argsref[2])*$$argsref[-1]*" if($argnum== 8);#A:lda x (n or m)
    return "${z_mult}${c_mult}(1+($$argsref[1]-1)*abs($$argsref[5]))*" if ($argnum == 4);# X: 1 + (m-1)*incX 
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[7]))*" if ($argnum == 6);# Y: 1 + (n-1)*incX 
    return "${z_mult}2*" if (($argnum == 3) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    #return "$$argsref[1]*abs($$argsref[2])*" if ($argnum == 8); # A : M x N
    #return "$$argsref[1]*abs($$argsref[5])*" if ($argnum == 4);# X : M x incX
    #return "$$argsref[2]*abs($$argsref[7])*" if ($argnum == 6);# Y : N x incY
  }
  #void cblas_zher(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                const int N, const double alpha, const void *X, const int incX,
  #                void *A, const int lda);
  # cher, zher
  if ($fname =~ /^cblas_[cz]her$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[2]*$$argsref[-1]*" if ($argnum == 6); # A : lda x n
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[5]))*" if ($argnum == 4); # X: 1 + (n-1)*incX
    #return "${z_mult}${c_mult}$$argsref[2]*abs($$argsref[5])*" if ($argnum == 4);# X : N x incX
  }
  #void cblas_zhpr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                const int N, const double alpha, const void *X,
  #                const int incX, void *A);
  # chpr, zhpr
  if ($fname =~ /^cblas_[cz]hpr$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[2]*($$argsref[2]+1)/2*" if ($argnum == 6); # A : n x (n+1)/2
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[5]))*" if ($argnum == 4); # X: 1 + (n-1)*incX
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 6); # A : N x N
    #return "$$argsref[2]*abs($$argsref[5])*" if ($argnum == 4);# X : N x incX
  }
  #void cblas_zher2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const int N,
  #                const void *alpha, const void *X, const int incX,
  #                const void *Y, const int incY, void *A, const int lda);
  # cher2, zher2
  if ($fname =~ /^cblas_[cz]her2$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[2]*$$argsref[-1]*" if ($argnum == 8); # A : lda x n
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[5]))*" if ($argnum == 4); # X: 1 + (n-1)*incX
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[7]))*" if ($argnum == 6); # Y: 1 + (n-1)*incY
    return "${z_mult}2*" if (($argnum == 3) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 8); # A : N x N
    #return "$$argsref[2]*abs($$argsref[5])*" if ($argnum == 4);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[7])*" if ($argnum == 6);# Y : N x incY
  }
  #void cblas_zhpr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const int N,
  #                const void *alpha, const void *X, const int incX,
  #                const void *Y, const int incY, void *Ap);
  # chpr2, zhpr2
  if ($fname =~ /^cblas_[cz]hpr2$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}$$argsref[2]*($$argsref[2]+1)/2*" if ($argnum == 8); # Ap : n x (n+1)/2
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[5]))*" if ($argnum == 4); # X: 1 + (n-1)*incX
    return "${z_mult}${c_mult}(1+($$argsref[2]-1)*abs($$argsref[7]))*" if ($argnum == 6); # Y: 1 + (n-1)*incY
    return "${z_mult}2*" if (($argnum == 3) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    #return "$$argsref[2]*abs($$argsref[2])*" if ($argnum == 8); # A : N x N
    #return "$$argsref[2]*abs($$argsref[5])*" if ($argnum == 4);# X : N x incX
    #return "$$argsref[2]*abs($$argsref[7])*" if ($argnum == 6);# Y : N x incY
  }

  ### BLAS Level 3 ###
  # sgemm, dgemm, cgemm, zgemm
  # void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
  #              const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
  #              const int K, const double alpha, const double *A,
  #              const int lda, const double *B, const int ldb,
  #              const double beta, double *C, const int ldc);
  #void cblas_cgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
  #               const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
  #               const int K, const void *alpha, const void *A,
  #               const int lda, const void *B, const int ldb,
  #               const void *beta, void *C, const int ldc);
  if ($fname =~ /^cblas_[sdcz]gemm$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}BLAS_ORD_T($$argsref[0],$$argsref[1],$$argsref[3],$$argsref[5])*$$argsref[8]*" if ($argnum == 7);
    return "${z_mult}${c_mult}BLAS_ORD_T($$argsref[0],$$argsref[2],$$argsref[5],$$argsref[4])*$$argsref[10]*" if ($argnum == 9);
    return "${z_mult}${c_mult}BLAS_ORD($$argsref[0],$$argsref[3],$$argsref[4])*$$argsref[13]*" if ($argnum == 12);
    return "${z_mult}2*" if (($argnum == 6) && ($fname =~ /^cblas_[cz]gemm$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 11) && ($fname =~ /^cblas_[cz]gemm$/)) ;# beta
  }
  #void cblas_ssymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
  #               const enum CBLAS_UPLO Uplo, const int M, const int N,
  #               const float alpha, const float *A, const int lda,
  #               const float *B, const int ldb, const float beta,
  #               float *C, const int ldc);
  #void cblas_chemm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
  #                 const enum CBLAS_UPLO Uplo, const int M, const int N,
  #                 const void *alpha, const void *A, const int lda,
  #                 const void *B, const int ldb, const void *beta,
  #                 void *C, const int ldc);
  # ssymm, dsymm, csymm, zsymm
  # chemm, zhemm
  if ($fname =~ /^cblas_[sdcz]symm|cblas_[cz]hemm$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}BLAS_SIDE($$argsref[1],$$argsref[3],$$argsref[4])*$$argsref[7]*" if ($argnum == 6); # A: lda x (m or n)
    return "${z_mult}${c_mult}BLAS_ORD($$argsref[0],$$argsref[3],$$argsref[4])*$$argsref[9]*" if ($argnum == 8);#B:ldb x (n or m)
    return "${z_mult}${c_mult}BLAS_ORD($$argsref[0],$$argsref[3],$$argsref[4])*$$argsref[12]*" if ($argnum==11);#C:ldc X (n or m)
    return "${z_mult}2*" if (($argnum == 5) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 10) && ($fname =~ /^cblas_[cz].*$/)) ;# beta
  }
  # void cblas_ssyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #               const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
  #               const float alpha, const float *A, const int lda,
  #               const float beta, float *C, const int ldc);
  # ssyrk, dsyrk, csyrk, zsyrk
  # cherk, zherk
  if ($fname =~ /^cblas_[sdcz]syrk|cblas_[cz]herk$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}BLAS_ORD_T($$argsref[0],$$argsref[2],$$argsref[3],$$argsref[4])*$$argsref[7]*" if ($argnum == 6); # A: lda X (k or n)
    return "${z_mult}${c_mult}$$argsref[3]*$$argsref[10]*" if ($argnum == 9); # C : ldc x n
    return "${z_mult}2*" if (($argnum == 5) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 8) && ($fname =~ /^cblas_[cz].*$/)) ;# beta
  }


  #void cblas_strmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
  #                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
  #                 const enum CBLAS_DIAG Diag, const int M, const int N,
  #                 const float alpha, const float *A, const int lda,
  #                 float *B, const int ldb);
  # strmm, dtrmm, ctrmm, ztrmm, strsm, dtrsm, ctrsm, ztrsm
  if ($fname =~ /^cblas_[sdcz]tr[ms]m$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}BLAS_SIDE($$argsref[1],$$argsref[5],$$argsref[6])*$$argsref[9]*" if ($argnum == 8); # A: lda x (m or n)
    return "${z_mult}${c_mult}BLAS_ORD($$argsref[0],$$argsref[5],$$argsref[6])*$$argsref[11]*" if($argnum== 10);#B:ldb x (n or m)
    return "${z_mult}2*" if (($argnum == 7) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    #return "$$argsref[5]*$$argsref[5]*" if ($argnum == 8); # A: MxM
    #return "$$argsref[5]*$$argsref[6]*" if ($argnum == 10);# B: MxN
  }

  # ssyr2k, dsyr2k, csyr2k, zsyr2k
  #void cblas_ssyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                  const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
  #                  const float alpha, const float *A, const int lda,
  #                  const float *B, const int ldb, const float beta,
  #                  float *C, const int ldc);
  # cher2k, zher2k
  #void cblas_cher2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
  #                  const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
  #                  const void *alpha, const void *A, const int lda,
  #                  const void *B, const int ldb, const float beta,
  #                  void *C, const int ldc);
  if ($fname =~ /^cblas_[sdcz]syr2k|cblas_[cz]her2k$/) {
    $z_mult = "COMP_DBL" if ($fname =~ /^cblas_z.*$/) ;
    $c_mult = "2*" if ($fname =~ /^cblas_[cz].*$/) ;
    return "${z_mult}${c_mult}BLAS_ORD_T($$argsref[0],$$argsref[2],$$argsref[3],$$argsref[4])*$$argsref[7]*" if ($argnum == 6); # A: lda X (k or n)
    return "${z_mult}${c_mult}BLAS_ORD_T($$argsref[0],$$argsref[2],$$argsref[3],$$argsref[4])*$$argsref[9]*" if ($argnum == 8); # A: ldb X (k or n)
    return "${z_mult}${c_mult}$$argsref[3]*$$argsref[12]*" if ($argnum == 11); # C : ldc x n
    return "${z_mult}2*" if (($argnum == 5) && ($fname =~ /^cblas_[cz].*$/)) ; # alpha
    return "${z_mult}2*" if (($argnum == 10) && ($fname =~ /^cblas_[cz].*$/)) ;# beta
  }
  return ""; # if control reaches here then no modifier
}

sub get_func_specific_offload_var
{
  my $func = shift;
  my $NAMESPACE = uc($namespace);
  $func_name = substr($func, 7);
#JXU
#  print "function name is $func_name\n";
#JXU
  if (index($blas_L1, "${func_name}|") != -1) {
    return "${NAMESPACE}_L1_OFFLOAD";
  }
  if (index($blas_L3, "${func_name}|") != -1) {
    return "${NAMESPACE}_L3_OFFLOAD";
  }
  if (index($blas_L2, "${func_name}|") != -1) {
    return "${NAMESPACE}_L2_OFFLOAD";
  }
  if (index("${func_name}|", "amax") != -1) {
    return "${NAMESPACE}_L1_OFFLOAD";
  }
#  return "${NAMESPACE}_L1_OFFLOAD" if ($func_name =~ /$blas_L1/);
#  return "${NAMESPACE}_L3_OFFLOAD" if ($func_name =~ /$blas_L3/);
#  return "${NAMESPACE}_L2_OFFLOAD" if ($func_name =~ /$blas_L2/);

#JXU
  print "function name not matched!\n";
#JXU

  # if no match then use the default offload variable
  return "${namespace}_offload"; 
}

# takes as argument a trimmed string that is a prototype. Semicolon at end does not matter.
# It will generate ARM C++ code that launches an OpenCL kernel code here 

sub generate_arm_from_proto($)
{
    my $string = shift;
    $string =~ s/;//;
    my $NAMESPACE = uc($namespace);

    # func return type
    my @tmp = split /[\(\)]/,$string;
    my $tramptype = $tmp[0];
    $tramptype =~ s/(.*)\ ([\* ]*).*/$1 $2/;
    $tramptype = trim($tramptype);

    # func name
    my $trampname = $tmp[0];
    $trampname =~ s/.*\ \**(.*)$/$1/;

    # global side effect!
    push @offloaded,$trampname;

    # kernel index
    my $trampdef = $trampname;
    $trampdef = uc $namespace . "_" . (uc $trampname) . "_IDX";

    # func args 
    shift @tmp;
    my @args = split /\,/,$tmp[0]; #/;
    my $lastargind = $#args;
    my @kernelargs;
    my @kerneltypes;
    # test for a vararg last argument and trunc, ugh
    if (($#args > -1) && (trim($args[$#args]) eq "...")) {
	$#args--;
	$lastargind = $#args;
    }

LOOP1:
{
    foreach my $arg (@args) {
	$arg = trim($arg);
	my $argname = $arg;
        # get arg name
	$argname =~ s/.*\ \**(.*)$/$1/;
	$argname = trim($argname);
	if ($argname =~ /void/i) {
	    next LOOP1;
	}
	push @kernelargs,$argname;
        # get arg type
	my $argtype = $arg;
	$argtype =~ s/(.*)$argname/$1/;
	$argtype = trim($argtype);
	push @kerneltypes,$argtype;
    }
}


    my $arm_comment_header = "/****** UNCOMMENT CODE BELOW FOR ARM EXECUTION (NO OFFLOAD) *******";
    my $arm_comment_trailer ="******************************************************************/";
    #my $arm_func_cond = get_func_based_arm_cond($trampname, \@kernelargs);
	my $arm_func_cond = get_offload_decision($trampname, \@kernelargs);
    my $arm_condition_code = "";
#JXU
#    print "trampname is $trampname\n";
#JXU	
    my $offload_var = get_func_specific_offload_var($trampname);
#JXU
    print "offload_var is $offload_var\n";
#JXU	
    my $indent = "";
    my $arm_end_condition_code = "";
    if (!$commentarm) {
        $arm_comment_header = "/* Dynamic condtional offload to ARM */";
        $arm_comment_trailer= "/* End ARM offload */";
        $arm_func_cond = " || (($offload_var == ${NAMESPACE}_OFFLOAD_SIZE) && ($arm_func_cond))" if ($arm_func_cond);
        $arm_condition_code .= "if (($offload_var == ${NAMESPACE}_OFFLOAD_NONE)$arm_func_cond) { ";
        $indent .= "\t";
        $arm_end_condition_code = "}";
    }
    my $no_offload_arm_call = "";
    $no_offload_arm_call .= "$tramptype rval = " unless ($tramptype =~ /^void$/i);
    $no_offload_arm_call .= "__real_$trampname(" . join(',', @kernelargs) . "); ";
    my $no_offload_arm_return = "return ";
    $no_offload_arm_return .= "rval" unless ($tramptype =~ /^void$/i);
    $no_offload_arm_return .= ";";
    my $arm_real_proto = $string;
    $arm_real_proto =~ s/$trampname/__real_$trampname/ ;

    my $armcode = <<"ARM_FROM_PROTO";
$source_code_header	
#include "${namespace}_acc.h"
#include "../../ticblas/ticblas.h"

#ifdef __cplusplus
extern "C" { 
#endif
    $arm_real_proto ; 

#ifdef __cplusplus
}
extern "C"
#endif
$string
{

	/* Do an init on first use */
	if (!${namespace}_init_done) ${namespace}_init();
	${NAMESPACE}_DEBUG_PRINT("Intercepted call to %s\\n", "$trampname");
ARM_FROM_PROTO

    if (index($trampname, "swap") != -1) {	
    $armcode .= "
	/* OpenCL cannot deal with overlapping memory regions. This is an issue when you
	 * are trying to swap two rows of a matrix, where the matrix is column major. Hence,
	 * the offload of this routine to the DSP is disabled.
	 */
#ifndef TI_CBLAS_SWAP_ENABLE_OFFLOAD
    TI_CBLAS_PROFILE_START();
	TI_CBLAS_DEBUG_PRINT(\"Executing ARM %s\\n\", \"$trampname\");
    $no_offload_arm_call
    TI_CBLAS_PROFILE_REPORT(\"  Entire %s call (ARM) took %8.2f us\\n\",\"$trampname\", (float) clock_diff);
	return ;
#else
";
}

    $armcode .= "
    ${NAMESPACE}_PROFILE_START();
	$arm_comment_header
    $arm_condition_code
	${NAMESPACE}_DEBUG_PRINT(\"Executing ARM %s\\n\", \"$trampname\"); 
	$no_offload_arm_call
    ${NAMESPACE}_PROFILE_REPORT(\"  Entire %s call (ARM) took %8.2f us\\n\",\"$trampname\", (float) clock_diff);
	$no_offload_arm_return
    $arm_end_condition_code
    $arm_comment_trailer

	/******************************************************************/
	/* DSP offload WILL be done if control reaches here */
	${NAMESPACE}_DEBUG_PRINT(\"Offloading to DSP %s\\n\", \"$trampname\"); 

	/* Lookup kernel pointer from global table */
#ifdef __cplusplus
	Event e;
	Kernel* __K;
#else
	cl_kernel __K;
#endif
    __K =  ${namespace}_get_kernel(\"ocl_$trampname\");

#ifdef __cplusplus
	try 
#else
	cl_int err = CL_SUCCESS;
#endif
	{
";

    my $i = 0;
    foreach $arg (@kernelargs) {
       if ($kerneltypes[$i] =~ /.*\*\s*/) {
           # pointer type arg
           my $perms = "CL_MEM_READ_WRITE";
           my $modifier = "";
           my $argtype = trim($kerneltypes[$i]);
           if ($argtype =~ /\s*const\s.*/) {
             $armcode .= "\t\t/* For const arguments we use CL_MEM_USE_READ_ONLY */\n";
             $perms = "CL_MEM_READ_ONLY";
             $modifier = "(void *)"; # needed as Buffer uses void* and not const <type>*
             $argtype =~ s/\s*const//;  # remove const
           }
           my $modify_bufsize = get_bufsize_modifier($trampname, $i, \@kernelargs);
		   #print "modify_bufsize = $modify_bufsize\n";
           $argtype =~ s/\*//;
           $argtype = trim($argtype);
           my $sizeoftype = $argtype;
           #$sizeoftype = "float" if ($argtype =~ /void/i);
		   if ($argtype =~ /void/i) {
		     $sizeoftype = "float";
			 if (index($modify_bufsize, "COMP_DBL") != -1) {
			   $sizeoftype = "double";
			   $modify_bufsize = $modify_bufsize =~ s/COMP_DBL//r;
             }
		   }
		   #print "sizeoftype = $sizeoftype\n";
		   #print "new modify_bufsize = $modify_bufsize\n";

           # when modify bufsize is a non-empty, non-constant string, then
           # we have to guard against the possibility
           # the the buffer size empty because one of the multipliers is 0 (BLAS allows that, for example)
           if ($modify_bufsize && ($modify_bufsize !~ /^[0-9*]+$/)) {
             $armcode .= "
		int size_buf$arg;
		size_buf$arg = ${modify_bufsize}sizeof($sizeoftype);
		size_buf$arg = MAX(size_buf$arg,1);
		   
#ifdef __cplusplus
		Buffer buf_$arg(*${namespace}_ocl_context, $perms|CL_MEM_USE_HOST_PTR, size_buf$arg, (void *)$arg);
		__K->setArg($i, buf_$arg);
#else
		cl_mem buf_$arg = clCreateBuffer(${namespace}_ocl_context, $perms|CL_MEM_USE_HOST_PTR, size_buf$arg, (void *)$arg, &err);
		${NAMESPACE}_OCL_CHKERROR(\"clCreateBuffer\",err);
		err |= clSetKernelArg(__K, $i, sizeof(buf_$arg), &buf_$arg);
		${NAMESPACE}_OCL_CHKERROR(\"clSetKernelArg\",err);
#endif
";
           }
           else {
             $armcode .= "
#ifdef __cplusplus
		Buffer buf_$arg(*${namespace}_ocl_context, $perms|CL_MEM_USE_HOST_PTR, ${modify_bufsize}sizeof($sizeoftype), (void *)$arg);
		__K->setArg($i, buf_$arg);
#else
		cl_mem buf_$arg = clCreateBuffer(${namespace}_ocl_context, $perms|CL_MEM_USE_HOST_PTR, ${modify_bufsize}sizeof($sizeoftype), (void *)$arg, &err);
		${NAMESPACE}_OCL_CHKERROR(\"clCreateBuffer\",err);
		err |= clSetKernelArg(__K, $i, sizeof(buf_$arg), &buf_$arg);
		${NAMESPACE}_OCL_CHKERROR(\"clSetKernelArg\",err);
#endif
";
          }
        }
        else {
           $armcode .= "
#ifdef __cplusplus
		__K->setArg($i, $arg);
#else
		err |= clSetKernelArg(__K, $i, sizeof($arg), &$arg);
#endif
";
        }
        $i++;
    }
#    print $i;
#    print "\n";
#    print "trampname is " . $trampname . "\n";
    $kernel_name = substr($trampname, 7);
#    print "kernel_name is " . $kernel_name . "\n";
#	print "blas_L3 string is ". $blas_L3 . "\n";
	if (index($blas_L3, '.'.$kernel_name.'|') != -1) {
#	    print "This is a level 3 function - " . $trampname . "\n";
	
        $i_plus_1 = $i+1;
        $armcode .= "
		void *msmc_ptr;
		size_t msmc_size = MSMC_BUF_SIZE;
		msmc_ptr = ${namespace}_mem_alloc(MSMC_BUF_SIZE);
#ifdef __cplusplus
		Buffer buf_MSMC(*${namespace}_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, MSMC_BUF_SIZE, (void *)msmc_ptr);
		//Buffer buf_MSMC(${namespace}_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_MSMC_TI, MSMC_BUF_SIZE);
		__K->setArg($i, buf_MSMC);

#else
		//cl_mem buf_MSMC = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_MSMC_TI, MSMC_BUF_SIZE, NULL, &err);
		cl_mem buf_MSMC = clCreateBuffer(${namespace}_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, MSMC_BUF_SIZE, (void *)msmc_ptr, &err);
		TI_CBLAS_OCL_CHKERROR(\"clCreateBuffer\",err);
		err |= clSetKernelArg(__K, $i, sizeof(buf_MSMC), &buf_MSMC);
		TI_CBLAS_OCL_CHKERROR(\"clSetKernelArg\",err);
#endif

#ifdef __cplusplus
		__K->setArg($i_plus_1, msmc_size);
#else
		err |= clSetKernelArg(__K, $i_plus_1, sizeof(msmc_size), &msmc_size);
#endif
";
    	$i=$i+2;
        $i_plus_1 = $i+1;
        $armcode .= "		
		void *ddr_ptr;
		size_t ddr_size = DDR_BUF_SIZE;
		ddr_ptr = __malloc_ddr(DDR_BUF_SIZE);
		Buffer buf_DDR(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, DDR_BUF_SIZE, ddr_ptr);
		__K->setArg($i, buf_DDR);		
		__K->setArg($i_plus_1, ddr_size);	
";
    	$i=$i+2;
        $armcode .= "		
        /* create a buffer argument to get the return error code from the DSP */
		int err_code;		
#ifdef __cplusplus
		Buffer buf_err(*${namespace}_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(int), &err_code);
		__K->setArg($i, buf_err);
#else
		cl_mem buf_err = clCreateBuffer(*${namespace}_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(int), &err_code, &err);
		${NAMESPACE}_OCL_CHKERROR(\"clCreateBuffer\",err);
		err |= clSetKernelArg(__K, $i, sizeof(buf_err), &buf_err);
		${NAMESPACE}_OCL_CHKERROR(\"clSetKernelArg\",err);
#endif
";
    	$i++;
	}
	
    if ($tramptype !~ /^void$/i) {
      $armcode .= "
                /* create a buffer argument to get the return value from the DSP */
		$tramptype retval;
#ifdef __cplusplus
		Buffer buf_retval(*${namespace}_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof($tramptype), &retval);
		__K->setArg($i, buf_retval);
#else
		cl_mem buf_retval = clCreateBuffer(*${namespace}_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof($tramptype), &retval, &err);
		${NAMESPACE}_OCL_CHKERROR(\"clCreateBuffer\",err);
		err |= clSetKernelArg(__K, $i, sizeof(buf_retval), &buf_retval);
		${NAMESPACE}_OCL_CHKERROR(\"clSetKernelArg\",err);
#endif
";
    }
		
    $armcode .= "
#ifdef __cplusplus
		${namespace}_ocl_Q->enqueueTask(*__K, 0, &e);
		e.wait();
#else
		cl_event e;
		err |= clEnqueueTask(${namespace}_ocl_Q, __K, 0, 0, &e);
		${NAMESPACE}_OCL_CHKERROR(\"clEnqueueTask\",err);
		err |= clWaitForEvents(1, &e);
		${NAMESPACE}_OCL_CHKERROR(\"clWaitForEvents\",err);
		err |= clReleaseEvent(e);
		${NAMESPACE}_OCL_CHKERROR(\"clReleaseEvent\",err);
#endif
";
	if (index($blas_L3, '.'.$kernel_name.'|') != -1) {
        $armcode .= "
        if(err_code != TICBLAS_SUCCESS) {
          printf(\"Error in offloaded $trampname with error code %d!\\n\", err_code);
        }
		
		${namespace}_mem_free(msmc_ptr);
		__free_ddr(ddr_ptr);
";
    }
    $armcode .= "
		${namespace}_delete_kernel(__K);

		${NAMESPACE}_DEBUG_PRINT(\"Finished executing %s\\n\", \"$trampname\");
		${NAMESPACE}_PROFILE_REPORT(\"  Entire %s call (DSP) took %8.2f us\\n\",\"$trampname\", (float) clock_diff);
		return ";
    $armcode .= "retval" unless ($tramptype =~ /^void$/i);
    $armcode .= ";\n";
    $armcode .= "\t}\n";
    $armcode .= "
#ifdef __cplusplus
	catch (Error err)
	{
        /* delete __K if it has not been deleted */
        if(__K!=NULL) {
            ${namespace}_delete_kernel(__K);
        }
    
		${namespace}_error(err.what(),err.err());
		return ";
    $armcode .= "0" unless ($tramptype =~ /^void$/i);
    $armcode .= ";\n";
    $armcode .= "\t}\n#endif\n";
    if (index($trampname, "swap") != -1) {	
    $armcode .= "#endif //TI_CBLAS_SWAP_ENABLE_OFFLOAD\n";
    }	
    $armcode .= "}\n";

    return $armcode;
}


# Generates the kernel.cl code from the prototype.
# Takes as argument the function prototype string.
sub generate_kernel_from_proto($)
{
    my $string = shift;
	print "In generate_kernel_from_proto, string is " . $string. "\n";

    my $oclcode = "";
    my @tmp = split /[\(\)]/,$string;
    $oclcode .= "kernel " . ocl_munge($tmp[0]) . "(";
    my $trampname = trampoline_munge($tmp[0]);
    my $trampproto = $trampname . "(";

    my $kernel_name = substr($tmp[0], 12); 
#	print "In generate_kernel_from_proto, kernel is " . $kernel_name . "\n";
#	print "In generate_kernel_from_proto, trampname is " . $trampname . "\n";
    my $tramptype = $tmp[0];
    $tramptype =~ s/(.*)\ ([\* ]*).*/$1 $2/;
    $tramptype = trim($tramptype);
    # strip type 
    $trampname =~ s/.*\ \**(.*)$/$1/;

    shift @tmp;
    my @args = split /\,/,$tmp[0]; #/;
    my $lastargind = $#args;
    my @trampargs;
# test for a vararg last argument, ugh
    if (($#args > -1) && (trim($args[$#args]) eq "...")) {
	$#args--;
	$lastargind = $#args;
    }
    my $comma = "";
LOOP1:
{
    foreach my $arg (@args) {
	$arg = trim($arg);
	my $argname = $arg;
# strip types
	$argname =~ s/.*\ \**(.*)$/$1/;
	if ($argname =~ /void/i) {
	    next LOOP1;
	}
        $comma = ", ";
	push @trampargs,$argname;
	if ($arg =~ /.*\*.*$/) { 
	    $oclcode .= "global $arg"; 
	    $trampproto .= "global $arg"; 
	} else { 
	    $oclcode .= "$arg"; 
	    $trampproto .= "$arg"; }
        # if it's last argument don't add comma
	if ($arg ne trim($args[$lastargind])) {
	    $oclcode .= ", ";
	    $trampproto .= ", ";
	}
	else {
    	if (index($blas_L3, '.'.$kernel_name.'|') != -1) {
    	    print "In generate_kernel_from_proto, this is a level 3 function - " . $trampname . "\n";
			$oclcode .= ", global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code";
			$trampproto .= ", global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code";
		}
	}
    }
}
    $oclcode .= "${comma}global $tramptype *retval" unless ($tramptype =~ /^void$/i);
    $trampproto .= "${comma}global $tramptype *retval" unless ($tramptype =~ /^void$/i);

    $trampproto .= ");";
    $oclcode .= ")\n{ ";

    $oclcode .= $trampname . "(";

    foreach my $arg (@trampargs) {
	$oclcode .= "$arg";
	if ($arg ne trim($trampargs[$lastargind])) {
	    $oclcode .= ", "; }
    }
    $oclcode .= "${comma}retval" unless ($tramptype =~ /^void$/i);

   	if (index($blas_L3, '.'.$kernel_name.'|') != -1) {
		$oclcode .= ", l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code";
	}
    $oclcode .= "); }";
    $oclcode = $trampproto . "\n" . $oclcode;
    return $oclcode;
}

sub generate_kernel_prologue
{
  my $rc = $source_code_header;
  $rc = "$::dep\n" if ($::dep);
  return $rc;
}

# generates the top portion of facade.c (c66x code)
# use once (not on per-function basis)
sub generate_facade_prologue
{
  my $facade_prologue = <<"FACADE_PROLOGUE";
$source_code_header  
#include "../../cblas/include/cblas.h"
#include "../../ticblas/ticblas.h"

#ifdef TI_CBLAS_DEBUG
#include "stdio.h"  

extern char *pool_mk_mem_L1;
extern char *pool_kn_mem_L1;
extern char *pool_mn_mem_L1;
extern char *pool_mk_mem_L2;
extern char *pool_kn_mem_L2;
extern char *pool_mn_mem_L2;
extern char *pool_mk_mem_L3;
extern char *pool_kn_mem_L3;
extern char *pool_mn_mem_L3;
#endif

extern int bli_l3_mem_config(void *msmc_buf, size_t msmc_buf_size, void *ddr_buf, size_t ddr_buf_size, size_t *l1D_SRAM_size_orig, size_t *l2_SRAM_size_orig);
extern int bli_l3_mem_reconfig(size_t l1D_SRAM_size_orig, size_t l2_SRAM_size_orig);

FACADE_PROLOGUE
  return $facade_prologue;
}

# takes as argument a trimmed string that is a prototype. Semicolon at end does not matter.
# It will generate DSP code like the following:
# void FFT_plan_1d_dp_c2c_facade(int N, global double *in, global double *out, 
#                                    global double *tw, int type, int mode, global char* plan)
# { FFT_plan_1d_dp_c2c(N, in, out, tw, type, mode, plan); }
sub generate_facade_from_proto($)
{
    my $string = shift;

    my @tmp = split /[\(\)]/,$string;
    my $dspcode = trampoline_munge($tmp[0]) . "(";
    my $trampname = $tmp[0];
    my $trampproto = $trampname . "(";

    my $tramptype = $tmp[0];
    $tramptype =~ s/(.*)\ ([\* ]*).*/$1 $2/;
    $tramptype = trim($tramptype);
    # strip type 
    $trampname =~ s/.*\ \**(.*)$/$1/;

    shift @tmp;
    my @args = split /\,/,$tmp[0]; #/;
    my $lastargind = $#args;
    my @trampargs;
# test for a vararg last argument, ugh
    if (($#args > -1) && (trim($args[$#args]) eq "...")) {
	$#args--;
	$lastargind = $#args;
    }
    my $comma = "";
LOOP1:
{
    foreach my $arg (@args) {
	$arg = trim($arg);
	my $argname = $arg;
# strip types
	$argname =~ s/.*\ \**(.*)$/$1/;
	if ($argname eq "void") {
	    next LOOP1;
	}
        $comma = ", ";
	push @trampargs,$argname;
	$dspcode .= "$arg"; 
	$trampproto .= "$arg"; 
        # if it's last argument don't add comma
	if ($arg ne trim($args[$lastargind])) {
	    $dspcode .= ", ";
	    $trampproto .= ", ";
	}
    }
}
    $dspcode .= "${comma}$tramptype *retval" unless ($tramptype =~ /^void$/);
    $trampproto .= "${comma}$tramptype *retval" unless ($tramptype =~ /^void$/);

    $kernel_name = substr($trampname, 7);
	if (index($blas_L3, '.'.$kernel_name.'|') != -1) {
		$dspcode .= ", void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code";
		$trampproto .= ", void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code";
    }
	
    $trampproto .= ");";
    $dspcode .= ")\n{";
#    print "trampproto is " . $trampproto . "\n";
#    print "dspcode is " . $dspcode . "\n";
	
#    $dspcode .= "\tCACHE_L1Size prevL1 = CACHE_getL1DSize();\n" if ($dspl1);
#    $dspcode .= "\tCACHE_setL1DSize(CACHE_L1_${dspl1}KCACHE);\n" if ($dspl1);
#    $dspcode .= "\tCACHE_L2Size prevL2 = CACHE_getL2Size();\n" if ($dspl2);
#    $dspcode .= "\tCACHE_setL2Size(CACHE_${dspl2}KCACHE);\n" if ($dspl2);

	if (index($blas_L3, '.'.$kernel_name.'|') != -1) {
#        print "facade code to setup cache for level 3 function ". $trampname ."\n";
        $dspcode .= "
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = bli_l3_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
";
	}
    else {	
#        print "facade code to setup cache for level 1 or 2 function ". $trampname ."\n";
#        $dspcode .= "
#    #pragma omp parallel
#    {
#        __cache_l2_flush();
#        __cache_l2_512k();
#    }
#";
        $dspcode .= "
";
    }
	
#   if (!($tramptype =~ /^void$/)) { 
#	$dspcode .= "return ";
#   }
    $dspcode .= "\t";
    $dspcode .= "*retval = " unless ($tramptype =~ /^void$/);
    $dspcode .= $trampname . "(";

    foreach my $arg (@trampargs) {
	$dspcode .= "$arg";
	if ($arg ne trim($trampargs[$lastargind])) {
	    $dspcode .= ", "; }
    }
    $dspcode .= ");\n";
#    $dspcode .= "\tCACHE_setL1DSize(prevL1);\n" if ($dspl1);
#    $dspcode .= "\tCACHE_setL2Size(prevL2);\n" if ($dspl2);
	if (index($blas_L3, '.'.$kernel_name.'|') != -1) {
#        print "facade code to return default cache for level 3 function ". $trampname ."\n";
        $dspcode .= "
	*err_code = bli_l3_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
";
	}
    else {	
#        print "facade code to return default cache for level 1 or 2 function ". $trampname ."\n";
#        $dspcode .= "
#   	// return default L2 cache (128 K)
#    #pragma omp parallel
#    {
#        __cache_l2_flush();
#        __cache_l2_128k();
#    }
#";
	}
    $dspcode .= "}\n";
#    $dspcode = $trampproto . "\n" . $dspcode;
    return $dspcode;
}

# Generates arm header. Use only once.
sub generate_arm_header()
{
    my $i = 0;
    my $hdr = "";
    my $NAMESPACE = uc($namespace);
    $hdr .= "
$source_code_header

#ifndef ${NAMESPACE}_H
#define ${NAMESPACE}_H

#ifdef __cplusplus
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#define __CL_ENABLE_EXCEPTIONS
#include <CL/cl.hpp>
using namespace std;
using namespace cl;
/* Both cl and std namespace define size_t, so we must be explicit */
#define size_t ::size_t
#ifndef ${NAMESPACE}_FAT_BINARY
#include \"ocl_util.h\"
#endif
#else
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <memory.h>
#include <CL/cl.h>
#include <CL/cl_ext.h>
#endif

extern int ${namespace}_disable_debug;

/* useful macros */
#ifdef ${NAMESPACE}_DEBUG
#define ${NAMESPACE}_DEBUG_PRINT(...) { if (! ${namespace}_disable_debug) { fprintf(stderr,\"$NAMESPACE DEBUG: \"); fprintf(stderr, __VA_ARGS__); } }
#else
#define ${NAMESPACE}_DEBUG_PRINT(...)
#endif

#define ${NAMESPACE}_ERROR_PRINT(...) { fprintf(stderr,\"$NAMESPACE ERROR: \"); fprintf(stderr, __VA_ARGS__); }
#define ${NAMESPACE}_ERROR_EXIT(...) { fprintf(stderr,\"$NAMESPACE ERROR: \"); fprintf(stderr, __VA_ARGS__); exit(1); }
#define ${NAMESPACE}_OCL_CHKERROR(A, B) if (B != CL_SUCCESS) { ${NAMESPACE}_ERROR_PRINT(\"opencl %s, error %d\\n\", A, B); exit(B); }

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define XOR(a,b) ((!(a)) != (!(b)))
#define XOR3(a,b,c) (((!(a)) != (!(b))) == (!(c)))

/* Profiling support */
#ifdef ${NAMESPACE}_PROFILE
#define ${NAMESPACE}_CLOCK CLOCK_REALTIME
#define clock_diff ((clock2.tv_sec-clock1.tv_sec)*1e6 + (clock2.tv_nsec-clock1.tv_nsec)/1e3)
#define ${NAMESPACE}_PROFILE_PRINT(...) fprintf(stderr,\"$NAMESPACE PROFILE: \"); fprintf(stderr, __VA_ARGS__);
#define ${NAMESPACE}_PROFILE_START() struct timespec clock1; clock_gettime(${NAMESPACE}_CLOCK, &clock1);
#define ${NAMESPACE}_PROFILE_REPORT(...) struct timespec clock2; clock_gettime(${NAMESPACE}_CLOCK, &clock2); ${NAMESPACE}_PROFILE_PRINT(__VA_ARGS__)

#else /* ${NAMESPACE}_PROFILE */
#define ${NAMESPACE}_PROFILE_PRINT(...)
#define ${NAMESPACE}_PROFILE_START()
#define ${NAMESPACE}_PROFILE_REPORT(...)
#define ${NAMESPACE}_PROFILE_OCL_REPORT()
#endif /* ${NAMESPACE}_PROFILE */

#ifdef __cplusplus
extern \"C\" {
#endif
$::dep
#include \"cblas.h\"
#ifdef __cplusplus
}
#endif

/* offload control */
/* NONE: Execute on ARM only */
/* DSP : Force offload to DSP */
/* SIZE:Decision to offload or not is decided based on size */
#define ${NAMESPACE}_OFFLOAD_NONE 0
#define ${NAMESPACE}_OFFLOAD_DSP 1
#define ${NAMESPACE}_OFFLOAD_SIZE 2

/* Global functions and variables */
extern void ${namespace}_error(const char* msg, int code);
extern void ${namespace}_init(void);
#ifdef __cplusplus
extern Kernel*			${namespace}_get_kernel(const char *fname);
extern Context			${namespace}_ocl_context;
extern std::vector<Device>	${namespace}_ocl_devices;
extern CommandQueue		${namespace}_ocl_Q;
extern Program::Binaries	${namespace}_ocl_binary;
extern Program			${namespace}_ocl_program;
extern Kernel*			${namespace}_ocl_kernels[];
#else
extern cl_kernel		${namespace}_get_kernelconst char *fname);
extern cl_context		${namespace}_ocl_context;
extern cl_command_queue		${namespace}_ocl_Q;
extern cl_program      	 	${namespace}_ocl_program;
extern cl_kernel	       	${namespace}_ocl_kernels[];
#endif

extern int ${namespace}_init_done;
extern int ${namespace}_kernel_valid[];
extern int ${namespace}_offload;

";

    foreach my $o (@offloaded) {
	$hdr .= "#define " . uc $namespace . "_" . uc $o . "_IDX $i\n";
	$i++;
    }
    $hdr .= "#define " . uc $namespace . "_" . "NUM_KERNELS $i\n\n";

      $hdr .= "
#define NUM_PNT_EACH_DIM 16
#define GEMM_OFFLOAD_TBL_SIZE (NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM)
#define SYRK_OFFLOAD_TBL_SIZE (NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM)
#define TRMM_OFFLOAD_TBL_SIZE (NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM)
#define TRSM_OFFLOAD_TBL_SIZE (NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM)
";	
    # BLAS-specific code
    if ($header =~ /blas|lapack/) {
      $hdr .= "
/* compile time defaults */
#ifndef ${NAMESPACE}_OFFLOAD
#define ${NAMESPACE}_OFFLOAD \"$offload\"
#endif

/* macros used for BLAS/LAPACK buffer size calculations */
#define BLAS_ORD(Order,a,b) ((Order==CblasRowMajor)? (a):(b))
#define BLAS_TRN(Trans,a,b) ((Trans==CblasNoTrans)? (a):(b))
#define BLAS_SIDE(Side,a,b) ((Side==CblasLeft)?(a):(b))
#define BLAS_ORD_T(Order,Trans,a,b) (XOR((Order==CblasRowMajor),(Trans==CblasNoTrans))?(b):(a))
#define BLAS_ORD_S(Order,Side,a,b) (XOR((Order==CblasRowMajor),((Side=='L')||(Side=='l')||(Side==CblasLeft)))?(b):(a))
#define BLAS_ORD_TS(Order,Trans,Side,a,b) (XOR3((Order==CblasRowMajor),(Trans==CblasNoTrans),((Side=='L')||(Side=='l')||(Side==CblasLeft)))?(b):(a))

";
    }
    for (my $i=0; $i<3; $i++) {
      my $lvl = $i+1;
      $hdr .= "extern int ${NAMESPACE}_L${lvl}_OFFLOAD;\n" if ($header =~ /blas/);
    }

	$hdr .= "
// allocated MSMC and L2 buffer sizes;
// be careful to allocate enough so memory overrun
// does not happen in BLIS/BLAS calls
//#define L2_BUF_SIZE 0x84000
//L2 Cache
//MK: Pool Size 550976, Num Blocks 2, Block size 275424
//KN: Pool Size 128, Num Blocks 0, Block size 3071640
//MN: Pool Size 128, Num Blocks 0, Block size 1400832
//0x86940=551232 = 550976+128+128
//#define L2_BUF_SIZE 0x86940
//#define L2_BUF_SIZE 0x862A0
//Added 3 MNR buffers for C. and increasing Kc for Z
#define L2_BUF_SIZE 0xBFE00
//#define L2_BUF_SIZE 0xBF980 // MR=NR=4 for S


//L3 Cache
//MK: Pool Size 128, Num Blocks 0, Block size 275424
//KN: Pool Size 6143536, Num Blocks 2, Block size 3071640
//MN: Pool Size 128, Num Blocks 0, Block size 1400832
//0x5DBF30 = 6143792=6143536+128+128
//ccs map file says 5dbf40
//Changed KC values to fit in the 4.5M of MSMC
//4647B0
// 0x4664B4
// Within 4.5M
//#define MSMC_BUF_SIZE 0x4647C0
#define MSMC_BUF_SIZE 0x47FDC0
//#define MSMC_BUF_SIZE 0x47F100 // MR=NR=4 for S


//DSPBLIS
//#define MSMC_BUF_SIZE 0x400000
	
extern char ofld_tbl_sgemm[GEMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_dgemm[GEMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_cgemm[GEMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_zgemm[GEMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ssyrk[SYRK_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_dsyrk[SYRK_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_csyrk[SYRK_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_zsyrk[SYRK_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_strmm[TRMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_dtrmm[TRMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ctrmm[TRMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ztrmm[TRMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_strsm[TRSM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_dtrsm[TRSM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ctrsm[TRSM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ztrsm[TRSM_OFFLOAD_TBL_SIZE];
extern int sgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K);
extern int dgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K);
extern int cgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K);
extern int zgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K);
extern int ssymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int dsymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int csymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int zsymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int chemm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int zhemm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int ssyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int dsyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int csyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int zsyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int cherk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int zherk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int ssyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int dsyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int csyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int zsyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int cher2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int zher2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int strmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int dtrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int ctrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int ztrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int strsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int dtrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int ctrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
extern int ztrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N);
";

    $hdr .= "\n#endif\n";
    return $hdr;
}

sub size_based_offload_header_prologue
{
  my $NAMESPACE = uc($namespace);
  my $sz_hdr = "/* This header contains kernel-specific offload thresholds (if any) */\n" .
               "/* It is only used when size-based offload is enabled (002) */\n";
  $sz_hdr .= "
/* Default min offload size. Matrices smaller than this will be executed on ARM */
#ifndef ${NAMESPACE}_OFFLOAD_MIN
#define ${NAMESPACE}_OFFLOAD_MIN $OFFLOAD_MIN
#endif
" if ($OFFLOAD_MIN ne "");
  $sz_hdr .= "
/* Default max offload size. Matrices larger than this will be executed on ARM */
#ifndef ${NAMESPACE}_OFFLOAD_MAX
#define ${NAMESPACE}_OFFLOAD_MAX $OFFLOAD_MAX
#endif
" if ($OFFLOAD_MAX ne "");

  $sz_hdr .= "\n/* Below are offload thresholds for each kernel */\n";
  return $sz_hdr;
}



# Arg1: Reference to array of function names in header
# Arg2: Regex of accept filter (optional). Defaults to accept ALL if empty string.
# Arg3: Regex of reject filter (optional). Defaults to reject NONE if empty string.
sub generate_code
{
    my $arrayref = shift;
    my $accept_filter = shift;
    my $reject_filter = shift;
    my $NAMESPACE = uc($namespace);

    generate_top_code();
    foreach my $t (@{$arrayref}) {
	print "Found function: |$t|\n" unless ($f);
        if ($accept_filter) {
          next unless ($t =~ m/$accept_filter/);
        }
        if ($reject_filter) {
          next if ($t =~ m/$reject_filter/);
        }
        chomp $t;
        my $_fname = $t;
        $_fname =~ /^\s*\S+\s+(\S+)\s*\(/; $_fname = $1;
        my $_FNAME = uc($_fname);
	print "codegen for $_fname\n";
	print "OCL code (${namespace}_kernel.cl):\n" unless ($f);
	write_output(generate_kernel_from_proto(trim($t)), "${namespace}_kernel.cl");
	print "DSP code (append to facade.c):\n" unless ($f);
	write_output(generate_facade_from_proto(trim($t)), "facade.c");
	print "ARM code:\n" unless ($f);
	write_output(generate_arm_from_proto(trim($t)),"${namespace}_$offloaded[-1]" . ".c");

        # per-kernel size thresholds
        #write_output("#define ${NAMESPACE}_${_FNAME}_OFFLOAD_MIN\t${NAMESPACE}_OFFLOAD_MIN\n" .
        #             "#define ${NAMESPACE}_${_FNAME}_OFFLOAD_MAX\t${NAMESPACE}_OFFLOAD_MAX\n", 
        #             "${namespace}_offload_sizes.h");
	#print "Makefile code (append to Makefile):\n" unless ($f);
	#write_output(generate_makefile_from_proto(trim($t)),"Makefile");
    }
    generate_bottom_code();
}

sub generate_top_code
{
    print "DSP facade.c prologue:\n" unless ($f);
    write_output(generate_facade_prologue(),"facade.c");
    print "DSP facade.c generated.\n";
    print "DSP ${namespace}_kernel.cl prologue:\n" unless ($f);
    write_output(generate_kernel_prologue(),"${namespace}_kernel.cl");
    print "DSP ${namespace}_kernel.cl generated.\n";
    write_output(get_enums_and_defines(),"${namespace}_kernel.cl");
    write_output(get_init_code(),"${namespace}_kernel.cl");
    print "ARM ${namespace}_initfini.c code:\n" unless ($f);
    write_output(generate_arm_init(), "${namespace}_initfini.c");
    #print "Makefile:\n" unless ($f);
    #write_output(generate_makefile_prologue($package, get_base_libname($armlib)), "Makefile");
    #print "${namespace}_offload_sizes.h:\n" unless ($f);
    #write_output(size_based_offload_header_prologue(), "${namespace}_offload_sizes.h");
}

sub generate_bottom_code
{
    print "ARM header code (${namespace}.h):\n" unless ($f);
    write_output(generate_arm_header(), "${namespace}.h");
    #print "Makefile:\n" unless ($f);
    #write_output(generate_makefile_epilogue($package, get_base_libname($armlib), $libdeps), "Makefile");
}

sub write_output
{
  my $outstr = shift;
  my $filename = shift;
  if (!defined($f)) {
    print "\n". $outstr . "\n";
  }
  else {
    open(OUTFILE, ">>$filename") || die "Could not open $filename for writing : $!\n";
    print OUTFILE $outstr . "\n";
    close OUTFILE;
  }
}

# checks whether depedencies are fulfilled prior to running the script
sub check_deps
{
  ( -x $CTAGS ) || die "Could not find $CTAGS. Please install ctags (apt-get install ctags OR yum install ctags)\n";
}

# returns an array containing function prototypes after reading in and
# parsing the header
sub get_func_protos()
{
   #print "cat $header | tr '\n' ' '  | sed 's/\\([{};]\\)/\\1\\n/g' > /tmp/$$.h";
   system("cat $header | tr '\n' ' '  | sed 's/\\([{};]\\)/\\1\\n/g' > /tmp/$$.h") && die "Could not generate tmp file: /tmp/$$.h for writing : $!\n";
   open(CTAGS_OUT, "$CTAGS -x --c-kinds=fp /tmp/$$.h |") || die "Could not open pipe for reading ctags output: $!\n";
   local @protos ;
   while (<CTAGS_OUT>) {
     #cblas_ztrsv      prototype    92 x.h              void cblas_ztrsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *A, const int lda, void *X, const int incX);
     # pick all the text from the fifth field onwards
     s/^\s*\S+\s+\S+\s+\d+\s+\S+\s+(.*)$/$1/;
     s/\/\*.*\*\///g; # remove C comments
     s/\/\/.*//g ; # remove C++ comments
	 #print "$_";
     push(@protos, $_);
   }
   close(CTAGS_OUT);
   unlink("/tmp/$$.h");
   print @protos;
   return \@protos;
}

# copy include makefiles from 
sub copy_make_includes
{
  my $base = shift;
  print "Copying include makefiles..\n";
  for my $file ("make.inc","opencl-make.inc") {
    next unless (-f "$base/$file");
    link "$base/$file",$file
  }
  
}

#### main starts here ###

$script = $0; chomp $script;
$scriptargs = "@ARGV";

my $scriptdir = `dirname $0`; chomp $scriptdir;

my $usage = "

$script [-h] [-f] [-fatbin] [-dep=</path/to/depheader]  \\
        [-inc=\"include-pattern\"] [-ex=\"exclude pattern\"] \\
        <package> </path/to/header> </path/to/armlib> [dep1] [dep2]..

        -f : Generate actual files instead of spewing out everything to stdout (Recommended)
        -h : This help message
   -fatbin : Generate a fat binary rather than the kernel.out. Note, the fat binary approach
             WILL fail by running out tmp space due to the large header generated if you
             generate all blas functions (Recommended not to use this option)
-dep=<header> This dependency header will be included in ARM sources files
             and DSP facade.c as well kernel .cl file
-inc=<regex>:Include regex. If set, only functions mathing this will be intercepted
             By default, this is assumed to be empty, and all functions are in header
             are intercpted. 
-ex=<regex>: Exclude regex. If set, functions mathing this will not be intercepted.
 <package> : The package name, for e.g., blas. The package MUST exist under /usr/src/dsp
-commentarm: Comment out the ARM exection code. This means all intercepted functions
             will be offloaded and the user will need to manually uncomment the code for
             executing any intercepted functions on ARM.
-dspl1=<KB>: Set DSP L1 to the specified size in KB prior to offload. Cache size will be
             automatically restored to the original value on return from the offload.
             This argument should ONLY be used if the underlying DSP kernel expects a 
             different L1 cache size than the OpenCL default.
-dspl2=<KB>: Set DSP L2 to the specified size in KB prior to offload. Cache size will be
             automatically restored to the original value on return from the offload.
             This argument should ONLY be used if the underlying DSP kernel expects a 
             different L2 cache size than the OpenCL default.
-offload=<value>: Default offload setting. If unset, this is assumed to a value to ensure
             size-based offload of all intercepted functions. The value can be overridden using
             the environment variable <NAMESPACE>_OFFLOAD. The NAMESPACE is derived
             using the header name. For cblas, NAMESPACE=TI_CBLAS, and the 
             environment variable is TI_CBLAS_OFFLOAD.
  <header> : Full path to header, e.g., ./cblas.h
  <armlib> : Full path to the ARM library. This will not be modified. A copy of this will
             be created in the working directory, and select (or all) functions in it will
             be intercepted. E.g., ../blas/acc/test/arm-blas/libcblas.a
    <deps> : Space separate dependency libraries needed for the DSP compile. These will be
             searched for in /usr/src/dsp/<package>. E.g., libtstatlas.a libatlas.a

BLAS/LAPACK-specific arguments:
-offmin=<nelems>: <nelems> is the number of elements in the result  vector/matrix 
                   below which execution is done on ARM.
                   e.g., -offmin=1000 will offload BLAS calls to DSP
                   only if result matrix/vector has a size >= 1000.
-offmax=<nelems>: <nelems> is the number of elements in the result  vector/matrix 
                   beyond which execution is done on ARM.
                   e.g., -offmax=100000 will execute on ARM for result matrix > 10K elements.
-f2cwraplib=<path to lib> Path to library containing f2c wrapper functions (if any)


EXAMPLES
========

Offload gemm/gemv except cgemm/zgemm:
$script -f -inc=\"cblas_.gem.\" -ex=\"cblas_[cz]gemm\" \\
        blas /path/to/cblas.h /path/to/libcblas.a  libtstatlas.a libatlas.a

Offload L1 BLAS: 
$script -f -inc=\"${blas_prefix}($blas_L1)\" blas /path/to/cblas.h /path/to/libcblas.a  libtstatlas.a libatlas.a

Offload L2 BLAS: 
$script -f -inc=\"${blas_prefix}($blas_L2)\" blas /path/to/cblas.h /path/to/libcblas.a  libtstatlas.a libatlas.a

Offload ALL BLAS:
$script -f blas /path/to/cblas.h /path/to/libcblas.a  libtstatlas.a libatlas.a

Offload L3 with dynamic offload to DSP for 100 < result matrix size < 10000,
also, set L1/L2 cache sizes to 4KB/128KB:
$script -f -dspl1=4 -dspl2=128 -offmin=100 -offmax=10000 -inc=\"$blas_prefix($blas_L3)\" blas /path/to/cblas.h /path/to/libcblas.a libtstatlas.a libatlas.a

Recommended settings for PARALLEL BLAS offload:
$script -f -fatbin -offmax=10000000 -offmin=10000 -offload=002  blas /path/to/cblas.h /path/to/arm/libptcblas.a libtstatlas.a libatlas.a

Recommended settings for SERIAL BLAS offload:
$script -f -offload=002 -fatbin -offmin=10000 -offmax=10000000 blas /path/to/cblas.h /path/to/arm/libcblas.a libtstatlas.a libatlas.a

Recommended settings for LAPACK offload:
$script -f -dep=../../blaswrap.h,../../f2c.h -fatbin -offload=002 -offmin=10000 -offmax=10000000 -f2cwraplib=../../prebuilt/lib/libcblaswr.a blas ../../clapack.h ../../prebuilt/lib/liblapack.a libf2c.a libcblaswr.a libtmglib.a libcblas.a libatlas.a

";

$::ex = $::ex || "";
$::inc = $::inc || "";
$::dep = $::dep || "";
$::exfile = $::exfile || "";

$h = $::h || "";
$fatbin = $::fatbin || "";
$commentarm = $::commentarm || 0;
$f = $::f || "";

if ($::dep) {
  my @deps = split(/,/, $::dep);
  $::dep = "";
  for $_d (@deps) {
    $::dep .= "#include \"$_d\"\n";
  }
}

$::offload = $::offload || "001"; # offload all intercepted functions
$offload = $::offload;

$::f2cwraplib=$::f2cwraplib || ""; # path to f2c wrapper library if any

# below is a hack to introduce conditional code for execution on ARM
# if resultant matrix contains more elements than the value specified
# below. This flag will not be documented as it's an ugly hack and may be
# removed at any time

# 0 => Level 1
# 1 => Level 2
# 2 => Level 3 
$::offmin = $::offmin || "";
$::offmax = $::offmax || "";
$OFFLOAD_MIN = $::offmin if ($::offmin ne "");
$OFFLOAD_MAX = $::offmax if ($::offmax ne "");

# cache size for DSP
# In KB. So -dspl1=4 means set L1 to 4KB
$dspl1 = $::dspl1 || "";
$dspl2 = $::dspl2 || "";

# set scriptargs
$scriptargs = "-dspl1=$dspl1 $scriptargs" if $dspl1;
$scriptargs = "-dspl2=$dspl2 $scriptargs" if $dspl2;
$scriptargs = "-inc=$::inc $scriptargs" if $::inc;
$scriptargs = "-ex=$::ex $scriptargs" if $::ex;
$scriptargs = "-offload=$offload $scriptargs" if $offload;
$scriptargs = "-offmin=$offmin $scriptargs" if $offmin;
$scriptargs = "-offmax=$offmax $scriptargs" if $offmax;
$scriptargs = "-fatbin $scriptargs" if $fatbin;
$scriptargs = "-l3min=$l3min $scriptargs" if $l3min;
$scriptargs = "-l3max=$l3max $scriptargs" if $l3max;
$scriptargs = "-f2cwraplib=$f2cwraplib $scriptargs" if $f2cwraplib;
$scriptargs = "-commentarm $scriptargs" if $commentarm;
$scriptargs = "-f $scriptargs" if $f;


my $inc_regex = $::inc ;  # defaults to empty => intercept all
my $ex_regex = $::ex ;    # defaults to empty => exclude none


$package = shift || die $usage; chomp $package;
$header = shift || die $usage; chomp $header;
#$armlib = shift || die $usage; chomp $armlib;  # /path/to/library.a
( -f "$header" ) || die "$header does not exist";
#( -f "$armlib" ) || warn "$armlib does not exist";
$libdeps = "@ARGV"; chomp $libdeps;


# derive namespace using header name
$namespace = `basename $header`; chomp $namespace; $namespace =~ s/^(.*)\.h/ti_$1/;
$NAMESPACE = uc($namespace);

check_deps();

if (defined($f)) {
#  for $tmpfile ("facade.c","facade.obj","${namespace}_kernel.cl", "${namespace}.h") {
#    next unless (-f $tmpfile);
#    print "Removing $tmpfile\n" ; unlink($tmpfile);
#  }
  #unlink glob "*.o";
  unlink glob "facade.c";
  unlink glob "ti_cblas_initfini.c";
  unlink glob "ti_cblas_kernel.cl";
  unlink glob "ti_cblas_cblas*.c";
  unlink glob "ti_cblas_acc.h";
  #unlink glob "*.inc";
  #unlink glob "*.a";
}

generate_code(get_func_protos(), $inc_regex, $ex_regex);
copy_make_includes($scriptdir);
link "$scriptdir/rename_f2c","./rename_f2c" if ($::f2cwraplib);
print "Default offload setting: $offload (override using ${NAMESPACE}_OFFLOAD)\n";

exit 0;
