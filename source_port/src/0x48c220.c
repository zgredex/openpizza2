// Game_AbortOrdersTargetingObject: ported from Pizza Connection 2 at 0x48c220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c220
#include "pc2_port.h"

void Game_AbortOrdersTargetingObject(int arg1,int arg2,void *arg3)

{
  int value1;
  void *pvVar2;
  int value3;
  
                    /* Aborts orders of every object targeting a removed object. */
  value3 = 0;
  value1 = Game_CountObjectsByState(DAT_0057c670,-1);
  if (0 < value1) {
    do {
      pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),value3,(int *)0x0);
      if (pvVar2 != arg3) {
        switch(*(uint32_t *)((intptr_t)pvVar2 + 0x30)) {
        case 0xd:
        case 0x16:
        case 0x17:
        case 0x1f:
          if (arg2 != 0) goto switchD_0048c26a_caseD_1d;
          break;
        case 0x1d:
        case 0x1e:
switchD_0048c26a_caseD_1d:
          Object_AbortOrderForTarget(pvVar2,arg1,arg2);
        }
      }
      value3 = value3 + 1;
      value1 = Game_CountObjectsByState(DAT_0057c670,-1);
    } while (value3 < value1);
  }
  return;
}
