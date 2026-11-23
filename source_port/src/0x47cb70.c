// Game_GetAverageCompanyValueByByte8: ported from Pizza Connection 2 at 0x47cb70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47cb70
#include "pc2_port.h"

int64_t __fastcall Game_GetAverageCompanyValueByByte8(int arg1,uint32_t arg2,char arg3)

{
  char cVar1;
  int value2;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  int value3;
  int value4;
  int64_t lvalue5;
  float local_c;
  
  value3 = 0;
  value4 = 0;
  local_c = 0.0;
  if (0 < *(int *)(arg1 + 0x170c)) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x16f8),value4,(int *)0x0);
      cVar1 = Game_GetPlayerByte8(value2);
      arg2 = extraout_EDX;
      if (cVar1 == arg3) {
        value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(value2 + 4),(int *)0x0);
        local_c = (float)*(double *)(value2 + 0x70) + local_c;
        value3 = value3 + 1;
        arg2 = extraout_EDX_00;
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)(arg1 + 0x170c));
    if (0 < value3) {
      lvalue5 = Math_RoundFloat(local_c / (float)value3);
      return lvalue5;
    }
  }
  return (uint64_t)arg2 << 0x20;
}
