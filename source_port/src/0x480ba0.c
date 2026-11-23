// Game_CountRecordsWithFieldA0: ported from Pizza Connection 2 at 0x480ba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480ba0
#include "pc2_port.h"

int __fastcall Game_CountRecordsWithFieldA0(int arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  
  self = *(void **)(arg1 + 0x16f0);
  value2 = 0;
  if ((self != (void *)0x0) && (value3 = 0, 0 < *(int *)((intptr_t)self + 0x8c))) {
    do {
      value1 = Game_MapRecordToGlobal(self,value3);
      if ((value1 != 0) && (*(int *)(value1 + 0xa0) != 0)) {
        value2 = value2 + 1;
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x8c));
  }
  return value2;
}
