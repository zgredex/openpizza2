// Map_FindObjectOnApproachLine: ported from Pizza Connection 2 at 0x512860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512860
#include "pc2_port.h"

int Map_FindObjectOnApproachLine(void *arg1,int arg2)

{
  bool flag1;
  bool flag2;
  bool flag3;
  char cVar4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  uint32_t uvalue8;
  int value9;
  int value10;
  int value11;
  int value12;
  int value13;
  int64_t lvalue14;
  int local_14;
  float local_10;
  
  value12 = *(int *)(arg2 + 0x18);
  value13 = *(int *)(arg2 + 0x14);
  uvalue8 = 0x10a - value13;
  uvalue5 = 0x112 - value12;
  flag1 = value13 < 0x10b;
  flag2 = value12 < 0x113;
  if (uvalue8 == 0) {
    local_10 = 0.0;
  }
  else {
    local_10 = (float)(intptr_t)uvalue5 / (float)(intptr_t)uvalue8;
  }
  flag3 = false;
  local_14 = 0;
  uvalue6 = Map_GetTileByte(DAT_0057c670,value13,value12);
  cVar4 = (char)uvalue6;
  do {
    if (cVar4 == '\0') {
      return 0;
    }
    if ((value13 == 0x10a) && (value12 == 0x112)) {
      flag3 = true;
    }
    value11 = 0;
    if (0 < *(int *)((intptr_t)arg1 + 0x14)) {
      do {
        value7 = IDMap_Lookup(arg1,value11,(int *)0x0);
        if ((((value7 != arg2) &&
             (value10 = *(int *)(value7 + 0x18) - value12, value9 = *(int *)(value7 + 0x14) - value13,
             value10 * value10 + value9 * value9 < 0xe1)) && (flag3)) && (local_14 < 0xf)) {
          return value7;
        }
        value11 = value11 + 1;
      } while (value11 < *(int *)((intptr_t)arg1 + 0x14));
    }
    if ((intptr_t)((uvalue5 ^ (intptr_t)uvalue5 >> 0x1f) - ((intptr_t)uvalue5 >> 0x1f)) <
        (intptr_t)((uvalue8 ^ (intptr_t)uvalue8 >> 0x1f) - ((intptr_t)uvalue8 >> 0x1f))) {
      value13 = value13 + (flag1 - 1 & 0xfffffffe) + 1;
      lvalue14 = Math_RoundFloat(((float)value13 - 266.0) * local_10 + 274.0);
      value12 = (intptr_t)lvalue14;
    }
    else {
      value12 = value12 + (flag2 - 1 & 0xfffffffe) + 1;
      if (local_10 != 0.0) {
        lvalue14 = Math_RoundFloat(((float)value12 - 274.0) / local_10 + 266.0);
        value13 = (intptr_t)lvalue14;
      }
    }
    if (flag3) {
      local_14 = local_14 + -1;
    }
    else {
      local_14 = local_14 + 1;
    }
    uvalue6 = Map_GetTileByte(DAT_0057c670,value13,value12);
    cVar4 = (char)uvalue6;
  } while( true );
}
