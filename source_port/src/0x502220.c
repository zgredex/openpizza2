// Game_GetGlobalStatsBand: ported from Pizza Connection 2 at 0x502220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502220
#include "pc2_port.h"

uint64_t Game_GetGlobalStatsBand(void)

{
  int value1;
  uint32_t extraout_EDX;
  uint32_t uvalue2;
  int value3;
  double fVar4;
  uint64_t uvalue5;
  float local_4;
  
  local_4 = 0.0;
  value3 = 0;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value1 != 0) {
      fVar4 = Stats_SumFilteredFloats3(value1,-1,-1,-1);
      local_4 = (float)(fVar4 + (double)local_4);
    }
    value3 = value3 + 1;
  } while (value3 < 6);
  Stats_SumFilteredFloats3
            (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),-1,-1,-1)
  ;
  uvalue5 = (uint64_t)extraout_EDX << 0x20;
  if (0.0 < local_4) {
    uvalue5 = __ftol();
    uvalue2 = (uint32_t)(uvalue5 >> 0x20);
    value3 = (intptr_t)uvalue5;
    if (0x3c < value3) {
      return CONCAT44(uvalue2,3);
    }
    if (0x31 < value3) {
      return CONCAT44(uvalue2,2);
    }
    if (0x27 < value3) {
      return CONCAT44(uvalue2,1);
    }
  }
  return uvalue5 & 0xffffffff00000000;
}
