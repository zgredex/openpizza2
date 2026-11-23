// UI_DecrementRowCounter: ported from Pizza Connection 2 at 0x5277d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5277d0
#include "pc2_port.h"

void __thiscall UI_DecrementRowCounter(void *self,uint8_t *arg1)

{
  int value1;
  
  value1 = StringList_Find(self,arg1,(int *)&arg1);
  if (value1 != 0) {
    *(int *)(*(int *)((intptr_t)self + 0x82f8) + 0x44 + (intptr_t)arg1 * 0x48) =
         *(int *)(*(int *)((intptr_t)self + 0x82f8) + 0x44 + (intptr_t)arg1 * 0x48) + -1;
  }
  return;
}
