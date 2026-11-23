// Object_GetPlayerValue: ported from Pizza Connection 2 at 0x50b6d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b6d0
#include "pc2_port.h"

void __thiscall Object_GetPlayerValue(void *self,int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (*(int *)((intptr_t)self + 0x30) != 0xd) {
    if (*(int *)((intptr_t)self + 0x110) == -1) {
      return;
    }
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x110));
  }
  value1 = *(int *)((intptr_t)self + 0x30);
  if (value1 != 0xd) {
    if (value1 == 0x17) {
      arg1 = *(int *)(value2 + 100);
    }
    else if (value1 == 0x1d) {
      arg1 = *(int *)(value2 + 0x6c);
    }
  }
  if (arg1 == 1) {
    if (((value1 == 0x1d) || (value1 == 0x17)) || (value1 == 0xd)) {
      Object_SetChildField2C(self,0);
    }
  }
  else if (arg1 == 2) {
    if (value1 == 0x1d) {
      Object_SetChildField2C(self,0x10);
      return;
    }
    if (value1 == 0x17) {
      Object_SetChildField2C(self,0x10);
      return;
    }
    if (value1 == 0xd) {
      Object_SetChildField2C(self,0x10);
      return;
    }
  }
  else if (arg1 == 3) {
    if (value1 == 0x1d) {
      Object_SetChildField2C(self,8);
      return;
    }
    if (value1 == 0x17) {
      Object_SetChildField2C(self,8);
      return;
    }
    if (value1 == 0xd) {
      Object_SetChildField2C(self,8);
      return;
    }
  }
  return;
}
