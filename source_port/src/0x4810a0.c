// Game_SetStageIfHigher: ported from Pizza Connection 2 at 0x4810a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4810a0
#include "pc2_port.h"

uint32_t __thiscall Game_SetStageIfHigher(void *self,int arg1)

{
  if (arg1 == 0) {
    *(uint32_t *)((intptr_t)self + 0x2c) = 0;
    return 1;
  }
  if (*(int *)((intptr_t)self + 0x2c) != arg1) {
    if (arg1 < *(int *)((intptr_t)self + 0x2c)) {
      return 0;
    }
    *(int *)((intptr_t)self + 0x2c) = arg1;
    Game_SetChildField94(self,1);
  }
  return 1;
}
