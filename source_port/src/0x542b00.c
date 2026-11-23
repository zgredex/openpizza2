// List_Remove: ported from Pizza Connection 2 at 0x542b00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x542b00
#include "pc2_port.h"

void __thiscall List_Remove(void *self,int arg1)

{
  if (*(int *)((intptr_t)self + 8) == arg1) {
    *(uint32_t *)((intptr_t)self + 8) = *(uint32_t *)(*(int *)((intptr_t)self + 8) + 4);
  }
  if (*(int *)(arg1 + 8) == 0) {
    *(uint32_t *)self = *(uint32_t *)(arg1 + 4);
  }
  else {
    *(uint32_t *)(*(int *)(arg1 + 8) + 4) = *(uint32_t *)(arg1 + 4);
  }
  if (arg1 == *(int *)((intptr_t)self + 4)) {
    *(uint32_t *)((intptr_t)self + 4) = *(uint32_t *)(arg1 + 8);
  }
  if (*(int *)(arg1 + 4) != 0) {
    *(uint32_t *)(*(int *)(arg1 + 4) + 8) = *(uint32_t *)(arg1 + 8);
  }
  *(int *)((intptr_t)self + 0xc) = *(int *)((intptr_t)self + 0xc) + -1;
  return;
}
