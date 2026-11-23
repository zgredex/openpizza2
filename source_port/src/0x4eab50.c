// SparseMap_Lookup48: ported from Pizza Connection 2 at 0x4eab50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eab50
#include "pc2_port.h"

uint32_t __thiscall SparseMap_Lookup48(void *self,int arg1)

{
  if (arg1 == -1) {
    return *(uint32_t *)((intptr_t)self + 4);
  }
  if (arg1 < 0) {
    return *(uint32_t *)((intptr_t)self + 8);
  }
  if (arg1 < 0x9c4) {
    return *(uint32_t *)((intptr_t)self + arg1 * 0x48 + 0x58);
  }
  return 0;
}
