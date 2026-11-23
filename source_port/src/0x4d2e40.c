// IsSpecialIdRange: ported from Pizza Connection 2 at 0x4d2e40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2e40
#include "pc2_port.h"

uint32_t __fastcall IsSpecialIdRange(int arg1)

{
  if ((*(int *)(arg1 + 0x20) < 0x84c) || (0x857 < *(int *)(arg1 + 0x20))) {
    return 0;
  }
  return 1;
}
