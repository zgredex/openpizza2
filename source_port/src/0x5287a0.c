// UI_DrawChildAt: ported from Pizza Connection 2 at 0x5287a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5287a0
#include "pc2_port.h"

void __thiscall UI_DrawChildAt(void *self,void *arg1)

{
  if ((*(int *)((intptr_t)self + 0x44) != 0) && (*(void **)((intptr_t)self + 0x54) != (void *)0x0)) {
    Sprite_Draw(*(void **)((intptr_t)self + 0x54),(intptr_t)arg1,*(uint32_t **)((intptr_t)self + 0x38),
                *(int *)((intptr_t)self + 0x3c));
    if (*(int *)((intptr_t)self + 0x48) != -1) {
      Text_SetMetrics2(*(void **)((intptr_t)self + 0x4c),
                       *(int *)((intptr_t)self + 0x30) + *(int *)((intptr_t)self + 0x38),
                       *(int *)((intptr_t)*(void **)((intptr_t)self + 0x4c) + 0x9b0) *
                       *(int *)((intptr_t)self + 0x48) + *(int *)((intptr_t)self + 0x34) +
                       *(int *)((intptr_t)self + 0x3c),0);
      Set_Field9B8(*(void **)((intptr_t)self + 0x4c),*(uint32_t *)((intptr_t)self + 0x60));
      Font_DrawTextLine(*(void **)((intptr_t)self + 0x4c),arg1,
                        *(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x48) * 4 + 0x6c));
    }
  }
  return;
}
