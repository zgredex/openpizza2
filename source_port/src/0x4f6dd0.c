// AI_CompanySlots_Load: ported from Pizza Connection 2 at 0x4f6dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f6dd0
#include "pc2_port.h"

void __thiscall AI_CompanySlots_Load(void *self,void *arg1)

{
  void *this_00;
  int value1;
  uint32_t *uptr2;
  uint32_t *uptr3;
  
  this_00 = arg1;
  uptr2 = (uint32_t *)((intptr_t)self + 0x3c);
  uptr3 = uptr2;
  for (value1 = 0x21c; value1 != 0; value1 = value1 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  CRT_Istream_Read(arg1,&arg1,4);
  value1 = 6;
  do {
    CRT_Istream_Read(this_00,uptr2,arg1);
    uptr2 = uptr2 + 0x5a;
    value1 = value1 + -1;
  } while (value1 != 0);
  return;
}
