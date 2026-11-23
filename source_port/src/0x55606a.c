// FUN_0055606a: ported from Pizza Connection 2 at 0x55606a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55606a
#include "pc2_port.h"

uint32_t __thiscall
FUN_0055606a(void *self,uint16_t *arg1,int *arg2,uint8_t *arg3,int arg4,int arg5,
            int arg6,int arg7)

{
  uint32_t uvalue1;
  char *cptr2;
  int value3;
  uint8_t flag4;
  uint8_t *bptr5;
  uint8_t *bptr6;
  int value7;
  uint8_t *bptr8;
  char local_60 [23];
  char local_49;
  uint32_t local_44;
  uint16_t uStack_40;
  uint8_t *local_3e;
  uint16_t local_3a;
  int local_34;
  int local_30;
  uint32_t local_2c;
  int local_28;
  int local_24;
  uint8_t *local_20;
  int local_1c;
  uint32_t local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint32_t local_8;
  
  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (uint8_t *)0x0;
  local_c = 0;
  local_18 = 0;
  bptr5 = arg3;
  while( true ) {
    flag4 = *bptr5;
    self = (void *)CONCAT31((int3)((uint32_t)self >> 8),flag4);
    if ((((flag4 != 0x20) && (flag4 != 9)) && (flag4 != 10)) && (flag4 != 0xd)) break;
    bptr5 = bptr5 + 1;
  }
  value7 = 0;
LAB_005560c1:
  value3 = 1;
  flag4 = *bptr5;
  bptr6 = bptr5 + 1;
  switch(value7) {
  case 0:
    if (('0' < (char)flag4) && ((char)flag4 < ':')) {
LAB_005560de:
      value7 = 3;
      goto LAB_00556302;
    }
    if (flag4 == DAT_00576cf4) goto LAB_005560ed;
    if (flag4 == 0x2b) {
      local_2c = 0;
      value7 = 2;
      bptr5 = bptr6;
    }
    else if (flag4 == 0x2d) {
      local_2c = 0x8000;
      value7 = 2;
      bptr5 = bptr6;
    }
    else {
      if (flag4 != 0x30) goto LAB_005563dd;
LAB_0055619d:
      value7 = value3;
      bptr5 = bptr6;
    }
    goto LAB_005560c1;
  case 1:
    if (('0' < (char)flag4) && (local_14 = value3, (char)flag4 < ':')) goto LAB_005560de;
    local_14 = value3;
    if (flag4 == DAT_00576cf4) goto LAB_005561f8;
    if ((flag4 == 0x2b) || (flag4 == 0x2d)) goto LAB_00556172;
    if (flag4 == 0x30) goto LAB_0055619d;
    goto LAB_0055614b;
  case 2:
    if (('0' < (char)flag4) && ((char)flag4 < ':')) goto LAB_005560de;
    if (flag4 != DAT_00576cf4) {
      if (flag4 == 0x30) goto LAB_0055619d;
      goto LAB_00556352;
    }
LAB_005560ed:
    value7 = 5;
    break;
  case 3:
    local_14 = value3;
    while( true ) {
      if (DAT_00576cf0 < 2) {
        uvalue1 = (uint8_t)PTR_DAT_00576ae4[(uint32_t)flag4 * 2] & 4;
        self = PTR_DAT_00576ae4;
      }
      else {
        bptr5 = (uint8_t *)0x4;
        uvalue1 = CRT_Mbtowc(self,(uint32_t)flag4,4);
        self = bptr5;
      }
      if (uvalue1 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        cptr2 = local_10 + 1;
        *local_10 = flag4 - 0x30;
        local_10 = cptr2;
      }
      else {
        local_c = local_c + 1;
      }
      flag4 = *bptr6;
      bptr6 = bptr6 + 1;
    }
    if (flag4 != DAT_00576cf4) goto LAB_0055625f;
LAB_005561f8:
    value7 = 4;
    bptr5 = bptr6;
    goto LAB_005560c1;
  case 4:
    local_28 = value3;
    local_14 = value3;
    if (local_8 == 0) {
      while (flag4 == 0x30) {
        local_c = local_c + -1;
        flag4 = *bptr6;
        bptr6 = bptr6 + 1;
      }
    }
    while( true ) {
      if (DAT_00576cf0 < 2) {
        uvalue1 = (uint8_t)PTR_DAT_00576ae4[(uint32_t)flag4 * 2] & 4;
        self = PTR_DAT_00576ae4;
      }
      else {
        bptr5 = (uint8_t *)0x4;
        uvalue1 = CRT_Mbtowc(self,(uint32_t)flag4,4);
        self = bptr5;
      }
      if (uvalue1 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        cptr2 = local_10 + 1;
        *local_10 = flag4 - 0x30;
        local_10 = cptr2;
      }
      flag4 = *bptr6;
      bptr6 = bptr6 + 1;
    }
LAB_0055625f:
    if ((flag4 == 0x2b) || (flag4 == 0x2d)) {
LAB_00556172:
      bptr6 = bptr6 + -1;
      value7 = 0xb;
    }
    else {
LAB_0055614b:
      if (((char)flag4 < 'D') ||
         (('E' < (char)flag4 && (((char)flag4 < 'd' || ('e' < (char)flag4)))))) goto LAB_005563dd;
      value7 = 6;
    }
    break;
  case 5:
    if (DAT_00576cf0 < 2) {
      uvalue1 = (uint8_t)PTR_DAT_00576ae4[(uint32_t)flag4 * 2] & 4;
      self = PTR_DAT_00576ae4;
      local_28 = value3;
    }
    else {
      bptr5 = (uint8_t *)0x4;
      local_28 = value3;
      uvalue1 = CRT_Mbtowc(self,(uint32_t)flag4,4);
      self = bptr5;
    }
    if (uvalue1 != 0) {
      value7 = 4;
      goto LAB_00556303;
    }
LAB_00556352:
    bptr6 = arg3;
    goto LAB_005563e2;
  case 6:
    self = bptr5 + -1;
    arg3 = self;
    if (('0' < (char)flag4) && ((char)flag4 < ':')) goto LAB_00556300;
    if (flag4 == 0x2b) goto LAB_00556338;
    if (flag4 == 0x2d) goto LAB_0055632c;
    if (flag4 != 0x30) goto LAB_005563e0;
LAB_005562d1:
    value7 = 8;
    break;
  case 7:
    if (((char)flag4 < '1') || ('9' < (char)flag4)) {
      if (flag4 == 0x30) goto LAB_005562d1;
      goto LAB_00556352;
    }
    goto LAB_00556300;
  case 8:
    while (flag4 == 0x30) {
      flag4 = *bptr6;
      bptr6 = bptr6 + 1;
    }
    local_24 = value3;
    if (((char)flag4 < '1') || ('9' < (char)flag4)) goto LAB_005563dd;
LAB_00556300:
    value7 = 9;
LAB_00556302:
LAB_00556303:
    bptr5 = bptr6 + -1;
    goto LAB_005560c1;
  case 9:
    local_24 = 1;
    bptr5 = (uint8_t *)0x0;
    goto LAB_00556363;
  default:
    goto switchD_005560cd_caseD_a;
  case 0xb:
    if (arg7 != 0) {
      arg3 = bptr5;
      if (flag4 == 0x2b) {
LAB_00556338:
        value7 = 7;
        self = arg3;
        break;
      }
      if (flag4 != 0x2d) {
LAB_005563e0:
        bptr6 = arg3;
        goto LAB_005563e2;
      }
LAB_0055632c:
      local_1c = -1;
      value7 = 7;
      self = arg3;
      bptr5 = bptr6;
      goto LAB_005560c1;
    }
    value7 = 10;
    bptr6 = bptr5;
switchD_005560cd_caseD_a:
    bptr5 = bptr6;
    if (value7 == 10) goto LAB_005563e2;
    goto LAB_005560c1;
  }
  bptr5 = bptr6;
  goto LAB_005560c1;
LAB_00556363:
  if (DAT_00576cf0 < 2) {
    uvalue1 = (uint8_t)PTR_DAT_00576ae4[(uint32_t)flag4 * 2] & 4;
    self = PTR_DAT_00576ae4;
  }
  else {
    bptr8 = (uint8_t *)0x4;
    uvalue1 = CRT_Mbtowc(self,(uint32_t)flag4,4);
    self = bptr8;
  }
  if (uvalue1 == 0) goto LAB_005563aa;
  self = (void *)(intptr_t)(char)flag4;
  bptr5 = (uint8_t *)((intptr_t)self + (intptr_t)bptr5 * 10 + -0x30);
  if (0x1450 < (intptr_t)bptr5) goto LAB_005563a5;
  flag4 = *bptr6;
  bptr6 = bptr6 + 1;
  goto LAB_00556363;
LAB_005563a5:
  bptr5 = (uint8_t *)0x1451;
LAB_005563aa:
  local_20 = bptr5;
  while( true ) {
    if (DAT_00576cf0 < 2) {
      uvalue1 = (uint8_t)PTR_DAT_00576ae4[(uint32_t)flag4 * 2] & 4;
      self = PTR_DAT_00576ae4;
    }
    else {
      bptr5 = (uint8_t *)0x4;
      uvalue1 = CRT_Mbtowc(self,(uint32_t)flag4,4);
      self = bptr5;
    }
    if (uvalue1 == 0) break;
    flag4 = *bptr6;
    bptr6 = bptr6 + 1;
  }
LAB_005563dd:
  bptr6 = bptr6 + -1;
LAB_005563e2:
  *arg2 = (intptr_t)bptr6;
  if (local_14 == 0) {
    local_44 = (local_44 & ~(0x0u << 16)) | (((0) & 0x0u) << 16);
    local_3a = 0;
    local_3e = (uint8_t *)0x0;
    arg3 = (uint8_t *)0x0;
    local_18 = 4;
    goto LAB_005564f0;
  }
  if (local_8 < 0x19) {
    cptr2 = local_10;
  }
  else {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    cptr2 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44 = (local_44 & ~(0x0u << 16)) | (((0) & 0x0u) << 16);
    local_3a = 0;
    local_3e = (uint8_t *)0x0;
    arg3 = (uint8_t *)0x0;
  }
  else {
    while (cptr2 = cptr2 + -1, *cptr2 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_00556cb7(local_60,local_8,&local_44);
    bptr5 = local_20;
    if (local_1c < 0) {
      bptr5 = (uint8_t *)-(intptr_t)local_20;
    }
    bptr5 = bptr5 + local_c;
    if (local_24 == 0) {
      bptr5 = bptr5 + arg5;
    }
    if (local_28 == 0) {
      bptr5 = bptr5 + -arg6;
    }
    if ((intptr_t)bptr5 < 0x1451) {
      if (-0x1451 < (intptr_t)bptr5) {
        FUN_005574b1(&local_44,(uint32_t)bptr5,arg4);
        arg3 = (uint8_t *)CONCAT22(uStack_40,((uint16_t)((local_44) >> 16)));
        goto LAB_00556475;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (uint16_t)arg3;
    local_3e = arg3;
    local_44 = (local_44 & ~(0x0u << 16)) | (((local_3a) & 0x0u) << 16);
  }
LAB_00556475:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44 = (local_44 & ~(0x0u << 16)) | (((0) & 0x0u) << 16);
      local_3a = 0;
      local_3e = (uint8_t *)0x0;
      arg3 = (uint8_t *)0x0;
      local_18 = 1;
    }
  }
  else {
    arg3 = (uint8_t *)0x0;
    local_3a = 0x7fff;
    local_3e = (uint8_t *)0x80000000;
    local_44 = (local_44 & ~(0x0u << 16)) | (((0) & 0x0u) << 16);
    local_18 = 2;
  }
LAB_005564f0:
  *(uint8_t **)(arg1 + 3) = local_3e;
  *(uint8_t **)(arg1 + 1) = arg3;
  arg1[5] = local_3a | (uint16_t)local_2c;
  *arg1 = (uint16_t)local_44;
  return local_18;
}
