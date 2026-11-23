// Person_ChooseWanderTarget: ported from Pizza Connection 2 at 0x50e600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e600
#include "pc2_port.h"

void __thiscall Person_ChooseWanderTarget(void *self,void *arg1)

{
  int value1;
  uint8_t unaff_SI;
  uint32_t unaff_EDI;
  
                    /* Chooses a person's next wander target. */
  value1 = Game_CountGoalTargets(arg1,*(int *)((intptr_t)self + 0xa4));
  if (value1 == 0) {
    value1 = Branch_PickRandomActiveCounter((intptr_t)arg1);
    *(int *)((intptr_t)self + 0x8c) = value1;
    value1 = RecordMap_Lookup1998(arg1,value1);
    value1 = AI_StepToNeighborCell(arg1,value1);
    if (value1 == 0) {
      Object_AbortOrderAndReturnHome(self);
      Object_SetState(self,6);
      return;
    }
    value1 = Person_AdvanceRoute(self,value1);
    if (value1 == 0) {
      Object_SetState(self,6);
      return;
    }
  }
  else {
    value1 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
    if (value1 == 0) {
      Object_AbortOrderAndReturnHome(self);
      Object_SetState(self,6);
      return;
    }
    Person_AdvanceRoute(self,value1);
  }
  Object_SetState(self,8);
  return;
}
