// Character_Save: ported from Pizza Connection 2 at 0x4d3ba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3ba0
#include "pc2_port.h"

void __thiscall Character_Save(void *self,void *arg1)

{
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x24,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x28,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x2c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x30,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x34,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x38,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x3c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x44,2000);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x814,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x818,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x81c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x820,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x824,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x40,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x825,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x18,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x20,4);
  return;
}
