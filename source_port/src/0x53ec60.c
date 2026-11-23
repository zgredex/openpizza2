// Sound_DecodeADPCM: ported from Pizza Connection 2 at 0x53ec60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53ec60
#include "pc2_port.h"

void __cdecl Sound_DecodeADPCM(char *arg1,short *arg2,int arg3,short *arg4)

{
  short svalue1;
  bool flag2;
  char *cptr3;
  int value4;
  int value5;
  int value6;
  int value7;
  short *psVar8;
  int local_4;
  
  psVar8 = arg2;
  value6 = (intptr_t)(char)arg4[1];
  arg2 = (short *)arg1;
  flag2 = false;
  value7 = (intptr_t)*arg4;
  svalue1 = (&DAT_00574a64)[value6];
  local_4 = arg3 * 2;
  arg1 = (char *)0x0;
  if (local_4 == 0) {
    *arg4 = *arg4;
    *(char *)(arg4 + 1) = (char)arg4[1];
    return;
  }
  do {
    value5 = (intptr_t)svalue1;
    if (flag2) {
      cptr3 = (char *)((intptr_t)arg1 >> 4);
    }
    else {
      cptr3 = (char *)(intptr_t)(char)*arg2;
      arg2 = (short *)((intptr_t)arg2 + 1);
      arg1 = cptr3;
    }
    flag2 = !flag2;
    value6 = value6 + *(int *)(&DAT_00574a24 + ((uint32_t)cptr3 & 0xf) * 4);
    if (value6 < 0) {
      value6 = 0;
    }
    else if (0x58 < value6) {
      value6 = 0x58;
    }
    value4 = 0;
    if (((uint32_t)cptr3 & 4) != 0) {
      value4 = value5;
    }
    if (((uint32_t)cptr3 & 2) != 0) {
      value4 = value4 + (value5 >> 1);
    }
    if (((uint32_t)cptr3 & 1) != 0) {
      value4 = value4 + (value5 >> 2);
    }
    value4 = value4 + (value5 >> 3);
    if (((uint32_t)cptr3 & 8) != 0) {
      value4 = -value4;
    }
    value7 = value7 + value4;
    if (value7 < 0x8000) {
      if (value7 < -0x8000) {
        value7 = -0x8000;
      }
    }
    else {
      value7 = 0x7fff;
    }
    *psVar8 = (short)value7;
    svalue1 = (&DAT_00574a64)[value6];
    psVar8 = psVar8 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  *arg4 = (short)value7;
  *(char *)(arg4 + 1) = (char)value6;
  return;
}
