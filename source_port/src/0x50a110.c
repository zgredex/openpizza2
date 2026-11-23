// Waiter_ServeCustomer: ported from Pizza Connection 2 at 0x50a110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a110
#include "pc2_port.h"

void __fastcall Waiter_ServeCustomer(void *arg1)

{
  int value1;
  int value2;
  void *self;
  void *this_00;
  int value3;
  
                    /* Serves a customer and books the payment. */
  Object_SetFieldA4Locked(arg1,0xffffffff);
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x20),*(int *)((intptr_t)arg1 + 0x50),(int *)0x0);
  self = (void *)Game_GetPlayerSubmapValue
                           (DAT_0057c670,*(int *)(value2 + 0x81c),*(int *)(value2 + 0x820));
  if (self == (void *)0x0) {
    Object_SetDestinationAndTarget(arg1,3,*(int *)((intptr_t)arg1 + 0xcc));
    return;
  }
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*(int *)((intptr_t)arg1 + 0x10c),
                                 (int *)0x0);
  if ((this_00 != (void *)0x0) && (*(int *)((intptr_t)this_00 + 0x38) == 0x1a)) {
    value2 = Game_FindRecordByField10(self,*(int *)((intptr_t)arg1 + 0x10c));
    if (value2 != 0) {
      value1 = *(int *)((intptr_t)self + 0x30);
      value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (value1 == value3) {
        UI_AppendCommandIfActive(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x19,1);
        MissionGoal_HandleEvent(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x19,-1,-1);
      }
      Stats_AddRecordValue(self,0x16,*(float *)(value2 + 0x1c),-1);
      *(uint32_t *)((intptr_t)this_00 + 0x4c) = 0;
      *(uint32_t *)((intptr_t)this_00 + 0x54) = 0;
      Object_SetState(this_00,4);
      UI_SetChildState(this_00,0xffff);
    }
    if ((*(char *)((intptr_t)this_00 + 0x104) != '\0') && (*(int *)((intptr_t)this_00 + 0xfc) != 0)) {
      value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      Map_ClearObjectFlags(*(void **)((intptr_t)this_00 + 0xfc),*(void **)(value2 + 0xfa8),1);
    }
  }
  Object_SetDestinationAndTarget(arg1,1,*(int *)((intptr_t)self + 0x16f0));
  return;
}
