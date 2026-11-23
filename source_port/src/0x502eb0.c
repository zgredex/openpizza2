// Game_HasBuildingForPlayer: ported from Pizza Connection 2 at 0x502eb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502eb0
#include "pc2_port.h"

uint32_t __fastcall Game_HasBuildingForPlayer(int arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  
  value1 = *(int *)(arg1 + 0x48);
  if (*(int *)(arg1 + 0x48) == 0x16) {
    value3 = 0;
    value1 = DAT_0057c670;
    if (0 < *(int *)(DAT_0057c670 + 0x50)) {
      do {
        value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value3,(int *)0x0);
        if (*(int *)(value1 + 0x30) < 8) {
          uvalue2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
          if (*(int *)(value1 + 0x14c + uvalue2 * 4) == 0) {
            return uvalue2 & 0xffffff00;
          }
        }
        value3 = value3 + 1;
        value1 = DAT_0057c670;
      } while (value3 < *(int *)(DAT_0057c670 + 0x50));
    }
  }
  return CONCAT31((int3)((uint32_t)value1 >> 8),1);
}
