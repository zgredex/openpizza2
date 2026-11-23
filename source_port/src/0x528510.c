// UI_ScrollChildByVelocity: ported from Pizza Connection 2 at 0x528510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528510
#include "pc2_port.h"

bool __thiscall UI_ScrollChildByVelocity(void *self,uint32_t arg1,int arg2)

{
  int value1;
  int64_t lvalue2;
  
  if (*(int *)((intptr_t)self + 0x1c) < 0) {
    *(uint32_t *)((intptr_t)self + 0x2c) = *(uint32_t *)((intptr_t)self + 0x34);
    *(uint32_t *)((intptr_t)self + 0x30) = *(uint32_t *)((intptr_t)self + 0x38);
  }
  else {
    *(float *)((intptr_t)self + 0x2c) =
         (float)arg2 * *(float *)((intptr_t)self + 0x24) + *(float *)((intptr_t)self + 0x2c);
    *(float *)((intptr_t)self + 0x30) =
         (float)arg2 * *(float *)((intptr_t)self + 0x28) + *(float *)((intptr_t)self + 0x30);
  }
  lvalue2 = __ftol();
  value1 = (intptr_t)lvalue2;
  lvalue2 = __ftol();
  UI_MoveChildToPosition(*(void **)((intptr_t)self + 0x20),(intptr_t)lvalue2,value1);
  UI_ClipChildRect(*(int *)((intptr_t)self + 0x20));
  return -1 < *(int *)((intptr_t)self + 0x1c);
}
