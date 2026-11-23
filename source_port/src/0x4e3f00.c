// Game_ComputeAverageSkill: ported from Pizza Connection 2 at 0x4e3f00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3f00
#include "pc2_port.h"

int __thiscall Game_ComputeAverageSkill(void *self,int arg1)

{
  int value1;
  void *this_00;
  int value2;
  int value3;
  int value4;
  
  value1 = *(int *)((intptr_t)self + 0x124);
  value3 = 0;
  value4 = 0;
  if (0 < value1) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x110),value4,(int *)0x0);
      value2 = Index_Map8To5(this_00,arg1);
      value3 = value3 + value2;
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  if (value1 == 0) {
    return 0;
  }
  return value3 / value1;
}
