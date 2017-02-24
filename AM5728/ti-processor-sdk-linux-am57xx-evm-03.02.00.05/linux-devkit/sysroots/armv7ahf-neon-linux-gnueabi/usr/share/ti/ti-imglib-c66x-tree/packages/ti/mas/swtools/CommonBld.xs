/******************************************************************************
 * FILE PURPOSE: Common Build file
 ******************************************************************************
 * FILE NAME: CommonBld.xs  
 *
 * DESCRIPTION: This file contains common build functionality for the Package.bld.
 *              This file is created to avoid duplication of common processing in
 *              different packages.
 * TABS: NONE
 *
 ******************************************************************************/

   /* Source File Arrays */
   var files = new Array();
   var archiveFiles = new Array();
   var exeTarget = new Array();
   var generatedFiles = new Array();
   var ccsProjects = new Array();
   /* Package Specific Arguments used for Parsing and Print Usage */
   var args = new Array();
   var argisdebug = false; 

   var errorFound = false;

   /* Compiler options for speed optimization */
   var libParams_speed;
   
   /* Compiler options for size optimization */
   var libParams_size;

   /* Compiler options for debug*/
   var libParams_debug;

   /* Executable options for speed optimization */
   var exeParams_speed = {
                          copts:"", 
                          aopts:"",
                          cfgScript: "test.cfg",
                          lopts:"",  
                          exportExe: false,
                          exportCfg: false
                        }; 

   /* Executable options for size optimization */  
   var exeParams_size = {
                          copts:"", 
                          aopts:"",
                          cfgScript: "test.cfg",
                          lopts:"",
                          exportExe: false,
                          exportCfg: false   
                        };


   /* Default C flags for C54x */
   var commonC54xCopts = " -pds815 -pds817 -pds1112 -pds825 -pds838 -pds828 -pds827 -pds77 -pds837 -pds824 -ss -k -ms -g -as -dC548 -v548";
  
   /* Default A flags for C54x */
   var commonC54xAopts = " -s -dC548 -mf -v548";

   /* Default compiler option for C54x */
   var c54_libParams = 
         {
            copts: commonC54xCopts,
            aopts: commonC54xAopts
         };  
         
   /* Default compiler option for MVARM9 */
   var mvarm9_libParams = 
         {
            copts: " -O2",
            aopts: ""
         };  
         
  /* Default compiler option for GCARMV6 */
   var armv6_libParams = 
         {
            copts: " -O2",
            aopts: ""
         };         

  /* Default compiler option for GCARMV7A */
  /* Default arm v7a CPU is cortex A8 */
   var armcpu = "cortex-a8";
   var cortexa8_libParams = 
         {
            copts: " -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -O2 -ftree-vectorize ",
            aopts: ""
         };         
   var cortexa9_libParams = 
         {
            copts: " -mcpu=cortex-a9 -mfpu=neon -mfloat-abi=softfp -O2 -ftree-vectorize ",
            aopts: ""
         };         




  /* Default compiler option for WinCE */
   var wince_libParams = 
         {
            copts: " -Ot",
            aopts: ""
         };  

   var wince_dbgParams = 
         {
            copts: " -Zi -Od",
            aopts: ""
         };  
         
 /* Default compiler option for WinCE */
   var vc98_libParams = 
         {
            copts: " -Ot -Zi",
            aopts: ""
         };  

   var vc98_dbgParams = 
         {
            copts: " -Z7 -Odi -MTd -D_DEBUG=1",
            aopts: ""
         };           
  
  /* CPU flag for C55x */
  var c55x_cpu_version="2.1";

   /* Common C flags for C55x */
   var commonC55xCopts = " -c -pds1112 -pds825 -pds838 -pds828 -pds827 -pds77 -pds837 -pds824 -vcpu:2.1 -mg -ss -k -dC5510 -as -g --ptrdiff_size=16";

   /* Common A flags for C55x */
   var commonC55xAopts = " -vcpu:2.1 -as -al -g";
  
   /* C55x compiler option for speed */
   var C55xSpeedOpts = " -o2 -mn";
  
   /* C55x compiler option for size */
   var C55xSizeOpts = " -ms";

   /* Common C flags for C55x V3 */
   var commonC55xv3Copts = " -c -pds1112 -pds825 -pds838 -pds828 -pds827 -pds77 -pds837 -pds824 -vcpu:3.3 -mg -ss -k -dC5510 -as -g --ptrdiff_size=16";

   /* Common A flags for C55x */
   var commonC55xv3Aopts = " -vcpu:3.3 -as -al -g";
  
 
   /* Default compiler option for C55x - Debug */
   const c55_libParams_debug = 
         {
            copts: commonC55xCopts,
            aopts: commonC55xAopts
         };  /* compiler options for debug */

   /* Default compiler option for C55x - Speed more critical */
   const c55_libParams_speed = 
         {
            copts: commonC55xCopts+C55xSpeedOpts,
            aopts: commonC55xAopts
         };  /* compiler options for speed optimization */

   /* Default compiler option for C55x - Size more critical */
   const c55_libParams_size  = 
         {
            copts: commonC55xCopts+C55xSpeedOpts+C55xSizeOpts,
            aopts: commonC55xAopts
         };  /* compiler options for size optimization */

/* Default compiler option for C55x - Debug */
   const c55v3_libParams_debug = 
         {
            copts: commonC55xv3Copts,
            aopts: commonC55xv3Aopts
         };  /* compiler options for debug */

   /* Default compiler option for C55x - Speed more critical */
   const c55v3_libParams_speed = 
         {
            copts: commonC55xv3Copts+C55xSpeedOpts,
            aopts: commonC55xv3Aopts
         };  /* compiler options for speed optimization */

   /* Default compiler option for C55x - Size more critical */
   const c55v3_libParams_size  = 
         {
            copts: commonC55xv3Copts+C55xSpeedOpts+C55xSizeOpts,
            aopts: commonC55xv3Aopts
         };  /* compiler options for size optimization */


   /* Common C flags for C64x */
   var commonC64xCopts = " -c -k -q --mem_model:data=far -al -pds1111 -pds827 -pds824 -pds837 -pds1037 -pds195 -pdsw225 -pdsw994 -pdsw262 -pds77 -pden -pds232 --consultant -mw -os -g -mi10000 -as -ss";

   /* Common A flags for C64x */
   var commonC64xAopts = " -ea.s -c -k -mi1000";
  
   /* C64x compiler option for speed */
   var C64xSpeedOpts = " -o3 --optimize_with_debug";

   /* C64x compiler option for size */
   var C64xSizeOpts = " -ms3";

   /* Default compiler option for C64x - debug */
   var c64_libParams_debug = 
       {
          copts: commonC64xCopts,
          aopts: commonC64xAopts
       };  /* compiler options for debug */

   /* Default compiler option for C64x - Speed more critical */
   var c64_libParams_speed = 
       {
          copts: commonC64xCopts + C64xSpeedOpts,
          aopts: commonC64xAopts
       };  /* compiler options for speed optimization */

   /* Default compiler option for C64x - Size more critical */
   var c64_libParams_size  = 
       {
          copts: commonC64xCopts + C64xSpeedOpts + C64xSizeOpts,
          aopts: commonC64xAopts
       };  /* compiler options for size optimization */
       
  /* C66x option */      
   var c66_libParams_debug = 
       {
          copts: commonC64xCopts ,
          aopts: commonC64xAopts + " --strip_coff_underscore"
       };  /* compiler options for debug */

   /* Default compiler option for C66x - Speed more critical */
   var c66_libParams_speed = 
       {
          copts: commonC64xCopts + C64xSpeedOpts,
          aopts: commonC64xAopts + " --strip_coff_underscore"
       };  /* compiler options for speed optimization */

   /* Default compiler option for C66x - Size more critical */
   var c66_libParams_size  = 
       {
          copts: commonC64xCopts + C64xSpeedOpts + C64xSizeOpts,
          aopts: commonC64xAopts + " --strip_coff_underscore"
       };  /* compiler options for size optimization */
  
  
   /* Global file Array used to store the file to be TARed */
   var fileArray= new Array();
   var minPkgArray = new Array();
   

   /* Target Extension */      
   var ext="";
   
   /* default delivery type */
   var delivery_type = "obj";

   /* Global Version String Variable used by Print Usage */
   var verStr;

   /* version string of the package*/
   var version="";
   var pkgStdVer="1.0";

   /* Module Name */
   var name;

   /* list of supported targets */
   var targets;
   
   /* Target in XDCARGS */
   var xdcargs_targ;

   /* parsed target */
   var targs= new Array();

   /* target independent */
   var targ_indp=false;

   /* Default Archive  of headers and package artifacts*/
   var archiveTypeDefault = true;
   
   /* Directory where library will be created */
   var libraryPath="";
   
   /* Handle for generating bundle */
   var generateBundle=false; 
   var bundleid;
   var isBundlePkg=false;
   var install=false;
   var kernel=false;
   var setPostBuildStep=false;
   var winInstallname;
   var linuxInstallname;
      
   /* Bundle name */
   var bundlename;
   var bundletype;
   var bundleMakeDoc;
  
   /* Bundle components */
   var bundleComponents = new String();
   
   /*Make File Changes */
   var makefilelocal;
   var listxdcpath = new Array();
   var dependencyAdded=false;
   
   /* Copy Module */
   var copy = xdc.loadCapsule('ti/mas/swtools/Copy.xs');
  

/*
 *  @brief This function Parses command line arguments for package specific build options.
 *
 *  @param[in]  arguments  Array of command line arguments.
 *
 *  @retval     targs  List of supported targets.
 *
 */
function parseArgs(arguments)
{
 /* Get XDC arguments */
  if(errorFound == true)
  {
   return;  
  }
  var args_xs = java.lang.System.getenv("ARGS_XS");
  if (args_xs != null) {
    Pkg.makeEpilogue+= "\nall:touch_xdcenv\n";
    Pkg.makeEpilogue+= "\ntouch_xdcenv:\n\t$(TOUCH) .xdcenv.mak\n";
    var argsnew =new String(args_xs);
    var getArgs = xdc.loadCapsule(argsnew);
    getArgs.getPkgArgs(Pkg.name, arguments);
    getArgs.showPkgArgs(Pkg.name, arguments);
  }
  else {
  /* Use XDCARGS passed in from build command */
  print ("ARGS SCRIPT ENV VAR NOT SPECIFIED");
 } /* end of if (args_xs != null) */

  /* Check if the package is target independent */
  if(targets==undefined)
  {  
     targets = [C54, C54_far, C55, C55_large, C64, C64_big_endian, C674, C674_big_endian, C674_elf, C674_big_endian_elf, C64P, C64P_big_endian, C66, C66_big_endian, C64P_elf, C64P_big_endian_elf, C66_elf, C66_big_endian_elf, MVArm9, GCArmv6, GCArmv7A, WinCE, VC98, TIArmv6le, TIArmv6be];
     /* Target Independent */
     targ_indp=true;
  }

  var xtargs = targets;
 
  /* Print Buffers used for PrintUsage */
  var print_buffer = new Array();
  print_buffer.help="";
  print_buffer.header="";
  print_buffer.options="";
  print_buffer.others="";
  var suppTargets= new Array();

  /* Copy the list of supported targets */
  for each(var j in targets)
    {
      /* Remove non-supported targets */
      if(j.name != undefined)
      {
         suppTargets.push(j);
      }
    }  /* end of for loop */
   
  /* Parse the Arguments */
  for (var k = 0; k < arguments.length; k++) 
  {
   switch (arguments[k]) 
   {
    case "all":
      ext="all";
      xdcargs_targ=arguments[k];
      break;
    case "c64Ple":
      var xtargs = [C64P];
      xdcargs_targ=arguments[k];
      break;
    case "c64Pbe":
      var xtargs = [C64P_big_endian];
      xdcargs_targ=arguments[k];         
      break;
    case "c64Ple_elf":
      var xtargs = [C64P_elf];
      xdcargs_targ=arguments[k];
      break;
    case "c64Pbe_elf":
      var xtargs = [C64P_big_endian_elf];
      xdcargs_targ=arguments[k];         
      break;  
    case "c64Px":
      var xtargs = [C64P, C64P_big_endian, C64P_elf,C64P_big_endian_elf];
      ext="c64Px";
      xdcargs_targ=arguments[k];
      break;
    case "c64Px_coff":
      var xtargs = [C64P, C64P_big_endian];
      ext="c64Px_coff";
      xdcargs_targ=arguments[k];
      break; 
    case "c64Px_elf":
      var xtargs = [C64P_elf,C64P_big_endian_elf];
      ext="c64Px_elf";
      xdcargs_targ=arguments[k];
      break;         
    case "c64le":
      var xtargs = [C64];
      xdcargs_targ=arguments[k];         
      break;
    case "c64be":
      var xtargs = [C64_big_endian];
      xdcargs_targ=arguments[k];         
      break;
    case "c674le":
      var xtargs = [C674];
      xdcargs_targ=arguments[k];         
      break;
    case "c674be":
      var xtargs = [C674_big_endian];
      xdcargs_targ=arguments[k];         
      break;    
    case "c674le_elf":
      var xtargs = [C674_elf];
      xdcargs_targ=arguments[k];         
      break;
    case "c674be_elf":
      var xtargs = [C674_big_endian_elf];
      xdcargs_targ=arguments[k];         
      break; 
   case "c674x":
      var xtargs = [C674, C674_elf];
      ext="c674x";
      xdcargs_targ=arguments[k];
      break;         

    case "c66le":
      var xtargs = [C66];
      xdcargs_targ=arguments[k];         
      break;
    case "c66be":
      var xtargs = [C66_big_endian];
      xdcargs_targ=arguments[k];         
      break;    
    case "c66le_elf":
      var xtargs = [C66_elf];
      xdcargs_targ=arguments[k];         
      break;
    case "c66be_elf":
      var xtargs = [C66_big_endian_elf];
      xdcargs_targ=arguments[k];         
      break;      
    case "c66x":
      var xtargs = [C66, C66_big_endian, C66_elf,C66_big_endian_elf];
      ext="c66x";
      xdcargs_targ=arguments[k];
      break; 
    case "c66x_coff":
      var xtargs = [C66, C66_big_endian];
      ext="c66x_coff";
      xdcargs_targ=arguments[k];
      break; 
    case "c66x_elf":
      var xtargs = [C66_elf,C66_big_endian_elf];
      ext="c66x_elf";
      xdcargs_targ=arguments[k];
      break;        
    case "c55l":
      var xtargs = [C55_large];
      xdcargs_targ=arguments[k];         
      break;
    case "c55s":
      var xtargs = [C55];
      xdcargs_targ=arguments[k];         
      break;
    case "c54f":
      var xtargs = [C54_far];
      xdcargs_targ=arguments[k];         
      break;
    case "c54n":
      var xtargs = [C54];
      xdcargs_targ=arguments[k];         
      break;
    case "mvarm9":
      var xtargs = [MVArm9];
      xdcargs_targ=arguments[k];         
      break;
    case "gcarmv6":
      var xtargs = [GCArmv6];
      xdcargs_targ=arguments[k];         
      break;  
    case "gcarmv7a":
      var xtargs = [GCArmv7A];
      xdcargs_targ=arguments[k];         
      break;  
    case "tiarmv6le":
      var xtargs = [TIArmv6le];
      xdcargs_targ=arguments[k];         
      break;        
    case "tiarmv6be":
      var xtargs = [TIArmv6be];
      xdcargs_targ=arguments[k];         
      break;              
    case "wince":
      var xtargs = [WinCE];
      xdcargs_targ=arguments[k];         
      break;
    case "vc98":
      var xtargs = [VC98];
      xdcargs_targ=arguments[k];         
      break;
    case "obj":
      delivery_type = "obj";
      break;
    case "src":
      delivery_type = "src";
      break;
    case "src-only":
      delivery_type = "src-only";
      break;      
    case "docs-only":
      delivery_type = "docs-only";
      break;            
    case "help":
      print_buffer.help = "general";
      break;
    case "covRun": /* don't default this one, see config.bld */
      break;
    case "kernel":
      kernel=true;
      break;
    case "setPostBuildStep":
      setPostBuildStep=true;
      break;
    case "install":
      install=true;
      break;
    case "debug":
      argisdebug = true; 
      Pkg.attrs.profile = "debug";
    default: 
      /* Search for Package Specific Arguments */
      var argfound=false;
      var argArray = [arguments[k], 0];
      var index    = arguments[k].indexOf("=");
      if (index >= 0)
      {
        argArray = [arguments[k].substring(0,index), arguments[k].substring(index+1)];
      }  
      if(argArray[0]== "bundle")
      {
          if (index >= 0)
          {      
            bundleid=argArray[1];
          }
            generateBundle=true; 
            break;    
      }
      if(argArray[0]== "cpu")
      {
          if (index >= 0 && (argArray[1]=="cortex-a9" || argArray[1]=="cortex-a8"))
          {      
            armcpu=argArray[1];
            xdcargs_targ += " "+arguments[k];
          }
          else if(index >= 0 && (argArray[1]=="3.3" || argArray[1]=="2.1"))
          {
            c55x_cpu_version = argArray[1];
            xdcargs_targ += " "+arguments[k];
          }
          else
          {
            print("\nERROR REASON: Invalid cpu  " + arguments[k] +"\n");
            print_buffer.help = "general";  
          }
      }
      
      if( args != null && argfound==false)
      {
        for (j in args)
        {
           
           if(args[j].value == argArray[0])
           {
             print("Argument found " + args[j].value);
             args[j].action(argArray[1]);
             argfound=true;
           }  
        }/* end of for (j in args) */
      }/* end of if( args != null) */
    
      if(argfound == false && argisdebug == false )
      {
         print("\nERROR REASON: Invalid Argument " + arguments[k] +"\n");
         print_buffer.help = "general";
      }  
      break;
    } /* end of switch */
  } /* end of for loop */
  if(xdcargs_targ == undefined)
  {
    xdcargs_targ="all";
    ext="all";
  }
 /* Check if the argument provided in the XDCARGS are supported by the package */
 /* Reset supported target list */
 targs= new Array();
 for each(var xtarget in xtargs)
 {
  for (var t=0; t < suppTargets.length; t++)
    {
        var istargsupported = false;
    if(xtarget == suppTargets[t])
    {
      targs.push(xtarget);
      istargsupported = true;
      break;
    }
  }
  if(istargsupported == false)
  {
       print("IMPORTANT: "+ xtarget+" target is not supported in this build environment. Please correct the build environment to support this target\n");
    }
 }
  

  /* If none of the target is supported print error*/
  if(targs.length < 1)
  {
      print("\nERROR REASON: Target Not Supported " + xtargs +"  in this Package\n");
      print_buffer.help = "general";
  }

  /* Print customized help usage */ 
  if(print_buffer.help == "general")
  {
    /* This will generate version string for the help */
    if(version.length > 0)
    {
       verStr  = String("_" + version[0] + "_" + version[1] + "_" + version[2] + "_" + version[3]);
    }
    else
    {  
       verStr = "";
    }
    /* Generate Print Buffer */
    print_buffer = printUsage(print_buffer);
    /* Add Package specific Arguments help */
    /* Search for Package Specific Arguments */
    if( args != null)
    { 
      for (j in args )
      {
         print_buffer = addUsage(print_buffer,args[j]);
      }
    }
    /* Print Help Usage */
    print(print_buffer.header);
    print(print_buffer.options);
    print(print_buffer.others);
    errorFound = true;
    java.lang.System.exit(1);
  }
  /* Check for test package. If the package is test, make delivery type to source */
  var temp=String(Pkg.name);
  temp=temp.split(".");
  if(temp[temp.length-1]=="test")
    delivery_type="src";
  return(targs);
 }

/*
 *  @brief This function returns defaults params for requested target.
 *
 *  @param[in]  localTarget  Requested Target.
 *
 *  @retval     targParams   Params of the requested target.
 *
 */

