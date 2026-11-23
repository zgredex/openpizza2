// Storage_RemoveRecord: ported from Pizza Connection 2 at 0x514080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514080
#include "pc2_port.h"

void __thiscall Storage_RemoveRecord(void *self,int arg1)

{
  int value1;
  
  value1 = Array_FindPair(self,*(int *)(arg1 + 0x3c));
  if (value1 != -1) {
    *(uint32_t *)((intptr_t)self + (value1 * 3 + 0x18) * 4) = 0;
    *(uint32_t *)((intptr_t)self + value1 * 0xc + 100) = 0;
  }
  return;
}
