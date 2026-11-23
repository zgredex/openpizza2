// Game_SetModeByte: ported from Pizza Connection 2 at 0x4e6300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e6300
#include "pc2_port.h"

void __thiscall Game_SetModeByte(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0xc) = arg1 & 0xff;
  if (((*(void **)(DAT_0057c670 + 0x220) == self) && (*(int *)(DAT_0057c670 + 0x2d8) == 0xb)) &&
     (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0)) {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x1861b,0x23,0);
  }
  return;
}
