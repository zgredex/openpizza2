// UI_SetClampedValue: ported from Pizza Connection 2 at 0x52a3a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52a3a0
#include "pc2_port.h"

void __thiscall UI_SetClampedValue(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  uint8_t local_104 [260];
  
  if (*(int *)((intptr_t)self + 0x388) != 0) {
    value1 = *(int *)((intptr_t)self + 0x9c);
    value2 = *(int *)((intptr_t)self + 0xa0);
    if (value1 < value2) {
      if (arg1 < value1) {
        arg1 = value1;
      }
      if (value2 < arg1) {
        arg1 = value2;
      }
    }
    else {
      if (value1 < arg1) {
        arg1 = value1;
      }
      if (arg1 < value2) {
        arg1 = value2;
      }
    }
  }
  *(int *)((intptr_t)self + arg2 * 4 + 0x8c) = arg1;
  if (*(int *)((intptr_t)self + 0xb8) != 0) {
    String_Format(local_104,*(uint8_t **)((intptr_t)self + 0xbc),arg1);
    (**(code **)(**(int **)((intptr_t)self + 0xb8) + 0xc))(0xe,0,local_104);
  }
  return;
}
