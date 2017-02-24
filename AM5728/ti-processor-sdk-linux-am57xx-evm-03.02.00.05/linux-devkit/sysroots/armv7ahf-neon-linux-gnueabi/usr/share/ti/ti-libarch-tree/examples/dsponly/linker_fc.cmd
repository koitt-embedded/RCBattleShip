

SECTIONS
{
    .fclocalfar :
    {
        "edmamgr.ae66"      (.fardata)
        "ecpy.ae66"         (.fardata)
        "edma3Chan.ae66"    (.fardata)
        "edma3.ae66"	    (.fardata)
        "rman.ae66"	        (.fardata)
        "nullres.ae66"	    (.fardata)
        "fcsettings.ae66"   (.fardata)
        "edma3_lld_rm.ae66" (.fardata)

        "edmamgr.ae66"      (.far)
        "ecpy.ae66"         (.far)
        "edma3Chan.ae66"    (.far)
        "edma3.ae66"	    (.far)
        "rman.ae66"	        (.far)
        "nullres.ae66"	    (.far)
        "fcsettings.ae66"   (.far)
        "edma3_lld_rm.ae66" (.far)
    } > L2SRAM

}
