// Math_PiecewiseLinear: ported from Pizza Connection 2 at 0x50fbe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fbe0
#include "pc2_port.h"

int Math_PiecewiseLinear(int arg1)

{
  if (arg1 < 0x32) {
    return (arg1 * 0x12) / 0x19;
  }
  return ((arg1 + -0x32) * 0x20) / 0x19 + 0x24;
}
