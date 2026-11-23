// FUN_00555965: ported from Pizza Connection 2 at 0x555965.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555965
#include "pc2_port.h"

uint32_t __cdecl FUN_00555965(uint16_t *arg1,uint32_t *arg2,int *arg3)

{
  uint16_t uvalue1;
  int value2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  uint32_t local_1c [3];
  uint32_t local_10;
  uint32_t local_c;
  int local_8;
  
  uvalue1 = arg1[5];
  local_10 = *(uint32_t *)(arg1 + 3);
  local_c = *(uint32_t *)(arg1 + 1);
  uvalue3 = uvalue1 & 0x7fff;
  value4 = uvalue3 - 0x3fff;
  local_8 = (uint32_t)*arg1 << 0x10;
  if (value4 == -0x3fff) {
    value4 = 0;
    value2 = FUN_005558bd((int *)&local_10);
    if (value2 != 0) {
LAB_00555a91:
      uvalue5 = 0;
      goto LAB_00555a93;
    }
    FUN_005558b1(&local_10);
  }
  else {
    FUN_00555896((intptr_t)local_1c,&local_10);
    value2 = FUN_0055580a((intptr_t)&local_10,arg3[2]);
    if (value2 != 0) {
      value4 = uvalue3 - 0x3ffe;
    }
    value2 = arg3[1];
    if (value4 < value2 - arg3[2]) {
      FUN_005558b1(&local_10);
    }
    else {
      if (value2 < value4) {
        if (*arg3 <= value4) {
          FUN_005558b1(&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_005558d8(&local_10,arg3[3]);
          value4 = arg3[5] + *arg3;
          uvalue5 = 1;
          goto LAB_00555a93;
        }
        local_10 = local_10 & 0x7fffffff;
        value4 = arg3[5] + value4;
        FUN_005558d8(&local_10,arg3[3]);
        goto LAB_00555a91;
      }
      FUN_00555896((intptr_t)&local_10,local_1c);
      FUN_005558d8(&local_10,value2 - value4);
      FUN_0055580a((intptr_t)&local_10,arg3[2]);
      FUN_005558d8(&local_10,arg3[3] + 1);
    }
  }
  value4 = 0;
  uvalue5 = 2;
LAB_00555a93:
  local_10 = value4 << (0x1fU - (char)arg3[3] & 0x1f) |
             -(uint32_t)((uvalue1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (arg3[4] == 0x40) {
    arg2[1] = local_10;
    *arg2 = local_c;
  }
  else if (arg3[4] == 0x20) {
    *arg2 = local_10;
  }
  return uvalue5;
}
