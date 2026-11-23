// GameCalendar_Load: ported from Pizza Connection 2 at 0x4dd590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd590
#include "pc2_port.h"

void __thiscall GameCalendar_Load(void *self,void *arg1)

{
  CRT_Istream_Read(arg1,(intptr_t)self + 7,1);
  CRT_Istream_Read(arg1,(intptr_t)self + 6,1);
  CRT_Istream_Read(arg1,(intptr_t)self + 8,1);
  CRT_Istream_Read(arg1,(intptr_t)self + 4,2);
  CRT_Istream_Read(arg1,(intptr_t)self + 10,2);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xc,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x19,1);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x18,1);
  CRT_Istream_Read(arg1,(uint32_t *)((intptr_t)self + 0x14),4);
  *(uint32_t *)((intptr_t)self + 0x14) = 0xc35;
  CRT_Istream_Read(arg1,(intptr_t)self + 0x10,4);
  if (DAT_0057c668 < 0x2e) {
    DAT_0057dfbc = 2000;
    return;
  }
  CRT_Istream_Read(arg1,&DAT_0057dfbc,4);
  return;
}
