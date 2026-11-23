// UI_Bar_Construct: ported from Pizza Connection 2 at 0x528930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528930
#include "pc2_port.h"

uint32_t * __thiscall
UI_Bar_Construct(void *self,uint32_t arg1,int arg2,int arg3,int arg4,uint32_t arg5,
                int arg6,char *arg7,uint32_t arg8,uint32_t *arg9)

{
  uint32_t *uptr1;
  char cVar2;
  int value3;
  char *cptr4;
  void *pvVar5;
  uint32_t *uptr6;
  int value7;
  int value8;
  uint32_t uvalue9;
  uint32_t uvalue10;
  int value11;
  int value12;
  char *cptr13;
  uint8_t uvalue14;
  int local_250;
  uint32_t local_24c;
  uint32_t local_248;
  uint32_t local_244;
  uint32_t local_240;
  int local_23c;
  int local_238;
  int local_234;
  int local_230;
  int local_22c;
  int local_228;
  int local_224;
  int local_220;
  void *local_21c;
  void *local_218;
  char local_214 [260];
  char local_110 [260];
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
                    /* Constructs a three-part UI bar with range and gradient fill. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a849;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_218 = self;
  UI_Child_Construct(self,arg1,arg3,arg4,arg6);
  *(uint8_t ***)self = &PTR_UI_Slider_Delete_0055c78c;
  pvVar5 = *(void **)(arg6 + 0x134);
  local_4 = 0;
  if (arg9 != (uint32_t *)0x0) {
    *arg9 = 0;
  }
  local_250 = 0;
  do {
    *(uint32_t *)((intptr_t)self + local_250 * 0x44 + 0x120) = 0;
    *(uint32_t *)((intptr_t)self + local_250 * 0x44 + 0x1ec) = 0;
    local_250 = local_250 + 1;
  } while (local_250 < 3);
  *(uint32_t *)((intptr_t)self + 0x344) = 0;
  value8 = 0;
  do {
    local_250 = 0;
    do {
      *(uint32_t *)((intptr_t)self + (local_250 + value8) * 0x44 + 0x388) = 0;
      local_250 = local_250 + 1;
    } while (local_250 < 3);
    value8 = value8 + 3;
  } while (value8 < 6);
  uvalue9 = 0xffffffff;
  do {
    cptr4 = arg7;
    if (uvalue9 == 0) break;
    uvalue9 = uvalue9 - 1;
    cptr4 = arg7 + 1;
    cVar2 = *arg7;
    arg7 = cptr4;
  } while (cVar2 != '\0');
  uvalue9 = ~uvalue9;
  cptr4 = cptr4 + -uvalue9;
  cptr13 = local_110;
  for (uvalue10 = uvalue9 >> 2; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
    *(uint32_t *)cptr13 = *(uint32_t *)cptr4;
    cptr4 = cptr4 + 4;
    cptr13 = cptr13 + 4;
  }
  for (uvalue9 = uvalue9 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
    *cptr13 = *cptr4;
    cptr4 = cptr4 + 1;
    cptr13 = cptr13 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0xc0) = arg8;
  *(uint32_t *)((intptr_t)self + 0x60) = 0;
  *(int *)((intptr_t)self + 0x54) = arg2;
  *(uint32_t *)((intptr_t)self + 0xb8) = 0;
  *(uint32_t *)((intptr_t)self + 0xbc) = 0;
  *(uint32_t *)((intptr_t)self + 0xa8) = 0;
  *(uint32_t *)((intptr_t)self + 0xc4) = 0;
  *(uint32_t *)((intptr_t)self + 0xcc) = 0;
  *(uint32_t *)((intptr_t)self + 0xd0) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x5c) = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 5;
  cptr4 = _strrchr(local_110,0x5f);
  if (cptr4 != (char *)0x0) {
    if (((('/' < cptr4[1]) && (cptr4[1] < ':')) && ('/' < cptr4[2])) && (cptr4[2] < ':')) {
      CRT_AtoiThunk(cptr4 + 1,(uint8_t *)(cptr4 + 1));
      *cptr4 = '\0';
    }
  }
  local_250 = 0;
  do {
    String_Format(local_214,(uint8_t *)s__s__02d_spr_00573b9c,local_110);
    value8 = Window_LoadSpriteCached
                      (pvVar5,local_214,(uint32_t *)0x1,
                       (uint32_t *)((intptr_t)self + local_250 * 0x44 + 0x1ac));
    if (value8 == 0) goto LAB_00528d08;
    local_250 = local_250 + 1;
  } while (local_250 < 3);
  if (*(int *)((intptr_t)self + 0xc0) == 0) {
    Sprite_GetSize(*(void **)((intptr_t)self + 0x1ec),&local_250,(int *)&local_24c);
    Sprite_GetSize(*(void **)((intptr_t)self + 0x230),(int *)&local_248,(int *)&local_24c);
    local_250 = local_250 + local_248;
    Sprite_GetSize(*(void **)((intptr_t)self + 0x274),(int *)&local_248,(int *)&local_24c);
    uvalue9 = local_248;
  }
  else {
    Sprite_GetSize(*(void **)((intptr_t)self + 0x1ec),(int *)&local_248,&local_250);
    Sprite_GetSize(*(void **)((intptr_t)self + 0x230),(int *)&local_248,(int *)&local_24c);
    local_250 = local_250 + local_24c;
    Sprite_GetSize(*(void **)((intptr_t)self + 0x274),(int *)&local_248,(int *)&local_24c);
    uvalue9 = local_24c;
  }
  if ((intptr_t)arg5 < (intptr_t)(local_250 + uvalue9)) {
    arg5 = local_250 + uvalue9;
  }
  *(uint32_t *)((intptr_t)self + 0xb4) = arg5;
  local_250 = 0;
  do {
    String_Format(local_214,(uint8_t *)s__s__02d_spr_00573b9c,local_110);
    value8 = Window_LoadSpriteCached
                      (pvVar5,local_214,(uint32_t *)0x1,
                       (uint32_t *)((intptr_t)self + local_250 * 0x44 + 0xe0));
    if (value8 == 0) {
LAB_00528d08:
      *arg9 = 2;
      ExceptionList = local_c;
      return self;
    }
    local_250 = local_250 + 1;
  } while (local_250 < 3);
  if (arg2 == 0) {
    local_250 = 0;
    do {
      String_Format(local_214,(uint8_t *)s__s__02d_spr_00573b9c,local_110);
      Window_LoadSpriteCached
                (pvVar5,local_214,(uint32_t *)(uint32_t)(local_250 < 2),
                 (uint32_t *)((intptr_t)self + local_250 * 0x44 + 0x348));
      local_250 = local_250 + 1;
    } while (local_250 < 3);
  }
  *(uint32_t *)((intptr_t)self + 100) = 0xfffffc19;
  *(uint32_t *)((intptr_t)self + 0x68) = 0xfffffc19;
  *(uint32_t *)((intptr_t)self + 0x4f0) = 0;
  *(uint32_t *)((intptr_t)self + 0x4f4) = 0;
  Sprite_GetSize(*(void **)((intptr_t)self + 0x1ec),(int *)&local_240,(int *)&local_244);
  Sprite_GetSize(*(void **)((intptr_t)self + 0x230),(int *)&local_248,(int *)&local_24c);
  if (*(int *)((intptr_t)self + 0xc0) == 0) {
    if ((intptr_t)local_244 <= (intptr_t)local_24c) {
      local_244 = local_24c;
    }
  }
  else if ((intptr_t)local_240 <= (intptr_t)local_248) {
    local_240 = local_248;
  }
  *(uint32_t *)((intptr_t)self + 200) = arg5;
  *(uint32_t *)((intptr_t)self + 0x9c) = 0;
  *(uint32_t *)((intptr_t)self + 0x94) = 0;
  *(uint32_t *)((intptr_t)self + 0xa0) = 100;
  *(uint32_t *)((intptr_t)self + 0x98) = 100;
  *(uint32_t *)((intptr_t)self + 0x58) = 0;
  UI_SetClampedValue(self,0,0);
  UI_SetClampedValue(self,0,1);
  Sprite_GetSize(*(void **)((intptr_t)self + 0x274),(int *)&local_248,(int *)&local_24c);
  if (*(int *)((intptr_t)self + 0xc0) == 0) {
    local_240 = arg5;
    if ((intptr_t)local_244 <= (intptr_t)local_24c) {
      local_244 = local_24c;
    }
  }
  else {
    if ((intptr_t)local_240 <= (intptr_t)local_248) {
      local_240 = local_248;
    }
    local_244 = arg5;
  }
  pvVar5 = operator_new(0x50);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  local_21c = pvVar5;
  if (pvVar5 == (void *)0x0) {
    uptr6 = (uint32_t *)0x0;
  }
  else {
    uvalue14 = 2;
    value8 = 0x10;
    uvalue9 = Color_RGBTo16(DAT_0057c5c8,0,0xff,0);
    uptr6 = Sprite_CreateRaw(pvVar5,local_240,local_244,uvalue9,value8,uvalue14);
  }
  local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
  *(uint32_t **)((intptr_t)self + 0x344) = uptr6;
  *(uint32_t *)((intptr_t)self + 0xd4) = 0xffff;
  *(uint32_t *)((intptr_t)self + 0xd8) = 0xffffff;
  *(uint32_t *)((intptr_t)self + 0xdc) = 0xff0000;
  UI_Bar_BuildGradientFill((intptr_t)self);
  if (*(int *)((intptr_t)self + 0xa8) == 999999) {
    *(uint32_t *)((intptr_t)self + 0xa8) = 0;
  }
  Sprite_GetSize(*(void **)((intptr_t)self + 0x230),&local_220,&local_224);
  if (*(int *)((intptr_t)self + 0xc0) == 0) {
    *(int *)((intptr_t)self + 0x4f0) = -*(int *)((intptr_t)self + 0xa8);
    Sprite_GetHotspot(*(void **)((intptr_t)self + 0x1ec),(int *)&local_248,(int *)&local_24c);
    local_248 = 0;
    *(int *)((intptr_t)self + 0x4f4) = -(local_224 / 2);
  }
  else {
    *(int *)((intptr_t)self + 0x4f0) = -(local_220 / 2);
    Sprite_GetHotspot(*(void **)((intptr_t)self + 0x1ec),(int *)&local_248,(int *)&local_24c);
    local_24c = 0;
    *(int *)((intptr_t)self + 0x4f4) = -*(int *)((intptr_t)self + 0xa8);
  }
  *(uint32_t *)((intptr_t)self + 0x28) = *(int *)((intptr_t)self + 0x28) + local_248 + *(int *)((intptr_t)self + 0x4f0)
  ;
  *(uint32_t *)((intptr_t)self + 0x2c) = *(int *)((intptr_t)self + 0x2c) + *(int *)((intptr_t)self + 0x4f4) + local_24c
  ;
  UI_LayoutChildElements((intptr_t)self);
  UI_SetAbsolutePosition(self,local_240,local_244);
  *(uint32_t *)((intptr_t)self + 0x88) = 0;
  *(uint32_t *)((intptr_t)self + 0x84) = 0;
  if (*(int *)((intptr_t)self + 0x388) == 0) {
    ExceptionList = local_c;
    return self;
  }
  local_250 = 0;
  value8 = local_234;
  value12 = local_230;
  do {
    pvVar5 = *(void **)((intptr_t)self + local_250 * 0x44 + 0x388);
    if (pvVar5 != (void *)0x0) {
      Sprite_GetSize(pvVar5,(int *)&local_248,(int *)&local_24c);
      Sprite_GetHotspot(*(void **)((intptr_t)self + local_250 * 0x44 + 0x388),&local_228,&local_22c);
      if (local_250 == 0) {
        local_23c = local_228;
        local_238 = local_22c;
        value8 = local_228 + local_248;
        value12 = local_22c + local_24c;
      }
      else {
        if (local_228 < local_23c) {
          local_23c = local_228;
        }
        if (local_22c < local_238) {
          local_238 = local_22c;
        }
        if (value8 < (intptr_t)(local_228 + local_248)) {
          value8 = local_228 + local_248;
        }
        if (value12 < (intptr_t)(local_24c + local_22c)) {
          value12 = local_24c + local_22c;
        }
      }
    }
    local_250 = local_250 + 1;
  } while (local_250 < 3);
  uptr1 = (uint32_t *)((intptr_t)self + 0xb0);
  local_234 = value8;
  local_230 = value12;
  Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x388),(uint32_t *)((intptr_t)self + 0xac),uptr1);
  Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x1ec),&local_248,&local_24c);
  uvalue9 = *(uint32_t *)((intptr_t)self + 0xac);
  if (*(int *)((intptr_t)self + 0xc0) == 0) {
    *(int *)((intptr_t)self + 0x84) = -(((intptr_t)(local_248 - uvalue9) >> 1) + *(int *)((intptr_t)self + 0x4f0));
    value8 = (intptr_t)(local_24c - *uptr1) >> 1;
  }
  else {
    *(int *)((intptr_t)self + 0x84) = -((intptr_t)(local_248 - uvalue9) >> 1);
    value8 = ((intptr_t)(local_24c - *uptr1) >> 1) + *(int *)((intptr_t)self + 0x4f4);
  }
  *(int *)((intptr_t)self + 0x88) = -value8;
  if (*(int *)((intptr_t)self + 0xc0) == 0) {
    value12 = *(int *)((intptr_t)self + 0x84);
    value8 = *(int *)((intptr_t)self + 0x28);
    local_234 = (*(int *)((intptr_t)self + 0xa4) - value12) + value8 + local_234;
    value11 = *(int *)((intptr_t)self + 0x30);
    if (local_234 <= *(int *)((intptr_t)self + 0x30)) {
LAB_005290aa:
      local_234 = value11;
    }
  }
  else {
    value8 = *(int *)((intptr_t)self + 0x28);
    value12 = *(int *)((intptr_t)self + 0x84);
    local_234 = (value8 - value12) + local_234;
    value11 = *(int *)((intptr_t)self + 0x30);
    if (local_234 <= *(int *)((intptr_t)self + 0x30)) goto LAB_005290aa;
  }
  *(int *)((intptr_t)self + 0x30) = local_234;
  if (*(int *)((intptr_t)self + 0xc0) == 0) {
    value7 = *(int *)((intptr_t)self + 0x2c);
    value11 = *(int *)((intptr_t)self + 0x88);
    local_230 = (value7 - value11) + local_230;
    value3 = *(int *)((intptr_t)self + 0x34);
    if (*(int *)((intptr_t)self + 0x34) < local_230) goto LAB_005290f7;
  }
  else {
    value11 = *(int *)((intptr_t)self + 0x88);
    value7 = *(int *)((intptr_t)self + 0x2c);
    local_230 = (*(int *)((intptr_t)self + 0xa4) - value11) + value7 + local_230;
    value3 = *(int *)((intptr_t)self + 0x34);
    if (*(int *)((intptr_t)self + 0x34) < local_230) goto LAB_005290f7;
  }
  local_230 = value3;
LAB_005290f7:
  *(int *)((intptr_t)self + 0x34) = local_230;
  local_23c = (value8 - value12) + local_23c;
  if (local_23c < value8) {
    value8 = local_23c;
  }
  *(int *)((intptr_t)self + 0x28) = value8;
  local_238 = local_238 + (value7 - value11);
  if (local_238 < value7) {
    value7 = local_238;
  }
  *(int *)((intptr_t)self + 0x2c) = value7;
  ExceptionList = local_c;
  return self;
}
