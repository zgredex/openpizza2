// FUN_00556d7e: ported from Pizza Connection 2 at 0x556d7e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556d7e
#include "pc2_port.h"

uint32_t __cdecl
FUN_00556d7e(uint32_t arg1,uint32_t arg2,uint32_t arg3,int arg4,uint8_t arg5,short *arg6)

{
  short *psVar1;
  uint32_t uvalue2;
  short *psVar3;
  char cVar4;
  uint32_t uvalue5;
  short *psVar6;
  short *psVar7;
  short svalue8;
  int value9;
  int value10;
  char *cptr11;
  uint8_t local_20;
  uint8_t local_1f;
  uint8_t local_1e;
  uint8_t local_1d;
  uint8_t local_1c;
  uint8_t local_1b;
  uint8_t local_1a;
  uint8_t local_19;
  uint8_t local_18;
  uint8_t local_17;
  uint8_t local_16;
  uint8_t local_15;
  uint16_t local_14;
  uint32_t local_12;
  uint32_t local_e;
  uint8_t local_a;
  char cStack_9;
  uint32_t local_8;
  
  psVar3 = arg6;
  uvalue5 = arg3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_8 = 1;
  if ((arg3 & 0x8000) == 0) {
    *(uint8_t *)(arg6 + 1) = 0x20;
  }
  else {
    *(uint8_t *)(arg6 + 1) = 0x2d;
  }
  if ((((short)uvalue5 == 0) && (arg2 == 0)) && (arg1 == 0)) {
LAB_00556df5:
    *psVar3 = 0;
    *(uint8_t *)(psVar3 + 1) = 0x20;
    *(uint8_t *)((intptr_t)psVar3 + 3) = 1;
    *(uint8_t *)(psVar3 + 2) = 0x30;
  }
  else {
    if ((short)uvalue5 == 0x7fff) {
      *arg6 = 1;
      if (((arg2 == 0x80000000) && (arg1 == 0)) || ((arg2 & 0x40000000) != 0)) {
        if (((arg3 & 0x8000) == 0) || (arg2 != 0xc0000000)) {
          if ((arg2 != 0x80000000) || (arg1 != 0)) goto LAB_00556e73;
          cptr11 = "1#INF";
        }
        else {
          if (arg1 != 0) {
LAB_00556e73:
            cptr11 = "1#QNAN";
            goto LAB_00556e78;
          }
          cptr11 = "1#IND";
        }
        _strcpy((uint32_t *)(arg6 + 2),(uint32_t *)cptr11);
        *(uint8_t *)((intptr_t)psVar3 + 3) = 5;
      }
      else {
        cptr11 = "1#SNAN";
LAB_00556e78:
        _strcpy((uint32_t *)(arg6 + 2),(uint32_t *)cptr11);
        *(uint8_t *)((intptr_t)psVar3 + 3) = 6;
      }
      local_8 = 0;
      goto LAB_00556fe4;
    }
    local_14 = 0;
    local_a = (uint8_t)uvalue5;
    cStack_9 = (char)(uvalue5 >> 8);
    svalue8 = (short)(((uvalue5 >> 8) + (arg2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uvalue5 * 0x4d10 >>
                   0x10);
    local_e = arg2;
    local_12 = arg1;
    FUN_005574b1((int *)&local_14,-(intptr_t)svalue8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      svalue8 = svalue8 + 1;
      FUN_00557291((int *)&local_14,(int *)&local_20);
    }
    *psVar3 = svalue8;
    if ((arg5 & 1) == 0) {
      value10 = arg4;
    }
    else {
      value10 = arg4 + svalue8;
      if (arg4 + svalue8 < 1) goto LAB_00556df5;
    }
    if (0x15 < value10) {
      value10 = 0x15;
    }
    value9 = CONCAT11(cStack_9,local_a) - 0x3ffe;
    local_a = 0;
    cStack_9 = '\0';
    arg6 = (short *)0x8;
    do {
      FUN_00556c5c((uint32_t *)&local_14);
      arg6 = (short *)((intptr_t)arg6 + -1);
    } while (arg6 != (short *)0x0);
    if (value9 < 0) {
      arg6 = (short *)0x0;
      for (uvalue5 = -value9 & 0xff; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        FUN_00556c8a((uint32_t *)&local_14);
      }
    }
    arg4 = value10 + 1;
    psVar6 = psVar3 + 2;
    if (0 < arg4) {
      arg6 = psVar6;
      uvalue5 = local_12;
      uvalue2 = local_e;
      do {
        local_e = (local_e & ~(0xffffu << 16)) | ((((uint16_t)(uvalue2 >> 0x10)) & 0xffffu) << 16);
        local_e = (local_e & ~(0x0u << 16)) | ((((uint16_t)uvalue2) & 0x0u) << 16);
        local_12 = (local_12 & ~(0xffffu << 16)) | ((((uint16_t)(uvalue5 >> 0x10)) & 0xffffu) << 16);
        local_12 = (local_12 & ~(0x0u << 16)) | ((((uint16_t)uvalue5) & 0x0u) << 16);
        arg1 = CONCAT22((uint16_t)local_12,local_14);
        arg2 = CONCAT22((uint16_t)local_e,((uint16_t)((local_12) >> 16)));
        arg3 = CONCAT13(cStack_9,CONCAT12(local_a,((uint16_t)((local_e) >> 16))));
        local_12 = uvalue5;
        local_e = uvalue2;
        FUN_00556c5c((uint32_t *)&local_14);
        FUN_00556c5c((uint32_t *)&local_14);
        ___add_12((uint32_t *)&local_14,&arg1);
        FUN_00556c5c((uint32_t *)&local_14);
        cVar4 = cStack_9;
        cStack_9 = '\0';
        psVar6 = (short *)((intptr_t)arg6 + 1);
        arg4 = arg4 + -1;
        *(char *)arg6 = cVar4 + '0';
        arg6 = psVar6;
        uvalue5 = local_12;
        uvalue2 = local_e;
      } while (arg4 != 0);
    }
    psVar7 = psVar6 + -1;
    psVar1 = psVar3 + 2;
    if ('4' < *(char *)((intptr_t)psVar6 + -1)) {
      for (; psVar1 <= psVar7; psVar7 = (short *)((intptr_t)psVar7 + -1)) {
        if ((char)*psVar7 != '9') {
          if (psVar1 <= psVar7) goto LAB_00556fd0;
          break;
        }
        *(char *)psVar7 = '0';
      }
      psVar7 = (short *)((intptr_t)psVar7 + 1);
      *psVar3 = *psVar3 + 1;
LAB_00556fd0:
      *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_00556fd2:
      cVar4 = ((char)psVar7 - (char)psVar3) + -3;
      *(char *)((intptr_t)psVar3 + 3) = cVar4;
      *(uint8_t *)(cVar4 + 4 + (intptr_t)psVar3) = 0;
      goto LAB_00556fe4;
    }
    for (; psVar1 <= psVar7; psVar7 = (short *)((intptr_t)psVar7 + -1)) {
      if ((char)*psVar7 != '0') {
        if (psVar1 <= psVar7) goto LAB_00556fd2;
        break;
      }
    }
    *psVar3 = 0;
    *(uint8_t *)(psVar3 + 1) = 0x20;
    *(uint8_t *)((intptr_t)psVar3 + 3) = 1;
    *(char *)psVar1 = '0';
  }
  *(uint8_t *)((intptr_t)psVar3 + 5) = 0;
  local_8 = 1;
LAB_00556fe4:
  return local_8;
}
