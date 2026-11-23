// UI_SetActiveChild: ported from Pizza Connection 2 at 0x528200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528200
#include "pc2_port.h"

void __thiscall UI_SetActiveChild(void *self,int *arg1)

{
  int *ptr1;
  
  ptr1 = *(int **)((intptr_t)self + 0x230);
  if (arg1 != ptr1) {
    if (ptr1 != (int *)0x0) {
      (**(code **)(*ptr1 + 0xc))(10,0,0);
    }
    *(int **)((intptr_t)self + 0x230) = arg1;
  }
  return;
}