function getTargParams(localTarget)
{
    var targParams={};
    targParams.ofd="";

    switch(localTarget)
    {
    case C54: 
      targParams.libParams_speed=c54_libParams;
      targParams.libParams_size=c54_libParams;
      targParams.libParams_debug=c54_libParams;
      targParams.target="c54n";
      targParams.ext = "c54n";
      targParams.targDirectory = "c54";   
      targParams.platform="ti.platforms.sim54xx";
      targParams.dstDir="c" + C54.suffix;
      targParams.ofd=C54.rootDir.toString().replace(/\\/g,"\/")+"/bin/ofd500";
      targParams.envtoolvar="C54X_GEN_INSTALL_DIR";
      targParams.internaldefs=" -Dti_targets_C54 -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C54x Near Memory Model";
      targParams.targstring="C54";
      break;

    case C54_far:
      targParams.libParams_speed=c54_libParams;
      targParams.libParams_size=c54_libParams;
      targParams.libParams_debug=c54_libParams;
      targParams.target="c54f";
      targParams.ext = "c54f";
      targParams.targDirectory = "c54";   
      targParams.platform="ti.platforms.sim54xx";
      targParams.dstDir="c" + C54_far.suffix;
      targParams.ofd=C54_far.rootDir.toString().replace(/\\/g,"\/")+"/bin/ofd500";
      targParams.envtoolvar="C54X_GEN_INSTALL_DIR";
      targParams.internaldefs=" -Dti_targets_C54_far -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";            
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C54x Far Memory Model"; 
      targParams.targstring="C54_far";     
      break;

    case C55: 
      targParams.libParams_speed=c55_libParams_speed;
      targParams.libParams_size=c55_libParams_size;
      targParams.libParams_debug=c55_libParams_debug;
      targParams.target="c55s";
      targParams.ext = "c55s";
      targParams.targDirectory = "c55";   
      targParams.platform="ti.platforms.sim55xx";
      targParams.dstDir="c" + C55.suffix;
      targParams.ofd=C55.rootDir.toString().replace(/\\/g,"\/")+"/bin/ofd55";
      targParams.envtoolvar="C55X_GEN_INSTALL_DIR";   
      targParams.internaldefs=" -Dti_targets_C55 -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                     
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C55x Small Memory Model";   
      targParams.targstring="C55";         
      break;

    case C55_large: 
      if(c55x_cpu_version == "3.3")
      {
        targParams.libParams_speed=c55v3_libParams_speed;
        targParams.libParams_size=c55v3_libParams_size;
        targParams.libParams_debug=c55v3_libParams_debug;
        targParams.string="C55x Large Memory Model CPU 3.3"; 
         
      }
      else
      {
        targParams.libParams_speed=c55_libParams_speed;
        targParams.libParams_size=c55_libParams_size;
        targParams.libParams_debug=c55_libParams_debug;
        targParams.string="C55x Large Memory Model"; 
        
      }
      targParams.target="c55l";
      targParams.ext = "c55l";
      targParams.targstring="C55_large";
      targParams.targDirectory = "c55";   
      targParams.platform="ti.platforms.sim55xx";
      targParams.dstDir="c" + C55_large.suffix;
      targParams.ofd=C55_large.rootDir.toString().replace(/\\/g,"\/")+"/bin/ofd55";
      targParams.envtoolvar="C55X_GEN_INSTALL_DIR";      
      targParams.internaldefs=" -Dti_targets_C55_large -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";
      targParams.internallinkdefs=" -o $@ -m $@.map";      
                      
      break;

    case C64:
      targParams.libParams_speed=c64_libParams_speed;
      targParams.libParams_size=c64_libParams_size;
      targParams.libParams_debug=c64_libParams_debug;
      targParams.target="c64le";
      targParams.ext = "c64le";
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.sim64xx";
      targParams.dstDir="c" + C64.suffix;
      targParams.ofd=C64.rootDir.toString().replace(/\\/g,"\/")+"/bin/ofd6x";
      targParams.envtoolvar="C6X_GEN_INSTALL_DIR";      
      targParams.internaldefs=" -Dti_targets_C64 -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";     
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C64x Little Endian"; 
      targParams.targstring="C64";                
      break;

    case C64_big_endian:       
      targParams.libParams_speed=c64_libParams_speed;
      targParams.libParams_size=c64_libParams_size;
      targParams.libParams_debug=c64_libParams_debug;
      targParams.target="c64be";
      targParams.ext = "c64be";
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.sim64xx";
      targParams.dstDir="c" + C64_big_endian.suffix;
      targParams.ofd=C64_big_endian.rootDir.toString().replace(/\\/g,"\/")+"/bin/ofd6x";
      targParams.envtoolvar="C6X_GEN_INSTALL_DIR";   
      targParams.internaldefs=" -Dti_targets_C64_big_endian -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                    
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C64x Big Endian";   
      targParams.targstring="C64_big_endian";                     
      break;
      
    case C674:
      targParams.libParams_speed=c64_libParams_speed;
      targParams.libParams_size=c64_libParams_size;
      targParams.libParams_debug=c64_libParams_debug;
      targParams.target="c674le";
      targParams.ext = "c674le";
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.evmDA830";
      targParams.dstDir="c" + C674.suffix;
      targParams.ofd="";
      targParams.envtoolvar="C674X_GEN_INSTALL_DIR";         
      targParams.internaldefs=" -Dti_targets_C674 -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                          
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C67x Little Endian";      
      targParams.targstring="C674";                        
      break;

    case C674_big_endian:       
      targParams.libParams_speed=c64_libParams_speed;
      targParams.libParams_size=c64_libParams_size;
      targParams.libParams_debug=c64_libParams_debug;
      targParams.target="c674be";
      targParams.ext = "c674be";
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.evmDA830";
      targParams.dstDir="c" + C674_big_endian.suffix;
      targParams.ofd="";
      targParams.envtoolvar="C674X_GEN_INSTALL_DIR";               
      targParams.internaldefs=" -Dti_targets_C674_big_endian -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                          
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C67x Big Endian";
      targParams.targstring="C674_big_endian";                                    
      break;      


case C674_elf:
      targParams.libParams_speed=c66_libParams_speed;
      targParams.libParams_size=c66_libParams_size;
      targParams.libParams_debug=c66_libParams_debug;
      targParams.target="ce674le";
      targParams.ext = "ce674le";
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.evmDA830";
      targParams.dstDir="c" + C674_elf.suffix;
      targParams.ofd="";
      targParams.envtoolvar="C674X_GEN_INSTALL_DIR";         
      targParams.internaldefs=" -Dti_targets_elf_C674 -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(OBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                          
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C67x ELF Little Endian";      
      targParams.targstring="C674_elf";                        
      break;

    case C674_big_endian_elf:       
      targParams.libParams_speed=c66_libParams_speed;
      targParams.libParams_size=c66_libParams_size;
      targParams.libParams_debug=c66_libParams_debug;
      targParams.target="ce674be";
      targParams.ext = "ce674be";
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.evmDA830";
      targParams.dstDir="c" + C674_big_endian_elf.suffix;
      targParams.ofd="";
      targParams.envtoolvar="C674X_GEN_INSTALL_DIR";               
      targParams.internaldefs=" -Dti_targets_elf_C674_big_endian -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                          
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C67x ELF Big Endian";
      targParams.targstring="C674_big_endian_elf";                                    
      break;     
      
    case C66:
      targParams.libParams_speed=c64_libParams_speed;
      targParams.libParams_size=c64_libParams_size;
      targParams.libParams_debug=c64_libParams_debug;
      targParams.target="c66le";
      targParams.ext = "c66le";
      targParams.targDirectory = "c64";   
      targParams.platform=C66.platform;
      targParams.dstDir="c" + C66.suffix;
      targParams.ofd="";
      targParams.envtoolvar="C66X_GEN_INSTALL_DIR";            
      targParams.internaldefs=" -Dti_targets_C66 -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                          
      targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C66x COFF Little Endian";    
      targParams.targstring="C66";                                
      break;

    case C66_big_endian:       
      targParams.libParams_speed=c64_libParams_speed;
      targParams.libParams_size=c64_libParams_size;
      targParams.libParams_debug=c64_libParams_debug;
      targParams.target="c66be";
      targParams.ext = "c66be";
      targParams.targDirectory = "c64";   
      targParams.platform=C66_big_endian.platform;
      targParams.dstDir="c" + C66_big_endian.suffix;
      targParams.ofd="";
      targParams.envtoolvar="C66X_GEN_INSTALL_DIR";                  
      targParams.internaldefs=" -Dti_targets_C66_big_endian -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                          
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C66x COFF Big Endian";  
    targParams.targstring="C66_big_endian";                                  
      break;       

  case C66_elf:
      targParams.libParams_speed=c66_libParams_speed;
      targParams.libParams_size=c66_libParams_size;
      targParams.libParams_debug=c66_libParams_debug;
      targParams.target="ce66le";
      targParams.ext = "ce66le";
      targParams.targDirectory = "c64";   
      targParams.platform=C66_elf.platform;
      targParams.dstDir="c" + C66_elf.suffix;
      targParams.ofd="";
      targParams.envtoolvar="C66X_GEN_INSTALL_DIR";            
      targParams.internaldefs=" -Dti_targets_elf_C66 -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                          
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C66x ELF Little Endian"; 
    targParams.targstring="C66_elf";                                   
      break;

    case C66_big_endian_elf:       
      targParams.libParams_speed=c66_libParams_speed;
      targParams.libParams_size=c66_libParams_size;
      targParams.libParams_debug=c66_libParams_debug;
      targParams.target="ce66be";
      targParams.ext = "ce66be";
      targParams.targDirectory = "c64";   
      targParams.platform=C66_big_endian_elf.platform;
      targParams.dstDir="c" + C66_big_endian_elf.suffix;
      targParams.ofd="";
      targParams.envtoolvar="C66X_GEN_INSTALL_DIR";                  
      targParams.internaldefs=" -Dti_targets_elf_C66_big_endian -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                          
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C66x ELF Big Endian";   
    targParams.targstring="C66_big_endian_elf";                                 
      break;    

    case C64P:
      targParams.libParams_speed=c64_libParams_speed;
      targParams.libParams_size=c64_libParams_size;
      targParams.libParams_debug=c64_libParams_debug;
      targParams.target="c64Ple";
      targParams.ext = "c64Ple"; 
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.sim64Pxx";
      targParams.dstDir="c" + C64P.suffix;
      targParams.ofd=C64P.rootDir.toString().replace(/\\/g,"\/")+"/bin/ofd6x";
      targParams.envtoolvar="C6X_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dti_targets_C64P -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                                     
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C64x+ COFF Little Endian";  
    targParams.targstring="C64P";                                  
      break;

    case C64P_big_endian:       
      targParams.libParams_speed=c64_libParams_speed;
      targParams.libParams_size=c64_libParams_size;
      targParams.libParams_debug=c64_libParams_debug;
      targParams.target="c64Pbe";
      targParams.ext = "c64Pbe";
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.sim64Pxx";
      targParams.dstDir="c" + C64P_big_endian.suffix;
      targParams.ofd=C64P_big_endian.rootDir.toString().replace(/\\/g,"\/")+"/bin/ofd6x";
      targParams.envtoolvar="C6X_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dti_targets_C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                                     
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C64x+ COFF Big Endian";   
    targParams.targstring="C64P_big_endian";                                       
      break;

    case C64P_elf:
      targParams.libParams_speed=c66_libParams_speed;
      targParams.libParams_size=c66_libParams_size;
      targParams.libParams_debug=c66_libParams_debug;
      targParams.target="ce64Ple";
      targParams.ext = "ce64Ple"; 
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.sim64Pxx";
      targParams.dstDir="c" + C64P_elf.suffix;
      targParams.envtoolvar="C6X_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dti_targets_elf_C64P -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                                     
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C64x+ ELF Little Endian";  
    targParams.targstring="C64P_elf";                                  
      break;

    case C64P_big_endian_elf:       
      targParams.libParams_speed=c66_libParams_speed;
      targParams.libParams_size=c66_libParams_size;
      targParams.libParams_debug=c66_libParams_debug;
      targParams.target="ce64Pbe";
      targParams.ext = "ce64Pbe";
      targParams.targDirectory = "c64";   
      targParams.platform="ti.platforms.sim64Pxx";
      targParams.dstDir="c" + C64P_big_endian_elf.suffix;
      targParams.envtoolvar="C6X_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dti_targets_elf_C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                                     
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="C64x+ Big Endian";   
    targParams.targstring="C64P_big_endian_elf";                                       
      break;

   case MVArm9:       
      targParams.libParams_speed=mvarm9_libParams;
      targParams.libParams_size=mvarm9_libParams;
      targParams.libParams_debug=mvarm9_libParams;
      targParams.target="mvarm9";
      targParams.ext = "mvarm9";
      targParams.targDirectory = "arm";   
      targParams.platform=MVArm9.platform;
      targParams.dstDir="mvarm9";
      targParams.envtoolvar="MONTAVISTA_ARM9_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dgnu_targets_MVArm9 -Dxdc_target_types__=gnu/targets/arm/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -o $@ ";  
    targParams.internallinkdefs="-Wl,-Map=$@.map -o $@";                                             
      targParams.string="Montavista Arm9";    
    targParams.targstring="MVArm9";                                      
      break;      

   case GCArmv6:       
      targParams.libParams_speed=armv6_libParams;
      targParams.libParams_size=armv6_libParams;
      targParams.libParams_debug=armv6_libParams;
      targParams.target="gcarmv6";
      targParams.ext = "gcarmv6";
      targParams.targDirectory = "arm";   
      targParams.platform=GCArmv6.platform;
      targParams.dstDir="gcarmv6";
      targParams.envtoolvar="GNU_ARM11_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dgnu_targets_arm_GCArmv6 -Dxdc_target_types__=gnu/targets/arm/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -o $@ ";                                     
    targParams.internallinkdefs="-Wl,-Map=$@.map -o $@ ";                                             
      targParams.string="GCC Arm11";   
    targParams.targstring="GCArmv6";                                             
      break;      

   case GCArmv7A:       
      if(armcpu == "cortex-a8")
      {
        targParams.envtoolvar="GNU_ARM_CORTEXA8_GEN_INSTALL_DIR"; 
        targParams.string="GCC Arm Cortex A8";
        targParams.libParams_speed=cortexa8_libParams;
        targParams.libParams_size=cortexa8_libParams;
        targParams.libParams_debug=cortexa8_libParams;

      }
      else if(armcpu == "cortex-a9")
      {
         targParams.envtoolvar="GNU_ARM_CORTEXA9_GEN_INSTALL_DIR"; 
         targParams.string="GCC Arm Cortex A9";
         targParams.libParams_speed=cortexa9_libParams;
         targParams.libParams_size=cortexa9_libParams;
         targParams.libParams_debug=cortexa9_libParams;

      }
      
      targParams.target="gcarmv7a";
      targParams.ext = "gcarmv7a";
      targParams.targDirectory = "arm";   
      targParams.platform=GCArmv7A.platform;
      targParams.dstDir="gcarmv7a";
      targParams.internaldefs=" -Dgnu_targets_arm_GCArmv7A -Dxdc_target_types__=gnu/targets/arm/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -o $@ ";                                     
       targParams.internallinkdefs="-Wl,-Map=$@.map -o $@ ";                                             
      targParams.targstring="GCArmv7A";                                               
      break; 
      
  case TIArmv6le:       
      targParams.libParams_speed=armv6_libParams;
      targParams.libParams_size=armv6_libParams;
      targParams.libParams_debug=armv6_libParams;
      targParams.target="tiarmv6le";
      targParams.ext = "tiarmv6le";
      targParams.targDirectory = "arm";   
      targParams.platform=TIArmv6le.platform;
      targParams.dstDir="tiarmv6le";
      targParams.envtoolvar="TI_ARM11_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dti_targets_arm_Arm11 -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                                     
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="TI Arm11 Little Endian"; 
    targParams.targstring="TIArmv6le";                                               
      break;            

  case TIArmv6be:       
      targParams.libParams_speed=armv6_libParams;
      targParams.libParams_size=armv6_libParams;
      targParams.libParams_debug=armv6_libParams;
      targParams.target="tiarmv6be";
      targParams.ext = "tiarmv6be";
      targParams.targDirectory = "arm";   
      targParams.platform=TIArmv6be.platform;
      targParams.dstDir="tiarmv6be";
      targParams.envtoolvar="TI_ARM11_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dti_targets_arm_Arm11_big_endian -Dxdc_target_types__=ti/targets/std.h -eo.$(OBJEXT) -ea.$(AOBJEXT) -fr=$(@D) -fs=$(@D) -ppa -ppd=$@.dep ";                                     
    targParams.internallinkdefs=" -o $@ -m $@.map";      
      targParams.string="TI Arm11 Big Endian";  
    targParams.targstring="TIArmv6be";                                                    
      break;            

   case WinCE:       
      targParams.libParams_speed=wince_libParams;
      targParams.libParams_size=wince_libParams;
      targParams.libParams_debug=wince_dbgParams;
      targParams.target="wince";
      targParams.ext = "wince";
      targParams.targDirectory = "arm";   
      targParams.platform=WinCE.platform;
      targParams.dstDir="wince";
      targParams.string="Windows CE";      
    targParams.targstring="WinCE";                                          
      break;      
   
   case VC98:       
      targParams.libParams_speed=vc98_libParams;
      targParams.libParams_size=vc98_libParams;
      targParams.libParams_debug=vc98_dbgParams;
      targParams.target="vc98";
      targParams.ext = "vc98";
      targParams.targDirectory = "arm";   
      targParams.platform=VC98.platform;
      targParams.dstDir="vc98";
      targParams.string="MSVC 98";     
      targParams.envtoolvar="MSVC_GEN_INSTALL_DIR"; 
      targParams.internaldefs=" -Dmicrosoft_targets_VC98 -Dxdc_target_types__=microsoft/targets/std.h -Fo$@ ";
      /* mfc42.lib mfcs42.lib msvcirt.lib */
      if(argisdebug == true){
         targParams.internallinkdefs=" -debug -map:$@.map -pdb:$@.pdb -machine:ix86 -out:$@  -nodefaultlib -incremental:no msvcrt.lib  setargv.obj oldnames.lib ole32.lib oleaut32.lib olepro32.lib uuid.lib kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib comctl32.lib";                                          
      }
      else
      {
         targParams.internallinkdefs=" -map:$@.map -pdb:$@.pdb -machine:ix86 -out:$@  -nodefaultlib -incremental:no msvcrt.lib  setargv.obj oldnames.lib ole32.lib oleaut32.lib olepro32.lib uuid.lib kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib comctl32.lib";                                          
      }
      targParams.string="Microsoft VC98";                                                      
      targParams.targstring="VC98";
      break;      
       
      
      }
      /* If library path is specified, over-write targParams.dstDir */
      if(libraryPath != "")
      {
        targParams.dstDir=libraryPath;
      }
     return(targParams);
}

  
function createMake(makefile)
{
    /* Create the main make file */
    var fileModule = xdc.module('xdc.services.io.File');
    if(makefile==undefined)
    {
      try{
          makefile = fileModule.open("makefile", "w");
         } catch (ex)
         {
           print("makefile cannot be written to. Please check Writing Permissions.");
           java.lang.System.exit(1);
         }   
      /* Add to Archive list */
      if(delivery_type=="src")
      {
         fileArray.push("makefile");
      }
    includeMake("makefile");     
         
    Pkg.makeEpilogue += "clean::\n\t-$(RM)  makefile\n";
    makefile.writeLine("#*******************************************************************************");
    makefile.writeLine("#* FILE PURPOSE: Top level makefile for Creating Component Libraries");
    makefile.writeLine("#*******************************************************************************");
    makefile.writeLine("#* FILE NAME: makefile");
    makefile.writeLine("#*");
    makefile.writeLine("#* DESCRIPTION: Defines Compiler tools paths, libraries , Build Options ");
    makefile.writeLine("#*");
    makefile.writeLine("#*");
    makefile.writeLine("#* This is an auto-generated file          ");
    makefile.writeLine("#*******************************************************************************");
    makefile.writeLine("#*");
    makefile.writeLine("# (Mandatory) Specify where various tools are installed.");

    var file = xdc.module('xdc.services.io.File');
    
    var c64ToolsDir   = java.lang.System.getenv("C64CODEGENTOOL");
    if(c64ToolsDir)
    {
      makefile.writeLine("\n# C6X_GEN_INSTALL_DIR   - C6x Code gen tools install directory");    
      makefile.writeLine("export C6X_GEN_INSTALL_DIR ?= "+c64ToolsDir.toString().replace("\\","\/"));
    }
    
    var c674ToolsDir   = java.lang.System.getenv("C674CODEGENTOOL");
    if(c674ToolsDir)
    {
      makefile.writeLine("\n# C674X_GEN_INSTALL_DIR   - C674x Code gen tools install directory");    
      makefile.writeLine("export C674X_GEN_INSTALL_DIR ?= "+c674ToolsDir.toString().replace("\\","\/"));
    }
    
    
    var c66ToolsDir   = java.lang.System.getenv("C66CODEGENTOOL");
    if(c66ToolsDir)
    {
      makefile.writeLine("\n# C66X_GEN_INSTALL_DIR   - C6x Code gen tools install directory");    
      makefile.writeLine("export C66X_GEN_INSTALL_DIR ?= "+c66ToolsDir.toString().replace("\\","\/"));
    }    
    
    var c54ToolsDir   = java.lang.System.getenv("C54CODEGENTOOL"); 
    if(c54ToolsDir)
    {
      makefile.writeLine("\n# C54X_GEN_INSTALL_DIR   - C54x Code gen tools install directory");    
      makefile.writeLine("export C54X_GEN_INSTALL_DIR ?= "+c54ToolsDir.toString().replace("\\","\/"));
    }    
    
    var c55ToolsDir   = java.lang.System.getenv("C55CODEGENTOOL"); 
    if(c55ToolsDir)
    {
      makefile.writeLine("\n# C55X_GEN_INSTALL_DIR   - C55x Code gen tools install directory");    
      makefile.writeLine("export C55X_GEN_INSTALL_DIR ?= "+c55ToolsDir.toString().replace("\\","\/"));
      
    } 
    
    var Arm11ToolsDir = java.lang.System.getenv("Arm11TITool");  
    
    if(Arm11ToolsDir)
    {
      makefile.writeLine("\n# TI_ARM11_GEN_INSTALL_DIR   - TI ARM11 Code gen tools install directory");    
      makefile.writeLine("export TI_ARM11_GEN_INSTALL_DIR ?= "+Arm11ToolsDir.toString().replace("\\","\/"));
      
    }       
    
    var mvarm9ToolsDir = java.lang.System.getenv("MVARM9CGTOOL");  
    
    if(mvarm9ToolsDir)
    {
      makefile.writeLine("\n# MONTAVISTA_ARM9_GEN_INSTALL_DIR   - Montavista ARM9 Code gen tools install directory");    
      makefile.writeLine("export MONTAVISTA_ARM9_GEN_INSTALL_DIR ?= "+mvarm9ToolsDir.toString().replace("\\","\/"));
      
    }       

    var gcarmv6ToolsDir = java.lang.System.getenv("GCARMV6CGTOOL");  
    
    if(gcarmv6ToolsDir)
    {
      makefile.writeLine("\n# GNU_ARM11_GEN_INSTALL_DIR   - GNU ARM11 Code gen tools install directory");    
      makefile.writeLine("export GNU_ARM11_GEN_INSTALL_DIR ?= "+gcarmv6ToolsDir.toString().replace("\\","\/"));
      
    }       

    var gcarmv7aToolsDir = java.lang.System.getenv("GCARMV7ACGTOOL");  
    
    if(gcarmv7aToolsDir)
    {
      makefile.writeLine("\n# "+getTargParams(GCArmv7A).envtoolvar   +"- GNU ARM11 Code gen tools install directory");    
      makefile.writeLine("export "+getTargParams(GCArmv7A).envtoolvar +"?= "+gcarmv7aToolsDir.toString().replace("\\","\/"));
    }       


    var vc98ToolsDir = java.lang.System.getenv("VC98TOOL");  
    
    if(vc98ToolsDir)
    {
      makefile.writeLine("\n# MSVC_GEN_INSTALL_DIR   - MS VC98 Code gen tools install directory");    
      makefile.writeLine("export MSVC_GEN_INSTALL_DIR ?= "+vc98ToolsDir.toString().replace("\\","\/"));
      
    }           
    
    /* Create INCDIR from XDCPATH */
    
    /* copy the environment array from the current environment */
    var env   = java.lang.System.getenv();
    var getxdcpath=String(java.lang.System.getenv("XDCPATH"));
    getxdcpath= getxdcpath.replace(/\\/g,"/");
    var keys  = env.keySet().toArray();
    var key;
    var stat={};
    var env_j=[];
    for (var i = 0; i < keys.length; i++) {
         key = String(keys[i]);
         if(key.match("INSTALL_DIR"))
         {
           var keyPath=String(env.get(key));
           keyPath=keyPath.replace(/\\/g,"/");
           var file = xdc.module('xdc.services.io.File');
           keyPath=file.getDOSPath(keyPath);
           if(getxdcpath.toString().match(keyPath))
           {
               listxdcpath.push({keyname: key,keypath: keyPath});
               makefile.writeLine("\n# PATH TO  "+key.replace(/_/g," "));    
               makefile.writeLine("export "+key+"     ?= " + keyPath);
               while(getxdcpath.toString().match(keyPath))
               {
                 getxdcpath=getxdcpath.toString().replace(keyPath,"$("+key+")");
               }
           }
         }
    
   }
     var pkgroot="..";
     for (var i = Pkg.name.split('.').length; i > 1; i--) {
            pkgroot+="/..";
        }
        
    makefile.writeLine("\n# ROOT Directory");        
    makefile.writeLine("export ROOTDIR := "+pkgroot);
    
    makefile.writeLine("\n# INCLUDE Directory");
    makefile.writeLine("export INCDIR := "+getxdcpath+";$(ROOTDIR)");        
    
    makefile.writeLine("\n# Common Macros used in make");  
    makefile.writeLine("\nifndef RM");     
    makefile.writeLine("export RM = rm -f");
    makefile.writeLine("endif");        
    
    makefile.writeLine("\nifndef CP");     
    makefile.writeLine("export CP = cp -p");    
    makefile.writeLine("endif");    
        
    makefile.writeLine("\nexport MKDIR = mkdir -p");
    
    makefile.writeLine("\nifndef RMDIR");         
    makefile.writeLine("export RMDIR = rm -rf");
    makefile.writeLine("endif");        
    
    makefile.writeLine("\nifndef SED"); 
    makefile.writeLine("export SED = sed");    
    makefile.writeLine("endif");    
    
    makefile.writeLine("\nifndef MAKE"); 
    makefile.writeLine("export MAKE = make");    
    makefile.writeLine("endif");        

    makefile.writeLine("\n# PHONY Targets");                
    makefile.writeLine(".PHONY: all clean cleanall ");    
      
    makefile.writeLine("\n# FORCE Targets");                
    makefile.writeLine("FORCE: ");          
      
        
      
      makefile.writeLine("\n# all rule");                
      makefile.writeLine("all: .executables");           
      makefile.writeLine(".executables: .libraries");
      makefile.writeLine(".libraries:");
      
      makefile.writeLine("\n# Clean Rule");          
      makefile.writeLine("clean:: clean_package");                  
      makefile.writeLine("# Clean Top Level Object Directory ");          
      makefile.writeLine("clean_package :\n\t$(RMDIR) package/lib");      
      makefile.writeLine("\t$(RMDIR) package/cfg");            
    }
    else
    {
     try{
          makefile = fileModule.open("makefile", "a");
         } catch (ex)
         {
           print("makefile cannot be written to. Please check Writing Permissions.");
           java.lang.System.exit(1);
         }  
    
    }

 return makefile;
}

