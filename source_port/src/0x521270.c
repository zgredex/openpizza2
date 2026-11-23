// UI_UpdateCustomControl: ported from Pizza Connection 2 at 0x521270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521270
#include "pc2_port.h"

void __thiscall UI_UpdateCustomControl(void *self,void *arg1,int arg2,int arg3)

{
  char cVar1;
  void *this_00;
  void *this_01;
  uint8_t uvalue2;
  int value3;
  int value4;
  uint32_t extraout_var;
  
  if (*(code **)((intptr_t)self + 0x70) != (code *)0x0) {
    value3 = (**(code **)((intptr_t)self + 0x70))(self,*(uint32_t *)((intptr_t)self + 0x74));
    if (value3 == 0) {
      UI_DetachObject((intptr_t)self);
    }
  }
  value3 = *(int *)(*(int *)((intptr_t)self + 0x68) + 0x28);
  value4 = Sprite_GetPixelBuffer(*(void **)((intptr_t)self + 0x60));
  if (value3 == value4) {
    cVar1 = *(char *)(*(int *)((intptr_t)self + 0x60) + 5);
    uvalue2 = Sprite_GetFormat(*(int *)((intptr_t)self + 0x60));
    if ((CONCAT31(extraout_var,uvalue2) != 0) || (cVar1 != '\x10')) {
      Sprite_Draw(*(void **)((intptr_t)self + 0x60),(intptr_t)arg1,
                  (uint32_t *)(*(int *)((intptr_t)self + 0x38) + arg2),
                  *(int *)((intptr_t)self + 0x3c) + arg3);
      return;
    }
  }
  else {
    this_00 = *(void **)((intptr_t)self + 100);
    if (*(char *)((intptr_t)this_00 + 5) != '\x10') {
      Sprite_Draw(this_00,(intptr_t)arg1,(uint32_t *)(*(int *)((intptr_t)self + 0x38) + arg2),
                  *(int *)((intptr_t)self + 0x3c) + arg3);
      return;
    }
    this_01 = *(void **)((intptr_t)self + 0x68);
    if (*(char *)((intptr_t)this_00 + 0x39) == '\0') {
      Sprite_RealizeLazy(this_00);
    }
    Surface_Configure(this_01,*(uint32_t *)((intptr_t)this_00 + 0x2c),
                      (uint16_t)((intptr_t)*(short *)((intptr_t)this_00 + 6) >> 1),*(uint16_t *)((intptr_t)this_00 + 8)
                      ,(intptr_t)*(short *)((intptr_t)this_00 + 6));
  }
  Surface_Reset(*(int *)((intptr_t)self + 0x68));
  value3 = *(int *)((intptr_t)self + 0x68);
  Gfx_Blit16Clipped(arg1,*(int *)((intptr_t)self + 0x38) + arg2,
                    *(int *)((intptr_t)self + 0x3c) + arg3,(uint32_t)*(uint16_t *)(value3 + 0x1a),
                    (uint32_t)*(uint16_t *)(value3 + 0x1c),value3,0,0);
  return;
}
