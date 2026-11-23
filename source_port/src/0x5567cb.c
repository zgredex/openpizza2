// FUN_005567cb: ported from Pizza Connection 2 at 0x5567cb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5567cb
#include "pc2_port.h"

void FUN_005567cb(void)

{
  int value1;
  uint32_t *uptr2;
  
  uptr2 = &DAT_00585ac0;
  for (value1 = 0x40; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  *(uint8_t *)uptr2 = 0;
  DAT_005859ac = 0;
  DAT_005859bc = 0;
  DAT_00585bc4 = 0;
  DAT_005859b0 = 0;
  DAT_005859b4 = 0;
  DAT_005859b8 = 0;
  return;
}
