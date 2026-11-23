// CityInfo_UpdateDemandRatingBars: ported from Pizza Connection 2 at 0x4c51b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c51b0
#include "pc2_port.h"

void __cdecl CityInfo_UpdateDemandRatingBars(void *arg1)

{
  void *self;
  int value1;
  int value2;
  
                    /* Fills city demand-rating bars from weather-weighted category demand. */
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value2 = 0;
  do {
    value1 = Economy_ApplyTablePercent(self,value2);
    Rating_UpdateBarByKey(arg1,0x58e,value2,value1,DAT_00580ed4);
    value2 = value2 + 1;
  } while (value2 < 8);
  Submenu_SetObjectPicture
            (arg1,*(int *)(*(int *)(DAT_0057c670 + 0x218) + 0x20),1,0x1f55,-1,
             *(int *)(DAT_0057c670 + 0x218));
  CityInfo_InitQuarterPanel(arg1);
  return;
}
