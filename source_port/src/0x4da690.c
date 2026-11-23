// Array_FindIndexStride60: ported from Pizza Connection 2 at 0x4da690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da690
#include "pc2_port.h"

void __thiscall Array_FindIndexStride60(void *self,int arg1)

{
  int value1;
  int value2;
  
  value1 = 0;
  value2 = (intptr_t)self + 0xdc8;
  do {
    if (value2 == arg1) {
      return;
    }
    value1 = value1 + 1;
    value2 = value2 + 0x60;
  } while (value1 < 4);
  return;
}
