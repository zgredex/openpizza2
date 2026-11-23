// RecipeTopping_Save: ported from Pizza Connection 2 at 0x4d1ba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d1ba0
#include "pc2_port.h"

void __thiscall RecipeTopping_Save(void *self,void *arg1)

{
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 5,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 6,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x11,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14,8);
  return;
}
