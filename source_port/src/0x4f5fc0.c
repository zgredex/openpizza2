// Object_ClearField28: ported from Pizza Connection 2 at 0x4f5fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5fc0
#include "pc2_port.h"

void __fastcall Object_ClearField28(int arg1)

{
  *(uint32_t *)(arg1 + 0x28) = 0;
  return;
}
