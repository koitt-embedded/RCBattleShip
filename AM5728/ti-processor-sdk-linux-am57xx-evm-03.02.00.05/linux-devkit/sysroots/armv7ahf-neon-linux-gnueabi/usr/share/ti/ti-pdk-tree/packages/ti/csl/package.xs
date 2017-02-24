/*
 *  ======== package.xs ========
 *
 */


/*
 *  ======== Package.getLibs ========
 *  This function is called when a program's configuration files are
 *  being generated and it returns the name of a library appropriate
 *  for the program's configuration.
 */

function getLibs(prog)
{

    var suffix = prog.build.target.suffix;

    /* Default CSL library */
    var name = this.$name + ".a" + suffix;

    /* Check if intc library needs to be returned */
    var name_intc = "";
    if (this.Settings.useCSLIntcLib == true)
    {
       name_intc = this.$name + ".intc" + ".a" + suffix;
    }    

    /* Read LIBDIR variable */
    var lib_dir = java.lang.System.getenv("LIBDIR");

    /* If NULL, default to "lib" folder */
    if (lib_dir == null)
    {
        lib_dir = "./lib";
    } else {
        print ("\tSystem environment LIBDIR variable defined : " + lib_dir);
    }

    /* Device types supported */
    var deviceTypes = [
                        'k2k',
                        'k2h',
                        'k2e',
                        'k2l',
                        'k2g',
                        'dra75x',
                        'dra78x',
                        'am572x',
                        'am571x',
                        'c6678',
                        'c6657',
                        'am335x',
                        'am437x'
                      ];
    
    /* Search for the supported devices (defined in config.bld) */
    for each(var device in deviceTypes)
    {
        if (this.Settings.deviceType.equals(device))
        {
            lib_dir = lib_dir + "/" + device;
            break;
        }
    }

    /* Get target folder, if applicable */
    if ( java.lang.String(suffix).contains('66') )
        lib_dir = lib_dir + "/c66";
	else if (java.lang.String(suffix).contains('a15'))
		lib_dir = lib_dir + "/a15";
	else if (java.lang.String(suffix).contains('m4'))
		lib_dir = lib_dir + "/m4";
	else if (java.lang.String(suffix).contains('a8'))
		lib_dir = lib_dir + "/a8";
	else if (java.lang.String(suffix).contains('a9'))
		lib_dir = lib_dir + "/a9";

	var libProfiles = ["debug", "release"];
    /* get the configured library profile */
    for each(var profile in libProfiles)
    {
        if (this.Settings.libProfile.equals(profile))
        {
            lib_dir = lib_dir + "/" + profile;
            break;
        }
    }	
	
    if ((java.io.File(this.packageBase + lib_dir + "/" + name).exists()) || 
        (java.io.File(this.packageBase + lib_dir + "/" + name_intc).exists())) 
    {
        /* CSL library */
        var lib = lib_dir + "/" + name;

        /* CSL INTC library, if exist */
        if(name_intc != "")
        {
            lib = lib + ";" + lib_dir +"/" + name_intc;
        }

        print ("\tLinking with library " + this.$name + ":" + lib);
        return lib;
    }
    
    /* Could not find any library, throw exception */
    if(name_intc != "")
        throw new Error("\tLibrary not found : " + name + ", " + name_intc);
    else
        throw new Error("\tLibrary not found : " + name);
}

/*
 *  ======== package.close ========
 */
function close()
{    
    if (xdc.om.$name != 'cfg') {
        return;
    }
}

