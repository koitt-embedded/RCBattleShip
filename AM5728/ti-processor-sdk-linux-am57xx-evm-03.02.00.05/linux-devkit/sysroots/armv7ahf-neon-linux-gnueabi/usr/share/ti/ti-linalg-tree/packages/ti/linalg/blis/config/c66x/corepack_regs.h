/**
   Structures for CorePack registers.
*/

#ifndef RT_COREPACK_REGS_H
#define RT_COREPACK_REGS_H

#include <stdint.h>

/**
   IDMA registers placed at 0x0182 0000.
*/
struct corepack_idma_regs {
  uint32_t idma0_stat;		/* 0000 */
  uint32_t idma0_mask;		/* 0004 */
  uint32_t idma0_source;	/* 0008 */
  uint32_t idma0_dest;		/* 000C */
  uint32_t idma0_count;		/* 0010 */
  uint32_t res1[59];		/* 0014 - 00ff */
  uint32_t idma1_stat;		/* 0100 */
  uint32_t res2;		/* 0104 */
  uint32_t idma1_source;	/* 0108 */
  uint32_t idma1_dest;		/* 010c */
  uint32_t idma1_count;		/* 0110 */
  uint32_t res3[16315];		/* 0114 - ffff */
};

/**
   Cache registers placed at 0x0184 0000.
*/
struct corepack_cache_regs {
  uint32_t l2cfg;		/* 0000 */
  uint32_t res1[7];		/* 0004 - 001f */
  uint32_t l1pcfg;		/* 0020 */
  uint32_t l1pcc;		/* 0024 */
  uint32_t res2[6];		/* 0028 - 003f */
  uint32_t l1dcfg;		/* 0040 */
  uint32_t l1dcc;		/* 0044 */
  uint32_t res3[4078];		/* 0048 - 3fff */
  uint32_t l2wbar;		/* 4000 */
  uint32_t l2wwc;		/* 4004 */
  uint32_t res4[2];		/* 4008 - 400f */
  uint32_t l2wibar;		/* 4010 */
  uint32_t l2wiwc;		/* 4014 */
  uint32_t l2ibar;		/* 4018 */
  uint32_t l2iwc;		/* 401c */
  uint32_t l1pibar;		/* 4020 */
  uint32_t l1piwc;		/* 4024 */
  uint32_t res5[2];		/* 4028 - 402f */
  uint32_t l1dwibar;		/* 4030 */
  uint32_t l1dwiwc;		/* 4034 */
  uint32_t res6[2];		/* 4038 - 403f */
  uint32_t l1dwbar;		/* 4040 */
  uint32_t l1dwwc;		/* 4044 */
  uint32_t l1dibar;		/* 4048 */
  uint32_t l1diwc;		/* 404c */
  uint32_t res7[1004];		/* 4050 - 4fff */
  uint32_t l2wb;		/* 5000 */
  uint32_t l2wbinv;		/* 5004 */
  uint32_t l2inv;		/* 5008 */
  uint32_t res8[7];		/* 500c - 5027 */
  uint32_t l1pinv;		/* 5028 */
  uint32_t res9[5];		/* 502c - 503f */
  uint32_t l1dwb;		/* 5040 */
  uint32_t l1dwbinv;		/* 5044 */
  uint32_t l1dinv;		/* 5048 */
  uint32_t res10[3053];		/* 504c - 7fff */
  uint32_t mar[256];		/* 8000 - 83ff */
  uint32_t res11[7936];		/* 8400 - ffff */
};

struct corepack_regs {
  uint32_t res1[32768];		                    /* 0180 0000 - 0181 ffff */
  struct corepack_idma_regs idma_regs;		    /* 0182 0000 - 0182 ffff */
  uint32_t res2[16384];				    /* 0183 0000 - 0183 ffff */
  struct corepack_cache_regs cache_regs;	    /* 0184 0000 - 0184 ffff */
};

static volatile struct corepack_regs * const corepack_regs =
  (struct corepack_regs *)(0x01800000ul);

#endif