function askGcc(target, opt, filter)
    {
        var gccCmd = target.rootDir + "/" + target.LONGNAME;
        
        var cmd = gccCmd + " " + opt;
        var status = {};
        
        var attrs = null;
        
        /* If remote execution is run through a script, that script may need
         * PATH or other environment variables.
         */
        if  ("cmdPrefix" in target.$orig
            && target.$orig.cmdPrefix != undefined) {
            attrs = {useEnv: true};
        }
                
        if (xdc.exec(cmd, attrs, status) >= 0) {
            var va = status.output.match(filter);
            if (va != null) {
                return (va[0]);
            }
            else {
                print(target.$name + ": warning: failed to parse '"
                    + opt + "' output (= '" + status.output + "')"+
           "; check compiler options");
            }
        }
        else {
            print(target.$name + ": warning: exec of '" + cmd + "' failed:"
                + status.output + "; check tools installation");
        }

        return ("");
    }

function getGNUTargetPath(path,targetname)
{
  path=path.toString().replace("rootDir",getTargParams(targetname).envtoolvar);
  path=path.toString().replace("$(LONGNAME)",targetname.LONGNAME);
 /* call compiler to get its target machine and set GCCTARG */
    var result;
    if (targetname.GCCTARG == null) {
        if ((result = askGcc(targetname, "-dumpmachine", /^[\w-\.]+/)) == "") {
            print(targetname.$name + ": warning: can't determine gcc target; ");
            print("Check if " + targetname.rootDir + "/bin/gcc can run on ");
            if (targetname.remoteHost != null) {
                print(targetname.remoteHost + ". ");
            }
            else {
                print(xdc.om['xdc.bld'].BuildEnvironment.hostOSName + ". ");
            }
            print("Also, try explicitly setting the GCCTARG configuration "
                + "parameter.");
        }
//      print("setting " + target.$name + ".GCCTARG to " + result);
        targetname.GCCTARG = result;
    }

  path=path.toString().replace("$(GCCTARG)",targetname.GCCTARG);
  
  return path;
}

function createLibMake(makelibname,targetname, objectPath)
{
   
    var fileModule = xdc.module('xdc.services.io.File');
    try{
     var dstFile = new java.io.File(makelibname);
     dstFile.getParentFile().mkdirs();    
     libmakefile = fileModule.open(makelibname, "w");
     /* Add to Archive list */
    if(delivery_type=="src"){
       fileArray.push(makelibname);
     }
     
    } catch (ex)
    {
     print(makelibname+" cannot be written to. Please check Writing Permissions.");
     java.lang.System.exit(1);
    }   
    libmakefile.writeLine("#*******************************************************************************");
    libmakefile.writeLine("#* FILE PURPOSE: Lower level makefile for Creating Component Libraries");
    libmakefile.writeLine("#*******************************************************************************");
    libmakefile.writeLine("#* FILE NAME: "+makelibname);
    libmakefile.writeLine("#*");
    libmakefile.writeLine("#* DESCRIPTION: Defines Source Files, Compilers flags and build rules");
    libmakefile.writeLine("#*");
    libmakefile.writeLine("#*");
    libmakefile.writeLine("#* This is an auto-generated file          ");
    libmakefile.writeLine("#*******************************************************************************");
    libmakefile.writeLine("#");
    libmakefile.writeLine("");
    libmakefile.writeLine("#");
    libmakefile.writeLine("# Macro definitions referenced below");
    libmakefile.writeLine("#");
    libmakefile.writeLine("empty =");
    libmakefile.writeLine("space =$(empty) $(empty)");
    var namestring=String(targetname);
    if(namestring.match("gnu.targets"))
    {
      libmakefile.writeLine("CC = "+getGNUTargetPath(targetname.cc.cmd,targetname)+" "+targetname.cc.opts +" "+targetname.ccOpts.prefix+" "+targetname.ccOpts.suffix);
      libmakefile.writeLine("AC = "+getGNUTargetPath(targetname.asm.cmd,targetname)+" "+targetname.asm.opts);    
      libmakefile.writeLine("ARIN = "+getGNUTargetPath(targetname.ar.cmd,targetname)+" "+targetname.ar.opts);    
      libmakefile.writeLine("LD = "+getGNUTargetPath(targetname.lnk.cmd,targetname)+" "+targetname.lnk.opts+" "+targetname.lnkOpts.prefix+" "+getGNUTargetPath(targetname.lnkOpts.suffix,targetname)+" "+exeParams_speed.lopts); 
      libmakefile.writeLine("CGINCS = "+getGNUTargetPath(targetname.includeOpts,targetname));        
      libmakefile.writeLine("RTSLIB = ");            
    }
    else if(namestring.match("ti.targets"))
    {
       var rtslibtemp = targetname.lnkOpts.suffix.toString().split("/");
       var rtslib;
       for(n=0;n<rtslibtemp.length;n++)
       {
          if(rtslibtemp[n].match(".lib"))
          { 
             rtslib=rtslibtemp[n];
          }
       }

      libmakefile.writeLine("CC = \"$("+getTargParams(targetname).envtoolvar+")/bin/\""+targetname.cc.cmd +" "+targetname.cc.opts);
      libmakefile.writeLine("AC = \"$("+getTargParams(targetname).envtoolvar+")/bin/\""+targetname.asm.cmd +" "+targetname.asm.opts);    
      libmakefile.writeLine("ARIN = \"$("+getTargParams(targetname).envtoolvar+")/bin/\""+targetname.ar.cmd +" "+targetname.ar.opts);    
      libmakefile.writeLine("LD = \"$("+getTargParams(targetname).envtoolvar+")/bin/\""+targetname.lnk.cmd +" "+targetname.lnk.opts+" "+exeParams_speed.lopts);   
      libmakefile.writeLine("CGINCS = $(strip $(subst $(space),\\$(space),$("+getTargParams(targetname).envtoolvar+")/include))");   
      libmakefile.writeLine("RTSLIB = -l \"$("+getTargParams(targetname).envtoolvar+")/lib/"+rtslib+"\"");        
    }
  else if(namestring.match("microsoft.targets"))
  {
      libmakefile.writeLine("CC = \"$("+getTargParams(targetname).envtoolvar+')/vc/bin/\"cl.exe -nologo -c -W3 -Zp1 -DWIN32 -D_DLL -D_AFXDLL -DEXPORT=""');
      libmakefile.writeLine("AC = \"$("+getTargParams(targetname).envtoolvar+")/vc/bin/\"cl.exe -nologo -c" );    
      libmakefile.writeLine("ARIN = \"$("+getTargParams(targetname).envtoolvar+")/vc/bin/\"lib -nologo");    
      libmakefile.writeLine("LD = \"$("+getTargParams(targetname).envtoolvar+")/vc/bin/\"link -nologo");
      libmakefile.writeLine("CGINCS = $(strip $(subst $(space),\\$(space),$("+getTargParams(targetname).envtoolvar+")/vc/include))");    
      libmakefile.writeLine("RTSLIB = -libpath:\"$("+getTargParams(targetname).envtoolvar+")/vc/lib\" -libpath:\"$("+getTargParams(targetname).envtoolvar+")/Common7/IDE\"");  

  }
    libmakefile.writeLine("INCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\\$(space),$(subst \\,\/,$(INCDIR)))))");
    libmakefile.writeLine("OBJEXT = o"+targetname.suffix); 
    libmakefile.writeLine("AOBJEXT = s"+targetname.suffix);     
    libmakefile.writeLine("INTERNALDEFS = "+getTargParams(targetname).internaldefs);
    libmakefile.writeLine("INTERNALLINKDEFS = "+getTargParams(targetname).internallinkdefs);
  libmakefile.writeLine("OBJDIR = "+objectPath);    
   
 return libmakefile;

}

function makeAddRawObjects(srcString, makefilename,srcfiles,targetName)
{
  var  objectliststring = srcString.toString().toUpperCase() + "OBJS";
  /* List all the source object files */
  makefilename.writeLine("\n#List the "+srcString+" Object Files");  
  makefilename.writeLine(objectliststring + "= \\");
  for(var i=0;i<srcfiles.length-1;i++)
  {
    makefilename.writeLine("    "+srcfiles[i]+"\\");
  }
    makefilename.writeLine("    "+srcfiles[i]+"\n");  


}

function makeAddObjects(srcString, makefilename, srcfiles, flags,fileExt, targetName)
{
  var  sourcestring = (srcString + fileExt).toString().toUpperCase();
  var  compileflagstring = sourcestring + "FLAGS";
  var  objectliststring = sourcestring + "OBJS";
  /* List all the source files */
  makefilename.writeLine("\n#List the "+srcString+" Files");  
  makefilename.writeLine(sourcestring + "= \\");
  for(var i=0;i<srcfiles.length-1;i++)
  {
    makefilename.writeLine("    "+srcfiles[i]+"\\");
  }
    makefilename.writeLine("    "+srcfiles[i]+"\n");
    
 /* Flags for the source files */
 makefilename.writeLine("# FLAGS for the "+srcString+" Files"); 
 makefilename.writeLine(compileflagstring+" = "+flags+"\n");     
 makefilename.writeLine("# Make Rule for the "+srcString+" Files");  
 
 makefilename.writeLine(objectliststring +" = $(patsubst %."+fileExt+", $(OBJDIR)/%.$(OBJEXT), $(" + sourcestring + "))"); 
 makefilename.writeLine("\n$("+objectliststring+"): $(OBJDIR)/%.$(OBJEXT): %."+fileExt);   
 if(fileExt == "c")
 { 
   makefilename.writeLine("\t-@echo cl"+targetName.suffix +" $< ...");     
 }
 else
 {
   makefilename.writeLine("\t-@echo asm"+targetName.suffix +" $< ...");      
 }
 makefilename.writeLine("\tif [ ! -d $(@D) ]; then $(MKDIR) $(@D) ; fi;");           
 
 if(fileExt == "c")
 {
   if(String(targetName).match("microsoft.targets"))
   {
      makefilename.writeLine("\t$(CC) $("+compileflagstring+") $(INTERNALDEFS) $(INCS) -I$(CGINCS) $< ");

   }
   else
   {
       makefilename.writeLine("\t-$(RM) $@.dep");
       makefilename.writeLine("\t$(CC) $("+compileflagstring+") $(INTERNALDEFS) $(INCS) -I$(CGINCS) -fc $< ");
       makefilename.writeLine("\t-@$(CP) $@.dep $@.pp; \\");
       makefilename.writeLine("         $(SED) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\\\$$//' \\");
       makefilename.writeLine("             -e '/^$$/ d' -e 's/$$/ :/' < $@.pp >> $@.dep; \\");
       makefilename.writeLine("         $(RM) $@.pp ");
   }
 }
 else if(fileExt == "s")
 {
   makefilename.writeLine("\t$(AC) $("+compileflagstring+") $(INTERNALDEFS) $(INCS) -I$(CGINCS) -fa $< ");
 }
 else if(fileExt == "sa")
 {
   makefilename.writeLine("\t$(AC) $("+compileflagstring+") $(INTERNALDEFS) $(INCS) -I$(CGINCS) $< ");
 }
   makefilename.writeLine("\n#Create Empty rule for dependency");
   makefilename.writeLine("$("+objectliststring+"):"+makefilename.$private.fd);
   makefilename.writeLine(makefilename.$private.fd+":");
   makefilename.writeLine("\n#Include Depedency for "+srcString+" Files");
   makefilename.writeLine("ifneq (clean,$(MAKECMDGOALS))");
   makefilename.writeLine(" -include $("+objectliststring+":%.$(OBJEXT)=%.$(OBJEXT).dep)");
   makefilename.writeLine("endif");
 
}



/*
 *  @brief This function Creates Library.
 *
 *  @param[in]  libName  Library Name.
 *
 *  @retval     Pkg      Generated Pkg.
 *
 */

function createLib(libName)
{
       
  var target;

  if(generateBundle==true)
      return;  
  
  if(libName == undefined )
  {
   var temp = Pkg.name.split(".");
   libName = temp[temp.length-1];
  }
  
   makefilelocal = createMake(makefilelocal);

  
  
  
  for(var k=0;k<targs.length;k++)
  {
     var targParams=getTargParams(targs[k]);
     var clib=""; 
     var alib=""; 
     var cmlib="";

     var targetDir = new java.io.File(targParams.dstDir);
     if(!(targetDir.exists() && targetDir.isDirectory()))
     {
       targetDir.mkdirs();
     }
     

    for(ID in files)
    {
      /* set the defaults if not defined */
      if(files[ID].compile == undefined)
        files[ID].compile= true;
         
      if(files[ID].target == undefined)
        files[ID].target=["all"];
         
      if(files[ID].compiler_flags == undefined)
        files[ID].compiler_flags="default-speed";
         
      if(files[ID].cmodel == undefined)
        files[ID].cmodel=false;
         
      if(files[ID].base_directory == undefined)
        files[ID].base_directory=".";
         
      if(files[ID].def_flags == undefined)
        files[ID].def_flags="";


      /* Check if the following list needs to be compiled */
      if(files[ID].compile == true)
      {
            var flags={
                       copts:"",
                        aopts:""
                       };
       
            /* Compile for default speed options */             
             if(files[ID].compiler_flags=="default-speed")
             {
                flags.copts=targParams.libParams_speed.copts + files[ID].def_flags;
                flags.aopts=targParams.libParams_speed.aopts + files[ID].def_flags;
             }
             /* Compile for default size options */             
             else if(files[ID].compiler_flags=="default-size")
             {
                flags.copts=targParams.libParams_size.copts + files[ID].def_flags;
                flags.aopts=targParams.libParams_size.aopts + files[ID].def_flags;
             }
             /* Compile for default debug options */             
             else if(files[ID].compiler_flags=="default-debug")
             {
                flags.copts=targParams.libParams_debug.copts + files[ID].def_flags;
                flags.aopts=targParams.libParams_debug.aopts + files[ID].def_flags;
             }
             /* Compile with user defined options */             
             else
             {
                flags.copts=files[ID].compiler_flags + files[ID].def_flags;
                flags.aopts=files[ID].compiler_flags + files[ID].def_flags;
             }

            /* Construct the source file with complete address and differentiate c and assembly files */
            cfiles=[];
            afiles=[];
            lafiles=[];
            miscfiles=[];
            for(var l=0;l < files[ID].files.length; l++)
            { 
                var temp = files[ID].files[l].split(".");
               if(temp[temp.length - 1]=="c")
               {
                 cfiles.push(files[ID].base_directory+"/"+files[ID].files[l]);
               }
               else if(temp[temp.length - 1]=="s" )
               {
                 afiles.push(files[ID].base_directory+"/"+files[ID].files[l]);
               }
               else if( temp[temp.length - 1]=="sa")
               {
                 lafiles.push(files[ID].base_directory+"/"+files[ID].files[l]);
               }
               else 
               {
                 miscfiles.push(files[ID].base_directory+"/"+files[ID].files[l]);
               }
             
              
            }
            

        for( var q = 0 ; q < files[ID].target.length; q++)
        { 
           objfiles=[];
           if((files[ID].target[q]==targParams.target) || (files[ID].target[q]=="all"))
           {
             if(miscfiles.length > 0)
             {
              
               for each(var object in miscfiles)
               { 
                 if(object.toString().match("o"+targs[k].suffix))
                 {
                   objfiles.push(object);

                 }
                 else
                 {
                   print("invalid file extension  "+ object);
                   java.lang.System.exit(1); 
                 }
               }
             
             }
             if(files[ID].cmodel==true)
             {
              if(cmlib=="")
              {
/*                cmlib = Pkg.addLibrary(targParams.dstDir + "/"+libName+"_cm", targs[k]);*/
                  cmlib = targParams.dstDir + "/"+libName+"_cm.a"+targs[k].suffix;
                  var objectPath= "./package/lib/"+targParams.dstDir + "/"+libName+"_cm";
                  makefilelocal.writeLine("\n\n# Make rule to create "+cmlib+" library");
                  makefilelocal.writeLine(".libraries: "+ cmlib);
                  makefilelocal.writeLine(cmlib+": FORCE\n\t$(MAKE) -f "+cmlib+".mk $@");                  
                  var makefilecmlib= createLibMake(cmlib+".mk",targs[k],objectPath);
                  makefilelocal.writeLine("# Rule to clean "+cmlib+" library");
                  makefilelocal.writeLine("clean ::\n\t$(RM) "+ cmlib);                  
                  cmlibrule="\n\n"+cmlib+" :";                        
              }
/*                cmlib.addObjects(cfiles,flags);  */
                  makeAddObjects(ID, makefilecmlib,cfiles,flags.copts,"c",targs[k]);  
                  cmlibrule += " $("+ID.toString().toUpperCase() + "COBJS)";  
                  if(delivery_type=="src")
                 {
                    fileArray=fileArray.concat(cfiles);
                 }                

             }
             else
             {
                if(cfiles.length > 0)
                {
                  if(clib=="")
                  {
/*                      clib = Pkg.addLibrary(targParams.dstDir + "/"+libName+"_c", targs[k]);*/
                        clib = targParams.dstDir + "/"+libName+"_c.a"+targs[k].suffix;
                        var objectPath= "./package/lib/"+targParams.dstDir + "/"+libName+"_c";
                        makefilelocal.writeLine("\n\n# Make rule to create "+clib+" library");
                        makefilelocal.writeLine(".libraries: "+ clib);
                        makefilelocal.writeLine(clib+": FORCE\n\t$(MAKE) -f "+clib+".mk $@");                                 

                        var makefileclib= createLibMake(clib+".mk",targs[k],objectPath);  
                        makefilelocal.writeLine("# Rule to clean "+clib+" library");                                              
                        makefilelocal.writeLine("clean ::\n\t$(RM) "+ clib);                                          
                        clibrule="\n\n"+clib+" :";                                                
                        
                  }
/*                  clib.addObjects(cfiles,flags); */
                   makeAddObjects(ID,makefileclib,cfiles,flags.copts,"c",targs[k]);
                   clibrule += " $("+ID.toString().toUpperCase() + "COBJS)";    
                   if(delivery_type=="src")
                 {
                    fileArray=fileArray.concat(cfiles);
                 }               
                }
                if(afiles.length > 0 || lafiles.length > 0 || objfiles.length > 0)
               {
                 if(alib=="")
                 {
/*                    alib = Pkg.addLibrary(targParams.dstDir + "/"+libName+"_a", targs[k]);*/
                      alib = targParams.dstDir + "/"+libName+"_a.a"+targs[k].suffix;
                      var objectPath= "./package/lib/"+targParams.dstDir + "/"+libName+"_a";
                      makefilelocal.writeLine("\n\n# Make rule to create "+alib+" library");
                      makefilelocal.writeLine(".libraries: "+ alib);
                      makefilelocal.writeLine(alib+": FORCE\n\t$(MAKE) -f "+alib+".mk $@");                                 
                      var makefilealib= createLibMake(alib+".mk",targs[k],objectPath); 
                      makefilelocal.writeLine("# Rule to clean "+alib+" library");                                          
                      makefilelocal.writeLine("clean ::\n\t$(RM) "+ alib);                                        
                      alibrule="\n\n"+alib+" :";                                                                         
                 }
/*                 alib.addObjects(afiles,flags); */
                   if(afiles.length > 0)
                   {     
                     makeAddObjects(ID, makefilealib,afiles,flags.aopts,"s",targs[k]);
                     alibrule += " $("+ID.toString().toUpperCase() + "SOBJS)";
                     if(delivery_type=="src")
                     {
                       fileArray=fileArray.concat(afiles);
                     }
                   }
                   if(lafiles.length > 0)
                   {     
                     makeAddObjects(ID, makefilealib,lafiles,flags.aopts,"sa",targs[k]);
                     alibrule += " $("+ID.toString().toUpperCase() + "SAOBJS)";
                     if(delivery_type=="src")
                     {
                       fileArray=fileArray.concat(lafiles);
                     }
                   } 
                  if(objfiles.length > 0)
                  {
                    makeAddRawObjects(ID, makefilealib,objfiles,targs[k]);
                    alibrule += " $("+ID.toString().toUpperCase() + "OBJS)";
                    if(delivery_type=="src")
                     {
                       fileArray=fileArray.concat(objfiles);
                     }
                  }                
                  

               }
             }

           }
         }   
           
           
         }
          
    }
    
       
      if(cmlib != "")
      {
         makefilecmlib.writeLine(cmlibrule);
         makefilecmlib.writeLine("\t@echo archiving $? into $@ ...");
     if(String(targs[k]).match("microsoft.targets")) 
     {
       makefilecmlib.writeLine("\t$(ARIN) -out:$@ $^");
     }
     else
     {
           makefilecmlib.writeLine("\t$(ARIN) $@ $?");
     }
         makefilecmlib.close();                  
         fileArray.push(targParams.dstDir + "/"+libName+"_cm.a" + targs[k].suffix);
         if(targParams.ofd != "")
         {
             Pkg.makeEpilogue += "\n" + targParams.dstDir + "/"+libName+"_cm.a" + targs[k].suffix+"_size.txt" + ": " + targParams.dstDir + "/"+libName+"_cm.a" + targs[k].suffix;
             Pkg.makeEpilogue += "\n\t "+targParams.ofd +" -x " + "$<" +" > tmp.xml";
             Pkg.makeEpilogue += "\n\t sectti tmp.xml > " + "$@";
             Pkg.makeEpilogue += "\n\t $(RM) tmp.xml\n\n";
             fileArray.push(targParams.dstDir + "/"+libName+"_cm.a" + targs[k].suffix+"_size.txt");
         }
         
      }
      if(clib != "")
      {
         makefileclib.writeLine(clibrule);
         makefileclib.writeLine("\t@echo archiving $? into $@ ...");         
     if(String(targs[k]).match("microsoft.targets")) 
     {
       makefileclib.writeLine("\t$(ARIN) -out:$@ $^");
     }
     else
     {
           makefileclib.writeLine("\t$(ARIN) $@ $?");
     }
         makefileclib.close();
         fileArray.push(targParams.dstDir + "/"+libName+"_c.a" + targs[k].suffix);
         if(targParams.ofd != "")
         {
             Pkg.makeEpilogue += "\n" + targParams.dstDir + "/"+libName+"_c.a" + targs[k].suffix+"_size.txt" + ": " + targParams.dstDir + "/"+libName+"_c.a" + targs[k].suffix;
             Pkg.makeEpilogue += "\n\t "+targParams.ofd +" -x " + "$<" +" > tmp.xml";
             Pkg.makeEpilogue += "\n\t sectti tmp.xml > " + "$@";
             Pkg.makeEpilogue += "\n\t $(RM) tmp.xml\n\n";
             fileArray.push(targParams.dstDir + "/"+libName+"_c.a" + targs[k].suffix+"_size.txt");
         }

      }
      if(alib != "")
      {
         makefilealib.writeLine(alibrule);
         makefilealib.writeLine("\t@echo archiving $? into $@ ...");         
     if(String(targs[k]).match("microsoft.targets")) 
     {
       makefilealib.writeLine("\t$(ARIN) -out:$@ $^");
     }
     else
         {
           makefilealib.writeLine("\t$(ARIN) $@ $?");
     }
         makefilealib.close();         
         fileArray.push(targParams.dstDir + "/"+libName+"_a.a" + targs[k].suffix);
         if(targParams.ofd != "")
         {
             Pkg.makeEpilogue += "\n" + targParams.dstDir + "/"+libName+"_a.a" + targs[k].suffix+"_size.txt" + ": " + targParams.dstDir + "/"+libName+"_a.a" + targs[k].suffix;
             Pkg.makeEpilogue += "\n\t "+targParams.ofd +" -x " + "$<" +" > tmp.xml";
             Pkg.makeEpilogue += "\n\t sectti tmp.xml > " + "$@";
             Pkg.makeEpilogue += "\n\t $(RM) tmp.xml\n\n";
             fileArray.push(targParams.dstDir + "/"+libName+"_a.a" + targs[k].suffix+"_size.txt");
         }
         
      }
      
   }
 makefilelocal.close();
 return(Pkg);
} 


