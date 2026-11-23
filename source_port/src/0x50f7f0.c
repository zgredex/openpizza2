// Company_GetPercentModifier: ported from Pizza Connection 2 at 0x50f7f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f7f0
#include "pc2_port.h"

int __thiscall Company_GetPercentModifier(void *self,int arg1)

{
  if (arg1 == -1) {
    arg1 = *(int *)((intptr_t)self + 0x20);
  }
  if (*(int *)((intptr_t)self + 8) == 1) {
    return (arg1 * 100) / 10000;
  }
  if (*(int *)((intptr_t)self + 8) == 2) {
    return (arg1 * 100) / 5000;
  }
  return 100;
}
