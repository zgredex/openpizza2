// Stream_ValidateRange: ported from Pizza Connection 2 at 0x54dc72.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dc72
#include "pc2_port.h"

uint32_t __fastcall Stream_ValidateRange(int arg1)

{
  if ((*(uint32_t *)(arg1 + 0x28) < *(uint32_t *)(arg1 + 0x2c)) ||
     (*(uint32_t *)(arg1 + 0x18) < *(uint32_t *)(arg1 + 0x1c))) {
    return 0xffffffff;
  }
  return 0;
}
