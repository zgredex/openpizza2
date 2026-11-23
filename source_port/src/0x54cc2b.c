// CRT_Ostream_Write: ported from Pizza Connection 2 at 0x54cc2b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cc2b
#include "pc2_port.h"

int * __thiscall CRT_Ostream_Write(char *self,uint32_t arg1,uint32_t arg2)

{
  uint32_t *uptr1;
  int value2;
  int unaff_retaddr;
  
  value2 = Stream_BeginRead(self);
  if (value2 != 0) {
    value2 = (**(code **)(**(int **)(*(int *)(*(int *)self + 4) + 4 + (intptr_t)self) + 0x14))
                      (arg1,arg2);
    if (value2 != unaff_retaddr) {
      uptr1 = (uint32_t *)(*(int *)(*(int *)self + 4) + 8 + (intptr_t)self);
      *uptr1 = *uptr1 | 6;
    }
    CRT_Ostream_Suffix(self);
  }
  return self;
}
