// AdCampaign_GoToNextQueuedBuilding: ported from Pizza Connection 2 at 0x409c60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x409c60
#include "pc2_port.h"

int __thiscall AdCampaign_GoToNextQueuedBuilding(void *self,int arg1,void *arg2)

{
  void *this_00;
  int value1;
  
                    /* Sends an ad campaign to its next queued building. */
  if (*(int *)((intptr_t)arg2 + 0x128) < 1) {
    return 0;
  }
  this_00 = *(void **)((intptr_t)arg2 + 0xc4);
  do {
    value1 = IDMap_Lookup((void *)((intptr_t)arg2 + 0x114),0,(int *)0x0);
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value1,(int *)0x0);
    if ((*(int *)(value1 + 0x38) == 0xb) && (*(int *)(value1 + 0xf4) == *(int *)(arg1 + 0x16f0))) {
      Object_SetState(arg2,0xf);
      UI_DetachChildRecord((intptr_t)arg2);
      *(uint32_t *)((intptr_t)arg2 + 0x10c) = *(uint32_t *)(value1 + 0x164);
      Object_SetChildField2C(arg2,0);
      value1 = Array_GetRecord28(this_00,1,
                                (intptr_t)*(short *)(*(int *)(*(int *)((intptr_t)this_00 + 0x4c) + 8 +
                                                        *(int *)(value1 + 0x8c) * 0xc) + 0x24));
      Person_AdvanceRoute(arg2,value1);
      value1 = 1;
    }
    else {
      value1 = 0;
    }
    IDMap_RemoveRecursive((void *)((intptr_t)arg2 + 0x114),0);
  } while ((value1 == 0) && (0 < *(int *)((intptr_t)arg2 + 0x128)));
  return value1;
}
