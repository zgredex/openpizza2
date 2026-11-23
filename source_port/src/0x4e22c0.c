// Game_CompleteStaffAssignment: ported from Pizza Connection 2 at 0x4e22c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e22c0
#include "pc2_port.h"

void __thiscall Game_CompleteStaffAssignment(void *self,int arg1,void *arg2)

{
  int value1;
  void *this_00;
  int value2;
  
  value1 = *(int *)((intptr_t)self + 0x194);
  value2 = 0;
  if (0 < value1) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x180),value2,(int *)0x0);
      Storage_RemoveRecord(this_00,arg1);
      value2 = value2 + 1;
    } while (value2 < value1);
  }
  StaffList_AddId(arg2,*(int *)(arg1 + 0x3c));
  if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x18659,0x23,0);
  }
  return;
}
