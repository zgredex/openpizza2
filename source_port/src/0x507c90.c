// Person_WanderToLinkedCell: ported from Pizza Connection 2 at 0x507c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507c90
#include "pc2_port.h"

void __fastcall Person_WanderToLinkedCell(void *arg1)

{
  void *self;
  int value1;
  int value2;
  
                    /* Sends a person to a random linked cell two steps away. */
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  self = *(void **)(value1 + 0xfa8);
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  if (*(int *)((intptr_t)arg1 + 0xd0) == 0) {
    NoOp_Stub();
  }
  value1 = Array_GetRecord28(self,1,*(int *)(*(int *)((intptr_t)arg1 + 0xcc) + 0x54));
  value1 = Map_PickRandomLinkedCellInSteps(value1,2);
  if (*(int *)((intptr_t)arg1 + 200) == 0) {
    value2 = 0;
  }
  else {
    value2 = *(int *)(*(int *)((intptr_t)arg1 + 200) + 0x20);
  }
  Person_PathToTileAndStep(arg1,value2,value1);
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
