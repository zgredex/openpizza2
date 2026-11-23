// UI_Sprite_BeginAnimation: ported from Pizza Connection 2 at 0x521b40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521b40
#include "pc2_port.h"

void __thiscall
UI_Sprite_BeginAnimation(void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3)

{
  void *this_00;
  
  this_00 = *(void **)(*(int *)((intptr_t)self + 8) + 0x134);
  if (*(int *)((intptr_t)self + 0x4c) == 0) {
    *(uint32_t *)((intptr_t)self + 0x9c) = 0;
    UI_AddEffectObject(this_00,self);
    *(uint32_t *)((intptr_t)self + 0x4c) = 1;
    *(uint32_t *)((intptr_t)self + 0x74) = arg3;
    *(uint32_t *)((intptr_t)self + 0x70) = arg2;
    return;
  }
  *(uint32_t *)((intptr_t)self + 0x74) = arg3;
  *(uint32_t *)((intptr_t)self + 0x70) = arg2;
  return;
}
