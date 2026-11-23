// UI_SetChildrenField14: ported from Pizza Connection 2 at 0x481d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x481d30
#include "pc2_port.h"

void __thiscall UI_SetChildrenField14(void *self,uint32_t arg1)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  void *local_4;
  
  local_4 = self;
  this_00 = (void *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac),(int *)0x0);
  if (this_00 != (void *)0x0) {
    value1 = Get_FieldF0((intptr_t)this_00);
    value3 = 0;
    if (0 < value1) {
      do {
        value2 = Array_GetPair8(this_00,value3,&local_4);
        if (local_4 != (void *)0x1869f) {
          *(uint32_t *)(value2 + 0x14) = arg1;
        }
        value3 = value3 + 1;
      } while (value3 < value1);
    }
  }
  return;
}
