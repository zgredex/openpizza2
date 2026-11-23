// Object_GetField0C: ported from Pizza Connection 2 at 0x520e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520e20
#include "pc2_port.h"

uint32_t __fastcall Object_GetField0C(int arg1)

{
  return *(uint32_t *)(arg1 + 0xc);
}
