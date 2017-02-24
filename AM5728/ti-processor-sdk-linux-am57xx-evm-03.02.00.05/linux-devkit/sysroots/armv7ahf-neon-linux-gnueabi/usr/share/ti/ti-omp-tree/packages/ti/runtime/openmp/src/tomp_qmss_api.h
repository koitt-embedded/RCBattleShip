#ifndef _TOMP_QMSS_API_
#define _TOMP_QMSS_API_

#include <ti/drv/qmss/qmss_drv.h>

void __TI_omp_get_qmss_memory_regions(Qmss_MemRegInfo* memRegions, 
                                      int*             memRegionCount);

void __TI_omp_update_qmss_memory_regions(Qmss_MemRegInfo* memRegions, 
                                         int              memRegionCount);

#endif
