// Person_CancelVisitAtOccupiedBuilding: ported from Pizza Connection 2 at 0x50e310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e310
#include "pc2_port.h"

void __fastcall Person_CancelVisitAtOccupiedBuilding(void *arg1,uint32_t arg2,int arg3)

{
  int value1;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  void *pvVar2;
  
                    /* Cancels a person's visit when the target building is occupied. */
  pvVar2 = (void *)0x0;
  if ((arg3 != 0) && (value1 = *(int *)((intptr_t)arg1 + 0xf4), value1 != 0)) {
    pvVar2 = (void *)Game_GetPlayerSubmapValue
                               (DAT_0057c670,*(int *)(value1 + 8),*(int *)(value1 + 0x2c));
    arg2 = extraout_EDX;
  }
  if (*(int *)((intptr_t)arg1 + 0xa0) == 0) {
    switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
    case 10:
      Object_SetFieldA4Locked(arg1,0xffffffff);
      *(uint32_t *)((intptr_t)arg1 + 0x108) = 0xffffffff;
      if ((arg3 != 0) && (pvVar2 != (void *)0x0)) {
        *(uint8_t *)(*(int *)((intptr_t)arg1 + 0x10c) + 0x1880 + (intptr_t)pvVar2) = 0;
        Person_ReturnToHomeBase(arg1);
        return;
      }
      break;
    default:
      goto switchD_0050e39d_caseD_b;
    case 0xd:
    case 0x16:
    case 0x17:
    case 0x1d:
    case 0x1e:
    case 0x1f:
      Object_AbortOrderAndReturnHome(arg1);
      return;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      if (arg3 != 0) {
        Person_SetAtWork((intptr_t)arg1,arg2,(intptr_t)pvVar2,'\x01');
      }
      Object_SetDestinationAndTarget(arg1,3,*(int *)((intptr_t)arg1 + 0xcc));
      return;
    case 0x14:
      if (arg3 != 0) {
        if (pvVar2 != (void *)0x0) {
          Object_ClearAssignedRecord(arg1,pvVar2);
          arg2 = extraout_EDX_00;
        }
        Person_SetAtWork((intptr_t)arg1,arg2,(intptr_t)pvVar2,'\x01');
      }
      Object_SetFieldA4Locked(arg1,0xffffffff);
      Object_SetChildField2C(arg1,0);
      Object_SetDestinationAndTarget(arg1,3,*(int *)((intptr_t)arg1 + 0xcc));
      return;
    case 0x18:
    case 0x20:
      Object_SetFieldA4Locked(arg1,0xffffffff);
    }
  }
  else if (arg3 != 0) {
    Game_GetTimeByMode(arg1,0);
    *(uint32_t *)((intptr_t)arg1 + 0x4c) = 0;
    *(uint32_t *)((intptr_t)arg1 + 0x54) = 0;
    UI_SetChildState(arg1,0xffff);
    Object_SetState(arg1,2);
    Person_ReturnToHomeBase(arg1);
    return;
  }
  Person_ReturnToHomeBase(arg1);
switchD_0050e39d_caseD_b:
  return;
}
