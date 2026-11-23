// Object_AbortOrderAndReturnHome: ported from Pizza Connection 2 at 0x50bc40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50bc40
#include "pc2_port.h"

void __fastcall Object_AbortOrderAndReturnHome(void *arg1)

{
  void *pvVar1;
  int value2;
  
                    /* Cancels an actor's order and sends it back to its owner or HQ. */
  if (((*(int *)((intptr_t)arg1 + 0xa4) == 0x19) || (*(int *)((intptr_t)arg1 + 0xa4) == 0x1a)) &&
     (value2 = *(int *)((intptr_t)arg1 + 0xf4), value2 != 0)) {
    pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value2 + 8));
    if ((pvVar1 != (void *)0x0) && (value2 != 0)) {
      Advertising_StopCampaign(pvVar1,*(int *)(value2 + 0x48),*(int *)((intptr_t)pvVar1 + 0x48),0);
    }
  }
  if (*(int *)((intptr_t)arg1 + 0x30) == 0xd) {
    pvVar1 = arg1;
  }
  else {
    if (*(int *)((intptr_t)arg1 + 0x110) == -1) {
      return;
    }
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
    pvVar1 = *(void **)(value2 + 0x1d8);
  }
  switch(*(uint32_t *)((intptr_t)arg1 + 0xa4)) {
  case 1:
  case 2:
    if (*(int *)((intptr_t)arg1 + 0x74) == 0) {
      Person_ReturnToHomeBase(arg1);
    }
    *(uint32_t *)((intptr_t)arg1 + 0x110) = 0xffffffff;
    break;
  case 3:
  case 5:
  case 7:
  case 9:
  case 0xd:
  case 0x11:
    if ((*(int *)((intptr_t)arg1 + 0x74) == 0) && (pvVar1 != (void *)0x0)) {
      Object_SetDestinationAndTarget(arg1,2,(intptr_t)pvVar1);
    }
    UI_SetChildState(arg1,0xffff);
    Object_SetFieldA4Locked(arg1,0xffffffff);
    return;
  case 0xe:
    *(uint32_t *)((intptr_t)arg1 + 0x10c) = 0xffffffff;
    if ((*(int *)((intptr_t)arg1 + 0x74) == 0) && (pvVar1 != (void *)0x0)) {
      Object_SetDestinationAndTarget(arg1,2,(intptr_t)pvVar1);
      Object_SetFieldA4Locked(arg1,0xffffffff);
      return;
    }
    break;
  case 0xf:
  case 0x1c:
    *(uint32_t *)((intptr_t)arg1 + 0xac) = 0xffffffff;
  case 6:
  case 0x10:
  case 0x12:
  case 0x19:
  case 0x1a:
  case 0x1d:
    if ((*(int *)((intptr_t)arg1 + 0x74) == 0) && (pvVar1 != (void *)0x0)) {
      Object_SetDestinationAndTarget(arg1,2,(intptr_t)pvVar1);
      Object_SetFieldA4Locked(arg1,0xffffffff);
      return;
    }
    break;
  case 0x16:
  case 0x17:
  case 0x1b:
    if ((*(int *)((intptr_t)arg1 + 0x74) == 0) && (pvVar1 != (void *)0x0)) {
      Object_SetDestinationAndTarget(arg1,3,*(int *)((intptr_t)arg1 + 0xcc));
      Object_SetFieldA4Locked(arg1,0xffffffff);
      return;
    }
  }
  Object_SetFieldA4Locked(arg1,0xffffffff);
  return;
}
