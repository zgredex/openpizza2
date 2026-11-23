// Game_FindBestQualityBuilding: ported from Pizza Connection 2 at 0x4d8220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8220
#include "pc2_port.h"

void * Game_FindBestQualityBuilding(void)

{
  int value1;
  void *pvVar2;
  int value3;
  uint32_t extraout_EDX;
  int value4;
  int value5;
  int local_8;
  void *local_4;
  
  value4 = -1;
  local_4 = (void *)0x0;
  local_8 = 0;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,local_8);
    if ((value1 != 0) && (value5 = 0, 0 < *(int *)(value1 + 0x15c))) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value1 + 0x148),value5,(int *)0x0);
        if ((pvVar2 != (void *)0x0) &&
           (value3 = Branch_ComputeBuildingRating(pvVar2,extraout_EDX,-1), value4 < value3)) {
          value4 = value3;
          local_4 = pvVar2;
        }
        value5 = value5 + 1;
      } while (value5 < *(int *)(value1 + 0x15c));
    }
    local_8 = local_8 + 1;
  } while (local_8 < 6);
  if (value4 < 0x1e) {
    return (void *)0x0;
  }
  return local_4;
}
