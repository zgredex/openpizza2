// Player_Event_Load: ported from Pizza Connection 2 at 0x501a70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501a70
#include "pc2_port.h"

void __thiscall Player_Event_Load(void *self,void *arg1)

{
  CRT_Istream_Read(arg1,(intptr_t)self + 4,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 8,2);
  return;
}