function getDependentlibs(componentlist,targ)
{
    var dependent_libs=new Array();
    var file = xdc.module('xdc.services.io.File');
    for each(var comp in componentlist)
    {
        
        var pkg_xs=xdc.findFile(comp.replace(/\./g,"/")+"/package.xs")
        if(!pkg_xs)
        {
          continue;
        }
        
        var componentpath=file.getDOSPath(xdc.findFile(comp.replace(/\./g,"/")).toString().replace(/\\/g,"/")); 
        componentpath=componentpath.toString().replace(/\\/g,"/"); 
        for each( var name in listxdcpath)
        {
          if(componentpath.toString().match(name.keypath))
          {
             componentpath=componentpath.toString().replace(name.keypath,"$("+name.keyname+")");
             break;
          } 
        }
        var getlibsComp=xdc.loadCapsule(pkg_xs);
        var prog = {build : {target: targ}};
        var libs = getlibsComp.getLibs(prog);
        if(libs != undefined)
        {
            libs= libs.split(";");
        }
        else
        {
          print(comp + " didn't return valid library for "+targ +" name");
          java.lang.System.exit(1);
        }
        for each(var lib in libs)
        {
          if(comp != "ti.xdais")
          {
            dependent_libs.push(componentpath+"/"+lib); 
          }
        }
    }
    return dependent_libs;

}

/*
 *  @brief This function Creates Executables.
 *
 *  @retval     Pkg      Generated Pkg.
 *
 */                     

function createExe()
{
  /* Loop through the list of targets */   
  makefilelocal = createMake(); 

  for(var k=0;k<targs.length;k++)
  {
    for(n in exeTarget)
    {
       var linkercmdfile="";  
       var targParams=getTargParams(targs[k]);
       if(exeTarget[n].target==targParams.target)
       {   
          /* Defaults */
          if(exeTarget[n].base_directory == undefined)
          {
            exeTarget[n].base_directory = "lnkr/"+targParams.ext; 
          }  

          if(exeTarget[n].platform == undefined)
          {
            exeTarget[n].platform=targParams.platform; 
          }
       
          /* Common Executable configuration */
         if(exeTarget[n].linkTemplate == undefined)
         {
          if(xdc.findFile(exeTarget[n].base_directory+"/"+ exeTarget[n].name+".xdt"))
          {
               exeParams_speed.linkTemplate = exeTarget[n].base_directory+"/"+ exeTarget[n].name+".xdt";
          }
          else if (String(targs[k]).match("ti.targets"))
          {
             print("Error: Could not find "+exeTarget[n].base_directory+"/"+ exeTarget[n].name+".xdt");
             java.lang.System.exit(1);    
          }
         
         }
         else
         {
           exeParams_speed.linkTemplate = exeTarget[n].base_directory+"/"+exeTarget[n].linkTemplate;
         }
         
         if(exeTarget[n].lopts != undefined)
         {
           exeParams_speed.lopts=exeTarget[n].lopts;
         }
         else
         {
           exeParams_speed.lopts="";
         }

         if(exeTarget[n].def_flags == undefined)
         {
            exe_def_flag = "";
         }
         else
         {
           exe_def_flag = exeTarget[n].def_flags;
         }

         var ccspjts={ pjtName:     exeTarget[n].name,
                     location:       ".",
                     buildArtifact:  "Executable",
                     srcFiles:       new Array(),
                     cFlags:         "",
                     targets:        [targParams.target]   
                   }
        var linkfiles=new Array(); 



         if(exeParams_speed.linkTemplate != undefined && String(targs[k]).match("ti.targets"))
         {
           var fileModule = xdc.module('xdc.services.io.File');
           var openedFile;
           var readLine;

           openedFile = fileModule.open(exeParams_speed.linkTemplate, "r");
           if(openedFile==undefined)
           {
             print(exeParams_speed.linkTemplate + " cannot be read");
             java.lang.System.exit(1);
           }
           while((readLine=openedFile.readLine()) != null)
           {
             if(readLine.match(".cmd"))
             {
                 var cmdfile;
                /* Take care of window and linux path */
                 readLine=readLine.replace(/\\/g, "/");
                /* Remove inverted commas(") */
                 readLine=readLine.replace(/"/g, "");
                 cmdfile=readLine.split("/");
                 linkercmdfile = exeTarget[n].base_directory+"/"+cmdfile[cmdfile.length-1];                        
                 /* Create linker command file for CCSV4 project */
                 var readLinelnk;
                 ccslinkfile=linkercmdfile.toString().replace(".cmd","_ccs.cmd");
                 linkfiles.push(ccslinkfile);
                 fileArray.push(ccslinkfile);                     
                 generatedFiles.push(ccslinkfile);   
                 var lnkFilemake = fileModule.open(linkercmdfile, "r");
                 var lnkFileccs = fileModule.open(ccslinkfile, "w");
                 while((readLinelnk=lnkFilemake.readLine()) != null)
                 {
                   readLinelnk=readLinelnk.toString().replace(/\\/g,"/");
                   readLinelnk=readLinelnk.toString().replace("../../","../../../../");
                   readLinelnk=readLinelnk.toString().replace(".o"+targs[k].suffix,".obj")
                   lnkFileccs.writeLine(readLinelnk); 
                  
                 }
                 lnkFilemake.close();
                 lnkFileccs.close();
                 
              } 
           }  
          }
           
         if (delivery_type == "src")
         { 
             exeParams_speed.exportCfg = true;       
           if(exeParams_speed.linkTemplate != undefined)
           {                        
             fileArray.push(exeParams_speed.linkTemplate);                        
             if(linkercmdfile)
             {
               fileArray.push(linkercmdfile);               
             }
           }
         }  
      
/*         var pkgExe=Pkg.addExecutable (exeTarget[n].base_directory+"/"+exeTarget[n].name, targs[k], exeTarget[n].platform,
                                              exeParams_speed);*/
         /* Build All dependent packages first */
         /* Generate the list of components required */
         getComponentList(); 
         if(dependencyAdded==false)
         {   
            dependencyAdded=true;
            makefilelocal.writeLine("\n.executables: make_dependent ");   
            makefilelocal.writeLine("\nmake_dependent: ");   
            for(var z=0; z < pnameHistory.length; z++)
            {
              if(xdc.findFile(pnameHistory[z].replace(/\./g,"/")+"/package.xs") && pnameHistory[z] != "ti.xdais")
              {
                  var file = xdc.module('xdc.services.io.File');
                  var componentpath = xdc.findFile(pnameHistory[z].replace(/\./g,"/"));
                  componentpath=file.getDOSPath(componentpath.toString().replace(/\\/g,"/")); 
                  /* Replace absolute address with ENV variable for PATH */
                  for each( var name in listxdcpath)
                  {
                    if(componentpath.toString().match(name.keypath))
                    {
                        componentpath=componentpath.toString().replace(name.keypath,"$("+name.keyname+")");
                        break;
                     } 
                  }
                  
                  makefilelocal.writeLine("\t-@$(MAKE) -C "+componentpath+ " all");   
               }
            
            }
         
            makefilelocal.writeLine("\ncleanall: clean_dependent ");   
            makefilelocal.writeLine("\nclean_dependent: ");   
            for(var z=0; z < pnameHistory.length; z++)
            {
              if(xdc.findFile(pnameHistory[z].replace(/\./g,"/")+"/package.xs") && pnameHistory[z] != "ti.xdais")
              {
                  var file = xdc.module('xdc.services.io.File');
          var componentpath = xdc.findFile(pnameHistory[z].replace(/\./g,"/"));
          componentpath=file.getDOSPath(componentpath.toString().replace(/\\/g,"/")); 
                  componentpath=componentpath.toString().replace(/\\/g,"/"); 
                   for each( var name in listxdcpath)
                   {
                       if(componentpath.toString().match(name.keypath))
                      {
                        componentpath=componentpath.toString().replace(name.keypath,"$("+name.keyname+")");
                        break;
                      } 
                    }
                   makefilelocal.writeLine("\t-@$(MAKE) -C "+componentpath+ " clean");   
                 }
              }
              
           }
         if(!String(targs[k]).match("microsoft.targets"))
         {
            var exename = exeTarget[n].base_directory+"/"+ exeTarget[n].name+".x"+targs[k].suffix;
         }
         else
         {
           var exename = exeTarget[n].base_directory+"/"+ exeTarget[n].name+".exe";
         }
         fileArray.push(exename);
         var objectPath= "./package/cfg/"+exeTarget[n].base_directory+"/"+exeTarget[n].name;
         makefilelocal.writeLine("\n\n# Make rule to create "+exename+" executable");           
         makefilelocal.writeLine(".executables: "+ exename);
         makefilelocal.writeLine(exename+": FORCE\n\t@$(MAKE) -f "+exename+".mk $@");                  
         
         makefilelocal.writeLine("clean ::\n\t$(RM) "+ exename); 
         var makefileexe= createLibMake(exename+".mk",targs[k],objectPath);
         var objlist="";
         



         for(ID in files)
         {
           /* set the defaults if not defined */

           if(files[ID].compile == undefined)
             files[ID].compile= true;
         
           if(files[ID].target == undefined)
             files[ID].target=["all"];
         
           if(files[ID].compiler_flags == undefined)
             files[ID].compiler_flags="default-speed";
         
           if(files[ID].cmodel == undefined)
             files[ID].cmodel=false;
         
           if(files[ID].base_directory == undefined)
             files[ID].base_directory=".";
         
           if(files[ID].def_flags == undefined)
             files[ID].def_flags="";
             
           /* Check if the following list needs to be compiled */
           if(files[ID].compile == true)
           {
             var flags={
                        copts:"",
                        aopts:""
                        };
       
            /* Compile for default speed options */             
             if(files[ID].compiler_flags=="default-speed")
             {
                flags.copts=targParams.libParams_speed.copts + files[ID].def_flags + exe_def_flag;
                flags.aopts=targParams.libParams_speed.aopts + files[ID].def_flags + exe_def_flag;
             }
             /* Compile for default size options */             
             else if(files[ID].compiler_flags=="default-size")
             {
                flags.copts=targParams.libParams_size.copts + files[ID].def_flags + exe_def_flag;
                flags.aopts=targParams.libParams_size.aopts + files[ID].def_flags + exe_def_flag;
             }
             /* Compile for default debug options */             
             else if(files[ID].compiler_flags=="default-debug")
             {
                flags.copts=targParams.libParams_debug.copts + files[ID].def_flags + exe_def_flag;
                flags.aopts=targParams.libParams_debug.aopts + files[ID].def_flags + exe_def_flag;
             }
             /* Compile with user defined options */             
             else
             {
                flags.copts=files[ID].compiler_flags + files[ID].def_flags + exe_def_flag;
                flags.aopts=files[ID].compiler_flags + files[ID].def_flags + exe_def_flag;
             }

             
            /* Construct the source file with complete address and differentiate c and assembly files */
            cfiles=[];
            afiles=[];
            lafiles=[];
            miscfiles=[];
            for(var l=0;l < files[ID].files.length; l++)
            { 
             

               var temp = files[ID].files[l].split(".");
               if(temp[temp.length-1]=="c")
               {
                 cfiles.push(files[ID].base_directory+"/"+files[ID].files[l]);
                   
               }
               else if(temp[temp.length-1]=="s")
               {
                 afiles.push(files[ID].base_directory+"/"+files[ID].files[l]);
               }
               else if(temp[temp.length-1]=="sa")
               {
                 lafiles.push(files[ID].base_directory+"/"+files[ID].files[l]);
               }
               else
               {
                 miscfiles.push(files[ID].base_directory+"/"+files[ID].files[l]);
               }
                        
            }
            
            for( var q = 0 ; q < files[ID].target.length; q++)
            { 
              objfiles=[];
              if((files[ID].target[q]==targParams.target) || (files[ID].target[q]=="all"))
              {
                 if(miscfiles.length > 0)
                 {
                    for each(var object in miscfiles)
                    { 
                       if(object.toString().match("o"+targs[k].suffix))
                       {
                         objfiles.push(object);
                       }
                       else
                       {
                         print("invalid file extension  "+ object);
                         java.lang.System.exit(1); 
                       }
                 }
             }              
                if(cfiles.length > 0)
                {
/*                  pkgExe.addObjects(cfiles,flags); */
                  makeAddObjects(ID, makefileexe,cfiles,flags.copts,"c",targs[k]);  
                  objlist += " $("+ID.toString().toUpperCase() + "COBJS)"; 
                   if(delivery_type=="src")
                 {
                   
                    fileArray=fileArray.concat(cfiles);
                    linkfiles=linkfiles.concat(cfiles);
                 }                 
                }
                if(afiles.length > 0)
                {
/*                  pkgExe.addObjects(afiles,flags); */
                   makeAddObjects(ID, makefileexe,afiles,flags.aopts,"s",targs[k]);
                   objlist += " $("+ID.toString().toUpperCase() + "AOBJS)";
                     if(delivery_type=="src")
                 {
                     fileArray=fileArray.concat(afiles);
                     linkfiles=linkfiles.concat(afiles);
                 }
                }
                if(lafiles.length > 0)
                {
/*                  pkgExe.addObjects(afiles,flags); */
                   makeAddObjects(ID, makefileexe,lafiles,flags.copts,"sa",targs[k]);
                   objlist += " $("+ID.toString().toUpperCase() + "SAOBJS)";
                  if(delivery_type=="src")
                 {
                     fileArray=fileArray.concat(lafiles);
                     linkfiles=linkfiles.concat(lafiles);
                 }
                }
                if(objfiles.length > 0)
                {
                   makeAddRawObjects(ID, makefileexe,objfiles,targs[k]);
                   objlist += " $("+ID.toString().toUpperCase() + "OBJS)";
                }                
              }

            }
           }   
         }
        makefileexe.writeLine("\n\n");
        var dependent_libs=getDependentlibs(pnameHistory,targs[k]);
        for (var i=dependent_libs.length; i > 0 ; i--)
        {
           makefileexe.writeLine(exename+" :  "+dependent_libs[i-1]);
        }
         
         /* Check if we need to create Linker script for GCC */
         if((String(targs[k]).match("gnu.targets") || String(targs[k]).match("microsoft.targets")) && linkercmdfile=="")
         {
        linkercmdfile = "$^";
         }
         else if(linkercmdfile != "")
         {
           makefileexe.writeLine(exename+" :  "+linkercmdfile);
         }
         /* Add the link file list*/
         ccspjts.srcFiles = linkfiles;
         ccspjts.cFlags =  flags.copts;
         if (String(targs[k]).match("ti.targets"))
         {
           ccsProjects.push(ccspjts);
         }
         
         var exerule=exename+" : "+objlist;                       
         makefileexe.writeLine(exerule);
         makefileexe.writeLine("\t@echo lnk"+targs[k].suffix+" $@ ...");
     if(linkercmdfile == "$^")
     {
        makefileexe.writeLine("\t$(LD) "+linkercmdfile +" $(INTERNALLINKDEFS) $(RTSLIB)");
     }
     else
     {
        makefileexe.writeLine("\t$(LD) "+objlist+" "+linkercmdfile +" $(INTERNALLINKDEFS) $(RTSLIB)");
     }
         makefileexe.close();                           
          
       }   
     }
  }
 makefilelocal.close();
 createTestProjects();
 return(Pkg);
}     

/*
 *  @brief This function Creates Archive.
 *
 */                  

function createArchive(pkgName)
 {
  /* pkgname is obsolete now */
  if(pkgName != undefined && isBundlePkg!=true)
  {
    print("Package.name is obsolete");
  }
  /* Do normal release */ 
  if(generateBundle == false)
  {
  if(pkgName == undefined)
     pkgName=Pkg.name;
  /* Get the ZIP file name */
  rel_name=getZipFilename(pkgName,isBundlePkg);
  
  Pkg.generatedFiles=generatedFiles;
  
  /* Default Archive */
  if(archiveTypeDefault == true)
  {
    /* Archive Common Object Release files */
    archiveObject();

    /* Archive Header files */
    archiveHeaders(".",false);
 }

  /* Archive package specific files */
    archiveOtherFiles(archiveFiles);  

  /* Archive relnotes_archive folder*/
    if(xdc.findFile(".//docs//relnotes_archive"))
    {
       fileArray.push("docs/relnotes_archive");
    }

  /* Object Release */     
  if (delivery_type == "obj")
  {
     var obj = Pkg.addRelease(rel_name,{compress: false, archiver: "zip"});
     obj.otherFiles = fileArray;
     Pkg.defaultRelease = obj;
  }/* Source Release */
  else if (delivery_type == "src") 
  {
     var src = Pkg.addRelease (rel_name, {exportSrc: true, exportCfg: true, compress: false, archiver: "zip"});
     /* Archive Common Object Release files */
     fileArray.push("package.bld");
     if(archiveTypeDefault == true)
     {
       archiveSource();
     if(bundletype != "kernel"){
       archiveHeaders("src",true);
     }
     }
     src.otherFiles = fileArray;
     Pkg.defaultRelease = src;
     var miniPkg = java.lang.System.getenv("MINI_PACKAGE");
     if(miniPkg == "ON")
     {
       var cmd ="$(ZIP) -q -u $(PKGDIR)/$@";
       var filestoZip="";
       for each(var archfile in fileArray)
       {
           var srcFile=String(archfile);
           var dot = srcFile.lastIndexOf(".");
           var extension = srcFile.substr(dot,srcFile.length);      
           if (extension == ".h" || extension == ".s" || extension == ".sa" || extension == ".c" || extension == ".mk" || srcFile=="makefile" || extension == ".cmd")
           {
              if(srcFile != "Makedocs.mk" && !srcFile.match("doxygen.h"))
              {
                cmd += " $(PKGDIR)/"+srcFile.replace("./","");
                filestoZip += " "+srcFile.replace("./","");
              }
           }
        } 
        Pkg.makeEpilogue+= "\nrelease: "+rel_name+"_minipkg.zip\n";
        Pkg.makeEpilogue+= "\n"+rel_name+"_minipkg.zip:"+filestoZip;
      Pkg.makeEpilogue+= "\n\t@$(MSG) making release file $@ ...";
      Pkg.makeEpilogue+= "\n\t-$(RM) $@";
      Pkg.makeEpilogue+= "\n\tcd $(PKGROOT);"+cmd;
      Pkg.makeEpilogue+= "\n";
                
      }
   
  }
  
  }
  else
  {
    createBundle();
  }
            
}  

/*
 *  @brief This function Archives Object Release specific files.
 *
 *
 */      

function archiveObject()
{    
  /* Check if Doxygen files are there   */
  var packagename=String(Pkg.name);
  packagename=packagename.replace(/\./g,"//");
  if(xdc.findFile(packagename+"//docs//doxygen//APIDoxyfile.xdt"))
  {
   fileArray.push("docs//doxygen//APIDoxyfile.xdt");
  }
  if(xdc.findFile(packagename+"//docs//doxygen//doxyfile.xdt"))
  {
   fileArray.push("docs//doxygen//doxyfile.xdt");
  }

  var doxyFile = xdc.findFile(packagename+"//docs//doxygen//APIDoxyfile");
  if (doxyFile && xdc.om['xdc.bld'].BuildEnvironment.hostOSName == "Windows") {
    /* Get the CHM name and put it in the Archive */
    var fileModule = xdc.module('xdc.services.io.File');
    var openedFile;
    var readLine;
    try {
      openedFile = fileModule.open(doxyFile, "r");
    } 
    catch (ex) {
      print(srcFile + " cannot be read");
    }
    while ((readLine=openedFile.readLine()) != null) {
      if(readLine.match("CHM_FILE")) {   
        var temp = readLine.split("=");  
        var chmname = temp[temp.length-1].toString().replace(" ","");
        fileArray.push("docs//doxygen//html//"+chmname);
      }
    }
  }
  else if (xdc.findFile(packagename+"//docs//doxygen//Doxyfile") &&
           xdc.om['xdc.bld'].BuildEnvironment.hostOSName == "Windows") {
    /* Get the CHM name and put it in the Archive */
    var doxyfile = xdc.findFile(packagename+"//docs//doxygen//Doxyfile");
    var fileModule = xdc.module('xdc.services.io.File');
    var openedFile;
    var readLine;
    try {
      openedFile = fileModule.open(doxyfile, "r");
    } 
    catch (ex) {
      print(srcFile + " cannot be read");
    }
    while ((readLine=openedFile.readLine()) != null) {
      if(readLine.match("CHM_FILE")) {   
        var temp = readLine.split("=");  
        var chmname = temp[temp.length-1].toString().replace(" ","");
        fileArray.push(".//docs//doxygen//html//"+chmname);
      }
    }
  }      
}

/*
 *  @brief This function Archives Source Release specific files.
 *
 */ 

function archiveSource()
{
     var packagename=String(Pkg.name);
     packagename=packagename.replace(/\./g,"//");
  /* Common source release  files */
       fileArray.push("package.bld");
       if(xdc.findFile(packagename+"/config.bld"))
       {
         fileArray.push("config.bld");
       }
       if(xdc.findFile(packagename+"/cygwinxdc.bat"))
       {
         fileArray.push("cygwinxdc.bat");
       }
       if(xdc.findFile(packagename+"/Makedocs.mk.xdt"))
       {
         fileArray.push("Makedocs.mk.xdt");
       }
       else if(xdc.findFile(packagename+"/Makedocs.mk"))
       {
         fileArray.push("Makedocs.mk");
       }
       if(xdc.findFile(packagename+"/docs//doxygen//doxygen.h"))
       {
         fileArray.push("docs//doxygen//doxygen.h");
       }
       if(xdc.findFile(packagename+"//docs//doxygen//APIDoxyfile"))
       {
         fileArray.push("docs//doxygen//APIDoxyfile");
         if(xdc.om['xdc.bld'].BuildEnvironment.hostOSName == "Windows")
         {
           /* Get the CHM name and put it in the Archive */
          var doxyfile = xdc.findFile(packagename+"//docs//doxygen//APIDoxyfile");
          var fileModule = xdc.module('xdc.services.io.File');
          var openedFile;
          var readLine;
          try{
                openedFile = fileModule.open(doxyfile, "r");
              } catch (ex)
             {
                print(srcFile + " cannot be read");
             }
         while((readLine=openedFile.readLine()) != null)
            {
               if(readLine.match("CHM_FILE"))
               {   
                  var temp = readLine.split("=");  
                  var chmname = temp[temp.length-1].toString().replace(" ","");
                  var moduleAPIChm = "docs//doxygen//html//"+chmname;
                  fileArray.push(moduleAPIChm);
               }
            }
         }
       }
       if(xdc.findFile(packagename+"//docs//doxygen//Doxyfile"))
       {
         fileArray.push("docs//doxygen//Doxyfile");
         if(xdc.om['xdc.bld'].BuildEnvironment.hostOSName == "Windows")
         {
           /* Get the CHM name and put it in the Archive */
          var doxyfile = xdc.findFile(packagename+"/docs//doxygen//Doxyfile");
          var fileModule = xdc.module('xdc.services.io.File');
          var openedFile;
          var readLine;
          try{
                openedFile = fileModule.open(doxyfile, "r");
              } catch (ex)
             {
                print(srcFile + " cannot be read");
             }
         while((readLine=openedFile.readLine()) != null)
            {
               if(readLine.match("CHM_FILE"))
               {   
                  var temp = readLine.split("=");  
                  var chmname = temp[temp.length-1].toString().replace(" ","");
                  var moduleChm = ".//docs//doxygen//html//"+chmname;
                  fileArray.push(moduleChm);
               }
            }
         }
         
       }
       if(xdc.findFile(packagename+"/docs//doxygen//doxyfile.xdt"))
       {
         fileArray.push("docs//doxygen//doxyfile.xdt");
       }
       
       if(xdc.findFile(packagename+"/docs//doxygen//apidoxyfile.xdt"))
       {
         fileArray.push("docs//doxygen//apidoxyfile.xdt");
       }
       
       if(xdc.findFile(packagename+"/test.cfg"))
       {
         fileArray.push("test.cfg");
       }
}

/*
 *  @brief This function Archives Listed files.
 *
 */ 

function archiveOtherFiles(array)
{
    var archive;
    for(i in array)
    {  
      archive=false;
      if(array[i].delivery_type == undefined)
         array[i].delivery_type="obj";
         
      if(array[i].target == undefined)
         array[i].target=["all"];

      if(array[i].delivery_type == "obj" || array[i].delivery_type == delivery_type)
       {

          for( var q = 0 ; q < array[i].target.length; q++)
            { 
               if(array[i].target[q]=="all")
                  archive = true;
               else
               {
                 for( var k = 0 ; k < targs.length; k++)
                 {
                   var targParams=getTargParams(targs[k]);
                   if(array[i].target[q]==targParams.target)
                   {  
                     archive = true;
                   }
                 }
               }
            } 
         
        }
      if(array[i].delivery_type=="bundle" && isBundlePkg==true)  
      {
        archive=true;
      }
      if(archive==true)
      {  
        for(var j=0;j< array[i].files.length; j++)
        {
            if(array[i].base_directory == undefined)
            {
               fileArray.push(array[i].files[j]);
            } 
            else
            {
               fileArray.push(array[i].base_directory+"/"+array[i].files[j]);
            }
        }   
      }
    }
}

/*
 *  @brief This function Archives Header files.
 *
 */ 
function archiveHeaders(dirs,recurse)
{
  var file = new java.io.File(dirs);
  if(!file.isDirectory() && recurse == true)
    return;

  var list = file.list();
  var i, j;
  for (i = 0; i < list.length; i++)
  {
     var srcFile=String(list[i]);
     var dot = srcFile.lastIndexOf(".");
     var extension = srcFile.substr(dot,srcFile.length);      
     if (extension == ".h" || extension == ".html")
     {
        fileArray.push(dirs+"/"+list[i]);
     }
     if(recurse == true)
     {
        if(list[i] == "c54" || list[i] == "c55" || list[i] == "c64" || list[i] == "c64P" || list[i] == "c674" || list[i] == "c66" || list[i] == "arm")
        {
            for(var k=0;k<targs.length;k++)
            {
                var targParams=getTargParams(targs[k]);
                if(list[i]==targParams.targDirectory ||(list[i] == "c64P" && 
                   (targs[k]==C64P ||targs[k]==C64P_big_endian || targs[k]==C64P_elf ||targs[k]==C64P_big_endian_elf)) || ((list[i] == "c674" || list[i] == "c64P" ) && 
                   (targs[k]==C674 ||targs[k]==C674_big_endian || targs[k]==C674_elf ||targs[k]==C674_big_endian_elf)) 
                   ||(list[i] == "c66" && (targs[k]==C66 ||targs[k]==C66_big_endian || targs[k]==C66_elf ||targs[k]==C66_big_endian_elf)))
                  archiveHeaders(dirs+"/"+list[i],true); 
             
            }
         }
        else
        {
           archiveHeaders(dirs+"/"+list[i],true);
        } 
      }
    
  }
}

/*
 *  @brief This function Defines Common Clean rules.
 *
 */ 

function packageClean()
{ 
  /* Clean the creates docs directory during clean */
  var moduleChm = ".//docs//doxygen//*.chm";
  Pkg.makeEpilogue += "clean::\n\t-$(RM)  *.zip\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RM)  *.bin\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RM)  *.exe\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RM)  .//docs//doxygen//*.chm\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RM)  .//docs/*.chm\n";  
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) .//docs//doxygen//html\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) cov_out\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c54\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c54f\n"
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c55\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c55l\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c64\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c64e\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c674\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c674e\n";  
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) ce66\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) ce66e\n";  
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c64P\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) c64Pe\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) mvarm9\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) gcarmv6\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) gcarmv7a\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) wince\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) tiarmv6le\n";
  Pkg.makeEpilogue += "clean::\n\t-$(RMDIR) tiarmv6be\n";

}

