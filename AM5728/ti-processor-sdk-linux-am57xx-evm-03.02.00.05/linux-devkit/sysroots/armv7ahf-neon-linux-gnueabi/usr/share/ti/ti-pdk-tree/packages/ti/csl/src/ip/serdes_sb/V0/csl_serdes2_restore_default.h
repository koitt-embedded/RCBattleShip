/**
 * File csl_serdes2_restore_default.h
 *
 *  Brief
 *  Autogenerated SERDES CONFIG Functions.
 *
 *  It restores the serdes to its default values
 *
 *  
 *  ============================================================================
 *  @n   (C) Copyright 2013-2016, Texas Instruments, Inc.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
/** ============================================================================ 
 *
 * @defgroup CSL_SERDES_RESTORE SERDES RESTORE
 * @ingroup CSL_SERDES_API
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * This module deals with setting up SERDES restore configuration after a shutdown is initiated. The API flow should be as follows:   \n
 *
 * CSL_SerDes_Restore_Default (base_addr);
 *
 * @subsection References
 *    
 * ============================================================================
 */ 
static inline void CSL_SerDes_CMU_Restore_Default
(
 uint32_t base_addr
) 
{
    *(volatile uint32_t *)(base_addr + 0x0) = 0x00820803;
    *(volatile uint32_t *)(base_addr + 0x4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x10) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x14) = 0x00052E2E;
    *(volatile uint32_t *)(base_addr + 0x18) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x20) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x24) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x28) = 0xA0020000;
    *(volatile uint32_t *)(base_addr + 0x2C) = 0x20414402;
    *(volatile uint32_t *)(base_addr + 0x30) = 0x0000200C;
    *(volatile uint32_t *)(base_addr + 0x34) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x38) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x3C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x40) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x44) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x48) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x4C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x50) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x54) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x58) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x5C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x60) = 0x00041C5C;
    *(volatile uint32_t *)(base_addr + 0x64) = 0x0343C702;
    *(volatile uint32_t *)(base_addr + 0x68) = 0x17078200;
    *(volatile uint32_t *)(base_addr + 0x6C) = 0x00000012;
    *(volatile uint32_t *)(base_addr + 0x70) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x74) = 0x1C32C800;
    *(volatile uint32_t *)(base_addr + 0x78) = 0x4002C009;
    *(volatile uint32_t *)(base_addr + 0x7C) = 0x00001C00;
    *(volatile uint32_t *)(base_addr + 0x80) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x84) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x88) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x8C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x90) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x94) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x98) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x9C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xA0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xA4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xA8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xAC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xB0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xB4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xB8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xBC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xC0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xC4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xC8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xCC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xD0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xD4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xD8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xDC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xE0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xE4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xE8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xEC) = 0x39000000;
    *(volatile uint32_t *)(base_addr + 0xF0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xF4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xF8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xFC) = 0x03000000;
}        
static inline void CSL_SerDes_COMLANE_Restore_Default
(
 uint32_t base_addr
) 
{
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x0) = 0x0400019F;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x4) = 0x0000001E;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x8) = 0x32E12C08;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xC) = 0x74180181;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x10) = 0x00000006;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x14) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x18) = 0xBCE81463;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1C) = 0x00002EC0;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x20) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x24) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x28) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x2C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x30) = 0x142F2F00;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x34) = 0x14141414;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x38) = 0x00000014;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x3C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x40) = 0xE44C9500;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x44) = 0x5F733D95;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x48) = 0x34FDCAC9;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x4C) = 0xAC82870B;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x50) = 0x510F980A;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x54) = 0xC02E4E82;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x58) = 0x002D1441;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x5C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x60) = 0x00008000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x64) = 0x0C581220;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x68) = 0xE13B0602;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x6C) = 0xB8074CC1;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x70) = 0x3F02E989;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x74) = 0x00000001;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x78) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x7C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x80) = 0x0001FF00;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x84) = 0xF0000301;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x88) = 0xCF3FFFFF;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x8C) = 0x8103232F;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x90) = 0x55506001;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x94) = 0x01005555;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x98) = 0x00000020;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x9C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xA0) = 0x81000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xA4) = 0xAD52A835;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xA8) = 0x0552AD52;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xAC) = 0x290003F8;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xB0) = 0x0820816B;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xB4) = 0x10409782;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xB8) = 0x00000104;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xBC) = 0xFF000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xC0) = 0x2800FA8B;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xC4) = 0x01002800;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xC8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xCC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xD0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xD4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xD8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xDC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xE0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xE4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xE8) = 0x03000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xEC) = 0x541F4003;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xF0) = 0x0000A501;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xF4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xF8) = 0x364B7100;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0xFC) = 0x002C2A2A;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x100) = 0x0000A500;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x104) = 0x00000005;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x108) = 0x874F5833;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x10C) = 0x0400C05F;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x110) = 0x37011D00;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x114) = 0x1D37715D;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x118) = 0x0C00C031;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x11C) = 0x3F011D00;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x120) = 0x1D3F71DF;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x124) = 0x00000031;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x128) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x12C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x130) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x134) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x138) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x13C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x140) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x144) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x148) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x14C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x150) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x154) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x158) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x15C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x160) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x164) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x168) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x16C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x170) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x174) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x178) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x17C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x180) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x184) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x188) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x18C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x190) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x194) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x198) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x19C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1A0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1A4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1A8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1AC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1B0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1B4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1B8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1BC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1C0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1C4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1C8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1CC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1D0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1D4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1D8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1DC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1E0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1E4) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1E8) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1EC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1F0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1F4) = 0xF1000F00;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1F8) = 0x06010000;
    *(volatile uint32_t *)(base_addr + 0xa00 + 0x1FC) = 0x00000000;
}
static inline void CSL_SerDes_Lane_Restore_Default
(
 uint32_t base_addr,
 uint32_t lane_num
)
{
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x0) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x4) = 0x5E001080;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x8) = 0x00010006;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0xC) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x10) = 0x1B000023;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x14) = 0x2E003060;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x18) = 0x76800004;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x1C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x20) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x24) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x28) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x2C) = 0x00200002;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x30) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x34) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x38) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x3C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x40) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x44) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x48) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x4C) = 0x00800000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x50) = 0xD0001B00;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x54) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x58) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x5C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x60) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x64) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x68) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x6C) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x70) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x74) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x78) = 0x8F002000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x7C) = 0x00092A00;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x80) = 0x50285028;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x84) = 0x2D0F0385;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x88) = 0x20202040;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x8C) = 0x20404820;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x90) = 0x00202020;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x94) = 0x20633000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x98) = 0x79F44444;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0x9C) = 0x10003002;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0xA0) = 0xFFEE3048;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0xA4) = 0x0000000F;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0xA8) = 0x50000000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0xAC) = 0x00004000;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0xB0) = 0x1238BDF0;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0xB4) = 0xD0000A00;
    *(volatile uint32_t *)(base_addr + 0x200  + (lane_num*0x200)+ 0xB8) = 0x00000407;
}
static inline void CSL_SerDes_Restore_Default
(
 uint32_t base_addr
) 
{
    uint32_t lane_num;
    CSL_SerDes_COMLANE_Restore_Default(base_addr);
    for(lane_num=0; lane_num<4; lane_num++)
    {
        CSL_SerDes_Lane_Restore_Default(base_addr, lane_num);
    }
    CSL_SerDes_CMU_Restore_Default(base_addr);
}
/* @} */

