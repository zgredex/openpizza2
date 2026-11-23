// CarList_Save: ported from Pizza Connection 2 at 0x4d3490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3490
#include "pc2_port.h"

void __thiscall CarList_Save(void *self,void *arg1)

{
  void *local_4;
  
  local_4 = self;
  local_4 = (void *)Game_RemoveIDMapEntry(DAT_0057c5cc,*(int *)((intptr_t)self + 4));
  CRT_Ostream_Write(arg1,&local_4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc,4);
  Car_Save(self,arg1);
  return;
}
