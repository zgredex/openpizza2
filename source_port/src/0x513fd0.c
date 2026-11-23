// Get_Field2C: ported from Pizza Connection 2 at 0x513fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513fd0
#include "pc2_port.h"

uint32_t __fastcall Get_Field2C(int arg1)

{
  return *(uint32_t *)(arg1 + 0x2c);
}
