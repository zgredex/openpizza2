// AI_GetMaxPlanSteps: ported from Pizza Connection 2 at 0x4e2c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2c40
#include "pc2_port.h"

int __thiscall AI_GetMaxPlanSteps(void *self,int arg1)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  
  value3 = 0;
  value2 = 0;
  if (*(int *)((intptr_t)self + 0x124) < 1) {
    return 0;
  }
  do {
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x110),value2,(int *)0x0);
    value1 = AI_CountPlanSteps(this_00,arg1,0,-1);
    if (value3 < value1) {
      value3 = value1;
    }
    value2 = value2 + 1;
  } while (value2 < *(int *)((intptr_t)self + 0x124));
  return value3;
}
