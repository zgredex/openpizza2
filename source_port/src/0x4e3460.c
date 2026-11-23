// Recipe_SetOnMenu: ported from Pizza Connection 2 at 0x4e3460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3460
#include "pc2_port.h"

void __thiscall Recipe_SetOnMenu(void *self,int arg1,uint8_t arg2)

{
  if (arg1 != 0) {
    *(uint8_t *)(arg1 + 0x1dc) = arg2;
    Company_InvalidateAllBranchRatings((intptr_t)self);
    if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x18658,0x23,0);
    }
  }
  return;
}
