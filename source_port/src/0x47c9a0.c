// Game_GetAverageRecordValueByByte8: ported from Pizza Connection 2 at 0x47c9a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c9a0
#include "pc2_port.h"

uint64_t __fastcall Game_GetAverageRecordValueByByte8(int arg1,uint32_t arg2,char arg3)

{
  char cVar1;
  int value2;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  int value3;
  uint64_t uvalue4;
  float local_8;
  int local_4;
  
  value3 = 0;
  local_4 = 0;
  local_8 = 0.0;
  value2 = *(int *)(arg1 + 0x170c);
  if (0 < *(int *)(arg1 + 0x170c)) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x16f8),value3,(int *)0x0);
      arg2 = extraout_EDX;
      if (value2 != 0) {
        cVar1 = Game_GetPlayerByte8(value2);
        arg2 = extraout_EDX_00;
        if (cVar1 == arg3) {
          local_4 = local_4 + 1;
          local_8 = (float)*(int *)(value2 + 0xc) + local_8;
        }
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)(arg1 + 0x170c));
    value2 = local_4;
    if (0 < local_4) {
      local_8 = local_8 / (float)local_4;
      if (100.0 < local_8) {
        uvalue4 = Math_RoundFloat(100.0);
        return uvalue4;
      }
      if (local_8 < 0.0) {
        local_8 = 0.0;
      }
      uvalue4 = Math_RoundFloat(local_8);
      return uvalue4;
    }
  }
  return CONCAT44(arg2,value2) & 0xffffffffffffff00;
}
