// Customer_ApproachBranchEntrance: ported from Pizza Connection 2 at 0x409bb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x409bb0
#include "pc2_port.h"

uint32_t Customer_ApproachBranchEntrance(void *arg1,void *arg2)

{
  void *self;
  int value1;
  int *ptr2;
  
                    /* Moves a customer to a branch entrance cell. */
  self = *(void **)((intptr_t)arg2 + 0xc4);
  if (*(int *)((intptr_t)arg2 + 0x128) < *(int *)((intptr_t)arg2 + 0x98)) {
    value1 = AdCampaign_GoToNearestOwnBuilding(arg1,arg2);
    if (value1 != 0) {
      return 1;
    }
  }
  UI_DetachChildRecord((intptr_t)arg2);
  ptr2 = Map_LinkNeighbors(self,arg1);
  value1 = Array_GetRecord28(self,1,(intptr_t)*(short *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 +
                                                           *ptr2 * 0xc) + 0x24));
  if (value1 == 0) {
    NoOp_Stub();
    return 0;
  }
  *(int *)((intptr_t)arg2 + 0x88) = *ptr2;
  Object_SetState(arg2,8);
  Person_AdvanceRoute(arg2,value1);
  return 0;
}
