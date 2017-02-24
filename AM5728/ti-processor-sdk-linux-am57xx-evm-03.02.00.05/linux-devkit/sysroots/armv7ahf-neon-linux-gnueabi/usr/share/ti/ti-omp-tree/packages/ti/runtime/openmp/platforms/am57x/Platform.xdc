metaonly module Platform inherits xdc.platform.IPlatform 
{
config ti.platforms.generic.Platform.Instance CPU =
  ti.platforms.generic.Platform.create("CPU", {
    clockRate:      600,                                       
    catalogName:    "ti.catalog.c6000",
    deviceName:     "DRA7XX",

    customMemoryMap: 
    [ 
      /*-----------------------------------------------------------------------
      * L2 Related regions
      *----------------------------------------------------------------------*/
      [ "L2SRAM",    { name: "L2SRAM", 
                       base: 0x00800000, 
                       len:  0x00028000,    
                       space: "code/data", 
		       access: "RWX", } ],

      /*-----------------------------------------------------------------------
      * DDR Releated regions
      *----------------------------------------------------------------------*/
      [ "DDR3",      { name: "DDR3", 
                       base: 0x80000000, 
		       len:  0x01000000,
                       space: "code/data", 
		       access: "RWX", } ],

      /* Non-cached DDR */
      [ "DDR3_NC",   { name: "DDR3_NC",
                       base: 0x81000000,
                       len:  0x01000000,
                       space: "code/data",
                       access: "RWX", } ],

    ],

    l2Mode:"128k", 
    l1PMode:"32k", 
    l1DMode:"32k",
});

instance :
  override config string codeMemory  = "DDR3";
  override config string dataMemory  = "DDR3_NC";
  override config string stackMemory = "L2SRAM";
}
