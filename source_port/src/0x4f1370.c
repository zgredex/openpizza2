// List_AppendNode: ported from Pizza Connection 2 at 0x4f1370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1370
#include "pc2_port.h"

void __thiscall List_AppendNode(void *self,int arg1)

{
  int value1;
  int value2;
  
  value1 = *(int *)((intptr_t)self + 0xbc);
  if (value1 == 0) {
    *(int *)((intptr_t)self + 0xbc) = arg1;
    *(uint32_t *)(arg1 + 0x70) = 0;
    return;
  }
  for (value2 = *(int *)(value1 + 0x70); value2 != 0; value2 = *(int *)(value2 + 0x70)) {
    value1 = value2;
  }
  *(int *)(value1 + 0x70) = arg1;
  *(uint32_t *)(arg1 + 0x70) = 0;
  return;
}
