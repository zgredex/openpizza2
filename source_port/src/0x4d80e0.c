// Game_GetLowestValuePlayer: ported from Pizza Connection 2 at 0x4d80e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d80e0
#include "pc2_port.h"

int __fastcall Game_GetLowestValuePlayer(int arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  uint32_t *uptr5;
  
  value3 = -1;
  uvalue2 = 999999999;
  value4 = 0;
  uptr5 = (uint32_t *)(arg1 + 0xdac);
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value4);
    if ((value1 != 0) && (*uptr5 < uvalue2)) {
      uvalue2 = *uptr5;
      value3 = value4;
    }
    value4 = value4 + 1;
    uptr5 = uptr5 + 1;
  } while (value4 < 6);
  return value3;
}
