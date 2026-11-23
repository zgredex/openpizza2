// IsoMap_Load: ported from Pizza Connection 2 at 0x4eb4f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eb4f0
#include "pc2_port.h"


void __thiscall IsoMap_Load(void *self,int arg1,int arg2)

{
  char cVar1;
  bool flag2;
  int *this_00;
  int *this_01;
  char *cptr3;
  uint32_t *uptr4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  char *cptr8;
  char *cptr9;
  int local_440;
  uint32_t local_43c;
  int *local_438;
  int iStack_434;
  char *local_430 [4];
  uint8_t *local_420;
  uint8_t *local_41c;
  uint8_t *local_418;
  uint8_t *local_414;
  uint8_t local_410 [260];
  char acStack_30c [256];
  uint8_t local_20c [256];
  uint8_t local_10c [256];
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559fba;
  pvStack_c = ExceptionList;
  local_430[0] = s_KLEIN_00567cd4;
  local_430[1] = s_MITTEL_00567ccc;
  local_430[2] = s_GROSS_00567cc4;
  local_430[3] = &DAT_00567cbc;
  local_420 = &DAT_00567cb4;
  local_41c = &DAT_00567cac;
  local_418 = &DAT_00567ca4;
  local_414 = &DAT_00567ca0;
  flag2 = false;
  ExceptionList = &pvStack_c;
  String_Format(local_20c,(uint8_t *)s_Iso_Filiale_ROH__s_sty_00571adc,local_430[arg1]);
  String_Format(local_10c,(uint8_t *)s_Iso_Filiale__s__s_sty_00571ac4,local_430[arg2 + 3]);
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  if ((arg2 == 0) && (arg1 == 1)) {
    String_Format(local_410,(uint8_t *)s__sIsokarten__s_00571a60,&DAT_0057c278);
    local_438 = operator_new(0x5c);
    local_4 = arg2;
    if (local_438 == (int *)0x0) {
      this_00 = (int *)0x0;
    }
    else {
      this_00 = CRT_Ifstream_Construct();
    }
    local_4 = 0xffffffff;
    if ((*(uint8_t *)(*(int *)(*this_00 + 4) + 8 + (intptr_t)this_00) & 6) != 0) {
      CS_Leave(*(int *)(DAT_0057c670 + 0x240));
      NoOp_Stub();
    }
    flag2 = true;
  }
  else {
    this_00 = local_438;
  }
  String_Format(local_410,(uint8_t *)s__sIsokarten__s_00571a60,&DAT_0057c278);
  local_438 = operator_new(0x5c);
  local_4 = 1;
  if (local_438 == (void *)0x0) {
    this_01 = (int *)0x0;
  }
  else {
    this_01 = CRT_Ifstream_Construct();
  }
  local_4 = 0xffffffff;
  if ((*(uint8_t *)(*(int *)(*this_01 + 4) + 8 + (intptr_t)this_01) & 6) != 0) {
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
    NoOp_Stub();
  }
  if (flag2) {
    CRT_Istream_Read(this_00,(intptr_t)self + 0x7c,0x1e);
  }
  CRT_Istream_Read(this_01,(intptr_t)self + 0x7c,0x1e);
  do {
    CRT_Istream_Read(this_01,&local_440,4);
    if (flag2) {
      CRT_Istream_Read(this_00,&local_440,4);
    }
    if (local_440 == -1) break;
    if (flag2) {
      CRT_Istream_Read(this_00,&local_43c,4);
    }
    CRT_Istream_Read(this_01,&local_43c,4);
    if (*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_440 * 0xc) != 0) {
      local_43c = Game_GetMapValue(*(void **)((intptr_t)self + 4),local_43c);
      *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_440 * 0xc) + 0x10) = local_43c;
    }
  } while (local_440 != -1);
  if (this_01 != (int *)0x0) {
    (*(code *)**(uint32_t **)(*(int *)(*this_01 + 4) + (intptr_t)this_01))(1);
  }
  if ((flag2) && (this_00 != (int *)0x0)) {
    (*(code *)**(uint32_t **)(*(int *)(*this_00 + 4) + (intptr_t)this_00))(1);
  }
  uvalue5 = 0xffffffff;
  cptr3 = (char *)((intptr_t)self + 0x7c);
  do {
    cptr9 = cptr3;
    if (uvalue5 == 0) break;
    uvalue5 = uvalue5 - 1;
    cptr9 = cptr3 + 1;
    cVar1 = *cptr3;
    cptr3 = cptr9;
  } while (cVar1 != '\0');
  uvalue5 = ~uvalue5;
  cptr3 = cptr9 + -uvalue5;
  cptr9 = acStack_30c;
  for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *(uint32_t *)cptr9 = *(uint32_t *)cptr3;
    cptr3 = cptr3 + 4;
    cptr9 = cptr9 + 4;
  }
  for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *cptr9 = *cptr3;
    cptr3 = cptr3 + 1;
    cptr9 = cptr9 + 1;
  }
  cptr3 = _strrchr(acStack_30c,0x2e);
  if (cptr3 != (char *)0x0) {
    *cptr3 = '\0';
  }
  uvalue5 = 0xffffffff;
  cptr3 = &DAT_005719f8;
  do {
    cptr9 = cptr3;
    if (uvalue5 == 0) break;
    uvalue5 = uvalue5 - 1;
    cptr9 = cptr3 + 1;
    cVar1 = *cptr3;
    cptr3 = cptr9;
  } while (cVar1 != '\0');
  uvalue5 = ~uvalue5;
  value7 = -1;
  cptr3 = acStack_30c;
  do {
    cptr8 = cptr3;
    if (value7 == 0) break;
    value7 = value7 + -1;
    cptr8 = cptr3 + 1;
    cVar1 = *cptr3;
    cptr3 = cptr8;
  } while (cVar1 != '\0');
  cptr3 = cptr9 + -uvalue5;
  cptr9 = cptr8 + -1;
  for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *(uint32_t *)cptr9 = *(uint32_t *)cptr3;
    cptr3 = cptr3 + 4;
    cptr9 = cptr9 + 4;
  }
  for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *cptr9 = *cptr3;
    cptr3 = cptr3 + 1;
    cptr9 = cptr9 + 1;
  }
  if (*(uint32_t **)((intptr_t)self + 0x74) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)((intptr_t)self + 0x74))(1);
  }
  local_438 = operator_new(0x50);
  local_4 = 2;
  if (local_438 == (void *)0x0) {
    uptr4 = (uint32_t *)0x0;
  }
  else {
    uptr4 = Sprite_Load(local_438,DAT_0057c5c8,*(void **)(*(int *)((intptr_t)self + 4) + 0x2bf44),
                         acStack_30c,&iStack_434,0,(void *)0x0,0);
  }
  *(uint32_t **)((intptr_t)self + 0x74) = uptr4;
  local_4 = 0xffffffff;
  if (iStack_434 != 0) {
    NoOp_Stub();
  }
  *(uint32_t *)((intptr_t)self + 0xf4) = 1;
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  ExceptionList = pvStack_c;
  return;
}
