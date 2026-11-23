// Branch_ClearAssignedEmployee: ported from Pizza Connection 2 at 0x477b80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477b80
#include "pc2_port.h"

void __fastcall Branch_ClearAssignedEmployee(int arg1)

{
  int value1;
  
  *(uint32_t *)(arg1 + 0x14dc) = 0;
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x30));
  Company_InvalidateAllBranchRatings(value1);
  if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18658,0x23,0);
  }
  Game_ClearObjectFlag20(arg1);
  return;
}
