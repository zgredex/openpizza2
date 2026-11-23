// Game_HasIdleOtherPlayer: ported from Pizza Connection 2 at 0x48e060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48e060
#include "pc2_port.h"

int __fastcall Game_HasIdleOtherPlayer(void *arg1)

{
  int value1;
  uint3 uvalue2;
  int value3;
  
  value3 = 0;
  while( true ) {
    value1 = Game_GetPlayerBySlot(arg1,value3);
    uvalue2 = (uint3)((uint32_t)value1 >> 8);
    if (((value1 != *(int *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x2ec) * 4 + 0x200)) &&
        (value1 != 0)) && (*(int *)(value1 + 0x50) == 0)) break;
    value3 = value3 + 1;
    if (5 < value3) {
      return (uint32_t)uvalue2 << 8;
    }
  }
  return CONCAT31(uvalue2,1);
}
