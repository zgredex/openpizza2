// Game_FindMapRecordByTypeE: ported from Pizza Connection 2 at 0x477360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477360
#include "pc2_port.h"

int __fastcall Game_FindMapRecordByTypeE(int arg1)

{
  int value1;
  void *self;
  int value2;
  
  value2 = 0;
  self = *(void **)(arg1 + 0x16f0);
  if (0 < *(int *)((intptr_t)self + 0x8c)) {
    do {
      value1 = Game_MapRecordToGlobal(self,value2);
      if (*(int *)(value1 + 0x30) == 0xe) {
        return value1;
      }
      self = *(void **)(arg1 + 0x16f0);
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x8c));
  }
  return 0;
}
