// Player_ResetDebtHours: ported from Pizza Connection 2 at 0x4e3be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3be0
#include "pc2_port.h"

void __fastcall Player_ResetDebtHours(int arg1)

{
  if (0.0 <= *(double *)(arg1 + 0x108)) {
    *(uint32_t *)(arg1 + 0x1e8) = 0;
  }
  return;
}
