// Map_DrawRenderableByType: ported from Pizza Connection 2 at 0x52b390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52b390
#include "pc2_port.h"

void __thiscall Map_DrawRenderableByType(void *self,int arg1,int arg2,int arg3)

{
  switch(*(uint32_t *)((intptr_t)self + 0xa4)) {
  case 0:
    if (*(void **)((intptr_t)self + 0x94) != (void *)0x0) {
      if (*(uint16_t **)((intptr_t)self + 0x9c) != (uint16_t *)0xffffffff) {
        Sprite_Rotate(*(void **)((intptr_t)self + 0x94),*(uint16_t **)((intptr_t)self + 0x9c));
      }
      Sprite_Draw(*(void **)((intptr_t)self + 0x94),arg1,
                  (uint32_t *)(*(int *)((intptr_t)self + 0x38) + arg2),
                  *(int *)((intptr_t)self + 0x3c) + arg3);
      return;
    }
    break;
  case 1:
    if (*(void **)((intptr_t)self + 0x54) != (void *)0x0) {
      RecordList_DrawVariantSprite(*(void **)((intptr_t)self + 0x54),arg1,*(int *)((intptr_t)self + 0x98));
      return;
    }
    break;
  case 2:
    if (*(void **)((intptr_t)self + 0x54) != (void *)0x0) {
      Sprite_Blit24Bit(*(void **)((intptr_t)self + 0x54),arg1,*(int *)((intptr_t)self + 0x38) + arg2,
                       *(int *)((intptr_t)self + 0x3c) + arg3,-9999,-9999,0,0);
      return;
    }
    break;
  case 3:
    if (*(void **)((intptr_t)self + 0x54) != (void *)0x0) {
      Sprite_Blit24Bit(*(void **)((intptr_t)self + 0x54),arg1,*(int *)((intptr_t)self + 0x38) + arg2,
                       *(int *)((intptr_t)self + 0x3c) + arg3,-9999,-9999,0,0);
    }
  }
  return;
}
