/*
 * trgmsg.c
 *
 * Re-defines low level functions which implement C I/O
 *
 * Copyright (C) 2013   Texas Instruments Incorporated - http://www.ti.com/ 
 * 
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

//*****************************************************************************
//  TRGMSG.C
//  This is a re-implementation of trgmsg.c that is in the compiler RTS
//  library.  When linking, insure the linker sees this module before the
//  compiler RTS library.  That means this implementation of writemsg and
//  readmsg are used instead of the ones supplied in the compiler RTS library.
//****************************************************************************

/*****************************************************************************/
/* Bottom level data transfer routines for host communication with the       */
/* target.                                                                   */
/*                                                                           */
/* Functions:                                                                */
/*  writemsg()  -  Sends the passed data and parameters on to the host.      */
/*  readmsg()   -  Reads the data and parameters passed from the host.       */
/*****************************************************************************/

#include <stdlib.h>
#include <string.h>  

#include "trgcio.h"

#include "cio_qmss.h"


//----------------------------------------------------------------------------
// WRITEMSG - Sends the passed data and parameters on to the GPP
//----------------------------------------------------------------------------
_CODE_ACCESS void writemsg (      unsigned char  command,
                            const unsigned char *parm,
                            const          char *data,
                                  unsigned int   length)
{
    unsigned char *p;
    unsigned int i;

    CIO_Msg *msg = cio_msgAlloc();
    cio_msgInitHeader(msg, CIO_TRANSFER);

    p = (unsigned char *) msg->_CIOBUF_;

    /***********************************************************************/
    /* THE LENGTH IS WRITTEN AS A TARGET INT                               */
    /***********************************************************************/ 
    *(unsigned int *)p = length; 
    p += sizeof(unsigned int);

    /***********************************************************************/ 
    /* THE COMMAND IS WRITTEN AS A TARGET BYTE                             */
    /***********************************************************************/ 
    *p++ = command;

    /***********************************************************************/ 
    /* PACK THE PARAMETERS AND DATA SO THE HOST READS IT AS BYTE STREAM    */
    /***********************************************************************/ 
    for (i = 0; i < 8; i++)      PACKCHAR(*parm++, p, i);
    for (i = 0; i < length; i++) PACKCHAR(*data++, p, i+8);

    cio_msgSend(msg);
}

//----------------------------------------------------------------------------
// READMSG - Reads the data and parameters passed from the GPP
//----------------------------------------------------------------------------
_CODE_ACCESS void readmsg (register unsigned char *parm,
                           register char          *data)
{
    unsigned char *p;
    unsigned int i;
    unsigned int length;

    CIO_Msg *msg = cio_msgRecv();

    p = (unsigned char *) msg->_CIOBUF_;

    /***********************************************************************/
    /* THE LENGTH IS READ AS A TARGET INT                                  */
    /***********************************************************************/
    length = *(unsigned int *)p;
    p += sizeof(unsigned int);
    
    /***********************************************************************/
    /* UNPACK THE PARAMETERS AND DATA                                      */
    /***********************************************************************/
    for (i = 0; i < 8; i++) *parm++ = UNPACKCHAR(p, i);
    if (data != NULL) 
       for (i = 0; i < length; i++) *data++ = UNPACKCHAR(p, i+8);

    cio_msgFree(msg);
}


/* In C6000 RTS versions > 7.5, functions have the __TI_ prefix */

_CODE_ACCESS void __TI_writemsg (      unsigned char  command,
                                         const unsigned char *parm,
                                         const          char *data,
                                               unsigned int   length)
{
    return writemsg(command, parm, data, length);
}

_CODE_ACCESS void __TI_readmsg (register unsigned char *parm,
                                register char          *data)
{
    return readmsg(parm, data);
}
