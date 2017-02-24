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
