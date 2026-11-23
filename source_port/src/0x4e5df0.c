// Game_GetPlayerByte8: ported from Pizza Connection 2 at 0x4e5df0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e5df0
#include "pc2_port.h"

uint8_t __fastcall Game_GetPlayerByte8(int arg1)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(arg1 + 4),(int *)0x0);
  if (value1 == 0) {
    return 0;
  }
  return *(uint8_t *)(value1 + 8);
}
