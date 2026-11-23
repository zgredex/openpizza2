// Get_FieldF0: ported from Pizza Connection 2 at 0x5312e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5312e0
#include "pc2_port.h"

uint32_t __fastcall Get_FieldF0(int arg1)

{
  return *(uint32_t *)(arg1 + 0xf0);
}
