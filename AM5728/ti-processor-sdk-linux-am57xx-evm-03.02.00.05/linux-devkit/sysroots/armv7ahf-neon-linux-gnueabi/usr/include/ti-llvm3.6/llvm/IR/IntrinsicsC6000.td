//===- IntrinsicsC6000.td - Defines TI C6000 intrinsic   ---*- tablegen -*-===//
// 
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
// 
//===----------------------------------------------------------------------===//
//
// This file defines all of the TI C6000-specific intrinsics.
//
//===----------------------------------------------------------------------===//

let TargetPrefix = "c6000" in {  // All intrinsics start with "llvm.c6000.".

//===-------------------------- C6x Intrinsics --------------------------===//
//
def int_c6000_extu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty,llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_ext : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty],
                              [IntrNoMem]>;
def int_c6000_set : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty],
                              [IntrNoMem]>;
def int_c6000_clr : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty],
                              [IntrNoMem]>;
def int_c6000_extur : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                [IntrNoMem]>;
def int_c6000_extr : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_setr : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_clrr : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_sadd : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_ssub : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_sshl : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_add2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_sub2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_subc : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_lmbd : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_abs : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                              [IntrNoMem]>;
def int_c6000_labs : Intrinsic<[llvm_i64_ty], [llvm_i64_ty],
                               [IntrNoMem]>;
def int_c6000_norm : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_smpy : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_smpyhl : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                 [IntrNoMem]>;
def int_c6000_smpylh : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                 [IntrNoMem]>;
def int_c6000_smpyh : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                [IntrNoMem]>;
def int_c6000_mpy : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                              [IntrNoMem]>;
def int_c6000_mpyus : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                [IntrNoMem]>;
def int_c6000_mpysu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                [IntrNoMem]>;
def int_c6000_mpyu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                               [IntrNoMem]>;
def int_c6000_mpyhl : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                [IntrNoMem]>;
def int_c6000_mpyhuls : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyhslu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyhlu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                 [IntrNoMem]>;
def int_c6000_mpylh : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                [IntrNoMem]>;
def int_c6000_mpyluhs : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpylshu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpylhu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyh : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyhus : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyhsu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyhu : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_lsadd : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i64_ty],
                                  [IntrNoMem]>;
def int_c6000_lssub : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i64_ty],
                                  [IntrNoMem]>;
def int_c6000_sat : Intrinsic<[llvm_i32_ty], [llvm_i64_ty],
                                  [IntrNoMem]>;
def int_c6000_lnorm : Intrinsic<[llvm_i32_ty], [llvm_i64_ty],
                                  [IntrNoMem]>;
def int_c6000_fabs : Intrinsic<[llvm_double_ty], [llvm_double_ty],
                                  [IntrNoMem]>;
