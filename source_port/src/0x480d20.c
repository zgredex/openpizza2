// Game_HasBuildingWithSameType: ported from Pizza Connection 2 at 0x480d20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480d20
#include "pc2_port.h"

uint32_t __thiscall Game_HasBuildingWithSameType(void *self,int arg1,int arg2)

{
  void *this_00;
  int value1;
  int value2;
  
  this_00 = *(void **)((intptr_t)self + 0x16f0);
  value2 = 0;
  if (0 < *(int *)((intptr_t)this_00 + 0x8c)) {
    do {
      value1 = Game_MapRecordToGlobal(this_00,value2);
      if ((value1 != arg2) && (*(int *)(value1 + 0x8c) == *(int *)(arg1 + 0x20))) {
        return 1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)this_00 + 0x8c));
  }
  return 0;
}
