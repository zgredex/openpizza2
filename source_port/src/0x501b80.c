// Player_AIState_Load: ported from Pizza Connection 2 at 0x501b80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501b80
#include "pc2_port.h"

void __thiscall Player_AIState_Load(void *self,void *arg1)

{
  void *this_00;
  int value1;
  void *local_4;
  
  this_00 = arg1;
  local_4 = self;
  CRT_Istream_Read(arg1,(intptr_t)self + 4,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xc,0x34);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x44,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x40,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x48,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x4c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x50,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x54,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x58,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x5c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x60,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 100,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x84,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x88,0xe4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x16c,0xe4);
  CRT_Istream_Read(this_00,&arg1,4);
  value1 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      CRT_Istream_Read(this_00,&local_4,4);
      List_Add((void *)((intptr_t)self + 0x68),local_4);
      value1 = value1 + 1;
    } while (value1 < (intptr_t)arg1);
  }
  return;
}
