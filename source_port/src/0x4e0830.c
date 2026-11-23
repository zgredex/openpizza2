// Player_CountObjectsByType: ported from Pizza Connection 2 at 0x4e0830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0830
#include "pc2_port.h"

int __thiscall Player_CountObjectsByType(void *self,uint32_t arg1)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  
  value2 = 0;
  value3 = 0;
  if (*(int *)((intptr_t)self + 0x15c) < 1) {
    return 0;
  }
  do {
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),value3,(int *)0x0);
    value1 = Game_CountObjectsByType(this_00,arg1);
    value2 = value2 + value1;
    value3 = value3 + 1;
  } while (value3 < *(int *)((intptr_t)self + 0x15c));
  return value2;
}
