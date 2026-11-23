// Game_SetDifficulty: ported from Pizza Connection 2 at 0x50fb40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fb40
#include "pc2_port.h"

void __thiscall Game_SetDifficulty(void *self,int arg1)

{
  *(int *)((intptr_t)self + 8) = arg1;
  if (arg1 == 1) {
    *(uint32_t *)((intptr_t)self + 0x20) = 10000;
  }
  else {
    if (arg1 == 2) {
      *(uint32_t *)((intptr_t)self + 0x20) = 5000;
      return;
    }
    if (arg1 == 3) {
      *(uint32_t *)((intptr_t)self + 0x20) = 0xdac;
      return;
    }
  }
  return;
}
