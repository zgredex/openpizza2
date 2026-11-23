// Game_GetCurrentPlayerCompanyName: ported from Pizza Connection 2 at 0x482820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482820
#include "pc2_port.h"

uint32_t __fastcall Game_GetCurrentPlayerCompanyName(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x224 + *(int *)(arg1 + 0x2f0) * 4);
  if (value1 == 0) {
    return 0xffffffff;
  }
  return *(uint32_t *)(value1 + 8);
}
