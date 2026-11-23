// Get_Field19F4: ported from Pizza Connection 2 at 0x480050.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480050
#include "pc2_port.h"

uint32_t __fastcall Get_Field19F4(int arg1)

{
  return *(uint32_t *)(arg1 + 0x19f4);
}
