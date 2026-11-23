// StatsPeriodReport_Save: ported from Pizza Connection 2 at 0x401200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401200
#include "pc2_port.h"

void __thiscall StatsPeriodReport_Save(void *self,void *arg1)

{
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10,0x68);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x78,100);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xdc,0x280);
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 8,4);
  return;
}
