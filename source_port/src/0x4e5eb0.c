// ConstructionOrder_Load: ported from Pizza Connection 2 at 0x4e5eb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e5eb0
#include "pc2_port.h"

void __thiscall ConstructionOrder_Load(void *self,void *arg1)

{
  int *ptr1;
  
  CRT_Istream_Read(arg1,(intptr_t)self + 4,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 8,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xc,4);
  ptr1 = (int *)((intptr_t)self + 0x10);
  CRT_Istream_Read(arg1,ptr1,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x14,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x18,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x1c,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x20,4);
  if (*ptr1 < 3) {
    *ptr1 = 0;
  }
  return;
}
