// UI_Image_Construct: ported from Pizza Connection 2 at 0x51ef80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51ef80
#include "pc2_port.h"


uint32_t * __thiscall
UI_Image_Construct(void *self,uint32_t arg1,int arg2,int arg3,int arg4,int arg5,
                  char *arg6,uint32_t *arg7)

{
  char cVar1;
  void *pvVar2;
  uint32_t *uptr3;
  char *cptr4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  int value8;
  void *this_00;
  char *cptr9;
  int local_240;
  int local_23c;
  int local_238;
  int local_234;
  int local_230;
  int local_22c;
  int local_228;
  int local_21c;
  void *local_218;
  char local_214 [260];
  char local_110 [260];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs a multi-part UI image from sprite parts. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a53b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_218 = self;
  UI_Child_Construct(self,arg1,arg3,arg4,arg5);
  *(uint8_t ***)self = &PTR_UI_ImageElement_Delete_0055c704;
  pvVar2 = *(void **)(arg5 + 0x134);
  local_4 = 0;
  if (arg7 != (uint32_t *)0x0) {
    *arg7 = 0;
  }
  uvalue6 = 0xffffffff;
  do {
    cptr4 = arg6;
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cptr4 = arg6 + 1;
    cVar1 = *arg6;
    arg6 = cptr4;
  } while (cVar1 != '\0');
  uvalue6 = ~uvalue6;
  cptr4 = cptr4 + -uvalue6;
  cptr9 = local_214;
  for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
    *(uint32_t *)cptr9 = *(uint32_t *)cptr4;
    cptr4 = cptr4 + 4;
    cptr9 = cptr9 + 4;
  }
  uptr3 = (uint32_t *)((intptr_t)self + 0x94);
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *cptr9 = *cptr4;
    cptr4 = cptr4 + 1;
    cptr9 = cptr9 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x164) = 0;
  *(uint32_t *)((intptr_t)self + 0x168) = 0;
  *(uint32_t *)((intptr_t)self + 0x170) = 0;
  *(int *)((intptr_t)self + 0x16c) = arg2;
  value8 = 4;
  do {
    *uptr3 = 0;
    uptr3 = uptr3 + 0x11;
    value8 = value8 + -1;
  } while (value8 != 0);
  *(uint32_t *)((intptr_t)self + 0x40) = 1;
  cptr4 = _strrchr(local_214,0x5f);
  if (cptr4 != (char *)0x0) {
    CRT_AtoiThunk(this_00,(uint8_t *)(cptr4 + 1));
    *cptr4 = '\0';
  }
  local_21c = (arg2 != 0) + 3;
  value8 = 0;
  if (local_21c != 0) {
    uptr3 = (uint32_t *)((intptr_t)self + 0x54);
    do {
      String_Format(local_110,(uint8_t *)s__s__02d_spr_00573b9c,local_214);
      value5 = Window_LoadSpriteCached(pvVar2,local_110,(uint32_t *)(uint32_t)(value8 < 2),uptr3);
      if ((value5 == 0) && (value8 < 2)) {
        *arg7 = 2;
        ExceptionList = local_c;
        return self;
      }
      value8 = value8 + 1;
      uptr3 = uptr3 + 0x11;
    } while (value8 < local_21c);
  }
  if (arg7 != (uint32_t *)0x0) {
    *arg7 = 0;
  }
  local_22c = *(int *)((intptr_t)self + 0x28);
  local_228 = *(int *)((intptr_t)self + 0x2c);
  value8 = *(int *)((intptr_t)self + 0x30);
  value5 = *(int *)((intptr_t)self + 0x34);
  local_240 = 0;
  do {
    pvVar2 = *(void **)((intptr_t)self + local_240 * 0x44 + 0x94);
    if (pvVar2 != (void *)0x0) {
      Sprite_GetHotspot(pvVar2,&local_234,&local_230);
      Sprite_GetSize(*(void **)((intptr_t)self + local_240 * 0x44 + 0x94),&local_238,&local_23c);
      if (local_240 == 0) {
        local_22c = local_234;
        local_228 = local_230;
        value8 = local_238 + local_234;
        value5 = local_23c + local_230;
      }
      else {
        if (local_234 < local_22c) {
          local_22c = local_234;
        }
        if (local_230 < local_228) {
          local_228 = local_230;
        }
        if (value8 < local_234 + local_238) {
          value8 = local_234 + local_238;
        }
        if (value5 < local_23c + local_230) {
          value5 = local_23c + local_230;
        }
      }
    }
    local_240 = local_240 + 1;
  } while (local_240 < 4);
  *(int *)((intptr_t)self + 0x28) = *(int *)((intptr_t)self + 0x28) + local_22c;
  *(int *)((intptr_t)self + 0x2c) = *(int *)((intptr_t)self + 0x2c) + local_228;
  UI_SetAbsolutePosition(self,value8 - local_22c,value5 - local_228);
  ExceptionList = local_c;
  return self;
}
