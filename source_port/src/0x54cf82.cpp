// Stream_GetAvailable: ported from Pizza Connection 2 at 0x54cf82.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cf82
#include "pc2_port.h"

int __fastcall Stream_GetAvailable(int arg1)

{
  if (*(uint32_t *)(arg1 + 0x28) < *(uint32_t *)(arg1 + 0x2c)) {
    return *(uint32_t *)(arg1 + 0x2c) - *(uint32_t *)(arg1 + 0x28);
  }
  return 0;
}
