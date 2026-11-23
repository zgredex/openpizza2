// AI_WanderToRandomRoadTile: ported from Pizza Connection 2 at 0x50d790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d790
#include "pc2_port.h"

void __fastcall AI_WanderToRandomRoadTile(void *arg1)

{
  int value1;
  uint32_t uvalue2;
  uint32_t unaff_ESI;
  uint8_t unaff_retaddr;
  
                    /* Gives an idle object a random road wander target. */
  if (*(int *)((intptr_t)arg1 + 200) != 0) {
    value1 = AI_ComputePath(0,0,0,unaff_ESI,unaff_retaddr);
    Person_AdvanceRoute(arg1,value1);
    uvalue2 = Random_RangeFast(5,0xc);
    value1 = Array_GetPtr4((void *)(*(int *)((intptr_t)arg1 + 200) + 0x14),uvalue2);
    if (value1 != 0) {
      Person_AdvanceRoute(arg1,value1);
    }
    *(uint32_t *)((intptr_t)arg1 + 0x108) = 5;
  }
  return;
}
