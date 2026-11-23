// Game_CountAvailableBusinessBuildings: ported from Pizza Connection 2 at 0x4800d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4800d0
#include "pc2_port.h"

int __fastcall Game_CountAvailableBusinessBuildings(int arg1)

{
  int value1;
  int value2;
  void *self;
  int value3;
  int value4;
  
  value3 = 0;
  value4 = 0;
  self = *(void **)(arg1 + 0x16f0);
  if (0 < *(int *)((intptr_t)self + 0x8c)) {
    do {
      value2 = Game_MapRecordToGlobal(self,value4);
      if (((((*(int *)(value2 + 0x30) == 0x1d) && (value1 = *(int *)(value2 + 0xa4), value1 != 0xe)) &&
           (value1 != 0x19)) && (value1 != 0x1a)) || (*(int *)(value2 + 0x30) == 0x1e)) {
        value3 = value3 + 1;
      }
      self = *(void **)(arg1 + 0x16f0);
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0x8c));
  }
  return value3;
}
