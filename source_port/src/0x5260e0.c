// Object_GetId: ported from Pizza Connection 2 at 0x5260e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5260e0
#include "pc2_port.h"

uint32_t Object_GetId(int arg1)

{
  if (arg1 == 0) {
    return 0xffffffff;
  }
  return *(uint32_t *)(arg1 + 4);
}
