// Game_FindObjectByClass: ported from Pizza Connection 2 at 0x4d2aa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2aa0
#include "pc2_port.h"

int __thiscall Game_FindObjectByClass(void *self,int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x8c)) {
    do {
      value1 = Game_MapRecordToGlobal(self,value2);
      if (*(int *)(value1 + 0x30) == arg1) {
        return value1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x8c));
  }
  return 0;
}
