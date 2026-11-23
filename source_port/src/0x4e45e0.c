// Game_ComputeCityDateBonus: ported from Pizza Connection 2 at 0x4e45e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e45e0
#include "pc2_port.h"

void __fastcall Game_ComputeCityDateBonus(int arg1)

{
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  
  value6 = 0;
  *(uint32_t *)(arg1 + 0x18) = 0;
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0xc));
  value2 = Game_GetPlayerCity(value1);
  value1 = *(int *)(value2 + 0xa0);
  if (0 < value1) {
    do {
      value3 = IDMap_Lookup((void *)(value2 + 0x8c),value6,(int *)0x0);
      value5 = ((uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 4) -
              (uint32_t)*(uint16_t *)(value3 + 8)) + 1;
      if ((0 < value5) && (value5 < 4)) {
        value3 = *(int *)(value3 + 4);
        if (value3 == 0) {
          uvalue4 = 0x1e;
        }
        else if (value3 == 1) {
          uvalue4 = 0x28;
        }
        else {
          if (value3 != 2) goto LAB_004e4665;
          uvalue4 = 0x14;
        }
        *(int *)(arg1 + 0x18) =
             *(int *)(arg1 + 0x18) + (intptr_t)((int64_t)(uint64_t)uvalue4 / (int64_t)value5);
      }
LAB_004e4665:
      value6 = value6 + 1;
    } while (value6 < value1);
  }
  return;
}
