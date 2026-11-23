// Object_ClearField4: ported from Pizza Connection 2 at 0x54b3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b3c0
#include "pc2_port.h"

void __fastcall Object_ClearField4(int arg1)

{
  *(uint32_t *)(arg1 + 4) = 0;
  return;
}
