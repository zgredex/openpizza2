// Renderer_DrawPendingSprite: ported from Pizza Connection 2 at 0x51eb50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51eb50
#include "pc2_port.h"

uint32_t __thiscall Renderer_DrawPendingSprite(void *self,int arg1,LPRECT arg2)

{
  int xLeft;
  int local_8;
  int local_4;
  
  if (*(void **)((intptr_t)self + 4) == (void *)0x0) {
    return 0;
  }
  if (*(int *)((intptr_t)self + 0x18) != 0) {
    Sprite_GetSize(*(void **)((intptr_t)self + 4),&local_4,&local_8);
    xLeft = *(int *)((intptr_t)self + 0xc);
    if (xLeft == -9999) {
      return 0;
    }
    SetRect(arg2,xLeft,*(int *)((intptr_t)self + 0x10),local_4 + xLeft,
            local_8 + *(int *)((intptr_t)self + 0x10));
    Sprite_Draw(*(void **)((intptr_t)self + 4),arg1,*(uint32_t **)((intptr_t)self + 0xc),
                *(int *)((intptr_t)self + 0x10));
    *(uint32_t *)((intptr_t)self + 0x18) = 0;
  }
  if ((*(int *)self == 0) && (*(uint32_t **)((intptr_t)self + 4) != (uint32_t *)0x0)) {
    (**(code **)**(uint32_t **)((intptr_t)self + 4))(1);
    *(uint32_t *)((intptr_t)self + 4) = 0;
  }
  return 1;
}
