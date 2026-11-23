// UI_Text_BeginScrollAnimation: ported from Pizza Connection 2 at 0x520f30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520f30
#include "pc2_port.h"

void __thiscall UI_Text_BeginScrollAnimation(void *self,uint32_t arg1,uint32_t arg2)

{
  if (*(int *)((intptr_t)self + 0x4c) == 0) {
    UI_AddEffectObject(*(void **)(*(int *)((intptr_t)self + 8) + 0x134),self);
    *(uint32_t *)((intptr_t)self + 0x4c) = 1;
    *(uint32_t *)((intptr_t)self + 0x48) = arg2;
    *(uint32_t *)((intptr_t)self + 0x44) = arg1;
    return;
  }
  *(uint32_t *)((intptr_t)self + 0x48) = arg2;
  *(uint32_t *)((intptr_t)self + 0x44) = arg1;
  return;
}
