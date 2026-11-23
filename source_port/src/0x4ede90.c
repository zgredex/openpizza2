// UI_DrawObjectSprite: ported from Pizza Connection 2 at 0x4ede90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ede90
#include "pc2_port.h"

void __thiscall UI_DrawObjectSprite(void *self,uint32_t *arg1,void *arg2)

{
  void *this_00;
  
  this_00 = arg2;
  if (arg2 != (void *)0x0) {
    UI_AlignSpriteToRect(self,(int *)arg1,arg2,(int *)&arg1,(int *)&arg2);
    Sprite_BlitWithDefaultAlpha
              (this_00,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,arg1,(intptr_t)arg2,-1);
  }
  return;
}
