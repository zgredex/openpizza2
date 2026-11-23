// Economy_ApplyTablePercent: ported from Pizza Connection 2 at 0x4dd0f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd0f0
#include "pc2_port.h"

int __thiscall Economy_ApplyTablePercent(void *self,int arg1)

{
  return (*(int *)(&DAT_0056ca2c + (arg1 + *(int *)((intptr_t)self + 0x10bc) * 9) * 4) *
         *(int *)((intptr_t)self + arg1 * 4 + 0x6c)) / 100;
}
