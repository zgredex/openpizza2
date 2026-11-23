// Game_GetPlayerFieldC20: ported from Pizza Connection 2 at 0x4e2280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2280
#include "pc2_port.h"

uint32_t __fastcall Game_GetPlayerFieldC20(int arg1)

{
  int value1;
  
  if (*(int *)(arg1 + 0x1d8) == 0) {
    return 0;
  }
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  return *(uint32_t *)(value1 + 0xc20 + *(int *)(arg1 + 0x48) * 4);
}
