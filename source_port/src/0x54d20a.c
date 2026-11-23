// CRT_FileBufClose: ported from Pizza Connection 2 at 0x54d20a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d20a
#include "pc2_port.h"

int * __thiscall CRT_FileBufClose(void *self,uint32_t arg1)

{
  int value1;
  
  value1 = *(int *)(*(int *)(*(int *)self + 4) + 4 + (intptr_t)self);
  if (*(int *)(value1 + 0x30) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)(value1 + 0x34));
  }
  value1 = (**(code **)(**(int **)(*(int *)(*(int *)self + 4) + 4 + (intptr_t)self) + 0x10))(arg1,2);
  if (value1 == -1) {
    Thread_SetField8Locked
              ((void *)(*(int *)(*(int *)self + 4) + (intptr_t)self),
               *(uint32_t *)(*(int *)(*(int *)self + 4) + 8 + (intptr_t)self) | 2);
  }
  value1 = *(int *)(*(int *)(*(int *)self + 4) + 4 + (intptr_t)self);
  if (*(int *)(value1 + 0x30) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)(value1 + 0x34));
  }
  return self;
}
