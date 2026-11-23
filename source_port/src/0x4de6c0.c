// Game_CountRecordsByField34: ported from Pizza Connection 2 at 0x4de6c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de6c0
#include "pc2_port.h"

int __thiscall Game_CountRecordsByField34(void *self,int arg1)

{
  int value1;
  int value2;
  int local_4;
  
  value2 = 0;
  local_4 = 0;
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 0x15c)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value2,(int *)0x0);
      if (*(int *)(value1 + 0x34) == arg1) {
        local_4 = local_4 + 1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x15c));
    value1 = local_4;
  }
  return value1;
}
