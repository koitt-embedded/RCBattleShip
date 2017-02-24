/*
 * Copyright (c) 2012-2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== getSects ========
 */
function getSects()
{
    return "ti/runtime/cio/linkcmd.xdt";
}

/*
 *  ======== getLibs ========
 */
function getLibs( prog )
{
    var pkg = this;
 
    var suffix = prog.build.target.findSuffix(pkg);
    var debugFlag = "_debug";
 
    if (this.profile == "release")
        debugFlag = "_release"

    // If used along with OpenCL, use device specific code from OpenCL monitor
    // Also, if application initializes QMSS, pick up QMSS device files and
    // OSAL from the application.
    var ompSettings = xdc.module("ti.runtime.openmp.Settings");
    if (ompSettings.usingOpenCL == true)
        return (null);

    var target;
    if( String(Program.cpu.deviceName).search("663") != -1)
    {
        target = "_c6636";
    }
    else
    {
        Program.$logError("Device:" + Program.cpu.deviceName + 
                          " not supported", this);
    }

    lib = "lib/" + pkg.$name.replace(/\./g, "_") + target + debugFlag +  
                "_" + suffix + ".a" + suffix;

    if (java.io.File(this.packageBase + lib).exists())
    {
        return lib;
    }
    else
    {
         /* could not find any library, throw exception */
         throw new Error("Library not found: " + lib);
    }
}

