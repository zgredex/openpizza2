// GameClock_Construct: ported from Pizza Connection 2 at 0x4dd270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd270
#include "pc2_port.h"

uint32_t * __thiscall GameClock_Construct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_GameClock_Delete_0055c564;
  DAT_0057dfbc = 2000;
  if (arg1 == (void *)0x0) {
    GameClock_Reset((intptr_t)self);
  }
  else {
    GameCalendar_Load(self,arg1);
  }
  *(uint32_t *)((intptr_t)self + 0x1c) = 0;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 0xc35;
  CRT_BeginThread(0x4dd2d0,0,(intptr_t)self);
  return self;
}
