// UI_TextPanel_Construct: ported from Pizza Connection 2 at 0x52d360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52d360
#include "pc2_port.h"


uint32_t * __thiscall
UI_TextPanel_Construct
          (void *self,uint32_t arg1,int arg2,int arg3,char *arg4,char *arg5,
          char *arg6,int arg7,int arg8,int *arg9)

{
  char cVar1;
  char *cptr2;
  void *pvVar3;
  int value4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint32_t *uptr8;
  void *this_00;
  int value9;
  char *cptr10;
  uint32_t local_230;
  int local_22c;
  void *local_228;
  int local_224;
  uint32_t *local_220;
  uint32_t local_21c;
  void *local_218;
  char local_214 [260];
  char local_110 [260];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs the tiled text-panel control. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a90b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_218 = self;
  UI_Child_Construct(self,arg1,arg2,arg3,arg8);
  *(uint8_t ***)self = &PTR_UI_ButtonElement_Delete_0055c7e8;
  pvVar3 = *(void **)(arg8 + 0x134);
  *(uint32_t *)((intptr_t)self + 0x40) = 2;
  *arg9 = 0;
  local_4 = 0;
  *(uint32_t *)((intptr_t)self + 0x3c0) = 0;
  *(uint32_t *)((intptr_t)self + 0x3c4) = 0;
  *(uint32_t *)((intptr_t)self + 0x3ac) = 0;
  if (arg7 == 0) {
    *(uint32_t *)((intptr_t)self + 0x3a8) = 0;
  }
  else {
    *(uint32_t *)((intptr_t)self + 0x3a8) = 1;
  }
  uvalue6 = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x38c) = 0xd0d0d0;
  *(uint32_t *)((intptr_t)self + 0x390) = 0xffffff;
  *(uint32_t *)((intptr_t)self + 0x394) = 0xffff00;
  cptr2 = arg5;
  do {
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cVar1 = *cptr2;
    cptr2 = cptr2 + 1;
  } while (cVar1 != '\0');
  local_228 = pvVar3;
  cptr2 = operator_new(~uvalue6);
  uvalue6 = 0xffffffff;
  *(char **)((intptr_t)self + 0x58) = cptr2;
  do {
    cptr10 = arg5;
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cptr10 = arg5 + 1;
    cVar1 = *arg5;
    arg5 = cptr10;
  } while (cVar1 != '\0');
  uvalue6 = ~uvalue6;
  cptr10 = cptr10 + -uvalue6;
  for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
    *(uint32_t *)cptr2 = *(uint32_t *)cptr10;
    cptr10 = cptr10 + 4;
    cptr2 = cptr2 + 4;
  }
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *cptr2 = *cptr10;
    cptr10 = cptr10 + 1;
    cptr2 = cptr2 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x3b0) = 0;
  *(uint32_t *)((intptr_t)self + 0x3b4) = 0;
  *(uint32_t *)((intptr_t)self + 0x3b8) = 0;
  *(uint32_t *)((intptr_t)self + 0x3bc) = 0;
  pvVar3 = (void *)UI_LoadFontByName(pvVar3,arg4);
  *(void **)((intptr_t)self + 0x54) = pvVar3;
  *(uint32_t *)((intptr_t)self + 0x398) = 0;
  *(uint32_t *)((intptr_t)self + 0x3b8) = 0;
  if (pvVar3 == (void *)0x0) {
    uvalue6 = 0xffffffff;
    local_224 = 0x10;
    cptr2 = *(char **)((intptr_t)self + 0x58);
    do {
      if (uvalue6 == 0) break;
      uvalue6 = uvalue6 - 1;
      cVar1 = *cptr2;
      cptr2 = cptr2 + 1;
    } while (cVar1 != '\0');
    value4 = (~uvalue6 - 1) * 0xc;
    *(int *)((intptr_t)self + 0x3a4) = value4;
  }
  else {
    value4 = Font_MeasureText(pvVar3,*(char **)((intptr_t)self + 0x58));
    *(int *)((intptr_t)self + 0x3a4) = value4;
    local_224 = *(int *)(*(int *)((intptr_t)self + 0x54) + 0x9b0);
  }
  value5 = local_224;
  uptr8 = (uint32_t *)((intptr_t)self + 0x9c);
  value9 = 0xc;
  do {
    *uptr8 = 0;
    uptr8 = uptr8 + 0x11;
    value9 = value9 + -1;
  } while (value9 != 0);
  if (arg6 == (char *)0x0) {
    *(short *)((intptr_t)self + 0x3b0) = (short)value4;
    *(short *)((intptr_t)self + 0x3b2) = (short)local_224;
    UI_SetAbsolutePosition(self,value4,local_224);
  }
  else {
    uvalue6 = 0xffffffff;
    do {
      cptr2 = arg6;
      if (uvalue6 == 0) break;
      uvalue6 = uvalue6 - 1;
      cptr2 = arg6 + 1;
      cVar1 = *arg6;
      arg6 = cptr2;
    } while (cVar1 != '\0');
    uvalue6 = ~uvalue6;
    cptr2 = cptr2 + -uvalue6;
    cptr10 = local_214;
    for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
      *(uint32_t *)cptr10 = *(uint32_t *)cptr2;
      cptr2 = cptr2 + 4;
      cptr10 = cptr10 + 4;
    }
    for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *cptr10 = *cptr2;
      cptr2 = cptr2 + 1;
      cptr10 = cptr10 + 1;
    }
    local_21c = 0;
    cptr2 = _strrchr(local_214,0x5f);
    if (cptr2 != (char *)0x0) {
      local_21c = CRT_AtoiThunk(this_00,(uint8_t *)(cptr2 + 1));
      *cptr2 = '\0';
    }
    local_22c = 0;
    local_230 = 4 - (*(int *)((intptr_t)self + 0x3a8) != 1);
    if (0 < (intptr_t)local_230) {
      local_220 = (uint32_t *)((intptr_t)self + 0x5c);
      do {
        value4 = 0;
        uptr8 = local_220;
        do {
          String_Format(local_110,(uint8_t *)s__s__02d_spr_00573b9c,local_214);
          value5 = Window_LoadSpriteCached(local_228,local_110,(uint32_t *)0x1,uptr8);
          if (value5 == 0) {
            *arg9 = 2;
            ExceptionList = local_c;
            return self;
          }
          value4 = value4 + 1;
          uptr8 = uptr8 + 0x11;
        } while (value4 < 3);
        local_22c = local_22c + 1;
        local_220 = local_220 + 0x33;
      } while (local_22c < (intptr_t)local_230);
      value5 = local_224;
    }
    if (*arg9 == 0) {
      Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x9c),(uint32_t *)&local_228,&local_230);
      *(void **)((intptr_t)self + 0x39c) = local_228;
      *(int *)((intptr_t)self + 0x3a0) = (intptr_t)(local_230 - value5) >> 1;
      UI_ComputeElementRowExtent(self);
      *(short *)((intptr_t)self + 0x3b0) = *(short *)((intptr_t)self + 0x30) - *(short *)((intptr_t)self + 0x28);
      *(short *)((intptr_t)self + 0x3b2) = *(short *)((intptr_t)self + 0x34) - *(short *)((intptr_t)self + 0x2c);
    }
  }
  ExceptionList = local_c;
  return self;
}
