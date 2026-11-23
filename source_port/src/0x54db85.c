// File_WriteBytes: ported from Pizza Connection 2 at 0x54db85.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54db85
#include "pc2_port.h"

int __thiscall File_WriteBytes(void *self,uint8_t *arg1,int arg2)

{
  int value1;
  int local_8;
  
  local_8 = 0;
  if (arg2 != 0) {
    do {
      arg2 = arg2 + -1;
      if ((*(int *)((intptr_t)self + 8) == 0) &&
         (*(uint8_t **)((intptr_t)self + 0x1c) < *(uint8_t **)((intptr_t)self + 0x20))) {
        **(uint8_t **)((intptr_t)self + 0x1c) = *arg1;
        *(int *)((intptr_t)self + 0x1c) = *(int *)((intptr_t)self + 0x1c) + 1;
      }
      else {
        value1 = (**(code **)(*(int *)self + 0x1c))(*arg1);
        if (value1 == -1) {
          return local_8;
        }
      }
      arg1 = arg1 + 1;
      local_8 = local_8 + 1;
    } while (arg2 != 0);
  }
  return local_8;
}
