// State_Is2DOr2E: ported from Pizza Connection 2 at 0x50dbd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50dbd0
#include "pc2_port.h"

uint32_t __fastcall State_Is2DOr2E(int arg1)

{
  if ((*(int *)(arg1 + 0x38) == 0x2d) || (*(int *)(arg1 + 0x38) == 0x2e)) {
    return 1;
  }
  return 0;
}
