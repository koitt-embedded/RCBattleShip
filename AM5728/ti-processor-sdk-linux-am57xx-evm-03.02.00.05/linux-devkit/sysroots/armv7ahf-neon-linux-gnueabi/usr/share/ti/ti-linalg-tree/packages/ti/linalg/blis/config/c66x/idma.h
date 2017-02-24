/**
   Simple IDMA helper functions.
*/

/*

Copyright (c) 2012 Kungliga Tekniska Högskolan 
(Royal Institute of Technology, Stockholm, Sweden).
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.

*/

#ifndef RT_IDMA_H
#define RT_IDMA_H

#include "corepack_regs.h"

static inline void 
idma1_setup(void *dest, 
	    const void *source, 
	    unsigned size,
	    unsigned fill,
	    unsigned inter,
	    unsigned priority)
{
  uint32_t count;

  count = size | (fill << 16) | (inter << 28) | (priority << 29);

  corepack_regs->idma_regs.idma1_source = (uint32_t)source;
  corepack_regs->idma_regs.idma1_dest = (uint32_t)dest;
  corepack_regs->idma_regs.idma1_count = count;
}

static inline uint32_t
idma1_status()
{
  return corepack_regs->idma_regs.idma1_stat;
}

static inline int
idma1_done()
{
  return idma1_status() == 0;
}

#endif