def int_c6000_fabsf : Intrinsic<[llvm_float_ty], [llvm_float_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyid : Intrinsic<[llvm_double_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyidll : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_spint : Intrinsic<[llvm_i32_ty], [llvm_float_ty],
                                  [IntrNoMem]>;
def int_c6000_dpint : Intrinsic<[llvm_i32_ty], [llvm_double_ty],
                                  [IntrNoMem]>;
def int_c6000_rcpsp : Intrinsic<[llvm_float_ty], [llvm_float_ty],
                                  [IntrNoMem]>;
def int_c6000_rcpdp : Intrinsic<[llvm_double_ty], [llvm_double_ty],
                                  [IntrNoMem]>;
def int_c6000_rsqrsp : Intrinsic<[llvm_float_ty], [llvm_float_ty],
                                  [IntrNoMem]>;
def int_c6000_rsqrdp : Intrinsic<[llvm_double_ty], [llvm_double_ty],
                                  [IntrNoMem]>;
def int_c6000_hi : Intrinsic<[llvm_i32_ty], [llvm_double_ty],
                                  [IntrNoMem]>;
def int_c6000_hill : Intrinsic<[llvm_i32_ty], [llvm_i64_ty],
                                  [IntrNoMem]>;
def int_c6000_lo : Intrinsic<[llvm_i32_ty], [llvm_double_ty],
                                  [IntrNoMem]>;
def int_c6000_loll : Intrinsic<[llvm_i32_ty], [llvm_i64_ty],
                                  [IntrNoMem]>;
def int_c6000_itod : Intrinsic<[llvm_double_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_itoll : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_itof : Intrinsic<[llvm_float_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_ftoi : Intrinsic<[llvm_i32_ty], [llvm_float_ty],
                                  [IntrNoMem]>;
def int_c6000_add4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_avg2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_avgu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_cmpeq2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_cmpeq4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_cmpgt2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_cmpgtu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dotp2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dotpn2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dotpnrsu2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dotprsu2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dotpsu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dotpu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_gmpy4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_ldotp2 : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_max2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_maxu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_min2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_minu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpy2 : Intrinsic<[llvm_double_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpy2ll : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyhi : Intrinsic<[llvm_double_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyhill : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyhir : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyli : Intrinsic<[llvm_double_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpylill : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpylir : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpysu4 : Intrinsic<[llvm_double_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpysu4ll : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyu4 : Intrinsic<[llvm_double_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpyu4ll : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_pack2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_packh2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_packh4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_packhl2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_packl4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_packlh2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_rotl : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_sadd2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_saddu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_saddus2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_shlmb : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_shr2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_shrmb : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_shru2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_smpy2 : Intrinsic<[llvm_double_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_smpy2ll : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_spack2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_spacku4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_sshvl : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_sshvr : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_sub4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_subabs4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_abs2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_bitc4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_bitr : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_deal : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mvd : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_shfl : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_swap4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_unpkhu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_unpklu4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_xpnd2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_xpnd4 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_addsub : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_addsub2 : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_cmpy : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_cmpyr : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_cmpyr1 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_ddotph2 : Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_ddotph2r : Intrinsic<[llvm_i32_ty], [llvm_i64_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_ddotpl2 : Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_ddotpl2r : Intrinsic<[llvm_i32_ty], [llvm_i64_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_ddotp4 : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dpack2 : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dpackx2 : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_dmv : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_gmpy : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpy32ll : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpy32 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpy32su : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpy32us : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpy32u : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mpy2ir : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_rpack2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_saddsub : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_saddsub2 : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_shfl3 : Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_smpy32 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_ssub2 : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_xormpy : Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty],
                                  [IntrNoMem]>;
def int_c6000_mem8_const : Intrinsic<[llvm_ptri64_ty], [llvm_ptr_ty], 
                                     [IntrNoMem]>;
def int_c6000_memd8_const : Intrinsic<[llvm_ptrdouble_ty], [llvm_ptr_ty], 
                                      [IntrNoMem]>;
def int_c6000_mem4_const : Intrinsic<[llvm_ptri32_ty], [llvm_ptr_ty], 
                                     [IntrNoMem]>;
def int_c6000_mem2_const : Intrinsic<[llvm_ptri16_ty], [llvm_ptr_ty], 
                                     [IntrNoMem]>;
def int_c6000_mem8 : Intrinsic<[llvm_ptri64_ty], [llvm_ptr_ty], 
                               [IntrNoMem]>;
def int_c6000_memd8 : Intrinsic<[llvm_ptrdouble_ty], [llvm_ptr_ty], 
                                [IntrNoMem]>;
def int_c6000_mem4 : Intrinsic<[llvm_ptri32_ty], [llvm_ptr_ty], 
                               [IntrNoMem]>;
def int_c6000_mem2 : Intrinsic<[llvm_ptri16_ty], [llvm_ptr_ty], 
                               [IntrNoMem]>;
def int_c6000_amem8_const : Intrinsic<[llvm_ptri64_ty], [llvm_ptr_ty], 
                                      [IntrNoMem]>;
def int_c6000_amemd8_const : Intrinsic<[llvm_ptrdouble_ty], [llvm_ptr_ty], 
                                       [IntrNoMem]>;
def int_c6000_amem4_const : Intrinsic<[llvm_ptri32_ty], [llvm_ptr_ty], 
                                      [IntrNoMem]>;
def int_c6000_amem2_const : Intrinsic<[llvm_ptri16_ty], [llvm_ptr_ty], 
                                      [IntrNoMem]>;
def int_c6000_amem8 : Intrinsic<[llvm_ptri64_ty], [llvm_ptr_ty], 
                                [IntrNoMem]>;
def int_c6000_amemd8 : Intrinsic<[llvm_ptrdouble_ty], [llvm_ptr_ty], 
                                 [IntrNoMem]>;
def int_c6000_amem4 : Intrinsic<[llvm_ptri32_ty], [llvm_ptr_ty], 
                                [IntrNoMem]>;
def int_c6000_amem2 : Intrinsic<[llvm_ptri16_ty], [llvm_ptr_ty], 
                                [IntrNoMem]>;
def int_c6000_davgu4 : Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty],
                                  [IntrNoMem]>;
def int_c6000_davg2 : Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty],
                                  [IntrNoMem]>;

def int_c6000_qmpy32 : Intrinsic<[llvm_v4i32_ty], [llvm_v4i32_ty, llvm_v4i32_ty], [IntrNoMem]>;
def int_c6000_dcmpyr1: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dccmpyr1: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_cmpy32r1: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_ccmpy32r1: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_mpyu2: Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dotp4h: Intrinsic<[llvm_i32_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dotp4hll: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dotpsu4h: Intrinsic<[llvm_i32_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dotpsu4hll: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dadd: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dadd_c: Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dsadd: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dadd2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dsadd2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dsub: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dssub: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dssub2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dapys2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dshr: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dshru: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dshl: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dshr2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dshru2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_shl2: Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dshl2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dxpnd4: Intrinsic<[llvm_i64_ty], [llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dxpnd2: Intrinsic<[llvm_i64_ty], [llvm_i32_ty], [IntrNoMem]>;
def int_c6000_crot90: Intrinsic<[llvm_i32_ty], [llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dcrot90: Intrinsic<[llvm_i64_ty], [llvm_i64_ty], [IntrNoMem]>;
def int_c6000_crot270: Intrinsic<[llvm_i32_ty], [llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dcrot270: Intrinsic<[llvm_i64_ty], [llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dmax2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dmin2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dmaxu4: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dminu4: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dcmpgt2: Intrinsic<[llvm_i32_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dcmpeq2: Intrinsic<[llvm_i32_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dcmpgtu4: Intrinsic<[llvm_i32_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dcmpeq4: Intrinsic<[llvm_i32_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_davgnr2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_davgnru4: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_unpkbu4: Intrinsic<[llvm_i64_ty], [llvm_i32_ty], [IntrNoMem]>;
def int_c6000_unpkh2: Intrinsic<[llvm_i64_ty], [llvm_i32_ty], [IntrNoMem]>;
def int_c6000_unpkhu2: Intrinsic<[llvm_i64_ty], [llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dpackl2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dpackh2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dpackhl2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dpacklh4: Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dpackl4: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dpackh4: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dspacku4: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_land: Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_landn: Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_lor: Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dmpy2: Intrinsic<[llvm_v4i32_ty], [llvm_v4i16_ty, llvm_v4i16_ty], [IntrNoMem]>;
def int_c6000_dmpyu2: Intrinsic<[llvm_v4i32_ty], [llvm_v4i16_ty, llvm_v4i16_ty], [IntrNoMem]>;
def int_c6000_qmpysp: Intrinsic<[llvm_v4f32_ty], [llvm_v4f32_ty, llvm_v4f32_ty], [IntrNoMem]>;
def int_c6000_daddsp: Intrinsic<[llvm_v2f32_ty], [llvm_v2f32_ty, llvm_v2f32_ty], [IntrNoMem]>;
def int_c6000_dsubsp: Intrinsic<[llvm_v2f32_ty], [llvm_v2f32_ty, llvm_v2f32_ty], [IntrNoMem]>;
def int_c6000_dinthsp: Intrinsic<[llvm_v2f32_ty], [llvm_v2i16_ty], [IntrNoMem]>;
def int_c6000_dinthspu: Intrinsic<[llvm_v2f32_ty], [llvm_v2i16_ty], [IntrNoMem]>;
def int_c6000_dintsp: Intrinsic<[llvm_v2f32_ty], [llvm_v2i32_ty], [IntrNoMem]>;
def int_c6000_dintspu: Intrinsic<[llvm_v2f32_ty], [llvm_v2i32_ty], [IntrNoMem]>;
def int_c6000_dspinth: Intrinsic<[llvm_v2i16_ty], [llvm_v2f32_ty], [IntrNoMem]>;
def int_c6000_dspint: Intrinsic<[llvm_v2i32_ty], [llvm_v2f32_ty], [IntrNoMem]>;
def int_c6000_dmvd: Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem]>;
def int_c6000_dsmpy2: Intrinsic<[llvm_v4i32_ty], [llvm_v4i16_ty, llvm_v4i16_ty], [IntrNoMem]>;
def int_c6000_dpacklh2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_mpyspdp: Intrinsic<[llvm_double_ty], [llvm_float_ty, llvm_double_ty], [IntrNoMem]>;
def int_c6000_mpysp2dp: Intrinsic<[llvm_double_ty], [llvm_float_ty, llvm_float_ty], [IntrNoMem]>;
def int_c6000_dsub2: Intrinsic<[llvm_i64_ty], [llvm_i64_ty, llvm_i64_ty], [IntrNoMem]>;
def int_c6000_dmpysp: Intrinsic<[llvm_v2f32_ty], [llvm_v2f32_ty, llvm_v2f32_ty], [IntrNoMem]>;
def int_c6000_ddotpsu4h: Intrinsic<[llvm_v2i32_ty], [llvm_v8i16_ty, llvm_v8i16_ty], [IntrNoMem]>;
def int_c6000_dmpysu4: Intrinsic<[llvm_v8i16_ty], [llvm_v8i8_ty, llvm_v8i8_ty], [IntrNoMem]>;
def int_c6000_dmpyu4: Intrinsic<[llvm_v8i16_ty], [llvm_v8i8_ty, llvm_v8i8_ty], [IntrNoMem]>;
def int_c6000_dccmpy:  Intrinsic<[llvm_v4i32_ty], [llvm_v4i16_ty, llvm_v4i16_ty], [IntrNoMem]>;
def int_c6000_dcmpy:   Intrinsic<[llvm_v4i32_ty], [llvm_v4i16_ty, llvm_v4i16_ty], [IntrNoMem]>;
def int_c6000_ddotp4h: Intrinsic<[llvm_v2i32_ty], [llvm_v8i16_ty, llvm_v8i16_ty], [IntrNoMem]>;
def int_c6000_cmpysp:     Intrinsic<[llvm_v4f32_ty], [llvm_v2f32_ty, llvm_v2f32_ty], [IntrNoMem]>;
def int_c6000_ccmatmpy:   Intrinsic<[llvm_v4i32_ty], [llvm_v4i16_ty, llvm_v8i16_ty], [IntrNoMem]>;
def int_c6000_ccmatmpyr1: Intrinsic<[llvm_v4i16_ty], [llvm_v4i16_ty, llvm_v8i16_ty], [IntrNoMem]>;
def int_c6000_cmatmpy:    Intrinsic<[llvm_v4i32_ty], [llvm_v4i16_ty, llvm_v8i16_ty], [IntrNoMem]>;
def int_c6000_cmatmpyr1:  Intrinsic<[llvm_v4i16_ty], [llvm_v4i16_ty, llvm_v8i16_ty], [IntrNoMem]>;
def int_c6000_qsmpy32r1:  Intrinsic<[llvm_v4i32_ty], [llvm_v4i32_ty, llvm_v4i32_ty], [IntrNoMem]>;
def int_c6000_xorll_c:    Intrinsic<[llvm_i64_ty], [llvm_i32_ty, llvm_i64_ty], [IntrNoMem]>;

}
