// Renderer_InitOrCopyState: ported from Pizza Connection 2 at 0x538930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538930
#include "pc2_port.h"

void __thiscall Renderer_InitOrCopyState(void *self,int arg1)

{
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  if (arg1 == 0) {
    **(uint32_t **)((intptr_t)self + 0x40) = 0;
    *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 4) = 0;
    *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 8) = 0;
    *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 0x10) = 0;
    *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 0xc) = 0;
    *(uint16_t *)((intptr_t)self + 0x1a) = (uint16_t)DAT_00574734;
    *(uint16_t *)((intptr_t)self + 0x1c) = (uint16_t)DAT_00574738;
    *(uint32_t *)((intptr_t)self + 0x48) = 0;
    Surface_ResetFlags((intptr_t)self);
    *(uint32_t *)((intptr_t)self + 0x84) = 0;
    *(uint32_t *)((intptr_t)self + 0x88) = 0;
    *(uint32_t *)((intptr_t)self + 0x8c) = 0;
    *(uint32_t *)((intptr_t)self + 0x90) = 0;
    *(uint32_t *)((intptr_t)self + 0x94) = 0;
  }
  else {
    *(uint32_t *)((intptr_t)self + 0x44) = *(uint32_t *)(arg1 + 0x44);
    **(uint32_t **)((intptr_t)self + 0x40) = **(uint32_t **)(arg1 + 0x40);
    *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 4) = *(uint32_t *)(*(int *)(arg1 + 0x40) + 4);
    *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 8) = *(uint32_t *)(*(int *)(arg1 + 0x40) + 8);
    *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 0x10) =
         *(uint32_t *)(*(int *)(arg1 + 0x40) + 4);
    *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 0xc) =
         *(uint32_t *)(*(int *)(arg1 + 0x40) + 8);
    *(uint8_t *)((intptr_t)self + 0x18) = *(uint8_t *)(arg1 + 0x18);
    *(uint32_t *)((intptr_t)self + 0x24) = *(uint32_t *)(arg1 + 0x24);
    *(uint32_t *)((intptr_t)self + 0x34) = *(uint32_t *)(arg1 + 0x34);
    *(uint32_t *)((intptr_t)self + 0x38) = *(uint32_t *)(arg1 + 0x38);
    *(uint32_t *)((intptr_t)self + 0x3c) = *(uint32_t *)(arg1 + 0x3c);
    *(uint16_t *)((intptr_t)self + 0x1a) = *(uint16_t *)(arg1 + 0x1a);
    *(uint16_t *)((intptr_t)self + 0x1c) = *(uint16_t *)(arg1 + 0x1c);
    *(uint32_t *)((intptr_t)self + 0x48) = 1;
    *(int *)((intptr_t)self + 0x54) = arg1;
    *(uint32_t *)((intptr_t)self + 0x74) = *(uint32_t *)(arg1 + 0x74);
    *(uint32_t *)((intptr_t)self + 0x84) = *(uint32_t *)(arg1 + 0x84);
    *(uint32_t *)((intptr_t)self + 0x88) = *(uint32_t *)(arg1 + 0x88);
    *(uint32_t *)((intptr_t)self + 0x8c) = *(uint32_t *)(arg1 + 0x8c);
    *(uint32_t *)((intptr_t)self + 0x90) = *(uint32_t *)(arg1 + 0x90);
    *(uint32_t *)((intptr_t)self + 0x94) = *(uint32_t *)(arg1 + 0x94);
  }
  Surface_Reset((intptr_t)self);
  SetRect((LPRECT)((intptr_t)self + 100),0,0,(uint32_t)*(uint16_t *)((intptr_t)self + 0x1a),
          (uint32_t)*(uint16_t *)((intptr_t)self + 0x1c));
  *(uint32_t *)((intptr_t)self + 0x5c) = 0;
  *(uint32_t *)((intptr_t)self + 0x60) = 0;
  *(uint32_t *)((intptr_t)self + 0x58) = 1;
  return;
}
