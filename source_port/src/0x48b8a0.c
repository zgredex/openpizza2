// Map_ScrollToClamped: ported from Pizza Connection 2 at 0x48b8a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b8a0
#include "pc2_port.h"

void __thiscall Map_ScrollToClamped(void *self,void *arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value3 = *(int *)((intptr_t)arg1 + 0x1016c) + *(int *)((intptr_t)arg1 + 0x2c);
  value4 = *(int *)((intptr_t)arg1 + 0x30) - *(int *)((intptr_t)arg1 + 0x10174);
  value2 = *(int *)((intptr_t)arg1 + 0x10170) + *(int *)((intptr_t)arg1 + 0x38) + DAT_00571954;
  value1 = (*(int *)((intptr_t)arg1 + 0x34) - *(int *)((intptr_t)arg1 + 0x10168)) + DAT_00571950;
  if (arg2 < value3) {
    arg2 = value3;
  }
  if (arg3 < value4) {
    arg3 = value4;
  }
  if (value1 <= arg2 + DAT_00571950) {
    arg2 = value1 - DAT_00571950;
  }
  if (value2 <= DAT_00571954 + arg3) {
    arg3 = value2 - DAT_00571954;
  }
  Map_SetScrollPosition(arg1,arg2,arg3);
  *(uint32_t *)((intptr_t)arg1 + 0xf4) = 1;
  value1 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
  if (arg1 == *(void **)(value1 + 0xfa8)) {
    Map_DrawMinimap(self);
  }
  return;
}
