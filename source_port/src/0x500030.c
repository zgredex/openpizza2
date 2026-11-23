// UI_UpdateAllSlots: ported from Pizza Connection 2 at 0x500030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500030
#include "pc2_port.h"

void __fastcall UI_UpdateAllSlots(void *arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  ptr2 = (int *)((intptr_t)arg1 + 0x118);
  do {
    if (*ptr2 != 0) {
      Company_ScheduleDeadline(arg1,value1,10 - DAT_0057bb24);
    }
    value1 = value1 + 1;
    ptr2 = ptr2 + 0x5a;
  } while (value1 < 6);
  return;
}
