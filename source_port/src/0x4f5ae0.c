// Object_ClearSlotRefs: ported from Pizza Connection 2 at 0x4f5ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5ae0
#include "pc2_port.h"

void __thiscall Object_ClearSlotRefs(void *self,int arg1)

{
  int value1;
  
  if (*(int *)(arg1 + 0x44) != -1) {
    value1 = *(int *)((intptr_t)self + 0x4c) + *(int *)(arg1 + 0x44) * 0xc;
    if ((value1 != 0) && (value1 = *(int *)(value1 + 8), value1 != 0)) {
      *(uint32_t *)(value1 + 0x38) = 0;
    }
    *(uint32_t *)(arg1 + 0x44) = 0xffffffff;
  }
  if (*(int *)(arg1 + 0x48) != -1) {
    value1 = *(int *)((intptr_t)self + 0x4c) + *(int *)(arg1 + 0x48) * 0xc;
    if ((value1 != 0) && (value1 = *(int *)(value1 + 8), value1 != 0)) {
      *(uint32_t *)(value1 + 0x38) = 0;
    }
    *(uint32_t *)(arg1 + 0x48) = 0xffffffff;
  }
  return;
}