/*
 *  @brief This function initializes Print Buffer used for displaying Print Usage.
 *
 *  @param[in]  print_buffer  Pointer to Print buffer Structure.
 *
 *  @retval     print_buffer  Pointer to Print buffer  Structure.
 *
 */

function printUsage(print_buffer)
{
  var targetOption;
  var targetDir;
  var temp = Pkg.name.split(".");
  var name = temp[temp.length-1];
  /* Print Buffer Header */
  print_buffer.header +="USAGE: \n";
  print_buffer.header += "xdc XDCARGS=\"<options>\" [release] [gendocs] [genapidocs]\n";

  /* Print Buffer Options */
  print_buffer.options +="  Options:\n";
  
  print_buffer.options +="      all      - Compile " + name + " for all supported targets\n";

  for (var k = 0; k < targets.length; k++) {
  switch (targets[k]) {
    case C64P:
      print_buffer.options +="      c64Ple      - Compile " + name + " for c64+ target (little-endian)\n";
      targetOption="c64Ple";
      targetDir="c64P";
      break;
    case C64P_big_endian:
      print_buffer.options +="      c64Pbe      - Compile " + name + " for c64+ target (big-endian)\n";    
      targetOption="c64Pbe";
      targetDir="c64Pe";
      break;
    case C64:
      print_buffer.options +="      c64le       - Compile " + name + " for c64 target (little-endian)\n"; 
      targetOption="c64le";
      targetDir="c64";
      break;
    case C64_big_endian:
      print_buffer.options +="      c64be       - Compile " + name + " for c64 target (big-endian)\n"; 
      targetOption="c64be";
      targetDir="c64e";
      break;
    case C674:
      print_buffer.options +="      c674le       - Compile " + name + " for c674 coff target (little-endian)\n"; 
      targetOption="c674le";
      targetDir="c674";
      break;
    case C674_big_endian:
      print_buffer.options +="      c674be       - Compile " + name + " for c674 coff target (big-endian)\n"; 
      targetOption="c674be";
      targetDir="c674e";
      break;
    case C674_elf:
      print_buffer.options +="      c674le_elf       - Compile " + name + " for c674 elf target (little-endian)\n"; 
      targetOption="c674le";
      targetDir="c674";
      break;
    case C674_big_endian:
      print_buffer.options +="      c674be_elf       - Compile " + name + " for c674 elf target (big-endian)\n"; 
      targetOption="c674be";
      targetDir="c674e";
      break;
    case C66:
      print_buffer.options +="      c66le       - Compile " + name + " for c66 target (little-endian)\n"; 
      targetOption="c66le";
      targetDir="ce66";
      break;
    case C66_big_endian:
      print_buffer.options +="      c66be       - Compile " + name + " for c66 target (big-endian)\n"; 
      targetOption="c66be";
      targetDir="ce66e";
      break;      
      
    case C55_large:
      print_buffer.options +="      c55l        - Compile " + name + " for c55 target (large mode)\n";
      targetOption="c55l";
      targetDir="c55L";
      break;
    case C55:
      print_buffer.options +="      c55s        - Compile " + name + " for c55 target (small mode)\n";
      targetOption="c55s";
      targetDir="c55";
      break;
    case C54_far:
      print_buffer.options +="      c54f        - Compile " + name + " for c54 target (far mode)\n";
      targetOption="c54f"; 
      targetDir="c54f";
      break;
    case C54:
      print_buffer.options +="      c54n        - Compile " + name + " for c54 target (near mode)\n";
      targetOption="c54n";
      targetDir="c54"; 
      break;
    case MVArm9:
      print_buffer.options +="      mvarm9      - Compile " + name + " for montavista arm9 target (MVArm9) \n";
      targetOption="mvarm9";
      targetDir="mvarm9"; 
      break;
    case GCArmv6:
      print_buffer.options +="      gcarmv6     - Compile " + name + " for GNU armv6 target (GCArmv6) \n";
      targetOption="gcarmv6";
      targetDir="gcarmv6"; 
      break;      
    case GCArmv7A:
      print_buffer.options +="      gcarmv7a     - Compile " + name + " for GNU arm Cortex A8/A9 target based on cpu='cortex-a8'(default) or 'cortex-a9'  (GCArmv7A) \n";
      targetOption="gcarmv7a";
      targetDir="gcarmv7a"; 
      break;      
    case TIArmv6le:
      print_buffer.options +="      tiarmv6le     - Compile " + name + " for TI armv6 LE target (TIArmv6le) \n";
      targetOption="tiarmv6le";
      targetDir="tiarmv6le"; 
      break;   
      
    case TIArmv6be:
      print_buffer.options +="      tiarmv6be     - Compile " + name + " for TI armv6 BE target (TIArmv6be) \n";
      targetOption="tiarmv6be";
      targetDir="tiarmv6be"; 
      break;         
      
    case WinCE:
      print_buffer.options +="      wince      - Compile " + name + " for wince target (WinCE) \n";
      targetOption="wince";
      targetDir="WCE"; 
      break;      
    }
    }

  print_buffer.options +="      obj         - Make a object release (default) [optional]\n";
  print_buffer.options +="      src         - Make a source release [optional]\n";
  print_buffer.options +="      covRun      - Forces Coverity to execute and evaluate the code\n";
  print_buffer.options +="      debug       - Use Debug Profile\n";
  
  /* Print Buffer Others */
  print_buffer.others +="\n";
  print_buffer.others +="  release    - Generate release tarball either source or object\n";
  print_buffer.others +="  gendocs    - Generate complete "+ name +" implementation documentation\n";
  print_buffer.others +="  genapidocs - Generate " + name + " API documenation\n";
  print_buffer.others +=" \n";
  print_buffer.others +="  By default "+ name +" is compiled for: \n";
  if(delivery_type=="obj")
   print_buffer.others +="     - Object delivery \n";
  else
   print_buffer.others +="     - Source delivery \n";
  print_buffer.others +=" ";
  print_buffer.others +="     Ex1: 'xdc XDCARGS=\""+targetOption+"\" release' will generate: \n";

  if(targ_indp==true)
   targetOption="";
  else
   targetOption="_"+targetOption;
  var temp = Pkg.name.replace(/\./g,"_"); 
 
  print_buffer.others +="            (a) Object tarball \""+temp + "_"+delivery_type+targetOption+"" + verStr + ".zip\"\n"; 
  if(name.match("test"))
  {
     print_buffer.others +="            (b) lnkr//"+targetDir+"//test_rel_xxx.x"+targetDir+" Executable\n";
  }
  else
  {
     var firsttime=true;
     for(n in files)
     {
        if(firsttime==true)
        {
            print_buffer.others +="            (b) "+targetDir+"//"+ name + "*.a"+targetDir+" library\n";
            firsttime=false;
        }  
     }
  }

  
  if(xdc.findFile(".//docs//doxygen//APIDoxyfile"))
  {
     print_buffer.others +="            (c) "+ name +" API documentation in \"docs//doxygen//"+ name.toUpperCase() +"API.chm\".\n";
  }



  print_buffer.others +="\n\n";

  return(print_buffer);
}

/*
 *  @brief This function initializes Print Buffer Options used for displaying Print Usage.
 *         This is used for displaying package specific arguments.   
 *
 *  @param[in]  print_buffer  Pointer to Print buffer Structure.
 *  @param[in]  SpecificArgs  Pointer to Package Specific Argument Structure.
 *
 *  @retval     print_buffer  Pointer to Print buffer.
 *
 */

function addUsage(print_buffer,SpecificArgs)
{
  /* Add Additional Package Specific Options */
  if( SpecificArgs.type == undefined)
  { 
     print_buffer.options +="      " + SpecificArgs.value + "  - " + SpecificArgs.usageComment + "\n";
  }
  else if(SpecificArgs.type == "N")
  {
    print_buffer.options +="      " + SpecificArgs.value + " = N  - " + SpecificArgs.usageComment + "\n";   
  } 

  return(print_buffer);

}

/*
 *  @brief This function creates Version module based on the version template.    
 *
 *
 */
function createVersion()
{
   if(version==undefined)
   {
     print("Error: Parameter \'version\' not defined "); 
     java.lang.System.exit(1);
   }

  /* generate Version.xdc based on the version array above */
  if(pkgStdVer=="1.0")
  {
    if(version.length==4)
    {
    var tplt = xdc.loadTemplate('ti/mas/swtools/Version.xdt');
    tplt.genFile('Version.xdc', Pkg, version);
    var tplt = xdc.loadTemplate('ti/mas/swtools/Version.h.xdt');
    tplt.genFile('Version.h', Pkg, version);
    generatedFiles.push("Version.xdc");
    generatedFiles.push("Version.h");
    }
    else
    {
      print("Error: Packaging Version Standard Specified and Version doesn't match.....");
      java.lang.System.exit(1);
    }
    
  }
  else if (pkgStdVer=="2.0")
  {
     if(version.length==6)
    {
    var tplt = xdc.loadTemplate('ti/mas/swtools/Version2.xdt');
    tplt.genFile('Version.xdc', Pkg, version);
    var tplt = xdc.loadTemplate('ti/mas/swtools/Version2.h.xdt');
    tplt.genFile('Version.h', Pkg, version);
    generatedFiles.push("Version.xdc");
    generatedFiles.push("Version.h");
    }
    else
    {
      print("Error: Packaging Version Standard Specified and Version doesn't match.....");
      java.lang.System.exit(1);
    }
  
  
  }
  else
  {
    print("Error: Incorrect Packaging Version Specified.....");
    java.lang.System.exit(1);
  }

}

/*
 *  @brief This function includes GNU Make File.    
 *
 *
 */

function includeMake(makefile)
{
  Pkg.makePrologue += "\ninclude "+makefile;
  
}

function genAPIDoxyfile()
{
  /* generate APIdoxyfile based on the version array above */
  var tplt = xdc.loadTemplate('ti/mas/swtools/APIDoxyfile.xdt');
  tplt.genFile('./docs/doxygen/APIdoxyfile', Pkg, version);
}

function genDoxyfile()
{
  /* generate doxyfile based on the version array above */
  var tplt = xdc.loadTemplate('ti/mas/swtools/Doxyfile.xdt');
  tplt.genFile('./docs/doxygen/doxyfile', Pkg, version);
}

/* Used for bundling */
var Build = xdc.useModule('xdc.bld.BuildEnvironment');
var Pkg   = xdc.useModule('xdc.bld.PackageContents' );
var path = environment["xdc.path"].split(";");
var browser = new Packages.xdc.services.spec.BrowserSession(path);
var pnameArray = new Array();
var pnameHistory = new Array();
var pkgReleases = [];

/*
 *  @brief This function generates the bundle archive 
 *
 *
 */
function bundle()
{
  /* Check if packages directory exist, if not create it */
  var repositDir = new java.io.File("components");
  var packageDir = new java.io.File("packages");
  isBundlePkg=true;
  if(!(repositDir.exists() && repositDir.isDirectory()))
  {
    repositDir.mkdirs();
 
  }
  else
  {
    copy.deleteDir("components");
    repositDir.mkdirs();
  }
  if(!(packageDir.exists() && packageDir.isDirectory()))
  {
    packageDir.mkdirs();
 
  }
  if(kernel == true)
  {
      /* Create Lib and inc directory in the root folder */
       var targetDir = new java.io.File("lib");
       if(!(targetDir.exists() && targetDir.isDirectory()))
       {
         targetDir.mkdirs();
       }
       var targetDir = new java.io.File("inc");
       if(!(targetDir.exists() && targetDir.isDirectory()))
       {
         targetDir.mkdirs();
       }
    fileArray.push("lib");
    fileArray.push("inc");
    fileArray.push("packages");

  }

/* Generate the list of components required */
  getComponentList(); 
  
/* Archive Components */
  archiveComponents();  
  
  fileArray.push("components");
 /* Archive Eclipse folder*/
  if(xdc.findFile(".//eclipse"))
  {
     fileArray.push("eclipse");
  }

}
/*
 *  @brief This function archives the components for bundling 
 *
 *
 */
 
function archiveComponents()
{
Pkg.makePrologue += "\nrelease: copy_packages\n"
Pkg.makePrologue += "\ncopy_packages:\n"
for(var i=0; i < pnameHistory.length; i++)
  {
    for each (var relDesc in Build.getReleaseDescs(pnameHistory[i])) {
    if (relDesc.label = "default") {
      var imp = pnameHistory[i] + ": " + relDesc.aname;
      var relFile = xdc.getPackageBase(pnameHistory[i]) + relDesc.aname;
      Pkg.makePrologue += "\techo Copying "+relDesc.aname+" to components\n";
      Pkg.makePrologue += "\t-@$(CP) "+relFile+" components\n";
      Pkg.makePrologue += "\techo Unzipping "+relDesc.aname+" to packages\n";
      Pkg.makePrologue += "\t-@$(UNZIP) -uo -qq " + relFile + " -d packages \n";      
     
    }
  }
 }  
}
/*
 *  @brief This function generates the component list 
 *
 *
 */

function getComponentList()
{

  for each (var pname in Pkg.imports) {
    if (pname[0] == '*') {
      pname = pname.substring(1);
    }
    pname = pname.substr (0, pname.indexOf("{"));
    pnameArray.push(pname);

  }
  /* Add dependent package to the list */
  for(var i=0; i < pnameArray.length; i++)
 {
  if(checkpArray(pnameArray[i]) == false)
  {
    pnameHistory.push(pnameArray[i]);
    var pkgdep = browser.findPkg(pnameArray[i]);
    if(pkgdep)
    {
      var requires = pkgdep.getRequires().toArray(); /* convert Java list to an array for easier use below */
      for (var j = 0; j < requires.length; j++) {
        var req = requires[j];
        var split_temp = req.getText().toString().split("\\{");
        var temp = split_temp[0].split("\\*");
        if (temp.length > 1) {
         temp[0] = temp[1];
        }
        pnameArray.push(String(temp[0]));
      }
    }
  }
 }
 return pnameHistory;
} 
/*
 *  @brief This function Checks  the package in history 
 *
 *
 */

function checkpArray(cname)
{
   for(var i=0; i < pnameHistory.length; i++)
  {
    if(pnameHistory[i].match(cname))
    {
     return true;
    }
  }
  return false;
}

/*
 *  @brief This function creates the bundle package.
 *
 *
 */

