// FUN_00556798: ported from Pizza Connection 2 at 0x556798.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556798
#include "pc2_port.h"

uint32_t __cdecl FUN_00556798(int arg1)

{
  if (arg1 == 0x3a4) {
    return 0x411;
  }
  if (arg1 == 0x3a8) {
    return 0x804;
  }
  if (arg1 == 0x3b5) {
    return 0x412;
  }
  if (arg1 == 0x3b6) {
    return 0x404;
  }
  return 0;
}
