// Person_AdvanceRoute: ported from Pizza Connection 2 at 0x507d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507d90
#include "pc2_port.h"

int __thiscall Person_AdvanceRoute(void *self,int arg1)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  int value2;
  
                    /* Advances a person's route or rebuilds the path to its target. */
  if (*(int *)((intptr_t)self + 200) == 0) {
    return 0;
  }
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  if (*(int *)((intptr_t)self + 200) == 0) {
    value2 = 0;
  }
  else {
    value2 = *(int *)(*(int *)((intptr_t)self + 200) + 0x20);
  }
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)self);
  if ((CONCAT31(extraout_var,uvalue1) == 0) || (*(short *)(*(int *)((intptr_t)self + 200) + 0x28) == -1)) {
    value2 = Person_PathToTileAndStep(self,value2,arg1);
  }
  else {
    value2 = Person_RecomputePathStep((intptr_t)self);
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return value2;
}
