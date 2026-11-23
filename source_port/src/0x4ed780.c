// UI_AlignSpriteToRect: ported from Pizza Connection 2 at 0x4ed780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed780
#include "pc2_port.h"

void __thiscall
UI_AlignSpriteToRect(void *self,int *arg1,void *arg2,int *arg3,int *arg4)

{
  int value1;
  void *local_4;
  
  local_4 = self;
  Sprite_GetRenderSize(arg2,(uint32_t *)&local_4,(uint32_t *)&arg2);
  *arg3 = (((*(int *)((intptr_t)self + 0xc) >> 1) - ((intptr_t)local_4 >> 1)) - *(int *)((intptr_t)self + 0x24))
             + *arg1;
  value1 = arg1[1] - *(int *)((intptr_t)self + 0x28);
  *arg4 = value1;
  if (*(int *)((intptr_t)self + 0xc) == 0x10) {
    *arg4 = value1 - (intptr_t)arg2;
    *arg4 = (value1 - (intptr_t)arg2) + *(int *)((intptr_t)self + 0x10) * 3;
    return;
  }
  if (*(int *)((intptr_t)self + 0xc) < (intptr_t)local_4) {
    *arg4 = value1 - (intptr_t)arg2;
    *arg4 = (value1 - (intptr_t)arg2) + *(int *)((intptr_t)self + 0x10) * 3;
  }
  return;
}
