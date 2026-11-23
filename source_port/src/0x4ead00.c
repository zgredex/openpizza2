// Game_TickWorldObjects: ported from Pizza Connection 2 at 0x4ead00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ead00
#include "pc2_port.h"

void __fastcall Game_TickWorldObjects(int arg1)

{
  void *pvVar1;
  int value2;
  
                    /* Ticks all world-object animations and records. */
  if ((*(int *)(DAT_0057c670 + 0x1508) == 0) && (value2 = 0, 0 < *(int *)(arg1 + 0x2c40c))) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)(arg1 + 0x2c3f8),value2,(int *)0x0);
      CityAds_UpdateCampaign(pvVar1);
      value2 = value2 + 1;
    } while (value2 < *(int *)(arg1 + 0x2c40c));
  }
  return;
}
