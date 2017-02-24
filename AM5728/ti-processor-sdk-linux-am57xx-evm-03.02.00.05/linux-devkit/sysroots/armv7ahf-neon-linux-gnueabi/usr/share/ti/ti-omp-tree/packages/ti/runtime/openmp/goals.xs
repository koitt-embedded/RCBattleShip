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
 *  ======== main ========
 */
function main(args)
{
    var build = new XML(readFile("package/package.bld.xml"));
   
    var pkg = build.@name;
    print("packageName=" + pkg);
    var makefiles = build.makefiles.srcFile;
    for (var i in makefiles) 
    {
        var tmp =  makefiles[i].@name;
        var pos = tmp.lastIndexOf(".mak");
        if (pos!=-1 && (tmp!="package.mak"))
        {
             goal = tmp.substring(0,pos);	
             print("buildGoal=" + goal);
        }
    }
    
    var releases = build.releases.release;
    for (var i in releases) {
        print("releaseGoal=" + releases[i].@pname);
    }
}

/*
 *  ======== readFile ========
 */
function readFile(fileName)
{
    var ins = new java.io.BufferedReader(new java.io.FileReader(fileName));
    var outs = new java.io.StringWriter();
    var nextLine;
    while ((nextLine = ins.readLine()) != null) 
    {
        outs.write(nextLine);
        outs.write("\n");
    }
    outs.flush();
    return (outs.toString());
}

main(arguments);
