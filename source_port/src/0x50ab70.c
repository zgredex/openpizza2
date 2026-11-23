// Object_Deactivate: ported from Pizza Connection 2 at 0x50ab70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50ab70
#include "pc2_port.h"

void __thiscall Object_Deactivate(void *self,void *arg1)

{
  uint8_t *bptr1;
  
  if (*(char *)((intptr_t)self + 0x104) != '\0') {
    if (arg1 != (void *)0x0) {
      Game_RemoveObjectFromList(arg1,self,0);
    }
    Object_SetFlag104(self,0);
    Object_SetFieldFC(self,0);
    if (*(int *)((intptr_t)self + 200) != 0) {
      bptr1 = (uint8_t *)(*(int *)((intptr_t)self + 200) + 0x10);
      *bptr1 = *bptr1 & 0xfe;
    }
  }
  return;
}
