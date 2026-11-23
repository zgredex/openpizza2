// Color_Convert555To565: ported from Pizza Connection 2 at 0x539340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539340
#include "pc2_port.h"

void __thiscall Color_Convert555To565(void *self,uint16_t *arg1,int arg2)

{
  if ((*(char *)((intptr_t)self + 0x18) != '\0') && (0 < arg2)) {
    do {
      arg2 = arg2 + -1;
      *arg1 = (*arg1 & 0xffe0) << 1 | *arg1 & 0x1f;
      arg1 = arg1 + 1;
    } while (arg2 != 0);
  }
  return;
}
