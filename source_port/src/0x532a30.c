// UI_AddUniquePair: ported from Pizza Connection 2 at 0x532a30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532a30
#include "pc2_port.h"

void __thiscall UI_AddUniquePair(void *self,int arg1,int arg2)

{
  int value1;
  int *ptr2;
  int value3;
  
  value3 = 0;
  value1 = *(int *)((intptr_t)self + 0x2b8);
  if (0 < value1) {
    do {
      ptr2 = (int *)Array_GetPtr((void *)((intptr_t)self + 0x2a8),value3);
      if (((ptr2 != (int *)0x0) && (*ptr2 == arg1)) && (ptr2[1] == arg2)) {
        return;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  ptr2 = operator_new(8);
  *ptr2 = arg1;
  ptr2[1] = arg2;
  Array_InsertGrow((void *)((intptr_t)self + 0x2a8),ptr2);
  return;
}
