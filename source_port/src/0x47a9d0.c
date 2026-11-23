// Branch_RemoveStaffMember: ported from Pizza Connection 2 at 0x47a9d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a9d0
#include "pc2_port.h"

void __thiscall Branch_RemoveStaffMember(void *self,int *arg1,int arg2)

{
  void *this_00;
  void *pvVar1;
  int value2;
  uint32_t *uptr3;
  void *this_01;
  
                    /* Removes one employee from a branch, releases their job, and refreshes staff
                       UI. */
  if (*arg1 == *(int *)((intptr_t)self + 0x14c4)) {
    *(uint32_t *)((intptr_t)self + 0x14c4) = 0;
  }
  this_00 = (void *)((intptr_t)self + 0x1500);
  value2 = Map_LookupLinear(this_00,(intptr_t)arg1);
  if (value2 != -1) {
    uptr3 = (uint32_t *)IDMap_Lookup(this_00,value2,(int *)0x0);
    pvVar1 = (void *)*uptr3;
    this_01 = (void *)Game_GetRecordByField814((intptr_t)pvVar1);
    if (*(int *)((intptr_t)this_01 + 0x108) != 1) {
      Person_ReleaseFromBranch(pvVar1);
    }
    *(uint32_t *)((intptr_t)this_01 + 0x7c) = 0xff;
    if ((*(char *)((intptr_t)pvVar1 + 0x824) == '\x03') && (*(int *)((intptr_t)this_01 + 0xa4) == 4)) {
      Object_ClearAssignedRecord(this_01,self);
    }
    IDMap_RemoveRecursive(this_00,value2);
    if (((arg2 == 0) && (*(void **)(DAT_0057c670 + 0x21c) == this_01)) &&
       (*(void **)(DAT_0057c670 + 0x25c) != (void *)0x0)) {
      UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x18629,0x23,0);
    }
    Object_SetFieldA4Locked(this_01,0xffffffff);
    *(uint32_t *)((intptr_t)this_01 + 0x88) = 0xffffffff;
    Stats_ResetAverages(self);
  }
  Game_ToggleObjectFlag2(self);
  return;
}
