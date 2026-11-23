// Player_Event_Save: ported from Pizza Connection 2 at 0x501a40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501a40
#include "pc2_port.h"

void __thiscall Player_Event_Save(void *self,void *arg1)

{
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 8,2);
  return;
}
