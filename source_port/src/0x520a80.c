// UI_Child_Construct: ported from Pizza Connection 2 at 0x520a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520a80
#include "pc2_port.h"

void __thiscall
UI_Child_Construct(void *self,uint32_t arg1,int arg2,int arg3,uint32_t arg4)

{
                    /* Constructs the base UI child element. */
  *(int *)((intptr_t)self + 0x38) = arg2;
  *(int *)((intptr_t)self + 0x28) = arg2;
  *(int *)((intptr_t)self + 0x3c) = arg3;
  *(int *)((intptr_t)self + 0x2c) = arg3;
  *(uint32_t *)((intptr_t)self + 8) = arg4;
  *(int *)((intptr_t)self + 0x30) = arg2 + 100;
  *(int *)((intptr_t)self + 0x34) = arg3 + 0x14;
  *(uint32_t *)((intptr_t)self + 4) = arg1;
  *(uint8_t ***)self = &PTR_UI_Child_Delete_0055c720;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 1;
  *(uint32_t *)((intptr_t)self + 0x1c) = 0;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 0x10) = 0;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  *(uint32_t *)((intptr_t)self + 0x20) = 1;
  *(uint32_t *)((intptr_t)self + 0x48) = 0;
  *(uint32_t *)((intptr_t)self + 0x44) = 0;
  *(uint32_t *)((intptr_t)self + 0x4c) = 0;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  return;
}
