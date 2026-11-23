// Product_HasStock: ported from Pizza Connection 2 at 0x512730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512730
#include "pc2_port.h"

bool __thiscall Product_HasStock(void *self,uint32_t arg1)

{
  return 0 < *(int *)((intptr_t)self + (arg1 & 0xff) * 4 + 100);
}
