// Stream_SetBuffer: ported from Pizza Connection 2 at 0x54d921.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d921
#include "pc2_port.h"

void __thiscall Stream_SetBuffer(void *self,int arg1)

{
  if ((*(int *)((intptr_t)self + 0x1c) != 0) && (*(uint32_t **)((intptr_t)self + 4) != (uint32_t *)0x0)) {
    (**(code **)**(uint32_t **)((intptr_t)self + 4))(1);
  }
  *(int *)((intptr_t)self + 4) = arg1;
  if (arg1 == 0) {
    *(uint32_t *)((intptr_t)self + 8) = *(uint32_t *)((intptr_t)self + 8) | 4;
  }
  else {
    *(uint32_t *)((intptr_t)self + 8) = *(uint32_t *)((intptr_t)self + 8) & 0xfffffffb;
  }
  return;
}
