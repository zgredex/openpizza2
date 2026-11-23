// Text_GetLineHeight: ported from Pizza Connection 2 at 0x535510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535510
#include "pc2_port.h"

uint32_t __fastcall Text_GetLineHeight(int arg1)

{
  return *(uint32_t *)(arg1 + 0x9b8);
}
