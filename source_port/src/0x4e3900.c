// Company_Dissolve: ported from Pizza Connection 2 at 0x4e3900.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3900
#include "pc2_port.h"

void __thiscall Company_Dissolve(void *self,int arg1)

{
  int value1;
  int *ptr2;
  uint32_t *uptr3;
  void *pvVar4;
  int value5;
  void *this_00;
  int value6;
  
                    /* Dissolves a company and releases its staff and branches. */
  value1 = Game_CountActiveObjectsByType(self,-1);
  value1 = value1 + -1;
  if (-1 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value1,(int *)0x0);
      Company_RemoveStaffMember(self,*ptr2);
      value1 = value1 + -1;
    } while (-1 < value1);
  }
  value1 = *(int *)((intptr_t)self + 0x140) + -1;
  if (-1 < value1) {
    do {
      uptr3 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)self + 300),value1,(int *)0x0);
      Company_DeactivatePlanEntry(self,uptr3,0);
      value1 = value1 + -1;
    } while (-1 < value1);
  }
  value1 = *(int *)((intptr_t)self + 0x15c);
  value6 = 0;
  if (0 < value1) {
    do {
      pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),value6,(int *)0x0);
      if (*(int *)((intptr_t)pvVar4 + 0x14c4) != 0) {
        value5 = IDMap_FindIndexByValue(pvVar4,*(int *)((intptr_t)pvVar4 + 0x14c4));
        ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)pvVar4 + 0x1500),value5,(int *)0x0);
        Branch_RemoveStaffMember(pvVar4,ptr2,0);
      }
      value6 = value6 + 1;
    } while (value6 < value1);
  }
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4)
                                 ,(int *)0x0);
  pvVar4 = *(void **)((intptr_t)self + 0x1d8);
  if (pvVar4 != (void *)0x0) {
    Game_AcquireStateLock(DAT_0057c670,0);
    if (arg1 == 0) {
      City_PlaceObjectOnMap(this_00,pvVar4,(void *)0x0);
    }
    else {
      MapObject_SpawnByKind(this_00,pvVar4,7,-1,(void *)0x23,-1);
    }
    *(uint32_t *)((intptr_t)this_00 + *(int *)((intptr_t)self + 0x48) * 4 + 0xc20) = 0;
    *(uint32_t *)((intptr_t)self + 0x1d8) = 0;
    Window_UnlockState((intptr_t)DAT_0057c670);
  }
  if (arg1 != 0) {
    value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (*(int *)((intptr_t)self + 0x48) == value1) {
      value1 = 3;
      ptr2 = *(int **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac);
      do {
        ptr2 = ptr2 + 1;
        if (*ptr2 == 0x1c) {
          Game_CompleteMissionStage();
        }
        value1 = value1 + -1;
      } while (value1 != 0);
    }
  }
  pvVar4 = *(void **)((intptr_t)DAT_0057c670 + 0x25c);
  if (pvVar4 != (void *)0x0) {
    UI_QueueControlCommand(pvVar4,-0x18617,0x23,0);
    value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (*(int *)((intptr_t)self + 0x48) == value1) {
      UI_QueueControlCommand(pvVar4,-0x18629,0x23,0);
    }
  }
  return;
}
