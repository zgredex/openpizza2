// Array_Copy68: ported from Pizza Connection 2 at 0x47c3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c3c0
#include "pc2_port.h"

void __thiscall Array_Copy68(void *self,uint32_t *arg1)

{
  int value1;
  uint32_t *uptr2;
  
  uptr2 = (uint32_t *)((intptr_t)self + 0x151c);
  for (value1 = 0x68; value1 != 0; value1 = value1 + -1) {
    *arg1 = *uptr2;
    uptr2 = uptr2 + 1;
    arg1 = arg1 + 1;
  }
  return;
}
