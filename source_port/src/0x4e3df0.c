// Gangster_CancelJobsTargetingPlayer: ported from Pizza Connection 2 at 0x4e3df0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3df0
#include "pc2_port.h"

void Gangster_CancelJobsTargetingPlayer(int arg1,int arg2)

{
  int value1;
  void *self;
  int value2;
  
                    /* Cancels gangster jobs that target a player, either forcing state or aborting
                       the order. */
  value2 = 0;
  value1 = Game_CountObjectsByState(DAT_0057c670,-1);
  if (0 < value1) {
    do {
      self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),value2,(int *)0x0);
      if ((*(int *)((intptr_t)self + 0x30) == 0x1d) &&
         (((*(int *)((intptr_t)self + 0xa4) == 0x19 || (*(int *)((intptr_t)self + 0xa4) == 0x1a)) &&
          (*(int *)(*(int *)((intptr_t)self + 0xfc) + 8) == arg1)))) {
        if (arg2 == 0) {
          Object_SetFieldA4Locked(self,0x1a);
        }
        else {
          Object_AbortOrderAndReturnHome(self);
          if (*(int *)((intptr_t)self + 0x74) != 0) {
            *(uint8_t *)((intptr_t)self + 0x81) = 1;
          }
        }
      }
      value2 = value2 + 1;
      value1 = Game_CountObjectsByState(DAT_0057c670,-1);
    } while (value2 < value1);
  }
  return;
}
