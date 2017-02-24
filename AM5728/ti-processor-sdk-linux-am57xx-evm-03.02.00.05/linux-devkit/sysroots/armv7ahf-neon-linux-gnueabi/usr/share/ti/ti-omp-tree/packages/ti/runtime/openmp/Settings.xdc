/*! Configure top-level OpenMP runtime parameters */
metaonly module Settings {
 
    enum DebugFlag 
    {
        DEBUG,
        RELEASE
    };

    /*! Set to false if application does not depend on RTSC components */
    config Bool usingRtsc = true;

    /*! @_nodoc Set to true if OpenMP runtime is used along with OpenCL */
    config Bool usingOpenCL = false;

    /*! Set to false if the application will intialize QMSS. OpenMP startup 
     *  function __TI_omp_start[_bios_mode] requires QMSS to be initialized
     *  via Qmss_init().
     */
    config Bool runtimeInitializesQmss = true;

    /*! @_nodoc Internal debug/release flag */
    config DebugFlag debugFlag;
}

