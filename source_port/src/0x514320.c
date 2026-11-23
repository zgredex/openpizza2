// Storage_GetCapacity: ported from Pizza Connection 2 at 0x514320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514320
#include "pc2_port.h"

int __fastcall Storage_GetCapacity(int arg1)

{
  return *(int *)(arg1 + 0x2c) * 0xf + 0x24;
}
