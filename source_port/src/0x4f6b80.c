// Mission_TickGoalDeadline: ported from Pizza Connection 2 at 0x4f6b80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f6b80
#include "pc2_port.h"

void __thiscall Mission_TickGoalDeadline(void *self,int arg1)

{
  if (*(char *)((intptr_t)self + 0xcc) == '\0') {
    *(int *)((intptr_t)self + 0xc0) = *(int *)((intptr_t)self + 0xc0) + -1;
    Mission_EvaluateGoals(self,arg1,'\0');
    if ((*(int *)((intptr_t)self + 0xc0) == 0) && (*(char *)((intptr_t)self + 0xcc) == '\0')) {
      Game_CompleteMissionStage();
    }
  }
  return;
}
