// CRT_StreamFlushChar: ported from Pizza Connection 2 at 0x54dd1c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dd1c
#include "pc2_port.h"

int __thiscall CRT_StreamFlushChar(void *self,char arg1)

{
  uint32_t *uptr1;
  int value2;
  int value3;
  
  if (*(uint32_t *)((intptr_t)self + 0x24) < *(uint32_t *)((intptr_t)self + 0x28)) {
    value2 = Stream_PutBackChar(self,arg1);
  }
  else {
    value2 = 1;
    value3 = (**(code **)(*(int *)self + 0xc))(0xffffffff,1);
    if (value3 == -1) {
      value2 = -1;
    }
    else if ((*(int *)((intptr_t)self + 8) == 0) && (*(int *)((intptr_t)self + 0x2c) != 0)) {
      uptr1 = *(uint32_t **)((intptr_t)self + 0x28);
      _memmove((uint32_t *)((intptr_t)uptr1 + 1),uptr1,(*(int *)((intptr_t)self + 0x2c) - (intptr_t)uptr1) - 1
              );
      **(uint8_t **)((intptr_t)self + 0x28) = (char)value2;
    }
  }
  return value2;
}
