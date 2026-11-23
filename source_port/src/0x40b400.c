// Person_UpdateBehavior: ported from Pizza Connection 2 at 0x40b400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x40b400
#include "pc2_port.h"

void __thiscall Person_UpdateBehavior(void *self,void *arg1)

{
  int value1;
  uint8_t uvalue2;
  uint32_t extraout_var;
  uint32_t *uptr3;
  void *pvVar4;
  int value5;
  uint32_t extraout_EDX;
  uint32_t uvalue6;
  uint32_t extraout_EDX_00;
  uint32_t extraout_EDX_01;
  void *pvVar7;
  uint32_t uvalue8;
  int value9;
  
                    /* Dispatches a person's per-frame behavior by type and state. */
  uvalue2 = Object_IsVisibleThisFrame((intptr_t)arg1);
  value9 = *(int *)((intptr_t)arg1 + 0x90);
  value1 = *(int *)((intptr_t)arg1 + 0x78);
  Person_DebugPrintLocation((intptr_t)arg1);
  value5 = *(int *)((intptr_t)arg1 + 0x30);
  if (value5 != 0x2e) {
    if (CONCAT31(extraout_var,uvalue2) != 0) goto LAB_0040b821;
    uvalue6 = extraout_EDX;
    if (value5 - 0xcU < 0x17) {
      uvalue6 = (uint32_t)*(uint8_t *)((intptr_t)&PTR_caseD_1e_0040b8a4 + value5);
      switch(value5) {
      case 0xc:
        if ((*(int *)((intptr_t)arg1 + 0x38) == 0x34) &&
           (value5 = *(int *)((intptr_t)arg1 + 0x98) + -1, *(int *)((intptr_t)arg1 + 0x98) = value5,
           value5 == 0)) {
          value5 = *(int *)((intptr_t)arg1 + 0x100);
          uvalue8 = 9;
LAB_0040b67d:
          Object_SetDestinationAndTarget(arg1,uvalue8,value5);
          *(uint32_t *)((intptr_t)arg1 + 0x98) = 0xffffffff;
          uvalue6 = extraout_EDX_01;
        }
        break;
      case 0xd:
        value5 = *(int *)((intptr_t)arg1 + 0x38);
        if (value5 != 0x18) goto LAB_0040b61c;
        value5 = *(int *)((intptr_t)arg1 + 0x98) + -1;
        *(int *)((intptr_t)arg1 + 0x98) = value5;
        if (value5 == 0) {
          value5 = *(int *)((intptr_t)arg1 + 0x100);
          uvalue8 = 0xb;
          goto LAB_0040b67d;
        }
        break;
      case 0x17:
      case 0x1d:
        value5 = *(int *)((intptr_t)arg1 + 0x38);
        if (value5 != 0x3a) goto LAB_0040b61c;
LAB_0040b621:
        Person_UpdateFightAction(arg1);
        uvalue6 = extraout_EDX_00;
        break;
      case 0x1e:
        value5 = *(int *)((intptr_t)arg1 + 0x38);
LAB_0040b61c:
        if (value5 == 0x3b) goto LAB_0040b621;
        break;
      case 0x22:
        if (*(int *)((intptr_t)arg1 + 0x38) == 8) {
          value9 = *(int *)((intptr_t)arg1 + 0x88);
          *(uint32_t *)((intptr_t)arg1 + 0x98) = 3;
          Object_SetState(arg1,0x35);
          UI_SetChildRecordVariant(arg1,value9 + 0x10);
          return;
        }
      }
    }
    if (value1 != 0) {
      Object_RebuildVisualAtDestination(arg1,0,*(int *)((intptr_t)arg1 + 0x78));
      return;
    }
    if (value9 != 0) {
      if (*(int *)((intptr_t)arg1 + 200) == 0) {
        value9 = 0;
      }
      else {
        value9 = *(int *)(*(int *)((intptr_t)arg1 + 200) + 0x20);
      }
      if (*(int *)((intptr_t)arg1 + 0xf8) == value9) {
        uvalue8 = *(uint32_t *)((intptr_t)arg1 + 0x90);
        *(uint32_t *)((intptr_t)arg1 + 0x90) = 0;
        switch(uvalue8) {
        case 1:
          goto switchD_0040b707_caseD_1;
        case 2:
          Object_ActionSpawnBranch(arg1,uvalue6);
          return;
        case 3:
          Person_OnArriveAtDestination(arg1);
          return;
        case 4:
          Waiter_LoadOrderFromKitchen(arg1);
          return;
        default:
          if (*(int *)((intptr_t)arg1 + 0xfc) == 0) {
            Debug_WarningMessageBox();
          }
          Object_Activate(arg1,*(void **)((intptr_t)arg1 + 0xfc));
          return;
        case 8:
          Waiter_ServeCustomer(arg1);
          return;
        case 9:
          Person_OnEnterBuilding(arg1);
          return;
        case 10:
          Object_SetWorkState(arg1);
          return;
        case 0xb:
          if (*(int *)(*(int *)((intptr_t)arg1 + 0xfc) + 4) != 0xf) {
            return;
          }
switchD_0040b707_caseD_1:
          Object_ActionActivate(arg1,uvalue6);
          return;
        case 0xc:
          Object_ActionRemove(arg1);
          return;
        }
      }
    }
    value9 = *(int *)((intptr_t)arg1 + 0x38);
    if (value9 == 2) {
      Object_Activate(arg1,*(void **)((intptr_t)arg1 + 0xfc));
      Person_DecideWaitOrLeaveHouse(arg1);
    }
    else if (value9 == 3) {
      Person_WanderToRandomTile(arg1);
    }
    else if (value9 == 0x1d) {
      if (*(int *)((intptr_t)arg1 + 0xfc) == 0) {
        Debug_WarningMessageBox();
      }
      Object_Deactivate(arg1,*(void **)((intptr_t)arg1 + 0xfc));
      Object_SetState(arg1,3);
    }
LAB_0040b821:
    if ((CONCAT31(extraout_var,uvalue2) != 0) && (*(int *)((intptr_t)arg1 + 0x30) == 0x22)) {
      if (*(int *)((intptr_t)arg1 + 0x38) == 8) {
        if (*(int *)((intptr_t)arg1 + 200) == 0) {
          *(uint32_t *)((intptr_t)arg1 + 0x88) = 0xffffffff;
          return;
        }
        *(uint32_t *)((intptr_t)arg1 + 0x88) = *(uint32_t *)(*(int *)((intptr_t)arg1 + 200) + 0xc);
        return;
      }
      if ((*(int *)((intptr_t)arg1 + 0x38) == 0x35) &&
         (value9 = *(int *)((intptr_t)arg1 + 0x98) + -1, *(int *)((intptr_t)arg1 + 0x98) = value9,
         value9 == 0)) {
        UI_DetachChildRecord((intptr_t)arg1);
        Person_WanderToLinkedCell(arg1);
        Object_SetState(arg1,8);
      }
    }
    return;
  }
  if (0 < *(int *)((intptr_t)arg1 + 0x98)) {
    *(int *)((intptr_t)arg1 + 0x98) = *(int *)((intptr_t)arg1 + 0x98) + -1;
  }
  if (*(int *)((intptr_t)arg1 + 0x38) == 0x18) {
    if (*(int *)((intptr_t)arg1 + 0x98) == 0) {
      UI_SetChildRecordVariant(arg1,0);
      Sound_PlayEffectByIndex(DAT_0057ba0c,0x1b);
      *(uint32_t *)((intptr_t)arg1 + 0x98) = 6;
      Object_SetState(arg1,0x3c);
      return;
    }
    return;
  }
  if (*(int *)((intptr_t)arg1 + 0x38) != 0x3c) {
    return;
  }
  if (*(int *)((intptr_t)arg1 + 0x98) != 4) goto LAB_0040b570;
  value9 = *(int *)((intptr_t)arg1 + 0x8c);
  if (value9 == 1) {
    pvVar7 = *(void **)((intptr_t)arg1 + 0xcc);
    pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
    MapObject_SpawnByKind(pvVar4,pvVar7,7,-1,(void *)0x23,-1);
    *(uint32_t *)((intptr_t)pvVar7 + 0x50) = 1;
    *(uint32_t *)((intptr_t)pvVar7 + 0x4c) = 0;
LAB_0040b55d:
    *(uint32_t *)((intptr_t)pvVar7 + 0xc) = 0xffffffff;
  }
  else {
    if (value9 == 2) {
      pvVar7 = *(void **)((intptr_t)arg1 + 0xcc);
      value9 = 1;
      pvVar4 = (void *)Game_GetPlayerBySlot(self,*(int *)((intptr_t)pvVar7 + 8));
      Company_Dissolve(pvVar4,value9);
      if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
        UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x18629,0x23,0);
      }
      goto LAB_0040b55d;
    }
    if (value9 == 3) {
      pvVar7 = *(void **)((intptr_t)arg1 + 0xcc);
      uptr3 = (uint32_t *)
               Game_GetPlayerMapValue(self,*(int *)((intptr_t)pvVar7 + 8),*(int *)((intptr_t)pvVar7 + 0x2c));
      if (uptr3 != (uint32_t *)0x0) {
        Game_CompleteObjectTransfer(self,uptr3);
      }
      pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
      MapObject_SpawnByKind(pvVar4,pvVar7,7,-1,(void *)0x23,-1);
      *(uint32_t *)((intptr_t)pvVar7 + 0x50) = 1;
      *(uint32_t *)((intptr_t)pvVar7 + 0x4c) = 0;
      if (*(void **)((intptr_t)self + 0x264) != (void *)0x0) {
        UI_QueueControlCommand(*(void **)((intptr_t)self + 0x264),-0x18613,0x23,0);
      }
      goto LAB_0040b55d;
    }
  }
  *(uint32_t *)(*(int *)((intptr_t)arg1 + 0xcc) + 0x94) = 0;
LAB_0040b570:
  if (0 < *(int *)((intptr_t)arg1 + 0x98)) {
    return;
  }
  if (*(int *)((intptr_t)arg1 + 0x38) == 0x2e) {
    return;
  }
  Object_SetState(arg1,0x2e);
  *(uint32_t *)((intptr_t)self + 0x368) = 1;
  Object_SetFlag104(arg1,1);
  return;
}
