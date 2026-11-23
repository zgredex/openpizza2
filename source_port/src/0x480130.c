// Game_CountGoalTargets: ported from Pizza Connection 2 at 0x480130.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480130
#include "pc2_port.h"

int __thiscall Game_CountGoalTargets(void *self,int arg1)

{
  int value1;
  int value2;
  void *this_00;
  int value3;
  int value4;
  
  this_00 = *(void **)((intptr_t)self + 0x16f0);
  value3 = 0;
  value4 = 0;
  if (*(int *)((intptr_t)this_00 + 0x8c) < 1) {
    return 0;
  }
  do {
    value2 = Game_MapRecordToGlobal(this_00,value4);
    if (arg1 == 0x16) {
      if ((((*(int *)(value2 + 0x30) == 0x1d) || (*(int *)(value2 + 0x30) == 0x1e)) &&
          (*(int *)(value2 + 0x38) != 0x38)) &&
         ((*(int *)(value2 + 0x38) != 0x39 && (*(int *)(value2 + 0x108) != 6)))) {
        value2 = *(int *)(value2 + 0xa4);
        goto joined_r0x004801d2;
      }
    }
    else if (((((arg1 == 0x17) || (arg1 == 0x1b)) &&
              ((value1 = *(int *)(value2 + 0x30), value1 == 0x1d ||
               (((value1 == 0x1e || (value1 == 0x1f)) || (value1 == 0x16)))))) &&
             ((*(int *)(value2 + 0x38) != 0x38 && (*(int *)(value2 + 0x38) != 0x39)))) &&
            (*(int *)(value2 + 0x108) != 6)) {
      value2 = *(int *)(value2 + 0xa4);
joined_r0x004801d2:
      if ((value2 != 0x19) && (value2 != 0x1a)) {
        value3 = value3 + 1;
      }
    }
    this_00 = *(void **)((intptr_t)self + 0x16f0);
    value4 = value4 + 1;
    if (*(int *)((intptr_t)this_00 + 0x8c) <= value4) {
      return value3;
    }
  } while( true );
}
