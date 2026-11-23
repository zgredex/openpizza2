// Object_SetDestinationAndTarget: ported from Pizza Connection 2 at 0x507e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507e20
#include "pc2_port.h"

void __thiscall Object_SetDestinationAndTarget(void *self,uint32_t arg1,int arg2)

{
  int value1;
  int value2;
  
                    /* Assigns a destination and target object to a map object. */
  if (*(int *)((intptr_t)self + 0x30) != 0x2e) {
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    value1 = Array_GetRecord28(*(void **)((intptr_t)self + 0xc4),1,*(int *)(arg2 + 0x54));
    *(uint32_t *)((intptr_t)self + 0x90) = arg1;
    *(int *)((intptr_t)self + 0xf8) = value1;
    if (*(void **)((intptr_t)self + 0xfc) != (void *)0x0) {
      Object_Deactivate(self,*(void **)((intptr_t)self + 0xfc));
    }
    Object_SetFieldFC(self,arg2);
    if (*(int *)(arg2 + 4) == 0xf) {
      *(int *)((intptr_t)self + 0xf4) = arg2;
    }
    else if (*(int *)((intptr_t)self + 0xa0) == 0) {
      Person_DecideWaitOrLeaveHouse(self);
    }
    else {
      Object_SetState(self,2);
    }
    value2 = State_IsMenuState((intptr_t)self);
    if (value2 != 0) {
      Person_DecideWaitOrLeaveHouse(self);
    }
    Person_AdvanceRoute(self,value1);
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  }
  return;
}
