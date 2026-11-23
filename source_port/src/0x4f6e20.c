// AI_CompanySlots_Save: ported from Pizza Connection 2 at 0x4f6e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f6e20
#include "pc2_port.h"

void __thiscall AI_CompanySlots_Save(void *self,void *arg1)

{
  int value1;
  int value2;
  uint32_t local_4;
  
  local_4 = 0x168;
  CRT_Ostream_Write(arg1,&local_4,4);
  value1 = (intptr_t)self + 0x3c;
  value2 = 6;
  do {
    CRT_Ostream_Write(arg1,value1,0x168);
    value1 = value1 + 0x168;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
