// UI_TextLabel_Construct: ported from Pizza Connection 2 at 0x522010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522010
#include "pc2_port.h"


uint32_t * __thiscall
UI_TextLabel_Construct
          (void *self,uint32_t arg1,int arg2,int arg3,char *arg4,char *arg5,
          int arg6,int arg7,uint32_t *arg8)

{
  uint8_t uvalue1;
  uint32_t uvalue2;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  int3 extraout_var_01;
  int value3;
  uint32_t extraout_var_02;
  int value4;
  void *pvVar5;
  uint32_t uvalue6;
  uint32_t *uptr7;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs an auto-wrapping text label. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a608;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  UI_Child_Construct(self,arg1,arg2,arg3,arg7);
  *(uint8_t ***)self = &PTR_UI_LabelElement_Delete_0055c758;
  pvVar5 = *(void **)(arg7 + 0x134);
  *arg8 = 0;
  local_4 = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 4;
  *(uint32_t *)((intptr_t)self + 0x58) = 0;
  uvalue2 = UI_LoadFontByName(pvVar5,arg4);
  *(uint32_t *)((intptr_t)self + 0x54) = uvalue2;
  if (uvalue2 == 0) {
    *arg8 = 1;
  }
  else {
    UI_SetAbsolutePosition(self,arg6,*(int *)(uvalue2 + 0x9b0));
    *(uint32_t *)((intptr_t)self + 0x5c) = 0xa0a0a0;
    *(uint32_t *)((intptr_t)self + 0x60) = 0xa0a000;
    *(uint32_t *)((intptr_t)self + 100) = 0xffffff;
    *(uint32_t *)((intptr_t)self + 0x68) = 0xff0000;
    *(uint32_t *)((intptr_t)self + 0x74) = 0;
    uvalue1 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),0x20);
    *(int *)((intptr_t)self + 0x84) = arg6 - CONCAT31(extraout_var,uvalue1);
    *(uint32_t *)((intptr_t)self + 0x78) = 0;
    *(uint32_t *)((intptr_t)self + 0x6c) = 0;
    *(uint32_t *)((intptr_t)self + 0x88) = 0xfffffc19;
    *(uint32_t *)((intptr_t)self + 0x98) = 0;
    uvalue1 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),0x20);
    value4 = CONCAT31(extraout_var_00,uvalue1);
    uvalue2 = 0x21;
    do {
      uvalue1 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),uvalue2);
      value3 = CONCAT31(extraout_var_01,uvalue1);
      if ((value3 != 0 && -1 < extraout_var_01) && (value3 < value4)) {
        value4 = value3;
      }
      uvalue2 = uvalue2 + 1;
    } while ((intptr_t)uvalue2 < 0x100);
    if (value4 == 0) {
      uvalue1 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),0x69);
      value4 = CONCAT31(extraout_var_02,uvalue1);
    }
    if (*(int *)((intptr_t)self + 0x84) < value4 * 2) {
      *(int *)((intptr_t)self + 0x84) = value4 * 2;
    }
    value4 = *(int *)((intptr_t)self + 0x84) / value4;
    *(int *)((intptr_t)self + 0x78) = value4;
    pvVar5 = operator_new(value4 + 1);
    *(void **)((intptr_t)self + 0x6c) = pvVar5;
    pvVar5 = operator_new(*(int *)((intptr_t)self + 0x78) + 1);
    uvalue6 = *(int *)((intptr_t)self + 0x78) + 1;
    *(void **)((intptr_t)self + 0x70) = pvVar5;
    uptr7 = *(uint32_t **)((intptr_t)self + 0x6c);
    for (uvalue2 = uvalue6 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *uptr7 = 0;
      uptr7 = uptr7 + 1;
    }
    for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *(uint8_t *)uptr7 = 0;
      uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
    }
    uvalue6 = *(int *)((intptr_t)self + 0x78) + 1;
    uptr7 = *(uint32_t **)((intptr_t)self + 0x70);
    for (uvalue2 = uvalue6 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *uptr7 = 0;
      uptr7 = uptr7 + 1;
    }
    for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *(uint8_t *)uptr7 = 0;
      uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
    }
    UI_SetTextFit(self,arg5);
    *(uint32_t *)((intptr_t)self + 0x80) = 0;
    *(uint32_t *)((intptr_t)self + 0x7c) = 0;
  }
  ExceptionList = local_c;
  return self;
}
