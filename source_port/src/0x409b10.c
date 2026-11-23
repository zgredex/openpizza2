// AdCampaign_GoToNearestOwnBuilding: ported from Pizza Connection 2 at 0x409b10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x409b10
#include "pc2_port.h"

uint32_t AdCampaign_GoToNearestOwnBuilding(void *arg1,void *arg2)

{
  void *self;
  void *this_00;
  int value1;
  
                    /* Sends an ad campaign to the nearest owned building. */
  self = *(void **)((intptr_t)arg2 + 0xc4);
  this_00 = Map_FindNearestCompanyBuilding(arg1,(intptr_t)arg2);
  if ((this_00 == (void *)0x0) || (*(int *)((intptr_t)this_00 + 0xc4) != *(int *)((intptr_t)arg2 + 0xc4)))
  {
    return 0;
  }
  Object_SetState(this_00,0xb);
  Object_SetState(arg2,0xc);
  UI_DetachChildRecord((intptr_t)arg2);
  *(uint32_t *)((intptr_t)arg2 + 0x10c) = *(uint32_t *)((intptr_t)this_00 + 0x164);
  Object_SetChildField2C(arg2,0x10);
  value1 = Array_GetRecord28(self,1,(intptr_t)*(short *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 +
                                                           *(int *)((intptr_t)this_00 + 0x8c) * 0xc) +
                                                  0x24));
  Person_AdvanceRoute(arg2,value1);
  return 1;
}
