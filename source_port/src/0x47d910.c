// Player_ComputeProductQualityScore: ported from Pizza Connection 2 at 0x47d910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47d910
#include "pc2_port.h"

int __fastcall
Player_ComputeProductQualityScore
          (int arg1,int arg2,uint32_t arg3,int arg4,int arg5)

{
  int value1;
  uint32_t uvalue2;
  int *ptr3;
  int value4;
  int extraout_EDX;
  int value5;
  int value6;
  int value7;
  uint64_t uvalue8;
  int64_t lvalue9;
  int local_c;
  
  value6 = 0;
  value5 = 0;
  value7 = 0;
  local_c = 100;
  if (*(int *)(arg1 + 0x19ac) < 1) {
LAB_0047d986:
    value7 = 0;
LAB_0047d988:
    if (value7 < *(int *)(&DAT_00567938 + arg4 * 4)) {
      arg2 = (value7 - *(int *)(&DAT_00567938 + arg4 * 4)) * 2 + 100;
      local_c = arg2;
    }
  }
  else {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x1998),value7,(int *)0x0);
      if ((value1 != 0) && (*(int *)(value1 + 0x1c) != 0)) {
        value6 = value6 + 1;
        value5 = value5 + *(int *)(value1 + 4);
      }
      value7 = value7 + 1;
    } while (value7 < *(int *)(arg1 + 0x19ac));
    arg2 = extraout_EDX;
    if (value6 == 0) goto LAB_0047d986;
    value7 = value5 / value6;
    arg2 = value5 % value6;
    if (-1 < value7) goto LAB_0047d988;
    local_c = (value7 - *(int *)(&DAT_00567938 + arg4 * 4)) * 4 + 100;
  }
  uvalue8 = Game_ComputeAverageCategoryValue(arg1,arg2,'\x05');
  value5 = (intptr_t)(uvalue8 >> 0x20);
  uvalue2 = (uint32_t)uvalue8 & 0xff;
  *(uint32_t *)(arg1 + 0x1870) = uvalue2;
  if ((intptr_t)uvalue2 < *(int *)(&DAT_00567958 + arg4 * 4)) {
    value5 = local_c + (uvalue2 - *(int *)(&DAT_00567958 + arg4 * 4)) * 10;
  }
  uvalue8 = Game_GetAverageRecordValueByByte8(arg1,value5,'\x05');
  uvalue2 = (uint32_t)uvalue8 & 0xff;
  lvalue9 = Game_GetAverageCompanyValueByByte8(arg1,(uint32_t)(uvalue8 >> 0x20),'\x05');
  lvalue9 = Math_RoundFloat((float)uvalue2 * 0.01 * (float)(intptr_t)lvalue9);
  value5 = (intptr_t)lvalue9;
  if (value5 < 0) {
    if (5 < value5) goto LAB_0047da2f;
    value5 = 100;
  }
  else if (value5 < 6) {
    value5 = *(int *)(&DAT_00567978 + (value5 + arg4 * 6) * 4);
  }
  else {
LAB_0047da2f:
    value5 = *(int *)(&DAT_0056798c + arg4 * 0x18);
  }
  value6 = 0;
  value5 = uvalue2 - value5;
  value7 = 0;
  value1 = 0;
  if (0 < *(int *)(arg1 + 0x1514)) {
    do {
      ptr3 = (int *)IDMap_Lookup((void *)(arg1 + 0x1500),value1,(int *)0x0);
      value4 = *ptr3;
      if ((value4 != 0) && (*(char *)(value4 + 0x824) == '\0')) {
        value6 = value6 + 1;
        value4 = Rating_ClampAdjusted(value4);
        value7 = value7 + value4;
      }
      value1 = value1 + 1;
    } while (value1 < *(int *)(arg1 + 0x1514));
    if (0 < value6) {
      value6 = (value7 / value6) / 0xc;
      if (value6 < 0) {
        return value5 - *(int *)(&DAT_00567a38 + arg5 * 0x24);
      }
      if (8 < value6) {
        return value5 - *(int *)(&DAT_00567a58 + arg5 * 0x24);
      }
      goto LAB_0047daca;
    }
  }
  value6 = 0;
LAB_0047daca:
  return value5 - *(int *)(&DAT_00567a38 + (value6 + arg5 * 9) * 4);
}
