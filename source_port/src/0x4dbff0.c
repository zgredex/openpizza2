// Game_GetPlayerQuarterStat: ported from Pizza Connection 2 at 0x4dbff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dbff0
#include "pc2_port.h"

int __thiscall Game_GetPlayerQuarterStat(void *self,int arg1,uint32_t arg2)

{
  switch(arg2) {
  case 0:
    return *(int *)((intptr_t)self + arg1 * 4 + 0x200);
  case 1:
    return *(int *)((intptr_t)self + arg1 * 4 + 0x240);
  case 2:
    return *(int *)((intptr_t)self + arg1 * 4 + 0x220);
  case 3:
    return *(int *)((intptr_t)self + arg1 * 4 + 0x260);
  default:
    return *(int *)((intptr_t)self + arg1 * 4 + 0x260) + *(int *)((intptr_t)self + arg1 * 4 + 0x240) +
           *(int *)((intptr_t)self + arg1 * 4 + 0x220) + *(int *)((intptr_t)self + arg1 * 4 + 0x200) >>
           2;
  }
}
