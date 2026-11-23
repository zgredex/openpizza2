// List_Insert: ported from Pizza Connection 2 at 0x546f00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546f00
#include "pc2_port.h"

void __thiscall List_Insert(void *self,int arg1,char arg2)

{
  if (arg2 == '\0') {
    *(uint32_t *)(arg1 + 8) = 0;
    *(uint32_t *)(arg1 + 4) = *(uint32_t *)self;
    if (*(int *)self != 0) {
      *(int *)(*(int *)self + 8) = arg1;
    }
    if (*(int *)((intptr_t)self + 8) == *(int *)self) {
      *(int *)((intptr_t)self + 8) = arg1;
    }
    *(int *)self = arg1;
    if (*(int *)((intptr_t)self + 4) == 0) {
      *(int *)((intptr_t)self + 4) = arg1;
    }
  }
  else {
    *(uint32_t *)(arg1 + 8) = *(uint32_t *)((intptr_t)self + 4);
    *(uint32_t *)(arg1 + 4) = 0;
    if (*(int *)((intptr_t)self + 4) != 0) {
      *(int *)(*(int *)((intptr_t)self + 4) + 4) = arg1;
    }
    if (*(int *)((intptr_t)self + 8) == *(int *)((intptr_t)self + 4)) {
      *(int *)((intptr_t)self + 8) = arg1;
    }
    *(int *)((intptr_t)self + 4) = arg1;
    if (*(int *)self == 0) {
      *(int *)self = arg1;
      *(int *)((intptr_t)self + 0xc) = *(int *)((intptr_t)self + 0xc) + 1;
      return;
    }
  }
  *(int *)((intptr_t)self + 0xc) = *(int *)((intptr_t)self + 0xc) + 1;
  return;
}
