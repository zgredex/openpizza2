// ConstructionOrder_Construct: ported from Pizza Connection 2 at 0x4e5d60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e5d60
#include "pc2_port.h"

void __thiscall ConstructionOrder_Construct(void *self,uint32_t arg1,uint32_t arg2)

{
                    /* Constructs a furniture construction order with quality and sentinels. */
  *(uint32_t *)((intptr_t)self + 4) = arg1;
  *(uint32_t *)((intptr_t)self + 8) = arg2;
  *(uint8_t ***)self = &PTR_ConstructionOrder_Delete_0055c5bc;
  *(uint32_t *)((intptr_t)self + 0xc) = 100;
  *(uint32_t *)((intptr_t)self + 0x10) = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x18) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x1c) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  return;
}
