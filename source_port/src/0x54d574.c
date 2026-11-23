// Stream_PutBackChar: ported from Pizza Connection 2 at 0x54d574.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d574
#include "pc2_port.h"

int __thiscall Stream_PutBackChar(void *self,char arg1)

{
  char *cptr1;
  int value2;
  
  if (*(uint32_t *)((intptr_t)self + 0x24) < *(uint32_t *)((intptr_t)self + 0x28)) {
    cptr1 = (char *)(*(uint32_t *)((intptr_t)self + 0x28) - 1);
    *(char **)((intptr_t)self + 0x28) = cptr1;
    *cptr1 = arg1;
    value2 = (intptr_t)arg1;
  }
  else {
    value2 = (**(code **)(*(int *)self + 0x24))((intptr_t)arg1);
  }
  return value2;
}
