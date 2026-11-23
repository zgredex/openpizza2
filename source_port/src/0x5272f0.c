// UI_ShowTooltip: ported from Pizza Connection 2 at 0x5272f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5272f0
#include "pc2_port.h"

void __thiscall UI_ShowTooltip(void *self,char *arg1,int arg2,int arg3)

{
  if (*(int *)((intptr_t)*(void **)((intptr_t)self + 0x244) + 0x14) != 0) {
    *(uint32_t *)((intptr_t)self + 0x82f0) = 1;
    return;
  }
  if (arg2 == -999) {
    arg2 = *(int *)((intptr_t)self + 0x82e4) + *(int *)((intptr_t)self + 0x248);
  }
  if (arg3 == -999) {
    arg3 = *(int *)((intptr_t)self + 0x82e8) + *(int *)((intptr_t)self + 0x24c);
  }
  Movie_PlayFile(*(void **)((intptr_t)self + 0x244),arg2,arg3,*(int *)((intptr_t)self + 0x270),
                 *(int *)((intptr_t)self + 0x274),arg1);
  *(uint32_t *)((intptr_t)self + 0x234) = 1;
  *(uint32_t *)((intptr_t)self + 0x82f0) = 1;
  return;
}
