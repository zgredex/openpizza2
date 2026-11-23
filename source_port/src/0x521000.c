// UI_ImageChild_Construct: ported from Pizza Connection 2 at 0x521000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521000
#include "pc2_port.h"

uint32_t * __thiscall
UI_ImageChild_Construct
          (void *self,uint32_t arg1,int arg2,int arg3,uint32_t arg4,int arg5,
          uint32_t arg6,uint32_t arg7)

{
  void *this_00;
  uint32_t *uptr1;
  void *pvVar2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs a UI image child with a private drawing surface. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a5b1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  UI_Child_Construct(self,arg1,arg2,arg3,arg7);
  local_4 = 0;
  Array_Construct((void *)((intptr_t)self + 0x84),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  *(uint8_t ***)self = &PTR_UI_Viewport_Delete_0055c73c;
  if ((intptr_t)arg6 < 8) {
    arg6 = (intptr_t)arg6 >> 3;
  }
  uvalue4 = arg6 & 0x38;
  if (uvalue4 == 0) {
    uvalue4 = 0x10;
  }
  Object_ClearFieldsA((intptr_t)self);
  *(uint32_t *)((intptr_t)self + 0x7c) = 0;
  *(uint32_t *)((intptr_t)self + 0x80) = 0;
  *(uint32_t *)((intptr_t)self + 0x98) = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 7;
  UI_SetAbsolutePosition(self,arg4,arg5);
  if ((intptr_t)arg4 < 1) {
    arg4 = 1;
  }
  if (arg5 < 1) {
    arg5 = 1;
  }
  uptr1 = Renderer_CreateChild(DAT_0057c5c8);
  *(uint32_t **)((intptr_t)self + 0x68) = uptr1;
  pvVar2 = operator_new(0x50);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  if (pvVar2 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = Sprite_CreateRaw(pvVar2,arg4,arg5,0,uvalue4,0);
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint32_t **)((intptr_t)self + 0x60) = uptr1;
  if (uvalue4 == 0x10) {
    uvalue3 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x68),0xff00);
    uptr1 = *(uint32_t **)((intptr_t)self + 0x60);
  }
  else {
    uvalue3 = 0;
  }
  Sprite_SetColorKey(uptr1,uvalue3);
  Sprite_FillTransparentColor(*(void **)((intptr_t)self + 0x60),-1);
  pvVar2 = *(void **)((intptr_t)self + 0x60);
  this_00 = *(void **)((intptr_t)self + 0x68);
  if (*(char *)((intptr_t)pvVar2 + 0x39) == '\0') {
    Sprite_RealizeLazy(pvVar2);
  }
  Surface_Configure(this_00,*(uint32_t *)((intptr_t)pvVar2 + 0x2c),
                    (uint16_t)((intptr_t)*(short *)((intptr_t)pvVar2 + 6) >> 1),*(uint16_t *)((intptr_t)pvVar2 + 8),
                    (intptr_t)*(short *)((intptr_t)pvVar2 + 6));
  ExceptionList = local_c;
  return self;
}
