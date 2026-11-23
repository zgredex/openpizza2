// Object_IsKnownId: ported from Pizza Connection 2 at 0x4f2a20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f2a20
#include "pc2_port.h"

uint32_t Object_IsKnownId(int arg1)

{
  if (arg1 == -1) {
    return 1;
  }
  if ((0x355 < arg1) && (arg1 < 0x603)) {
    return 1;
  }
  if ((arg1 < 0x19) || (0x20 < arg1)) {
    return 0;
  }
  return 1;
}
