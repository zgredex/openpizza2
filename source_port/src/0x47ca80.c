// Game_ComputeAverageCategoryValue: ported from Pizza Connection 2 at 0x47ca80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ca80
#include "pc2_port.h"

uint64_t __fastcall Game_ComputeAverageCategoryValue(int arg1,uint32_t arg2,char arg3)

{
  char cVar1;
  int value2;
  uint32_t uvalue3;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  uint32_t extraout_EDX_01;
  int value4;
  uint64_t uvalue5;
  float local_c;
  int local_8;
  
  value4 = 0;
  local_8 = 0;
  local_c = 0.0;
  value2 = *(int *)(arg1 + 0x170c);
  if (0 < *(int *)(arg1 + 0x170c)) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x16f8),value4,(int *)0x0);
      arg2 = extraout_EDX;
      if (value2 != 0) {
        cVar1 = Game_GetPlayerByte8(value2);
        arg2 = extraout_EDX_00;
        if (cVar1 == arg3) {
          uvalue3 = Game_GetRecordByte14(value2);
          local_8 = local_8 + 1;
          local_c = (float)(intptr_t)uvalue3 + local_c;
          arg2 = extraout_EDX_01;
        }
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)(arg1 + 0x170c));
    value2 = local_8;
    if (0 < local_8) {
      local_c = local_c / (float)local_8;
      if (2.0 < local_c) {
        uvalue5 = Math_RoundFloat(2.0);
        return uvalue5;
      }
      if (local_c < 0.0) {
        local_c = 0.0;
      }
      uvalue5 = Math_RoundFloat(local_c);
      return uvalue5;
    }
  }
  return CONCAT44(arg2,value2) & 0xffffffffffffff00;
}
