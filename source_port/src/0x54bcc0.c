// MapBadgeAnim_SetWindow: ported from Pizza Connection 2 at 0x54bcc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54bcc0
#include "pc2_port.h"

void __thiscall MapBadgeAnim_SetWindow(void *self,void *arg1,int arg2)

{
  uint32_t *uptr1;
  
  *(void **)((intptr_t)self + 0x1a8) = arg1;
  uptr1 = (uint32_t *)UI_GetWindowObject(arg1,arg2);
  *(uint32_t **)((intptr_t)self + 4) = uptr1;
  UI_UpdateAnimatedSprites(self,uptr1);
  return;
}
