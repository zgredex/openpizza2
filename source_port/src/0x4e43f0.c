// BuildingValue_Save: ported from Pizza Connection 2 at 0x4e43f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e43f0
#include "pc2_port.h"

void __thiscall BuildingValue_Save(void *self,void *arg1)

{
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10,8);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x18,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1c,1);
  return;
}
