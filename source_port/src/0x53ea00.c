// Sound_ADPCMDecode: ported from Pizza Connection 2 at 0x53ea00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53ea00
#include "pc2_port.h"

void __cdecl Sound_ADPCMDecode(char *arg1,uint16_t *arg2,uint32_t arg3,short *arg4)

{
  bool flag1;
  uint32_t uvalue2;
  int value3;
  char cVar4;
  uint16_t *uptr5;
  uint16_t *uptr6;
  int value7;
  int local_18;
  int local_14;
  int local_10;
  char *local_c;
  uint32_t local_8;
  int local_4;
  
  cVar4 = (char)arg4[1];
  local_14 = (intptr_t)cVar4;
  local_18 = (intptr_t)(char)arg4[3];
  local_c = arg1;
  local_10 = (intptr_t)(short)(&DAT_00574a64)[local_14];
  arg1 = (char *)(intptr_t)arg4[2];
  local_8 = 0;
  local_4 = (intptr_t)(short)(&DAT_00574a64)[local_18];
  arg3 = arg3 >> 3;
  uptr6 = (uint16_t *)(intptr_t)*arg4;
  if (arg3 != 0) {
    uptr6 = arg2;
    arg2 = (uint16_t *)(intptr_t)*arg4;
    do {
      flag1 = false;
      value7 = 8;
      uptr5 = uptr6;
      do {
        if (flag1) {
          uvalue2 = (intptr_t)local_8 >> 4;
        }
        else {
          uvalue2 = (uint32_t)*local_c;
          local_c = local_c + 1;
          local_8 = uvalue2;
        }
        flag1 = !flag1;
        local_14 = local_14 + *(int *)(&DAT_00574a24 + (uvalue2 & 0xf) * 4);
        if (local_14 < 0) {
          local_14 = 0;
        }
        else if (0x58 < local_14) {
          local_14 = 0x58;
        }
        value3 = 0;
        if ((uvalue2 & 4) != 0) {
          value3 = local_10;
        }
        if ((uvalue2 & 2) != 0) {
          value3 = value3 + (local_10 >> 1);
        }
        if ((uvalue2 & 1) != 0) {
          value3 = value3 + (local_10 >> 2);
        }
        value3 = value3 + (local_10 >> 3);
        if ((uvalue2 & 8) != 0) {
          value3 = -value3;
        }
        arg2 = (uint16_t *)((intptr_t)arg2 + value3);
        if ((intptr_t)arg2 < 0x8000) {
          if ((intptr_t)arg2 < -0x8000) {
            arg2 = (uint16_t *)0xffff8000;
          }
        }
        else {
          arg2 = (uint16_t *)0x7fff;
        }
        value7 = value7 + -1;
        local_10 = (intptr_t)(short)(&DAT_00574a64)[local_14];
        *uptr5 = (short)arg2;
        uptr5 = uptr5 + 2;
      } while (value7 != 0);
      flag1 = false;
      value7 = 8;
      uptr5 = uptr6 + 1;
      do {
        uptr6 = uptr5;
        if (flag1) {
          uvalue2 = (intptr_t)local_8 >> 4;
        }
        else {
          uvalue2 = (uint32_t)*local_c;
          local_c = local_c + 1;
          local_8 = uvalue2;
        }
        flag1 = !flag1;
        local_18 = local_18 + *(int *)(&DAT_00574a24 + (uvalue2 & 0xf) * 4);
        if (local_18 < 0) {
          local_18 = 0;
        }
        else if (0x58 < local_18) {
          local_18 = 0x58;
        }
        value3 = 0;
        if ((uvalue2 & 4) != 0) {
          value3 = local_4;
        }
        if ((uvalue2 & 2) != 0) {
          value3 = value3 + (local_4 >> 1);
        }
        if ((uvalue2 & 1) != 0) {
          value3 = value3 + (local_4 >> 2);
        }
        value3 = value3 + (local_4 >> 3);
        if ((uvalue2 & 8) != 0) {
          value3 = -value3;
        }
        arg1 = arg1 + value3;
        if ((intptr_t)arg1 < 0x8000) {
          if ((intptr_t)arg1 < -0x8000) {
            arg1 = (char *)0xffff8000;
          }
        }
        else {
          arg1 = (char *)0x7fff;
        }
        local_4 = (intptr_t)(short)(&DAT_00574a64)[local_18];
        *uptr6 = (short)arg1;
        value7 = value7 + -1;
        uptr5 = uptr6 + 2;
      } while (value7 != 0);
      arg3 = arg3 - 1;
      uptr6 = uptr6 + 1;
    } while (arg3 != 0);
    cVar4 = (char)local_14;
    uptr6 = arg2;
  }
  arg2 = uptr6;
  *(char *)(arg4 + 1) = cVar4;
  *(char *)(arg4 + 3) = (char)local_18;
  *arg4 = (short)arg2;
  arg4[2] = (short)arg1;
  return;
}
