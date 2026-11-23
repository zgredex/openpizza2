// Renderer_ApplySpriteTint: ported from Pizza Connection 2 at 0x51ee80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51ee80
#include "pc2_port.h"

void __thiscall Renderer_ApplySpriteTint(void *self,uint16_t *arg1,int arg2)

{
  int local_8;
  int local_4;
  
  if (*(int *)self != 0) {
    CS_Enter(*(int *)(*(int *)((intptr_t)self + 8) + 0x1c8));
    Sprite_GetSize(*(void **)self,&local_4,&local_8);
    if (*(int *)((intptr_t)self + 0x18) != 0) {
      Rect_Union(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 0xc),*(int *)((intptr_t)self + 0x10),
                 local_4 + *(int *)((intptr_t)self + 0xc),local_8 + *(int *)((intptr_t)self + 0x10));
    }
    if ((*(int *)((intptr_t)self + 0x24) != 0) && (arg2 == 0)) {
      arg1 = arg1 + 4;
    }
    Sprite_Rotate(*(void **)self,arg1);
    *(int *)((intptr_t)self + 0x24) = arg2;
    if (arg2 != 0) {
      Sprite_FillColor8(*(void **)self);
    }
    Sprite_GetSize(*(void **)self,&local_4,&local_8);
    if (*(int *)((intptr_t)self + 0x18) != 0) {
      Rect_Union(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 0xc),*(int *)((intptr_t)self + 0x10),
                 local_4 + *(int *)((intptr_t)self + 0xc),local_8 + *(int *)((intptr_t)self + 0x10));
    }
    CS_Leave(*(int *)(*(int *)((intptr_t)self + 8) + 0x1c8));
  }
  return;
}