function createBundle()
{
  /* Start bundle package by creating bundle folder */
  Pkg.makePrologue += "\n.PHONY: gendocs\n";  
  
  if (bundleid != undefined) {
    bundlename = bundleid;
  }

  if (bundlename == undefined) {
    var temp=String(Pkg.name);
    temp=temp.split(".");
    bundlename = temp[temp.length-1]+"_bundle";
  }
  
  var temp=String(Pkg.name);
  temp=temp.split(".");
  var ShortAppName=temp[temp.length-1].toString().toUpperCase();
  
  var bundelDir = new java.io.File(bundlename);
  
  /* File module for generating package.bld */
  var fileModule = xdc.module('xdc.services.io.File');
 
  var relnotearray = new Array();

  var license = true;

  /* Check if bundle directory exists, if not create it */
  if(!(bundelDir.exists() && bundelDir.isDirectory())) {
    bundelDir.mkdirs();
  }
  
  Pkg.makeEpilogue += "\nclean::\n\t-$(RMDIR) " + bundlename + "\n";  
  
  /* get the target params */
  var targParams = getTargParams(targs[0]);  
  
  /* Check for Version information */
  if (version == undefined) {
    print("Error: Parameter \'version\' not defined "); 
    java.lang.System.exit(1);
  }

  /* Create package.bld file under bundle folder */
  /* Create List of files to be archived for Bundle package */
  var argsString = "";
  for (var id in archiveFiles) {
    if (archiveFiles[id].delivery_type == "bundle") {
      argsString += "Package.archiveFiles[\""+id+"\"]={\n";
      if (archiveFiles[id].base_directory != undefined)
        argsString += "\tbase_directory: \""+archiveFiles[id].base_directory+"\",\n";     
      if (archiveFiles[id].target != undefined)
        argsString += "\ttarget: [\""+archiveFiles[id].target.toString().replace(/\,/g,"\",\"")+"\"],\n";  
      if (archiveFiles[id].files != undefined)
        argsString += "\tfiles: [\""+archiveFiles[id].files.toString().replace(/\,/g,"\",\"")+"\"],\n";  
      argsString+=" };\n\n";     
    }
  }
 
  var bundletarg = new Array(); 
  for (var x=0; x<targs.length; x++) {

    bundletarg.push(getTargParams(targs[x]).targstring);
  }
  
  if (bundleMakeDoc == undefined) {
    bundleMakeDoc = "Makedocs.mk";
  }

  if(bundleid != undefined)
     var archivefilename = bundleid;
  else
  {
     if(ext == "")
    {
      var targParams = getTargParams(targs[0]);
      ext = targParams.ext;  
    }     
  if(bundletype == "kernel")
     var archivefilename = bundlename+"_"+ext;
  else
     var archivefilename = bundlename+"_"+ext+"_"+delivery_type;
  }
     
  var tmpltArgs = new Array();
  if (pkgStdVer == "1.0") {
    tmpltArgs=[pkgStdVer,version[0],version[1],version[2],version[3],bundletarg,bundleMakeDoc,archivefilename,argsString];
  }
  else if (pkgStdVer == "2.0") {
    tmpltArgs=[pkgStdVer,version[0],version[1],version[2],version[3],version[4],version[5],bundletarg,bundleMakeDoc,archivefilename,argsString];
  }

  var tplt = xdc.loadTemplate('ti/mas/swtools/bundlepackagebld.xdt');
  tplt.genFile (bundlename+'/package.bld', Pkg, tmpltArgs);
  
  /* Case: package.xdc needs to be generated using package.xml */
  if (xdc.findFile(".//package.xml")) {
    /* Load XML File */
    var xmltree = xdc.loadXML(".//package.xml");
    if (xmltree["Product"].xml_packaging_version == "1.0.0.0") {
      var writeFile;
      /* Get the component Install target name */
      var impoNamesInstallXml = xmltree["Product"].Build.(@bundleid==bundleid).Install.Win32Name;
      winInstallname = impoNamesInstallXml["PreVersion"]+ xmltree["Product"].ComponentFamily.@version.toString().replace(/\./g,"_")+impoNamesInstallXml["PostVersion"];

      var impoNamesInstallXml = xmltree["Product"].Build.(@bundleid==bundleid).Install.LinuxName;
      linuxInstallname = impoNamesInstallXml["PreVersion"]+ xmltree["Product"].ComponentFamily.@version.toString().replace(/\./g,"_")+impoNamesInstallXml["PostVersion"];
      
      /* Get the Component target */
      var impoNamesProductXml = xmltree["Product"].Build.(@bundleid==bundleid).Platform;
      var platformlist = new Array();     
      /* Write the require list */
      for each (var m in impoNamesProductXml) {
        /* Open the package.xdc file to write */
        try {
          writeFile = fileModule.open(bundlename+"/package.xdc", "w");
        } 
        catch (ex) {
          print(bundlename+"/package.xdc cannot be written to. Please check Writing Permissions.");
          java.lang.System.exit(1);
        }    
        var componentlistxml = m.Component;
        var componentlist = "";
        var comma = "";
        for each (var j in componentlistxml) {
          componentlist += comma + "\n{\n name : \""+j.@name+"\",\n arg  : [\""+j.@arguments.toString().replace(/ /g,"\",\"")+"\"]\n}";
          comma = ",";
          if (!j.@name.toString().match(".test")) {
            var line = "requires " + j.@name + "[" + j.@compatibility + "];"
            writeFile.writeLine(line);
          
            if (xdc.findFile(j.@name.toString().replace(/\./g,"\/")+"/test")) {
              line = "requires "+j.@name+".test;"     
              writeFile.writeLine(line);
            }
          }
          /* Create Argument for Release Notes */  
          var srcFile = String(j.@name);     
          var dot = srcFile.lastIndexOf(".");
          var relname = srcFile.substr(dot+1,srcFile.length);
          if (searchReleasenotes(j.@name) != undefined) {     
            /* Check if we have already added this to releasenote array */
            var relnoteExists = false;
            for each (var relnote in relnotearray) {
              if (relnote.name == relname) {
                relnoteExists = true;
              }
            }
            /* If it doesn't exists add it to release note */
            if (relnoteExists == false) {
              relnotearray.push({html:searchReleasenotes(j.@name),name:relname});
            }
          }
        }
        
        var componentlistxml = m.Dependent;
        for each (var j in componentlistxml) {
          componentlist+=",\n{\n name : \""+j.@name+"\",\n arg  : [\""+j.@arguments.toString().replace(/ /g,"\",\"")+"\"]\n}";
        }
        
        /* Insert few blanks lines */
        line = "\n";
        writeFile.writeLine(line);
  
        /* Insert the Bundle package name */
        line = "package "+bundlename+"["+Pkg.version+"] {";
        writeFile.writeLine(line);
        line = "    module Version;";
        writeFile.writeLine(line);
        line = "    }";
        writeFile.writeLine(line);
  
        /* Create ARGS_XS file under bundle folder - if required */
        var tplt = xdc.loadTemplate('ti/mas/swtools/xdcargs.xs.xdt');
        tplt.genFile('./xdcargs_'+m.@name+'.xs', null,[componentlist]);
        Pkg.makeEpilogue += "clean::\n\t-$(RM) "+'./xdcargs_*'+"\n";  
        platformlist.push(Pkg.name.replace(/\./g,"/")+'/xdcargs_'+m.@name+'.xs');
      }    
      /* Command to create bundle package */
     /* Generate release notes header */
     var releaseString = "";
     for each (var relnote in relnotearray) {
       releaseString +="<li> <a href=\"./packages/"+relnote.html+"\"> "+relnote.name.toUpperCase()+" Release Notes</a>\n";
     }
     
     if(xdc.findFile("./docs/bundle/doxygen/release.h.xdt"))
     {
       var reltplt = Pkg.name.replace(/\./g,"/")+"/docs/bundle/doxygen/release.h.xdt";
       var tplt = xdc.loadTemplate(reltplt);
       tplt.genFile('docs/bundle/doxygen/release.h',Package,[releaseString,ext]);
     }
        
   
      /* Archive file name of the generated package */
      var ziptarget = getZipFilename(archivefilename,true)+".zip";
    
      /* Add to make file */
      Pkg.makeEpilogue += "\all :"+ ziptarget;  
      Pkg.makeEpilogue += "\n" +ziptarget+ ": "+bundlename+"/package.bld" ;
      for each (var plat in platformlist) {
        var cmd='xdc XDCARGS="" ARGS_XS="'+plat+'" release -PD '+bundlename+'\n';
        Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
        Pkg.makeEpilogue += "\n\t"+cmd;
        cmd='xdc XDCARGS="" releasenotes -P '+bundlename+'\n';
        Pkg.makeEpilogue += "\n\t-@ echo Generating Release Notes ...";  
        Pkg.makeEpilogue += "\n\t"+cmd;
        if(xdc.findFile("./examples"))
        {
            if(xdc.findFile("./examples/example.xs"))
            {
              cmd='xs -f ./examples/example.xs "' +plat +'" ' + bundlename+"\n" ;
              Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
              Pkg.makeEpilogue += "\n\t"+cmd;                    
            }
            
            cmd='xdc XDCARGS="all src" -PR .//'+bundlename+'//examples\n';
            Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
            Pkg.makeEpilogue += "\n\t"+cmd;        
        }        
        cmd='xdc clean -P '+bundlename+'\n';
        Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
        Pkg.makeEpilogue += "\n\t"+cmd;
        cmd='xdc XDCARGS="" ARGS_XS="'+plat+'" release -P '+bundlename+'\n';
        Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
        Pkg.makeEpilogue += "\n\t"+cmd;
      }
      Pkg.makeEpilogue += "\n\t $(CP) " + bundlename + "/$@ $@\n\n";    
    
      if (install == true) {
        var InstallJammerVersion = " -DVersion " + getVersionDisplayString();
        var PackageBaseDir = " -DPackageBaseDir " + java.io.File(".//").getPath() + "/tmp/" + bundlename;
        var WinInstallDir = " -DWinInstallDir C:/ti/" + getZipFilename(archivefilename,true);
        var AppName =" -DAppName " + Pkg.name;
        var linuxInstaller=" -DLinuxInstaller "+ linuxInstallname; 
        var winInstaller=" -DWinInstaller "+ winInstallname; 
      
        Pkg.makeEpilogue += "\all :" + linuxInstallname + " " + winInstallname;  
        Pkg.makeEpilogue += "\n" + linuxInstallname + " " + winInstallname + ": " + ziptarget;
        Pkg.makeEpilogue += "\n\t @echo -------------------------------------------------------\n";
        Pkg.makeEpilogue += "\t @echo Creating the Install\n";
        Pkg.makeEpilogue += "\t @echo -------------------------------------------------------\n";
        Pkg.makeEpilogue += "\t -$(MKDIR) tmp\n";           
        Pkg.makeEpilogue += "\t unzip -uo -qq " + ziptarget + " -d tmp \n";
        /* Check if package specific MPI file exists */
        if(xdc.findFile("./install/" + bundleid + ".mpi"))
        {
         var mpiName=bundleid + ".mpi";
         Pkg.makeEpilogue += "\t $(CP) -f " + xdc.findFile("./install/" + bundleid + ".mpi").replace(/\\/g,"/")+" .\n";
        }
        else {
         var mpiName="MAS-Install.mpi";
         var tplt = xdc.loadTemplate('ti/mas/swtools/MAS-Install.mpi.xdt');
     switch(ext)
     {
        case "c64Px":
          var installstring="C64x+";
          break;
        case "c64Px_coff":
          var installstring="C64x+ COFF";
          break;
        case "c64Px_elf":
          var installstring="C64x+ ELF";
          break;
        case "c674x":
          var installstring="C674x";
          break;
        case "c66x":
          var installstring="C66x";
          break;
       case "c66x_coff":
          var installstring="C66x COFF";
          break;
        case "c66x_elf":
          var installstring="C66x ELF";
          break;
        case "all": 
          var installstring="";
          break;
        default:
          var installstring=getTargParams(targs[0]).string;        
     }

         tplt.genFile (mpiName, Pkg, [bundlename.toString().toUpperCase(),installstring,true,license]);
        }
        Pkg.makeEpilogue += "\t@echo installjammer " + AppName +linuxInstaller+winInstaller+ InstallJammerVersion + PackageBaseDir + WinInstallDir + 
                          " --output-dir . --build " + mpiName+"\n";
        Pkg.makeEpilogue += "\tinstalljammer " + AppName+linuxInstaller+winInstaller+ InstallJammerVersion + PackageBaseDir + WinInstallDir + 
                          " --output-dir . --build " + mpiName + "\n";
        Pkg.makeEpilogue += "\t-$(RM) " + mpiName + "\n";
        Pkg.makeEpilogue += "\t-$(RMDIR) tmp\n"; 
        Pkg.makeEpilogue += "\t-$(RM) build.log\n";
        Pkg.makeEpilogue += "\t-$(RMDIR) /S /Q build\n"; 
        Pkg.makeEpilogue += "clean::\n";
        Pkg.makeEpilogue += "\t $(RM) *.exe\n";
        Pkg.makeEpilogue += "\t $(RM) *.bin\n";      
      }     
    }       
  } 
  else { /* Non-package.xml or Single component bundle release */
    /* Create the default package.xdc */
    var tplt = xdc.loadTemplate('ti/mas/swtools/bundlepackagexdc.xdt');
    tplt.genFile(bundlename+'/package.xdc', Pkg,[bundlename]);

    if (xdc.findFile("./docs/bundle/doxygen/release.h.xdt")) {
      var reltplt = Pkg.name.replace(/\./g,"/")+"/docs/bundle/doxygen/release.h.xdt";
      var tplt    = xdc.loadTemplate(reltplt);
      releaseString ="./packages/" + searchReleasenotes(Pkg.name);
      tplt.genFile('docs/bundle/doxygen/release.h',Package,[releaseString,ext]);
    }
    
    /* Archive file name of the generated package */
    var ziptarget = getZipFilename(archivefilename,true)+".zip";
    
      /* Add to make file */
    Pkg.makeEpilogue += "\all :"+ ziptarget;  
    Pkg.makeEpilogue += "\n" +ziptarget+ ": "+bundlename+"/package.bld" ;

    /* Command to create bundle package for non kernel component */
  if(bundletype != "kernel")
  {
    var cmd = 'xdc XDCARGS="'+xdcargs_targ +" "+delivery_type+'" release -PD '+ bundlename+'\n';
    Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
    Pkg.makeEpilogue += "\n\t"+cmd;
    cmd='xdc XDCARGS="" releasenotes -P '+bundlename+'\n';
    Pkg.makeEpilogue += "\n\t-@ echo Generating Release Notes ...";  
    Pkg.makeEpilogue += "\n\t"+cmd;
    cmd='xdc clean -P '+bundlename+'\n';
    Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
    Pkg.makeEpilogue += "\n\t"+cmd;
    var cmd = 'xdc XDCARGS="'+xdcargs_targ+" "+delivery_type+'" release -P '+ bundlename+'\n';
    Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
    Pkg.makeEpilogue += "\n\t"+cmd;    
    Pkg.makeEpilogue += "\n\t $(CP) "+bundlename+"/$@ $@\n\n"; 
    Pkg.makeEpilogue += "\nclean::\n\t-$(RMDIR) " + bundlename + "\n";     
  }
  else /* Command to create bundle package for kernel component */
  {
      var cmd = 'xdc XDCARGS="'+xdcargs_targ +" "+delivery_type+' kernel" release -PD '+ bundlename+'\n';
      Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
      Pkg.makeEpilogue += "\n\t"+cmd;
      cmd='xdc XDCARGS="" releasenotes -P '+bundlename+'\n';
      Pkg.makeEpilogue += "\n\t-@ echo Generating Release Notes ...";  
      Pkg.makeEpilogue += "\n\t"+cmd;
      cmd='xdc clean -P '+bundlename+'\n';
      Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
      Pkg.makeEpilogue += "\n\t"+cmd;
/*      var cmd = 'xdc XDCARGS="'+xdcargs_targ+' setPostBuildStep" -PR '+ bundlename+'/packages\n';*/
      var temp = xdc.findFile(".")+"/"+bundlename+"/packages";
      temp = temp.toString().replace(/\\/g,"/");
      var cmd = 'xdc XDCARGS="'+xdcargs_targ+' setPostBuildStep" '+bundlename.toUpperCase()+'_INSTALL_DIR='+temp+' -PR '+ bundlename+'/packages\n';
      Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
      Pkg.makeEpilogue += "\n\t"+cmd;    
      if(xdc.findFile("./examples"))
        {
            if(xdc.findFile("./examples/example.xs"))
            {
              cmd='xs -f ./examples/example.xs "' +getTargParams(targs[0]).targstring +'" ' + bundlename+"\n" ;
              Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
              Pkg.makeEpilogue += "\n\t"+cmd;                    
            }
            
            cmd='xdc XDCARGS="all" -PR .//'+bundlename+'//examples\n';
            Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
            Pkg.makeEpilogue += "\n\t"+cmd;        
        }           
      var cmd = 'xdc XDCARGS="'+xdcargs_targ+" "+delivery_type+' kernel" release -P '+ bundlename+'\n';
      Pkg.makeEpilogue += "\n\t-@ echo "+cmd;  
      Pkg.makeEpilogue += "\n\t"+cmd;    
      Pkg.makeEpilogue += "\n\t$(CP) "+bundlename+"/$@ $@";  
      Pkg.makeEpilogue += "\n\t$(RMDIR) "+bundlename+"\n\n";  

   }    
    
    if (install == true) {
        linuxInstallname=archivefilename+getVersionString()+"_Linux.bin";
        winInstallname=archivefilename+getVersionString()+"_Win32.exe" ;
        var InstallJammerVersion = " -DVersion " + getVersionDisplayString();
        var PackageBaseDir = " -DPackageBaseDir " + java.io.File(".//").getPath() + "/tmp/" + bundlename;
        var WinInstallDir = " -DWinInstallDir C:/ti/" + getZipFilename(archivefilename,true);
        var AppName =" -DAppName " + Pkg.name;
        var linuxInstaller=" -DLinuxInstaller "+ linuxInstallname; 
        var winInstaller=" -DWinInstaller "+ winInstallname; 
      
        Pkg.makeEpilogue += "\all :" + linuxInstallname + " " + winInstallname;  
        Pkg.makeEpilogue += "\n" + linuxInstallname + " " + winInstallname + ": " + ziptarget;
        Pkg.makeEpilogue += "\n\t @echo -------------------------------------------------------\n";
        Pkg.makeEpilogue += "\t @echo Creating the Install\n";
        Pkg.makeEpilogue += "\t @echo -------------------------------------------------------\n";
        Pkg.makeEpilogue += "\t -$(MKDIR) tmp\n";           
        Pkg.makeEpilogue += "\t unzip -uo -qq " + ziptarget + " -d tmp \n";
        /* Check if package specific MPI file exists */
        if(xdc.findFile("./install/" + bundlename + ".mpi"))
        {
         var mpiName=bundlename + ".mpi";
         Pkg.makeEpilogue += "\t $(CP) -f " + xdc.findFile("./install/" + bundlename + ".mpi").replace(/\\/g,"/")+" .\n";
        }
        else {
         var mpiName="MAS-Install.mpi";
         var tplt = xdc.loadTemplate('ti/mas/swtools/MAS-Install.mpi.xdt');
     if(bundletype != "kernel")
     {
       var unzip = true;
       var licensestring ="";
       var licensefile;
       /* Get the license string from the component folder */
       if (xdc.findFile("./install/LICENSE.txt"))
         {
             licensefile = "./install/LICENSE.txt";
         }
       else if(!xdc.findFile("./install/Software_License_Agreement.pdf"))
       {
         licensefile = xdc.findFile("ti/mas/swtools/LICENSE.txt").replace(/\\/g,"/");
       }
       else
       {
         print("Software_License_Agreement.pdf specified but the LICENSE.txt not specified");
       java.lang.System.exit(1);
       }
           var fileModule = xdc.module('xdc.services.io.File');
           var openedFile = fileModule.open(licensefile, "r");
           var readLine;
       while((readLine=openedFile.readLine()) != null)
           {
         licensestring+=readLine+"\n";
       }
       
       /* This specifies the file that will be shown after installation */
       if(xdc.findFile("./install/Software_License_Agreement.pdf"))
       {
        licensefile="Software_License_Agreement.pdf";
       }  
       else
       {
        licensefile="LICENSE.txt"; 
       }
     }
         else
     {
       var unzip = false;
       license = false;
     }

     switch(ext)
     {
        case "c64Px":
          var installstring="C64x+";
          break;
        case "c64Px_coff":
          var installstring="C64x+ COFF";
          break;
        case "c64Px_elf":
          var installstring="C64x+ ELF";
          break;
        case "c674x":
          var installstring="C674x";
          break;
        case "c66x":
          var installstring="C66x";
          break;
       case "c66x_coff":
          var installstring="C66x COFF";
          break;
        case "c66x_elf":
          var installstring="C66x ELF";
          break;
        case "all": 
          var installstring="";
          break;
         default:
            var installstring=getTargParams(targs[0]).string;        
     }
         tplt.genFile (mpiName, Pkg, [bundlename.toString().toUpperCase(),installstring,unzip,license,licensestring,licensefile]);
         
        }
        Pkg.makeEpilogue += "\t@echo installjammer " + AppName +linuxInstaller+winInstaller+ InstallJammerVersion + PackageBaseDir + WinInstallDir + 
                          " --output-dir . --build " + mpiName+"\n";
        Pkg.makeEpilogue += "\tinstalljammer " + AppName+linuxInstaller+winInstaller+ InstallJammerVersion + PackageBaseDir + WinInstallDir + 
                          " --output-dir . --build " + mpiName + "\n";
        Pkg.makeEpilogue += "\t-$(RM) " + mpiName + "\n";
        Pkg.makeEpilogue += "\t-$(RMDIR) tmp\n"; 
        Pkg.makeEpilogue += "\t-$(RM) build.log\n";
        Pkg.makeEpilogue += "\t-$(RMDIR) build\n"; 

        Pkg.makeEpilogue += "\n\nclean::\n";
        Pkg.makeEpilogue += "\t $(RM) *.exe\n";
        Pkg.makeEpilogue += "\t $(RM) *.bin\n";      
      }         
  }
  /* Clean generated file */
  if(install == true)
  { 
    generatedFiles.push(linuxInstallname);
  generatedFiles.push(winInstallname);

  }

  /* Copy bundle documents under bundle/docs folder */    
  print("Copying "+bundleMakeDoc+" to Bundle");
  copy.File(bundleMakeDoc,bundlename); 
  var repositDir = new java.io.File(bundlename+"/docs");
  if (!(repositDir.exists() && repositDir.isDirectory())) {
    repositDir.mkdirs();
  }
  
  copy.Directory("./docs/bundle", "./"+ bundlename + "/docs"); 
  print ("Copying ./docs/bundle/* ./"+ bundlename + "/docs ...\n");

  if (xdc.findFile("./docs/"+bundlename)) {
    copy.Directory("./docs/"+bundlename, "./"+ bundlename); 
    print("Copying ./docs/"+bundlename+"/* ./"+ bundlename +" ...\n");
  }  

  if(license != false){
    /* Copy LICENSE.txt if present */    
    if (xdc.findFile("./install/Software_License_Agreement.pdf"))
    {
    copy.File("./install/Software_License_Agreement.pdf","./"+ bundlename); 
    print("Copying ./install/Software_License_Agreement.pdf ./"+ bundlename +"/Software_License_Agreement.pdf ...\n");
    }
    else if (xdc.findFile("./install/LICENSE.txt")) {
    copy.File("./install/LICENSE.txt", "./"+ bundlename); 
    print("Copying ./install/LICENSE.txt ./"+ bundlename +"/LICENSE.txt ...\n");
    }
    else
    {
    copy.File(xdc.findFile("ti/mas/swtools/LICENSE.txt").replace(/\\/g,"/"), "./"+ bundlename); 
    print("Copying ./swtools/LICENSE.txt ./"+ bundlename +"/LICENSE.txt ...\n");    
    }
  }

  /* Copy bundle eclipse directory if present */    
  if (xdc.findFile("./eclipse")) {
    /* Search for templates */
    eclpeTemplate="./eclipse/"+bundlename+".xml.xdt";
    eclpeTOCTemplate="./eclipse/"+bundlename+"_toc.xml.xdt";
    if(xdc.findFile(eclpeTemplate))
    {
      var eclpeXml="./eclipse/"+bundlename+".xml";
      var tplt = xdc.loadTemplate(eclpeTemplate);
      if(ext == "")
      {
         var targParams = getTargParams(targs[0]);
         ext = targParams.ext;  
      }     
      tplt.genFile (eclpeXml, Pkg, [version[0],version[1],version[2],installstring,ext,version[3]]);
      generatedFiles.push(eclpeXml);
    }
    if(xdc.findFile(eclpeTOCTemplate))
    {
      var releasenotes=bundlename+getVersionString()+"_release_notes.html";
      var eclpeTOCXml="./eclipse/"+bundlename+"_toc.xml";
      var tplt = xdc.loadTemplate(eclpeTOCTemplate);
      tplt.genFile (eclpeTOCXml, Pkg, [installstring,releasenotes]);
      generatedFiles.push(eclpeTOCXml);
    }
    copy.Directory("./eclipse", "./"+ bundlename + "/eclipse"); 
    print ("Copying ./eclipse ./"+ bundlename + "/eclipse ...\n");
    
  }  
  
  if (xdc.findFile("./examples")) {
  var repositDir = new java.io.File(bundlename+"/examples");
  if (!(repositDir.exists() && repositDir.isDirectory())) {
    repositDir.mkdirs();
  }
  }
  
  
      
  /* Command to create bundle package */
  var cmd='xdc XDCARGS="'+targParams.target +'" gendocs -P '+bundlename+'\n';

  /* Add to make file */
  Pkg.makeEpilogue += "\ngendocs : genbundledocs\n";  
  Pkg.makeEpilogue += "\ngenbundledocs:\n\t-@ echo "+cmd;  
  Pkg.makeEpilogue += "\n\t"+cmd;
  
  /* Command to clean bundle package */
  var cmd='xdc clean -PD '+bundlename+'\n';
  /* Add to make file */
  Pkg.makePrologue += "\nclean ::";  
  Pkg.makePrologue += "\n\t-@"+cmd;  
}
/*
 *  @brief This function Returns the Archive file name to be generated.
 *
 *
 */
 function getVersionString()
 {
   var versionString="";
   if(pkgStdVer=="1.0")
     {
         
         for (var i = 0; i < version.length; i++) {
           versionString = versionString + "_" + version[i];
          }
     }
      else if(pkgStdVer=="2.0")
      {
       for (var i = 0; i < 4; i++) {
           versionString = versionString + "_" + version[i];
          }
       var quality;
       var btype;
       switch(version[4])
       {
        case 0:
               quality="_prealpha";
               break;
        case 1:
               quality="_alpha";
               break; 
        case 2:
               quality="_beta";
               break; 
        case 3:
               quality="";
               break; 
        default:
               print("Error: Quality is wrongly specified in Package.version");
               java.lang.System.exit(1);
       }
      switch(version[5])
       {
        case 0:
               btype="";
               break;
        case 1:
               btype="_eng";
               break; 
        case 2:
               btype="_dbg";
               break; 
        default:
               print("Error: Build type is wrongly specified in Package.version");
               java.lang.System.exit(1);
               break;                                              
       }       
      versionString+=quality+btype;
   }
  return versionString;   
   }
   
