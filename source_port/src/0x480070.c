// Game_CountObjectsType1DSub19: ported from Pizza Connection 2 at 0x480070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480070
#include "pc2_port.h"

int __fastcall Game_CountObjectsType1DSub19(int arg1)

{
  int value1;
  void *self;
  int value2;
  int value3;
  
  value2 = 0;
  value3 = 0;
  self = *(void **)(arg1 + 0x16f0);
  if (0 < *(int *)((intptr_t)self + 0x8c)) {
    do {
      value1 = Game_MapRecordToGlobal(self,value3);
      if ((*(int *)(value1 + 0x30) == 0x1d) && (*(int *)(value1 + 0xa4) == 0x19)) {
        value2 = value2 + 1;
      }
      self = *(void **)(arg1 + 0x16f0);
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x8c));
  }
  return value2;
}
