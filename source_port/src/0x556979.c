// FUN_00556979: ported from Pizza Connection 2 at 0x556979.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556979
#include "pc2_port.h"

void FUN_00556979(void)

{
  if (DAT_00586d2c == 0) {
    FUN_005565a1(-3);
    DAT_00586d2c = 1;
  }
  return;
}
