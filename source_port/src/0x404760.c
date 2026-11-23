// ShutdownScreens: ported from Pizza Connection 2 at 0x404760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x404760
#include "pc2_port.h"

void ShutdownScreens(void)

{
  if (DAT_0057c5f8 != '\x01') {
    DAT_0057c5f8 = '\x01';
    if (DAT_0057c5cc != (uint32_t *)0x0) {
      (**(code **)*DAT_0057c5cc)(1);
      DAT_0057c5cc = (uint32_t *)0x0;
    }
    if (DAT_0057c5c8 != (uint32_t *)0x0) {
      (**(code **)*DAT_0057c5c8)(1);
      DAT_0057c5c8 = (uint32_t *)0x0;
    }
  }
  return;
}
