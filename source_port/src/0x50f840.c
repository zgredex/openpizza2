// GamePlan_ComputeAverageEffect: ported from Pizza Connection 2 at 0x50f840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f840
#include "pc2_port.h"

int __thiscall GamePlan_ComputeAverageEffect(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value3 = 0;
  value2 = 0;
  do {
    value1 = GamePlan_ComputeCategoryEffect(self,arg1,value2);
    value3 = value3 + value1;
    value2 = value2 + 1;
  } while (value2 < 8);
  return value3 >> 3;
}
