// GamePlan_SaveRecord: ported from Pizza Connection 2 at 0x50f6b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f6b0
#include "pc2_port.h"

void __thiscall GamePlan_SaveRecord(void *self,void *arg1)

{
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x18,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x20,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x2c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x24,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x28,4);
  return;
}
