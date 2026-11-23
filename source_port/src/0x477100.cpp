// Clamp_0_100: ported from Pizza Connection 2 at 0x477100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477100
#include "pc2_port.h"

void Clamp_0_100(int *arg1)

{
  if (100 < *arg1) {
    *arg1 = 100;
  }
  if (*arg1 < 0) {
    *arg1 = 0;
  }
  return;
}
