// Car_PickRandomRoadStep: ported from Pizza Connection 2 at 0x4d35e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d35e0
#include "pc2_port.h"

void __fastcall Car_PickRandomRoadStep(void *arg1)

{
  int value1;
  int value2;
  
                    /* Gives an idle car a random road destination. */
  value1 = *(int *)(*(int *)((intptr_t)arg1 + 8) + 0x20);
  value2 = Array_GetRandomRecord28B(*(void **)((intptr_t)arg1 + 4),(int *)0x0);
  Car_DriveToPoint(arg1,value1,value2);
  return;
}