function getVersionDisplayString()
 {
   var versionString=version[0];
   if(pkgStdVer=="1.0")
     {
         
         for (var i = 1; i < version.length; i++) {
           versionString = versionString + "." + version[i];
          }
     }
      else if(pkgStdVer=="2.0")
      {
       for (var i = 1; i < 4; i++) {
           versionString = versionString + "." + version[i];
          }
       var quality;
       var btype;
       switch(version[4])
       {
        case 0:
               quality=" prealpha";
               break;
        case 1:
               quality=" alpha";
               break; 
        case 2:
               quality=" beta";
               break; 
        case 3:
               quality="";
               break; 
        default:
               print("Error: Quality is wrongly specified in Package.version");
               java.lang.System.exit(1);
       }
      switch(version[5])
       {
        case 0:
               btype="";
               break;
        case 1:
               btype=" eng";
               break; 
        case 2:
               btype=" dbg";
               break; 
        default:
               print("Error: Build type is wrongly specified in Package.version");
               java.lang.System.exit(1);
               break;                                              
       }       
      versionString+=quality+btype;
   }
  return versionString;   
   }   

function getZipFilename(pkgName,PkgisBundle)
{
  var rel_name = "";
  pkgName=String(pkgName);
  if (PkgisBundle == true) {
    rel_name = rel_name + pkgName + getVersionString();
    return rel_name;
  }

  var isTestPackage = false;
  var temp = pkgName.split(".");
  if (temp[temp.length - 1] == "test" ) {
    isTestPackage = true;
    pkgName=pkgName.replace(".test","");
  }

  /* Add package name */
  rel_name = pkgName.replace(/\./g,"_");
  /* Add delivery type */
  var rel_name = rel_name+"_" + delivery_type;

  /* Check if all the targets were build */
  if(ext == "")
  {
    var targParams = getTargParams(targs[0]);
    ext = targParams.ext; 
    if(c55x_cpu_version=="3.3")
     ext+="_cpuv3.3"; 
  }
  
  /* Check if the package is target independent */
  if (targ_indp == false) {
    rel_name = rel_name + "_" + ext;
  }
  
  if (!isTestPackage) {
    rel_name = rel_name + getVersionString();
  }
  else {
    /* Get version from the parent package */
    var paramarr = pkgName;
    var verModNotFound = 0;
    try {
      var versionMod = xdc.module(paramarr + ".Version");
    } 
    catch(e){
      /* because module throws error if module is not found. */
      verModNotFound = 1;
      print("The main package of the test package could not be loaded\n"+e);
    }
    
    if (versionMod.PKGSTD == 1) {
      versionString=versionMod.MAJOR+"_"+versionMod.MINOR+"_"+versionMod.XVERTICAL+"_"+versionMod.PATCH;
    }
    else if (versionMod.PKGSTD == 2) {
      versionString=versionMod.MAJOR+"_"+versionMod.MINOR+"_"+versionMod.PATCH+"_"+versionMod.BUILD;
    }
    rel_name = rel_name + "_" + versionString + "_test";
  }
  return rel_name;
} 

function searchReleasenotes(pkgname)
{
 pkgname=pkgname.toString().replace(/\./g,"/");
 var fullpath=xdc.findFile(pkgname);
 var dir = new java.io.File(fullpath);
  if(!dir.isDirectory())
    return;
  var list = dir.list();
   
  for each(var file  in list)
  {
    var srcFile=String(file);
    var dot = srcFile.lastIndexOf(".");
    var extension = srcFile.substr(dot,srcFile.length);     
    if(extension==".html")
      return pkgname+"/"+srcFile;
  } 
return;
}

function createTestProjects()
{

    if(xdc.om['xdc.bld'].BuildEnvironment.hostOSName != "Windows")
     return;

    var projectDir = new java.io.File("./package/projects");
    if(projectDir.exists())
     {
       projectDir["delete"]();
     projectDir.mkdirs();
     }
   else
   {
     projectDir.mkdirs();
   }
   fileArray.push("./package/projects");

 
  for each(var project in ccsProjects)
    {
      var createxml=false;
      for(var k=0;k<targs.length;k++)
      {
          var targParams=getTargParams(targs[k]);
          if(targParams.target.toString().match(project.targets))
          {
            createxml=true;
            break;
          }
      }
    if(createxml==true)
    {
        var file = new java.io.File("./package/projects/"+project.pjtName+"_"+project.targets+".xml");
        var indent = "    ";
        file["delete"]();


        var out = new java.io.BufferedWriter(new java.io.FileWriter(file));

        out.write('<?xml version="1.0" encoding="UTF-8"?>\n');
        out.write(' <Project>\n');

        /* output Project infomation */
        out.write(indent + '<params>\n');

        /* Output Project Parameters */
        out.write(indent + '    <name>'+project.pjtName+'</name>\n');
        out.write(indent + '    <location>'+project.location+'</location>\n');
        out.write(indent + '    <target>'+project.targets+'</target>\n');
        out.write(indent + '    <buildArtifact>'+project.buildArtifact+'</buildArtifact>\n');
        for each(var file in project.srcFiles)
        {
           out.write(indent + '    <files name="'+file+'"/>\n');
        }
        if(project.cFlags != "")
        {
          out.write(indent + '    <cFlags>'+project.cFlags+'</cFlags>\n');
        }
        else
        {
          out.write(indent + '    <cFlags>"default-speed"</cFlags>\n');
        }
        out.write(indent + '</params>\n');
        out.write(' </Project>\n');
        out.close();
     }
  }
  switch(String(java.lang.System.getenv("CCSVERSION")))
  {
      case "CCSV4.2":
       createbuildtestpjts("CCSV4.2");
       break;
      case "CCSV5":
       createbuildtestpjts("CCSV5");
       break;
      default:
       print("Error: CCSVERSION "+java.lang.System.getenv("CCSVERSION")+" specified in ENV is not supported");
       java.lang.System.exit(1);     
       
  }
    
  
  


}

function createProjects()
{

     var projectDir = new java.io.File("./package/projects");
     if(projectDir.exists())
     {
       projectDir["delete"]();
     projectDir.mkdirs();
     }
   else
   {
     projectDir.mkdirs();
   }
   fileArray.push("./package/projects");

 
  for each(var project in ccsProjects)
    {
      var createxml=false;
      for(var k=0;k<targs.length;k++)
       {
          var targParams=getTargParams(targs[k]);
          if(targParams.target.toString().match(project.targets))
        {
          createxml=true;
          break;
        }
      }
    if(createxml==true)
    {
        var file = new java.io.File("./package/projects/"+project.pjtName+"_"+project.targets+".xml");
          var indent = "    ";
        file["delete"]();


          var out = new java.io.BufferedWriter(new java.io.FileWriter(file));

          out.write('<?xml version="1.0" encoding="UTF-8"?>\n');
          out.write(' <Project>\n');

          /* output Project infomation */
          out.write(indent + '<params>\n');

          /* Output Project Parameters */
          out.write(indent + '    <name>'+project.pjtName+'</name>\n');
          out.write(indent + '    <location>'+project.location+'</location>\n');
        out.write(indent + '    <target>'+project.targets+'</target>\n');
        out.write(indent + '    <buildArtifact>'+project.buildArtifact+'</buildArtifact>\n');
        for each(var file in project.srcFiles)
        {
           out.write(indent + '    <files name="'+file+'"/>\n');
        }
        if(project.cFlags != "")
      {
        out.write(indent + '    <cFlags>'+project.cFlags+'</cFlags>\n');
      }
      else
      {
        out.write(indent + '    <cFlags>"default-speed"</cFlags>\n');
      }
          out.write(indent + '</params>\n');
        out.write(' </Project>\n');
        out.close();
     }
  }
  if(generateBundle==true)
      return;
   
     if(kernel == true)
  {
    switch(String(java.lang.System.getenv("CCSVERSION")))
    {
      case "CCSV4.2":
    case "CCSV5":
       createbuildccspjts("archive_only",String(java.lang.System.getenv("CCSVERSION")));
       break;
        default:
       print("Error: Invalid CCSVERSION "+ +" specified in ENV");
       java.lang.System.exit(1);     
       
    }
    
  }   
    else
  {
    switch(String(java.lang.System.getenv("CCSVERSION")))
    {
      case "CCSV4.2":
    case "CCSV5":
       createbuildccspjts("build_pjts",String(java.lang.System.getenv("CCSVERSION")));
       break;
        default:
       print("Error: Invalid CCSVERSION "+ +" specified in ENV");
       java.lang.System.exit(1);     
       
    }
    
  
  }
  if(setPostBuildStep == true)
  {
    createknlhdr();
  }

   
}

function createknlhdr()
{
        /* Create Kernel API header file */ 
    var targetpath = xdc.findFile("../inc");
        var temp = Pkg.name.split(".");
        var api = temp[temp.length-1]+".h"; 
    var fileModule = xdc.module('xdc.services.io.File');
    try{
        var apiHeader = fileModule.open(targetpath+"/"+api, "w");
     } catch (ex)
     {
      print( targetpath+"/"+ + " cannot be written to. Please check Writing Permissions.");
      java.lang.System.exit(1);
     }     
  
       /* Header Information */   
     apiHeader.writeLine("/* ========================================================================== */");
     apiHeader.writeLine("/**");        
     apiHeader.writeLine("*  @file   "+api);
     apiHeader.writeLine("*");
     apiHeader.writeLine("*  path    "+temp[temp.length-1]+"/inc");
     apiHeader.writeLine("*");
     apiHeader.writeLine("*  @brief  "+temp[temp.length-1]+" API File" );
     apiHeader.writeLine("*");
     apiHeader.writeLine("*  ============================================================================");
     apiHeader.writeLine("*  Copyright (c) Texas Instruments Incorporated 2011");
     apiHeader.writeLine("*");
     apiHeader.writeLine("*  ============================================================================");
     apiHeader.writeLine("*/");  

     var projectDir = new java.io.File("./package/projects");
     var projectXml = projectDir.list();
  
     for each(var xml in projectXml)
     {
       xml=String(xml);
       var dot = xml.lastIndexOf(".");
       var extension = xml.substr(dot,xml.length); 
       if(extension == ".xml")
       {
          var project=xdc.loadXML("./package/projects/"+xml);
          var headerfile = project["params"].name+".h";
          if(xdc.findFile("src/"+project["params"].name+"/"+headerfile))
          {
            apiHeader.writeLine("#include <"+Pkg.name.replace(/\./g,"/")+"/src/"+project["params"].name+"/"+headerfile+">");
          }
       }
     }
}

var component_install_dir;
var install_dir_string

function createMakeKnl(makefile)
{
    /* Create the main make file for Kernel packages */
    var fileModule = xdc.module('xdc.services.io.File');
    if(makefile==undefined)
    {
        try{
            makefile = fileModule.open("makefile", "w");
            } catch (ex)
            {
              print("makefile cannot be written to. Please check Writing Permissions.");
              java.lang.System.exit(1);
            }   
        /* Add to Archive list */
        if(delivery_type=="src")
        {
            fileArray.push("makefile");
        }
        generatedFiles.push("makefile");
        includeMake("makefile");     

        makefile.writeLine("#*******************************************************************************");
        makefile.writeLine("#* FILE PURPOSE: Top level makefile for Creating Kernel CCS Projects");
        makefile.writeLine("#*******************************************************************************");
        makefile.writeLine("#* FILE NAME: makefile");
        makefile.writeLine("#*");
        makefile.writeLine("#* DESCRIPTION: Defines Compiler tools paths, CCS path and rule to create and build CCS projects ");
        makefile.writeLine("#*");
        makefile.writeLine("#*");
        makefile.writeLine("#* This is an auto-generated file             ");
        makefile.writeLine("#*******************************************************************************");
        makefile.writeLine("#*");
        makefile.writeLine("# (Mandatory) Specify where various tools are installed.");

        var file = xdc.module('xdc.services.io.File');
    
        var cgtver = java.lang.System.getenv("CCSCGTVER")
        if(cgtver)
        {
          makefile.writeLine("\n# CCSCGTVER   - Code Generation version to be used for building CCS project");    
          makefile.writeLine("export CCSCGTVER ?= "+cgtver.toString().replace("\\","\/"));
        }
    
        /*var ccsToolsDir =  java.lang.System.getenv("CCS_INSTALL_DIR");
        if(ccsToolsDir)
        {
          makefile.writeLine("\n# CCS_INSTALL_DIR   - TI Code Composer Studio install directory");    
          makefile.writeLine("export CCS_INSTALL_DIR ?= "+ ccsToolsDir.toString().replace("\\","\/"));
      
        }*/
    makefile.writeLine("\n# CCS_INSTALL_DIR   - TI Code Composer Studio install directory");  
    makefile.writeLine("export CCSV4_INSTALL_DIR ?= C:/Program Files/Texas Instruments/ccsv4" );
    makefile.writeLine("export CCSV5_INSTALL_DIR ?= C:/Program Files/Texas Instruments/ccsv5" );

    
    makefile.writeLine("\nifneq ($(findstring $(CCSVERSION), CCSV4.2),)");
    makefile.writeLine("\texport CCS_INSTALL_DIR ?= $(CCSV4_INSTALL_DIR)" );
    makefile.writeLine("\texport ECLIPSE_CMD ?= java -jar \"$(CCS_INSTALL_DIR)/eclipse/startup.jar\"" );
    makefile.writeLine("endif");
    makefile.writeLine("\nifneq ($(findstring $(CCSVERSION), CCSV5),)");
    makefile.writeLine("\texport CCS_INSTALL_DIR ?= $(CCSV5_INSTALL_DIR)" );
    makefile.writeLine("\texport ECLIPSE_CMD ?= \"$(CCS_INSTALL_DIR)/eclipse/eclipsec.exe\" -noSplash" );
    makefile.writeLine("endif");


        if(bundlename != undefined)
        {
            makefile.writeLine("\n# "+bundlename.toUpperCase()+"_INSTALL_DIR   - "+bundlename.toUpperCase()+" install directory");    
            if(ext == "")
            {
              var targParams = getTargParams(targs[0]);
              ext = targParams.ext;  
            }     
            var archivefilename = bundlename+"_"+ext;
            component_install_dir = "C:/ti/"+getZipFilename(archivefilename,true)
            install_dir_string = bundlename.toUpperCase()+"_INSTALL_DIR";
            makefile.writeLine("export "+install_dir_string+" ?= "+component_install_dir.toString().replace("\\","\/")+"/packages");

        }
   
        makefile.writeLine("\n# Common Macros used in make");  
        makefile.writeLine("\nifndef RMDIR");         
        makefile.writeLine("export RMDIR = DEL /Q /F /S");
        makefile.writeLine("endif");    
    
    
    makefile.writeLine("\nifneq ($(findstring $(SHELL), sh.exe),)");
    makefile.writeLine("\tquote = \"");
    makefile.writeLine("else");
    makefile.writeLine("\tquote = '");
    makefile.writeLine("endif");    
    
        makefile.writeLine("\n# PHONY Targets");                
        makefile.writeLine(".PHONY: all clean cleanall ");    
      
        makefile.writeLine("\n# FORCE Targets");                
        makefile.writeLine("FORCE: ");          
      
        makefile.writeLine("\n# all rule");                
        makefile.writeLine("all: .executables");           
        makefile.writeLine(".executables: .projects");
        makefile.writeLine(".projects:");
        makefile.writeLine(".xdcenv.mak:");
      
     }
    else
    {
     try{
          makefile = fileModule.open("makefile", "a");
        } catch (ex)
        {
           print("makefile cannot be written to. Please check Writing Permissions.");
           java.lang.System.exit(1);
        }  
    
    }

 return makefile;
}


