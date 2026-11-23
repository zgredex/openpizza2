// Object_GetChildOrigin: ported from Pizza Connection 2 at 0x527ad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527ad0
#include "pc2_port.h"

void __thiscall Object_GetChildOrigin(void *self,uint32_t *arg1,uint32_t *arg2)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 0x8310);
  if (value1 == 0) {
    *arg1 = 0;
    *arg2 = 0;
    return;
  }
  *arg1 = *(uint32_t *)(value1 + 0xc);
  *arg2 = *(uint32_t *)(value1 + 0x10);
  return;
}
