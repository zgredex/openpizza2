// Game_DecayCityDateBonus: ported from Pizza Connection 2 at 0x4e46f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e46f0
#include "pc2_port.h"

void __fastcall Game_DecayCityDateBonus(int arg1)

{
  double dVar1;
  
  if (*(char *)(arg1 + 0x1c) == '\0') {
    if (*(double *)(arg1 + 0x10) <= 0.0) {
      if ((0.0 <= *(double *)(arg1 + 0x10)) ||
         (dVar1 = *(double *)(arg1 + 0x10) + 2.0, *(double *)(arg1 + 0x10) = dVar1,
         dVar1 <= 0.0)) goto LAB_004e4750;
    }
    else {
      dVar1 = *(double *)(arg1 + 0x10) - 4.0;
      *(double *)(arg1 + 0x10) = dVar1;
      if (0.0 <= dVar1) goto LAB_004e4750;
    }
    *(uint32_t *)(arg1 + 0x10) = 0;
    *(uint32_t *)(arg1 + 0x14) = 0;
  }
LAB_004e4750:
  *(uint8_t *)(arg1 + 0x1c) = 0;
  Game_ComputeCityDateBonus(arg1);
  return;
}
