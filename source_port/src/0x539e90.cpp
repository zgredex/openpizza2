// Object_ClearField54: ported from Pizza Connection 2 at 0x539e90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539e90
#include "pc2_port.h"

void __fastcall Object_ClearField54(int arg1)

{
  *(uint32_t *)(arg1 + 0x54) = 0;
  return;
}
