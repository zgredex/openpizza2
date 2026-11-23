// CRT_Istream_Read: ported from Pizza Connection 2 at 0x54cbc1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cbc1
#include "pc2_port.h"

int * __thiscall CRT_Istream_Read(char *self,uint32_t arg1,uint32_t arg2)

{
  uint32_t *uptr1;
  int value2;
  uint32_t uvalue3;
  uint32_t unaff_retaddr;
  
  value2 = CRT_Istream_Prefix(self,1);
  if (value2 != 0) {
    uvalue3 = (**(code **)(**(int **)(*(int *)(*(int *)self + 4) + 4 + (intptr_t)self) + 0x18))
                      (arg1,arg2);
    *(uint32_t *)((intptr_t)self + 8) = uvalue3;
    if (uvalue3 < unaff_retaddr) {
      uptr1 = (uint32_t *)(*(int *)(*(int *)self + 4) + 8 + (intptr_t)self);
      *uptr1 = *uptr1 | 3;
    }
    CRT_LeaveNestedLocks(self);
  }
  return self;
}
