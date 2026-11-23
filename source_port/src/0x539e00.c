// List_PushFront: ported from Pizza Connection 2 at 0x539e00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539e00
#include "pc2_port.h"

void __thiscall List_PushFront(void *self,uint32_t arg1)

{
  uint32_t *uptr1;
  
  uptr1 = operator_new(8);
  *uptr1 = arg1;
  uptr1[1] = *(uint32_t *)((intptr_t)self + 0x50);
  *(uint32_t **)((intptr_t)self + 0x50) = uptr1;
  return;
}
