// Record_GetScreenSortY: ported from Pizza Connection 2 at 0x4ef0c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ef0c0
#include "pc2_port.h"

int * __thiscall Record_GetScreenSortY(void *self,int *arg1)

{
  int *ptr1;
  void *local_4;
  
  ptr1 = arg1;
  local_4 = self;
  Record_GetTwoFloats48((void *)arg1[0x16],*arg1,&local_4,&arg1);
  if (ptr1[1] == -1) {
    return arg1 + 0x34;
  }
  return (int *)((intptr_t)arg1 + *(int *)((intptr_t)self + 0xfc));
}
