// Player_MissionState_Load: ported from Pizza Connection 2 at 0x4f5e50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5e50
#include "pc2_port.h"

void __thiscall Player_MissionState_Load(void *self,void *arg1)

{
  CRT_Istream_Read(arg1,(intptr_t)self + 4,0xc);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x10,0xb0);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xc0,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xc4,3);
  CRT_Istream_Read(arg1,(intptr_t)self + 200,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xcc,1);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xd0,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xd4,4);
  return;
}
