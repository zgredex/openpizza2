// Object_Activate: ported from Pizza Connection 2 at 0x50ab30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50ab30
#include "pc2_port.h"

void __thiscall Object_Activate(void *self,void *arg1)

{
  uint8_t *bptr1;
  
  if (*(char *)((intptr_t)self + 0x104) == '\0') {
    Object_SetFlag104(self,1);
    if (arg1 != (void *)0x0) {
      Game_AddObjectToList(arg1,self);
    }
    if (*(int *)((intptr_t)self + 0xc4) != 0) {
      bptr1 = (uint8_t *)(*(int *)((intptr_t)self + 200) + 0x10);
      *bptr1 = *bptr1 | 1;
    }
  }
  return;
}
