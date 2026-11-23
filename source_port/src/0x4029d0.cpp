// Resource_GetSize: ported from Pizza Connection 2 at 0x4029d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4029d0
#include "pc2_port.h"

uint32_t Resource_GetSize(int arg1)

{
  return *(uint32_t *)(arg1 + 8);
}
