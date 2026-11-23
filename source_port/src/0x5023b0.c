// Game_GetPlayerTierFromC20: ported from Pizza Connection 2 at 0x5023b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5023b0
#include "pc2_port.h"

uint32_t __fastcall Game_GetPlayerTierFromC20(uint32_t arg1)

{
  int value1;
  int value2;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  switch(*(uint32_t *)(value1 + 0xc20 + value2 * 4)) {
  case 0:
  case 1:
    return 0;
  case 2:
    return 1;
  case 3:
  case 4:
    return 2;
  case 5:
  case 6:
    return 3;
  default:
    return arg1;
  }
}
