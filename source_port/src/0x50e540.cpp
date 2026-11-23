// Object_IsState10: ported from Pizza Connection 2 at 0x50e540.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e540
#include "pc2_port.h"

bool __fastcall Object_IsState10(int arg1)

{
  return *(int *)(arg1 + 0x108) == 10;
}
