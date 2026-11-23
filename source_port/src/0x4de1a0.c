// Game_SumStatGridAll: ported from Pizza Connection 2 at 0x4de1a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de1a0
#include "pc2_port.h"

int __thiscall Game_SumStatGridAll(void *self,int arg1,int arg2,void *arg3)

{
  int value1;
  void *this_00;
  int value2;
  int value3;
  int value4;
  
  value3 = 0;
  if (arg3 != (void *)0x0) {
    value3 = Game_SumStatGrid(arg3,arg1,arg2);
    return value3;
  }
  value1 = *(int *)((intptr_t)self + 0x15c);
  value4 = 0;
  if (value1 < 1) {
    return 0;
  }
  do {
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),value4,(int *)0x0);
    value2 = Game_SumStatGrid(this_00,arg1,arg2);
    value3 = value3 + value2;
    value4 = value4 + 1;
  } while (value4 < value1);
  return value3;
}
