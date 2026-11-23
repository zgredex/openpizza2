// GammaOptions_DrawPreview: ported from Pizza Connection 2 at 0x4a0540.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a0540
#include "pc2_port.h"


void __cdecl GammaOptions_DrawPreview(void *arg1)

{
  int value1;
  void *self;
  uint32_t *this_00;
  uint32_t *uptr2;
  uint32_t *uptr3;
  uint8_t *bptr4;
  uint32_t *uptr5;
  uint32_t uvalue6;
  int value7;
  int value8;
  uint32_t *uptr9;
  int value10;
  tagRECT local_1c;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005587cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  value1 = UI_GetWindowObject(arg1,0x1f52);
  self = operator_new(0x18);
  local_4 = 0;
  if (self == (void *)0x0) {
    this_00 = (uint32_t *)0x0;
  }
  else {
    this_00 = Gfx_RectList_Construct(self,0xaa,0xaa,0xf);
  }
  local_4 = 0xffffffff;
  SetRect(&local_1c,0,0,800,600);
  Gfx_BlitRectList(this_00,(uint32_t *)&local_1c);
  uptr2 = (uint32_t *)Sprite_GetPixelBuffer(DAT_0057cda8);
  uptr3 = (uint32_t *)Sprite_GetPixelBuffer(DAT_0057cda4);
  for (value7 = 0x54ab; value7 != 0; value7 = value7 + -1) {
    *uptr3 = *uptr2;
    uptr2 = uptr2 + 1;
    uptr3 = uptr3 + 1;
  }
  value7 = Sprite_GetPixelBuffer(DAT_0057cda4);
  bptr4 = (uint8_t *)(value7 + 2);
  value8 = 0x70e4;
  value7 = DAT_00568c78;
  do {
    if ((intptr_t)(uint32_t)*bptr4 < value7) {
      *bptr4 = (uint8_t)value7;
      value7 = DAT_00568c78;
    }
    bptr4 = bptr4 + 3;
    value8 = value8 + -1;
  } while (value8 != 0);
  value10 = 0;
  value8 = 0;
  value7 = 0;
  uptr5 = (uint32_t *)Sprite_GetPixelBuffer(DAT_0057cda4);
  uptr9 = this_00;
  uvalue6 = Object_GetActiveValue(value1);
  Gfx_BlitRLEScaled(DAT_0057cda4,uvalue6,uptr9,uptr5,value7,value8,value10);
  *(uint32_t *)((intptr_t)arg1 + 0xe0) = 1;
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  ExceptionList = local_c;
  return;
}
