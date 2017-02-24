//===- IntrinsicsTI.td - Defines TI generic intrinsics   ---*- tablegen -*-===//
// 
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
// 
//===----------------------------------------------------------------------===//
//
// This file defines all of the TI generic intrinsics.
//
//===----------------------------------------------------------------------===//

let TargetPrefix = "ti" in {  // All intrinsics start with "llvm.ti.".

//===-------------------------- TI Generic Intrinsics ---------------------===//
//
def int_ti_abs : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                           [IntrNoMem]>;
def int_ti_labs : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                            [IntrNoMem]>;
def int_ti_llabs : Intrinsic<[llvm_i64_ty], [llvm_i64_ty],
                            [IntrNoMem]>;
def int_ti_fabs : Intrinsic<[llvm_double_ty], [llvm_double_ty],
                            [IntrNoMem]>;
def int_ti_fabsf : Intrinsic<[llvm_float_ty], [llvm_float_ty],
                             [IntrNoMem]>;
def int_ti_assert : Intrinsic<[], [llvm_i32_ty, llvm_ptr_ty]>;
def int_ti_nassert : Intrinsic<[], [llvm_i32_ty]>;
}
