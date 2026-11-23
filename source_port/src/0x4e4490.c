// Game_GetAdjustedValue: ported from Pizza Connection 2 at 0x4e4490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4490
#include "pc2_port.h"

int __fastcall Game_GetAdjustedValue(int arg1)

{
  int value1;
  int value2;
  int value3;
  int64_t lvalue4;
  
  lvalue4 = __ftol();
  value2 = *(int *)(arg1 + 0xc);
  value3 = (intptr_t)lvalue4 + *(int *)(arg1 + 0x18) + *(int *)(arg1 + 8);
  value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (value2 == value1) {
    value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(value1 + 0xc4) == 0) {
      if (*(int *)(value1 + 0x1ac) != 0) {
        value3 = 0x78;
      }
    }
    else {
      value3 = (value3 * 0xf) / 10;
    }
  }
  if (value2 != -1) {
    IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0xc));
    value2 = Game_GetPlayerCity(value2);
    lvalue4 = __ftol();
    value3 = ((intptr_t)lvalue4 * ((*(int *)(value2 + 100) + *(int *)(value2 + 0x4c)) * 3 + 100)) / 100;
  }
  if ((0 < *(int *)(arg1 + 8)) && (value3 < 0x3c)) {
    return 0x3c;
  }
  value2 = 500;
  if (value3 < 0x1f5) {
    value2 = value3;
  }
  return value2;
}
