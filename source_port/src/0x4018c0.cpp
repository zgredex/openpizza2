// IDMap_Update: ported from Pizza Connection 2 at 0x4018c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4018c0
#include "pc2_port.h"

void __thiscall IDMap_Update(void *self,int *arg1)

{
  int value1;
  
  if ((99999 < *arg1) && (value1 = 0, 0 < *(int *)((intptr_t)self + 0xc))) {
    do {
      if (*(int *)(*(int *)((intptr_t)self + 8) + value1 * 4) == *arg1) {
        *arg1 = value1;
      }
      value1 = value1 + 1;
    } while (value1 < *(int *)((intptr_t)self + 0xc));
  }
  return;
}
