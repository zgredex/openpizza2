// UI_SetChildTracking: ported from Pizza Connection 2 at 0x505e60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x505e60
#include "pc2_port.h"

void __thiscall UI_SetChildTracking(void *self,uint32_t arg1,int arg2)

{
  int value1;
  int value2;
  
  if (*(int *)((intptr_t)self + 200) != 0) {
    value1 = *(int *)(arg2 + 0x10);
    value2 = *(int *)(arg2 + 0xc);
    *(int *)(*(int *)((intptr_t)self + 200) + 0x20) = arg2;
    Record_SetDoubles48((void *)(*(int **)((intptr_t)self + 200))[0x16],**(int **)((intptr_t)self + 200),
                        value2 + -0xa0,value1 + -0xd0);
  }
  return;
}
