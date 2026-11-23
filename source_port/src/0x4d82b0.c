// Game_PickBestScoredRecord: ported from Pizza Connection 2 at 0x4d82b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d82b0
#include "pc2_port.h"

void * Game_PickBestScoredRecord(int arg1,void *arg2)

{
  void *self;
  void *pvVar1;
  int value2;
  int value3;
  int value4;
  
  self = arg2;
  value3 = 0;
  value4 = -10000;
  if (*(int *)((intptr_t)arg2 + 0x14) < 1) {
    return arg2;
  }
  do {
    pvVar1 = (void *)IDMap_Lookup(self,value3,(int *)0x0);
    value2 = Game_GetPlayerSubmapValue
                      (DAT_0057c670,*(int *)((intptr_t)pvVar1 + 8),*(int *)((intptr_t)pvVar1 + 0x2c));
    value2 = *(int *)(arg1 + 0x5c + *(int *)(value2 + 0x30) * 4);
    if (value4 <= value2) {
      value4 = value2;
      arg2 = pvVar1;
    }
    value3 = value3 + 1;
  } while (value3 < *(int *)((intptr_t)self + 0x14));
  return arg2;
}
