// Renderer_CopyState: ported from Pizza Connection 2 at 0x538870.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538870
#include "pc2_port.h"

void __thiscall Renderer_CopyState(void *self,int arg1)

{
  *(uint8_t *)((intptr_t)self + 0x30) = 0;
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint32_t *)((intptr_t)self + 0x44) = *(uint32_t *)(arg1 + 0x44);
  **(uint32_t **)((intptr_t)self + 0x40) = **(uint32_t **)(arg1 + 0x40);
  *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 4) = *(uint32_t *)(*(int *)(arg1 + 0x40) + 4);
  *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 8) = *(uint32_t *)(*(int *)(arg1 + 0x40) + 8);
  *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 0x10) = *(uint32_t *)(*(int *)(arg1 + 0x40) + 4)
  ;
  *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 0xc) = *(uint32_t *)(*(int *)(arg1 + 0x40) + 8);
  *(uint8_t *)((intptr_t)self + 0x18) = *(uint8_t *)(arg1 + 0x18);
  *(uint32_t *)((intptr_t)self + 0x24) = *(uint32_t *)(arg1 + 0x24);
  *(uint32_t *)((intptr_t)self + 0x34) = *(uint32_t *)(arg1 + 0x34);
  *(uint32_t *)((intptr_t)self + 0x38) = *(uint32_t *)(arg1 + 0x38);
  *(uint32_t *)((intptr_t)self + 0x3c) = *(uint32_t *)(arg1 + 0x3c);
  *(uint32_t *)((intptr_t)self + 0x48) = 1;
  *(int *)((intptr_t)self + 0x54) = arg1;
  *(uint32_t *)((intptr_t)self + 0x74) = *(uint32_t *)(arg1 + 0x74);
  *(uint32_t *)((intptr_t)self + 0x84) = *(uint32_t *)(arg1 + 0x84);
  *(uint32_t *)((intptr_t)self + 0x88) = *(uint32_t *)(arg1 + 0x88);
  *(uint32_t *)((intptr_t)self + 0x8c) = *(uint32_t *)(arg1 + 0x8c);
  *(uint32_t *)((intptr_t)self + 0x90) = *(uint32_t *)(arg1 + 0x90);
  *(uint32_t *)((intptr_t)self + 0x94) = *(uint32_t *)(arg1 + 0x94);
  *(uint8_t *)((intptr_t)self + 0x30) = *(uint8_t *)(arg1 + 0x30);
  return;
}
