// Branch_ExpelCustomers: ported from Pizza Connection 2 at 0x4d5580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5580
#include "pc2_port.h"

void Branch_ExpelCustomers(int arg1)

{
  int value1;
  void *self;
  int value2;
  
                    /* Makes a branch's customers leave. */
  CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x240));
  value2 = 0;
  value1 = Game_CountObjectsByState(DAT_0057c670,-1);
  if (0 < value1) {
    do {
      self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),value2,(int *)0x0);
      if (((*(int *)((intptr_t)self + 0x30) == 0x22) && (*(int *)((intptr_t)self + 0x108) != 0xb)) &&
         (*(int *)((intptr_t)self + 0xcc) == *(int *)(arg1 + 0x16f0))) {
        value1 = Person_CanContinuePath((intptr_t)self);
        if (value1 == 0) {
          UI_DetachChildRecord((intptr_t)self);
        }
        Object_SetDestinationAndTarget(self,3,*(int *)((intptr_t)self + 0xcc));
        Object_SetState(self,4);
        *(uint32_t *)((intptr_t)self + 0x108) = 0xb;
        CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
        return;
      }
      value2 = value2 + 1;
      value1 = Game_CountObjectsByState(DAT_0057c670,-1);
    } while (value2 < value1);
  }
  CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
  return;
}