function createbuildccspjts(action, ccsversion)
{
  var projectDir = new java.io.File("./package/projects");
  var projectXml = projectDir.list();
  makefilelocal = createMakeKnl(makefilelocal);

  
  eclipseCmd="$(ECLIPSE_CMD)";
  if(ccsversion == "CCSV4.2" )
  {
    var ccs_install_dir=java.lang.System.getenv("CCSV4_INSTALL_DIR");
    /* Check if CCS V4 is installed */
    if(!xdc.findFile(ccs_install_dir+"/eclipse/startup.jar"))
    {
      print("Error: CCS V4 could not be found at "+ccs_install_dir);
      java.lang.System.exit(1);
    }
  var eclipseCmdpjt="java -jar \"$(CCSV4_INSTALL_DIR)/eclipse/startup.jar\"";
  
  }
  else if(ccsversion == "CCSV5" )
  {
    var ccs_install_dir=java.lang.System.getenv("CCSV5_INSTALL_DIR");
     /* Check if CCS V5 is installed */
    if(!xdc.findFile(ccs_install_dir+"/eclipse/eclipsec.exe"))
    {
      print("Error: CCS V5 could not be found at "+ccs_install_dir);
      java.lang.System.exit(1);
    }
  var eclipseCmdpjt="\"$(CCSV5_INSTALL_DIR)/eclipse/eclipsec.exe\" -noSplash"
  
  }
  else
  {
    print("ERROR: "+ccsversion +" is not supported ");
  }
  
  if (setPostBuildStep == true) {
    var basepath     = new java.io.File(".");
    var targetpath   = xdc.findFile("../lib");
    var targetpathv5 = xdc.findFile("../../"+bundlename);
    var relative     = _toRelative(basepath.getCanonicalPath(),targetpath);
    var Command;
    
    /* CCS V5 Project */
    Command  = "\"$(CCSV5_INSTALL_DIR)/eclipse/eclipsec.exe\" -noSplash" +" ";
    Command += " -data \"C:/Temp/workspace\"";
    Command += " -application com.ti.ccstudio.apps.projectCreate";
    Command += " -ccs.autoGenerateMakefiles false";
    Command += " -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";
    Command += " -ccs.buildCommandFlags CCSVERSION=${CCSVERSION}";  
    Command += " -ccs.name "+bundlename.toString().toUpperCase();
    Command += " -ccs.location "+relative;
    Command += " -ccs.linkFile EXT_ROOT__"+bundlename.toString().toUpperCase()+"/makefile";
    Command += " -ccs.overwrite keep";
    Command += " -ccs.buildFlags CCSVERSION=${CCSVERSION}";
    Command += " -ccs.definePathVariable EXT_ROOT__"+bundlename.toString().toUpperCase()+" "+basepath.getCanonicalPath().toString().replace("\\","/");  
    Command += " -ccs.defineBuildVariable PROJECT_ROOT_PARENT \'$${PROJECT_ROOT}/..' @scope project";
    Command += " -ccs.buildLocation \'$${PROJECT_ROOT_PARENT}/"+_toRelative(targetpathv5,basepath.getCanonicalPath())+"'";
    Pkg.makeEpilogue += "\nall: "+ bundlename.toString().toUpperCase()+"_CCSV5";
    Pkg.makeEpilogue += "\n"+bundlename.toString().toUpperCase()+"_CCSV5"+ ": .xdcenv.mak Package.bld Package.mak" ;
    Pkg.makeEpilogue += "\n\t"+Command;
    Pkg.makeEpilogue += "\n\techo EXT_ROOT__"+bundlename.toString().toUpperCase()+"="+_toRelative(targetpath,basepath.getCanonicalPath())+" > "+relative+"/macros.ini";
    Pkg.makeEpilogue += '\n\t-$(RMDIR) "C:/Temp/workspace"\n\n';

    /* CCS V4 Project */
    Command  = "java -jar \"$(CCSV4_INSTALL_DIR)/eclipse/startup.jar\"" +" ";
    Command += " -data \"C:/Temp/workspace\"";
    Command += " -application com.ti.ccstudio.apps.projectCreate_stdMake";  
    Command += " -ccs.name "+bundlename.toString().toUpperCase();
    Command += " -ccs.location "+relative;
    Command += " -ccs.linkFile EXT_ROOT__"+bundlename.toString().toUpperCase()+"/makefile";
    Command += " -ccs.overwrite keep";
    Command += " -ccs.buildFlags CCSVERSION=${CCSVERSION}";
    Command += " -ccs.definePathVariable EXT_ROOT__"+bundlename.toString().toUpperCase()+" "+basepath.getCanonicalPath().toString().replace("\\","/");  
    Command += " -ccs.buildLocation \'$${PROJECT_ROOT}/"+_toRelative(targetpath,basepath.getCanonicalPath())+"'";
    Pkg.makeEpilogue += "\nall: "+ bundlename.toString().toUpperCase()+"_CCSV4";
    Pkg.makeEpilogue += "\n"+bundlename.toString().toUpperCase()+"_CCSV4"+ ": .xdcenv.mak Package.bld Package.mak" ;
    Pkg.makeEpilogue += "\n\t"+Command;
    Pkg.makeEpilogue += '\n\t-$(RMDIR) "C:/Temp/workspace"\n\n';
  }
  
  for each(var xml in projectXml)
     {
       xml=String(xml);
       var dot = xml.lastIndexOf(".");
       var extension = xml.substr(dot,xml.length); 
     if(extension == ".xml")
     {
        var project=xdc.loadXML("./package/projects/"+xml);
      for each(var target in targs)
      {
            var targParams=getTargParams(target);
            if(targParams.target.toString().match(project["params"].target))
      {
        switch(target)
        {

           case C64P:
           var endianness = "little";      
           var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
           var outputFormat = "coff";   
           var cflags = "-mv64plus -k -mw";   
           var suffix = "LE_COFF";     
           break;
      
           case C64P_big_endian:
           var endianness = "big";      
           var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
           var outputFormat = "coff";   
           var cflags = "-mv64plus -k -mw";    
           var suffix = "BE_COFF";                    
           break;   

           case C64P_elf:
           var endianness = "little";      
           var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
           var outputFormat = "elf";   
           var cflags = "-mv64plus -k -mw";   
           var suffix = "LE_ELF";     
           break;

           case C674:
           var endianness = "little";      
           var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
           var outputFormat = "coff";   
           var cflags = "-mv6740 -k -mw";   
           var suffix = "LE_COFF";     
           break;
      
           case C674_elf:
           var endianness = "little";      
           var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
           var outputFormat = "elf";   
           var cflags = "-mv6740 -k -mw";   
           var suffix = "LE_ELF";     
           break;
      
           case C64P_big_endian_elf:
           var endianness = "big";      
           var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
           var outputFormat = "elf";   
           var cflags = "-mv64plus -k -mw";    
           var suffix = "BE_ELF";                    
           break;   

           case C66:
           var endianness = "little";      
           var device = "com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
           var outputFormat = "coff";   
           var cflags = "-mv6600 -k -mw";  
           var suffix = "LE_COFF";                      
           break;   
   
           case C66_big_endian:
           var endianness = "big";      
           var device = "com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";
           var outputFormat = "coff";   
           var cflags = "-mv6600 -k -mw";     
           var suffix = "BE_COFF";                                    
           break;   
   
           case C66_elf:
           var endianness = "little";      
           var device = "com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
           var outputFormat = "elf";   
           var cflags = "-mv6600 -k  -mw";  
           var suffix = "LE_ELF";                      
           break;   
   
           case C66_big_endian_elf:
           var endianness = "big";      
           var device = "com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";
           var outputFormat = "elf";   
           var cflags = "-mv6600 -k  -mw";     
           var suffix = "BE_ELF";                                    
           break;   

           default:
           return;
 
        } 
        var projectname=project["params"].name+"_"+project["params"].target.toUpperCase()+"_"+suffix;
        var objfile = project["params"].name+".obj";
        var headerfile = project["params"].name+".h"
        var projectlocation=project["params"].location+"/"+projectname; 
        var linkfile=project["params"].files.@name;
        var envPath = "EXT_ROOT__"+projectname.toUpperCase();
        var projectroot = project["params"].location;
              var cgtversion = java.lang.System.getenv("CCSCGTVER");
        if(cgtversion == undefined)    
        {
          print("Error: ENV CCSCGTVER not defined ");
        java.lang.System.exit(1);

        }
        cflags += " "+ project["params"].cFlags;

        
          
        /* Command to create CCS V4 Project */
        var Command = eclipseCmd+" ";
              Command += " -data \"C:/Temp/workspace\"";
              Command += " -application com.ti.ccstudio.apps.projectCreate";  
              Command += " -ccs.name "+projectname;
              Command += " -ccs.device "+device;
              Command += " -ccs.endianness "+endianness;
              Command += " -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable";

        var pkgroot="..";
        for (var i = Pkg.name.split('.').length; i > 1; i--) {
            pkgroot+="/..";
        } 
        var includepath=" -i"+pkgroot+"/../"+_toRelative(projectlocation,".");
        var includepathArray= new Array();
        includepathArray.push(
                               {
                     path: "./",
                     macro: envPath,
                     canpath: (java.io.File(projectroot)).getCanonicalPath()
                   }
                             );
       for each( var file in linkfile)
       {  
          if(xdc.findFile(file))
          {
              var envmacro="";
              var pathexists=false;
              var dstpath = java.io.File(file).getParentFile();
              if(dstpath == null)
              {
                dstpath=".";
              }
              
              var relative=_toRelative(projectroot,dstpath);
          var temp = file.toString().replace(/\\/g,"/");
          fileArray.push(temp);
          temp=temp.split("/");
          
          for each( var element in includepathArray)
          {
             if(element.path == relative)
           {
             pathexists=true;
             envmacro=element.macro;
             break;
           }
          }
          if(pathexists == false)
          {
            envmacro="EXT_ROOT__"+projectname.toUpperCase()+"_"+dstpath.toString().toUpperCase();
            envmacro=envmacro.toString().replace(/\./g,"");
            envmacro=envmacro.toString().replace(/\\/g,"");
            envmacro=envmacro.toString().replace(/\//g,"");

            includepathArray.push(
                                 {
                                   path: relative,
                                   macro: envmacro,
                                   canpath: dstpath.getCanonicalPath() 
                                 }
                     );
                  }
          var dot = String(temp[temp.length-1]).lastIndexOf(".");
                  var extension = String(temp[temp.length-1]).substr(dot,String(temp[temp.length-1]).length); 
               if(extension == ".s" || extension == ".sa")
               {
                 objfile = String(temp[temp.length-1]).substr(0,dot) +".obj";
               }
          if(extension != ".h")
          {
             Command +=" -ccs.linkFile "+ envmacro+"/"+temp[temp.length-1];
                  }  
              }
        else
        {
          print("Error : "+file +" not found");
          java.lang.System.exit(1);

        }
              }
           Command += " -ccs.setCompilerOptions \""+cflags+" -g "+includepath+"\" @configurations Debug";
           Command += " -ccs.setCompilerOptions \""+cflags+" -o3 --symdebug:none " + includepath+"\" @configurations Release";
           Command += " -ccs.location "+projectlocation;
           Command += " -ccs.overwrite full";
           Command += " -ccs.rts libc.a";
           Command += " -ccs.cgtVersion $(CCSCGTVER)";
           Command += " -ccs.outputFormat "+outputFormat;
         /* Create macros for portable CCS V4 Projects */
       for each(var element in includepathArray)
       {
         var incpath = String(element.canpath).replace(/\\/g,"/");
         if(bundlename != undefined)
         {
             var env   = java.lang.System.getenv();
             var keys  = env.keySet().toArray();
             var key;
             var stat={};
             var env_j=[];
             for (var i = 0; i < keys.length; i++) {
               key = String(keys[i]);
               if(key.match(install_dir_string))
               {
                   var keyPath=String(env.get(key));
                   keyPath=keyPath.replace(/\\/g,"/");
                   var file = xdc.module('xdc.services.io.File');
                   keyPath=file.getDOSPath(keyPath);
                   if(incpath.toString().match(keyPath))
                   {
                       incpath=incpath.toString().replace(keyPath,"$("+key+")");
                       break;
                   }
               }
             }
         }
       
         Command += " -ccs.definePathVariable "+element.macro+" \""+incpath+"\"";  
       }
          
          /* Need a neat way to do this */
      if(setPostBuildStep == true)
      {
        var basepath = new java.io.File(projectroot+"/"+projectname+"/Release");
      var targetpath = xdc.findFile("../lib");
            var temp = Pkg.name.split(".");
            var libName = temp[temp.length-1];

            var relative=_toRelative(basepath.getCanonicalPath(),targetpath);
         
            Command += " -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq "+relative+"/"+libName+".a"+target.suffix+" "+objfile+"$(quote) @configurations Release";
        }

      if(action != "archive_only")
      {
          makefilelocal.writeLine("\n#############################################################");
          makefilelocal.writeLine("\n# Rule to Build Project "+ projectname);
          makefilelocal.writeLine("\n#############################################################");
          var outfile=projectlocation+"/Release/"+projectname+".out";
          if(setPostBuildStep == true) 
          {
            makefilelocal.writeLine("\nall: "+ outfile);
          }
          else
          {
            makefilelocal.writeLine("\n.executables: "+ outfile);
          }
          
          makefilelocal.writeLine("\n"+projectlocation+"/.project: .xdcenv.mak Package.bld Package.mak");
          makefilelocal.writeLine("\t"+Command);
          for each(var element in includepathArray)
          {
           makefilelocal.writeLine("\techo "+element.macro+"=../"+element.path+" >> "+projectlocation+"/macros.ini"); 
          }
          makefilelocal.writeLine("\t-$(RMDIR) \"C:/Temp/workspace\"");

          /* Command to import CCS V4 Projects */
          var Command2 = eclipseCmd+" ";
          Command2 +=" -data \"C:/Temp/workspace\"";
          Command2 +=" -application com.ti.ccstudio.apps.projectImport";
          Command2 +=" -ccs.projects "+projectname ;  

          var pjtloc = java.io.File(projectlocation).getCanonicalPath();
          pjtloc=String(pjtloc).replace(/\\/g,"/");
          if(bundlename != undefined)
          {
              var env   = java.lang.System.getenv();
              var keys  = env.keySet().toArray();
              var key;
              var stat={};
              var env_j=[];
              for (var i = 0; i < keys.length; i++) {
                key = String(keys[i]);
                if(key.match(install_dir_string))
                {
                    var keyPath=String(env.get(key));
                    keyPath=keyPath.replace(/\\/g,"/");
                    var file = xdc.module('xdc.services.io.File');
                    keyPath=file.getDOSPath(keyPath);
                    if(pjtloc.match(keyPath))
                    {
                        pjtloc=pjtloc.replace(keyPath,"$("+key+")");
                        break;
                    }
                }
              }
          }
          Command2 +=" -ccs.location \""+pjtloc+"\"";  

          /* Command to build CCS V4 Projects */
          var Command1 = eclipseCmd+" ";
          Command1 +=" -data \"C:/Temp/workspace\"";
          Command1 +=" -application com.ti.ccstudio.apps.projectBuild";
          Command1 +=" -ccs.projects "+projectname ;  
          Command1 +=" -ccs.configuration Release";
        
          for each( var file in linkfile)
          {
             makefilelocal.writeLine(outfile+": "+ file);
          }
          makefilelocal.writeLine(outfile+": "+ projectlocation+"/.project");
          makefilelocal.writeLine("\t-@ echo Importing Project "+projectname+" into workspace ...");  
          makefilelocal.writeLine("\t"+Command2);
          makefilelocal.writeLine("\t-@ echo Building Project "+projectname+" ...");  
          makefilelocal.writeLine("\t"+Command1);
          if(setPostBuildStep == true) 
          {
            makefilelocal.writeLine("\t-@ echo Cleaning Project "+projectname+" ..."); 
            makefilelocal.writeLine("\t-$(RMDIR) \""+projectlocation+"/Release\"\n");
            makefilelocal.writeLine("\t-$(RMDIR) \""+projectlocation+"/.settings\"\n");
          }
          makefilelocal.writeLine("\t-@ echo Project "+projectname+" Completed ...");  
          makefilelocal.writeLine("\t-@ echo ########################################");  
          makefilelocal.writeLine("\t-$(RMDIR) \"C:/Temp/workspace\"");
          /*makefilelocal.writeLine("\tif test ! -f "+outfile+"; then exit 1; fi;"); */
          makefilelocal.writeLine("");
          if(delivery_type == "src")
          {
             fileArray.push(projectlocation); 
             
          }
          
          makefilelocal.writeLine("clean::\n\t-$(RMDIR) \""+projectlocation+"\"\n"); 

      }
    }
    }
   }
 }     
}

function createbuildtestpjts(ccsversion)
{
  var projectDir = new java.io.File("./package/projects");
  var projectXml = projectDir.list();
  var eclipseCmd;
  var ccs_install_dir=java.lang.System.getenv("CCS_INSTALL_DIR");
  if(ccsversion == "CCSV4.2" )
  {
    eclipseCmd="java -jar \"$(CCS_INSTALL_DIR)/eclipse/startup.jar\"";
    /* Check if CCS V4 is installed */
    if(!xdc.findFile(ccs_install_dir+"/eclipse/startup.jar"))
    {
      print("Error: CCS V4 could not be found at "+ccs_install_dir);
      java.lang.System.exit(1);
    }
  }
  else if(ccsversion == "CCSV5" )
  {
    eclipseCmd="\"$(CCS_INSTALL_DIR)/eclipse/eclipsec.exe\" -noSplash";
     /* Check if CCS V4 is installed */
    if(!xdc.findFile(ccs_install_dir+"/eclipse/eclipsec.exe"))
    {
      print("Error: CCS V5 could not be found at "+ccs_install_dir);
      java.lang.System.exit(1);
    }
  }
  else
  {
    print("ERROR: "+ccsversion +" is not supported ");
  }
 
  
  for each(var xml in projectXml)
  {
       xml=String(xml);
       var dot = xml.lastIndexOf(".");
       var extension = xml.substr(dot,xml.length); 
       if(extension == ".xml")
       {
          var project=xdc.loadXML("./package/projects/"+xml);
          for each(var target in targs)
          {
             var targParams=getTargParams(target);
             if(targParams.target.toString().match(project["params"].target))
             {
                var cgtversion = java.lang.System.getenv("CCSCGTVER");
                switch(target)
                {
                   case C55_large:
                   var endianness = "big";      
                   var device ="com.ti.ccstudio.deviceModel.C5500.GenericC55xxDevice";   
                   var outputFormat = "coff";   
                   var cflags = "--ptrdiff_size=16 --memory_model=large --symdebug:none -Dti_targets_C55_large";   
                   var suffix = "COFF";     
                   var cgtversion = java.lang.System.getenv("CCSCGTVERC55");
                   break;

                   case C64P:
                   var endianness = "little";      
                   var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
                   var outputFormat = "coff";   
                   var cflags = "-mv64plus -k -mw -Dti_targets_C64P" ;   
                   var suffix = "LE_COFF";     
                   break;
      
                   case C64P_big_endian:
                   var endianness = "big";      
                   var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
                   var outputFormat = "coff";   
                   var cflags = "-mv64plus -k -mw  -Dti_targets_C64P_big_endian";    
                   var suffix = "BE_COFF";                    
                   break;   

                   case C64P_elf:
                   var endianness = "little";      
                   var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
                   var outputFormat = "elf";   
                   var cflags = "-mv64plus -k -mw --strip_coff_underscore -Dti_targets_elf_C64P";   
                   var suffix = "LE_ELF";     
                   break;
      
                   case C64P_big_endian_elf:
                   var endianness = "big";      
                   var device ="com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
                   var outputFormat = "elf";   
                   var cflags = "-mv64plus -k -mw --strip_coff_underscore -Dti_targets_elf_C64P_big_endian";    
                   var suffix = "BE_ELF";                    
                   break;   

                   case C66:
                   var endianness = "little";      
                   var device = "com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
                   var outputFormat = "coff";   
                   var cflags = "-mv6600 -k -mw -Dti_targets_C66";  
                   var suffix = "LE_COFF";                      
                   break;   
   
                   case C66_big_endian:
                   var endianness = "big";      
                   var device = "com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";
                   var outputFormat = "coff";   
                   var cflags = "-mv6600 -k -mw -Dti_targets_C66_big_endian";     
                   var suffix = "BE_COFF";                                    
                   break;   
   
                   case C66_elf:
                   var endianness = "little";      
                   var device = "com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";   
                   var outputFormat = "elf";   
                   var cflags = "-mv6600 -k  -mw --strip_coff_underscore -Dti_targets_elf_C66";  
                   var suffix = "LE_ELF";                      
                   break;   
   
                   case C66_big_endian_elf:
                   var endianness = "big";      
                   var device = "com.ti.ccstudio.deviceModel.C6000.CustomC6000Device";
                   var outputFormat = "elf";   
                   var cflags = "-mv6600 -k  -mw --strip_coff_underscore -Dti_targets_elf_C66_big_endian";     
                   var suffix = "BE_ELF";                                    
                   break;   

                   default:
                   continue;
 
                } 
        cflags+=" -Dxdc_target_types__=ti/targets/std.h ";
        var projectname=project["params"].name+"_"+project["params"].target.toUpperCase()+"_"+suffix;
        var projectlocation=project["params"].location+"/"+projectname; 
        var linkfile=project["params"].files.@name;
        var envPath = "EXT_ROOT__"+projectname.toUpperCase();
        var projectroot = project["params"].location;
        if(cgtversion == undefined)    
        {
          print("Error: ENV CCSCGTVER not defined ");
          java.lang.System.exit(1);
        }
        cflags += " "+ project["params"].cFlags;

        



        /* Command to create CCS Project */
        var   Command = eclipseCmd+" ";
              Command += " -data \"C:/Temp/workspace\"";
              Command += " -application com.ti.ccstudio.apps.projectCreate";  
              Command += " -ccs.name "+projectname;
              Command += " -ccs.device "+device;
              Command += " -ccs.endianness "+endianness;
              Command += " -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable";

        var pkgroot="..";
        for (var i = Pkg.name.split('.').length; i > 1; i--) {
            pkgroot+="/..";
        } 
        /* TODO: remove the hard-coded XDAIS include path */
        var includepath=" -i"+pkgroot+"/../"+_toRelative(projectlocation,".") + " -i$$$${XDAIS_CG_ROOT}/packages -i$$$${XDC_CG_ROOT}/packages " ;
        var includepathArray= new Array();
        includepathArray.push(
                               {
                     path: "./",
                     macro: envPath,
                     canpath: (java.io.File(projectroot)).getCanonicalPath()
                   }
                             );
       for each( var file in linkfile)
       {  
          if(xdc.findFile(file))
          {
              var envmacro="";
              var pathexists=false;
              var dstpath = java.io.File(file).getParentFile();
              if(dstpath == null)
              {
                dstpath=".";
              }
              
              var relative=_toRelative(projectroot,dstpath);
              var temp = file.toString().replace(/\\/g,"/");
              temp=temp.split("/");
            
              for each( var element in includepathArray)
             {
                 if(element.path == relative)
                 {
                   pathexists=true;
                   envmacro=element.macro;
                   break;
                 }
             }
          if(pathexists == false)
          {
            envmacro="EXT_ROOT__"+projectname.toUpperCase()+"_"+dstpath.toString().toUpperCase();
            envmacro=envmacro.toString().replace(/\./g,"");
            envmacro=envmacro.toString().replace(/\\/g,"");
            envmacro=envmacro.toString().replace(/\//g,"");

            includepathArray.push(
                                 {
                                   path: relative,
                                   macro: envmacro,
                                   canpath: dstpath.getCanonicalPath() 
                                 }
                     );
                  }
            var dot = String(temp[temp.length-1]).lastIndexOf(".");
            var extension = String(temp[temp.length-1]).substr(dot,String(temp[temp.length-1]).length); 
            Command +=" -ccs.linkFile "+ envmacro+"/"+temp[temp.length-1];
        }
        else
        {
          print("Error : "+file +" not found");
          java.lang.System.exit(1);

        }
      }
           var cflag_debug = cflags.toString().replace(/-o[0-3]/gi,"");
           var cflag_debug = cflag_debug.replace(/-os/gi,"");
           Command += " -ccs.setCompilerOptions \""+cflag_debug+" -g "+includepath+"\" @configurations Debug";
           Command += " -ccs.setCompilerOptions \""+cflags+" " + includepath+"\" @configurations Release";
           Command += " -ccs.location "+projectlocation;
           Command += " -ccs.overwrite full";
           Command += " -ccs.rts libc.a";
           Command += " -ccs.cgtVersion "+cgtversion;
           Command += " -ccs.outputFormat "+outputFormat;
           Command += " -rtsc.enableRtsc";
         /* Create macros for portable CCS V4 Projects */
       for each(var element in includepathArray)
       {
         var incpath = String(element.canpath).replace(/\\/g,"/");
         var env   = java.lang.System.getenv();
         var keys  = env.keySet().toArray();
         var key;
         var stat={};
         var env_j=[];
         for (var i = 0; i < keys.length; i++) {
            key = String(keys[i]);
            if(key.match(install_dir_string))
            {
                var keyPath=String(env.get(key));
                keyPath=keyPath.replace(/\\/g,"/");
                var file = xdc.module('xdc.services.io.File');
                keyPath=file.getDOSPath(keyPath);
                if(incpath.toString().match(keyPath))
                {
                    incpath=incpath.toString().replace(keyPath,"$("+key+")");
                    break;
                }
            }
          }
         
       
         Command += " -ccs.definePathVariable "+element.macro+" \""+incpath+"\"";  
       }
          
      Pkg.makeEpilogue +="\n\n#############################################################";
      Pkg.makeEpilogue +="\n# Rule to Build Project "+ projectname;
      Pkg.makeEpilogue +="\n#############################################################";
      var outfile=projectlocation+"/Debug/"+projectname+".out";
      Pkg.makeEpilogue +="\n\n.executables: "+ outfile;
      Pkg.makeEpilogue +="\n\n"+projectlocation+"/.project: .xdcenv.mak Package.bld Package.mak";
      Pkg.makeEpilogue +="\n\t"+Command;
      for each(var element in includepathArray)
      {
        Pkg.makeEpilogue +="\n\techo "+element.macro+"=../"+element.path+" >> "+projectlocation+"/macros.ini"; 
      }
      /* TODO : This needs to be fixed in CCS Command Line project create utility */
      var fixccs = xdc.findFile('ti/mas/swtools/fixccspjt.js');
       if(ccsversion == "CCSV4.2" )
      {
        Pkg.makeEpilogue +="\n\txs -f "+fixccs+" " +projectlocation+"/.cdtbuild"; 
      }
      else if(ccsversion == "CCSV5")
      {
        Pkg.makeEpilogue +="\n\txs -f "+fixccs+" " +projectlocation+"/.cproject"; 
      }
      Pkg.makeEpilogue +="\n\t-$(RMDIR) \"C:/Temp/workspace\"";

      /* Command to import CCS Projects */
      var Command2 = eclipseCmd+" ";
      Command2 +=" -data \"C:/Temp/workspace\"";
      Command2 +=" -application com.ti.ccstudio.apps.projectImport";
      Command2 +=" -ccs.projects "+projectname ;  

      var pjtloc = java.io.File(projectlocation).getCanonicalPath();
      pjtloc=String(pjtloc).replace(/\\/g,"/");
      if(bundlename != undefined)
      {
          var env   = java.lang.System.getenv();
          var keys  = env.keySet().toArray();
          var key;
          var stat={};
          var env_j=[];
          for (var i = 0; i < keys.length; i++) {
            key = String(keys[i]);
            if(key.match(install_dir_string))
            {
                var keyPath=String(env.get(key));
                keyPath=keyPath.replace(/\\/g,"/");
                var file = xdc.module('xdc.services.io.File');
                keyPath=file.getDOSPath(keyPath);
                if(pjtloc.match(keyPath))
                {
                    pjtloc=pjtloc.replace(keyPath,"$("+key+")");
                    break;
                }
            }
          }
      }
      Command2 +=" -ccs.location \""+pjtloc+"\"";  

      /* Command to build CCS V4 Projects */
      var Command1 = eclipseCmd+" ";
      Command1 +=" -data \"C:/Temp/workspace\"";
      Command1 +=" -application com.ti.ccstudio.apps.projectBuild";
      Command1 +=" -ccs.projects "+projectname ;  
      Command1 +=" -ccs.configuration Debug";
        
      for each( var file in linkfile)
      {
          Pkg.makeEpilogue +="\n\n"+outfile+": "+ file;
      }
      Pkg.makeEpilogue +="\n"+outfile+": "+ projectlocation+"/.project";
      Pkg.makeEpilogue +="\n\t-@ echo Importing Project "+projectname+" into workspace ...";  
      Pkg.makeEpilogue +="\n\t"+Command2;
      Pkg.makeEpilogue +="\n\t-@ echo Building Project "+projectname+" ...";  
      Pkg.makeEpilogue +="\n\t"+Command1;
      Pkg.makeEpilogue +="\n\t-$(RMDIR) \"C:/Temp/workspace\"";
      Pkg.makeEpilogue +="\n\tif test ! -f "+outfile+"; then exit 1; fi;"; 
      Pkg.makeEpilogue +="\n";
      if(delivery_type == "src")
      {
          fileArray.push(projectlocation); 

      }
      Pkg.makeEpilogue +="\n\nclean::\n\t-$(RMDIR) \""+projectlocation+"\"\n"; 

      }
    }
    }
   }
}     




function _toRelative(basePath, targetPath)
{
    basePath = String(java.io.File(basePath).getCanonicalPath());
    basePath = basePath.replace(/\\/g, '/');

    targetPath = String(java.io.File(targetPath).getCanonicalPath());
    targetPath = targetPath.replace(/\\/g, '/');

    var base = basePath.split('/');
    var target = targetPath.split('/');

    /*  Get all the common elements. Store them as a string, */
    /*  and also count how many of them there are.           */
    var common = '';
    var commonLength = 0;
    for (var i = 0; i < target.length && i < base.length; i++) {
         if (target[i] == base[i]) {
             common += target[i] + '/';
             commonLength++;
         }
         else {
            break;
        }
    }
    if (commonLength == 0) {
        return (null);
    }

    var relative = '';
    if (base.length == commonLength) {
        relative = './';
    }
    else {
        var numDirsUp = base.length - commonLength;
        for (var i = 1; i <= numDirsUp; i++) {
            relative += '../';
        }
    }
    if (targetPath.length > common.length) {
        relative += targetPath.substr(common.length);
    }
    return (relative);
}

