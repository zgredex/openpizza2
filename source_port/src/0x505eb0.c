// Object_PlaceSpriteAtCenter: ported from Pizza Connection 2 at 0x505eb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x505eb0
#include "pc2_port.h"

void __thiscall Object_PlaceSpriteAtCenter(void *self,uint32_t arg1,int arg2,int arg3)

{
  int *ptr1;
  
  ptr1 = *(int **)((intptr_t)self + 200);
  if (ptr1 != (int *)0x0) {
    Record_SetDoubles48((void *)ptr1[0x16],*ptr1,arg2 + -0xa0,arg3 + -0xd0);
  }
  return;
}
