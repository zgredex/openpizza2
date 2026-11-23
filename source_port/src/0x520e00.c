// Get_Field24: ported from Pizza Connection 2 at 0x520e00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520e00
#include "pc2_port.h"

uint32_t __fastcall Get_Field24(int arg1)

{
  return *(uint32_t *)(arg1 + 0x24);
}
