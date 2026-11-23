// Sprite_GetPointPair: ported from Pizza Connection 2 at 0x533560.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533560
#include "pc2_port.h"

uint32_t __thiscall
Sprite_GetPointPair(void *self,int arg1,uint32_t *arg2,uint32_t *arg3)

{
  int64_t lvalue1;
  
  if ((arg1 < 0) || (*(int *)((intptr_t)self + 0x48) <= arg1)) {
    return arg1 & 0xffffff00;
  }
  lvalue1 = __ftol();
  *arg2 = (intptr_t)lvalue1;
  lvalue1 = __ftol();
  *arg3 = (intptr_t)lvalue1;
  return CONCAT31((int3)((uint64_t)lvalue1 >> 8),1);
}
