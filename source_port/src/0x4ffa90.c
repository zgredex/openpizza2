// Company_ScheduleDeadline: ported from Pizza Connection 2 at 0x4ffa90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ffa90
#include "pc2_port.h"

void __thiscall Company_ScheduleDeadline(void *self,int arg1,int arg2)

{
  int value1;
  
  value1 = Game_GetDateField0C(DAT_0057c670);
  *(int *)((intptr_t)self + arg1 * 0x168 + 0x54) = value1 + arg2;
  Company_PushRecentEntry(self,arg1,1,-1,-1);
  return;
}
