// Movie_UpdateFrame: ported from Pizza Connection 2 at 0x52bad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52bad0
#include "pc2_port.h"

void __thiscall Movie_UpdateFrame(void *self,int arg1)

{
  void *this_00;
  int value1;
  uint32_t uvalue2;
  
  if (*(int *)((intptr_t)self + 0xa4) == 3) {
    if (((*(uint32_t **)((intptr_t)self + 0xb8))[3] == 0) &&
       (value1 = _BinkWait_4(**(uint32_t **)((intptr_t)self + 0xb8)), value1 == 0)) {
      MovieWindow_AdvanceFrame(self,DAT_0057c5c8);
      UI_ClipRect(*(void **)((intptr_t)self + 8),(int *)((intptr_t)self + 0x28),1);
      return;
    }
  }
  else {
    uvalue2 = *(int *)((intptr_t)self + 0xb4) + arg1;
    *(uint32_t *)((intptr_t)self + 0xb4) = uvalue2;
    if (100 < uvalue2) {
      do {
        uvalue2 = uvalue2 - 100;
      } while (100 < uvalue2);
      value1 = *(int *)((intptr_t)self + 0x98);
      *(uint32_t *)((intptr_t)self + 0xb4) = uvalue2;
      this_00 = *(void **)((intptr_t)self + 0x54);
      if (((-1 < value1) && (value1 < *(int *)((intptr_t)this_00 + 0x48))) &&
         (*(char *)(*(int *)((intptr_t)this_00 + 0x4c) + 0x3e + value1 * 0x48) != '\0')) {
        RecordList_TickFrame(this_00,value1);
        UI_ClipRect(*(void **)((intptr_t)self + 8),(int *)((intptr_t)self + 0x28),1);
        return;
      }
      if (*(int *)((intptr_t)self + 0xb0) == 0) {
        *(uint32_t *)((intptr_t)self + 0xb0) = 1;
        UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),0,0);
      }
    }
  }
  return;
}
