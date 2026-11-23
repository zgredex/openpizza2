// Screen_CloseSubStartMenu: ported from Pizza Connection 2 at 0x4052a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4052a0
#include "pc2_port.h"

void Screen_CloseSubStartMenu(void)

{
  if (DAT_0057c5f0 != (uint32_t *)0x0) {
    Window_DestroyChild(DAT_0057c5e0,DAT_0057c5f0);
  }
  DAT_0057c5f0 = (uint32_t *)0x0;
  return;
}
