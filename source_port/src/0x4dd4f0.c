// GameCalendar_Save: ported from Pizza Connection 2 at 0x4dd4f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd4f0
#include "pc2_port.h"

void __thiscall GameCalendar_Save(void *self,void *arg1)

{
  CRT_Ostream_Write(arg1,(intptr_t)self + 7,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 6,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 8,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,2);
  CRT_Ostream_Write(arg1,(intptr_t)self + 10,2);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x19,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x18,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10,4);
  CRT_Ostream_Write(arg1,&DAT_0057dfbc,4);
  return;
}
