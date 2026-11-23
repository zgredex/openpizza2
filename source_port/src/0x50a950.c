// Person_OnArriveAtDestination: ported from Pizza Connection 2 at 0x50a950.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a950
#include "pc2_port.h"

void __fastcall Person_OnArriveAtDestination(void *arg1)

{
  int value1;
  void *pvVar2;
  int value3;
  
                    /* Handles a person arriving at its movement destination. */
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  case 0xd:
    pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value1 = *(int *)((intptr_t)arg1 + 0x58);
    value3 = *(int *)((intptr_t)pvVar2 + value1 * 0x18 + 0x10e0) + 1;
    *(int *)((intptr_t)pvVar2 + value1 * 0x18 + 0x10e0) = value3;
    if (*(int *)((intptr_t)pvVar2 + value1 * 0x18 + 0x10dc) + value3 ==
        *(int *)((intptr_t)pvVar2 + value1 * 0x18 + 0x10d8)) {
      City_ResetPoliceDistrictSlot(pvVar2,2,*(int *)((intptr_t)arg1 + 0x58));
    }
  case 0x22:
    Object_SetState(arg1,0x2e);
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x368) = 1;
    break;
  case 0x16:
  case 0x1e:
  case 0x1f:
    if ((*(int *)(*(int *)((intptr_t)arg1 + 0xcc) + 4) == 0x11) &&
       (*(int *)((intptr_t)arg1 + 0x108) == 6)) {
      value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      *(int *)(value1 + 0x10b0) = *(int *)(value1 + 0x10b0) + 1;
      UI_ShiftChildRect((intptr_t)arg1);
      pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
      if (pvVar2 != (void *)0x0) {
        Company_RemoveStaffMember(pvVar2,*(int *)((intptr_t)arg1 + 0x164));
        *(uint32_t *)((intptr_t)arg1 + 0x110) = 0xffffffff;
      }
      *(uint32_t *)((intptr_t)arg1 + 0x108) = 0xffffffff;
      Object_InitCompanyBuildingGraphics(arg1,-1);
      pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                    *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
      pvVar2 = (void *)Map_GetRandomBuildingOfType(pvVar2,0x17,0,'\0');
      value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      value1 = Array_GetRecord28(*(void **)(value1 + 0xfa8),1,*(int *)((intptr_t)pvVar2 + 0x54));
      UI_SetChildTracking(arg1,0,value1);
      Object_SetChildField2C(arg1,0);
      Person_DecideWaitOrLeaveHouse(arg1);
      UI_DetachChildRecord((intptr_t)arg1);
      Object_Activate(arg1,pvVar2);
      return;
    }
  }
  Object_Activate(arg1,*(void **)((intptr_t)arg1 + 0xfc));
  return;
}
