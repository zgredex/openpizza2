// Person_OnEnterBuilding: ported from Pizza Connection 2 at 0x50a7e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a7e0
#include "pc2_port.h"

void __fastcall Person_OnEnterBuilding(void *arg1)

{
  int value1;
  void *self;
  int value2;
  void *pvVar3;
  uint32_t unaff_EDI;
  
                    /* Handles a person entering a building by type. */
  if (*(int *)((intptr_t)arg1 + 0x30) == 0xc) {
    Object_SetChildField2C(arg1,0);
    pvVar3 = (void *)Game_GetPlayerMapValue
                               (DAT_0057c670,*(int *)(*(int *)((intptr_t)arg1 + 0xfc) + 8),
                                *(int *)(*(int *)((intptr_t)arg1 + 0xfc) + 0x2c));
    if (pvVar3 != (void *)0x0) {
      Storage_ProduceBatch(pvVar3);
    }
    Object_SetDestinationAndTarget(arg1,10,*(int *)((intptr_t)arg1 + 0xcc));
  }
  else if (*(int *)((intptr_t)arg1 + 0x30) == 0x1f) {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
    pvVar3 = *(void **)((intptr_t)arg1 + 0xfc);
    self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                                (int *)0x0);
    City_CreateExplosionEffect(self,3,0x2e,pvVar3);
    Game_AbortOrdersTargetingObject(*(int *)((intptr_t)arg1 + 0xfc),1,arg1);
    *(uint32_t *)(*(int *)((intptr_t)arg1 + 0xfc) + 0x94) = 1;
    *(uint32_t *)(*(int *)((intptr_t)arg1 + 0xfc) + 0xc) = 0x12378d6;
    Person_SetRouteToBuilding(arg1,*(int *)(value1 + 0x1d8));
    Object_SetChildField2C(arg1,0);
    value1 = *(int *)((intptr_t)pvVar3 + 8);
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (value1 == value2) {
      value1 = Game_HasKeyedRecordEntry(DAT_0057c670,7,(intptr_t)pvVar3);
      if (value1 == 0) {
        value1 = UI_Briefing_Printf((intptr_t)DAT_0057c670,5,4,-1,-1,(intptr_t)pvVar3,DAT_005828a8,DAT_00582188
                                   ,unaff_EDI);
        Game_SetMessageField34(DAT_0057c670,value1,7);
        return;
      }
    }
  }
  return;
}
