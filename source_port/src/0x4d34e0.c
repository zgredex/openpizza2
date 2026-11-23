// Car_LoadFromStream: ported from Pizza Connection 2 at 0x4d34e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d34e0
#include "pc2_port.h"

void __thiscall Car_LoadFromStream(void *self,void *arg1)

{
  void *this_00;
  uint32_t uvalue1;
  
                    /* Deserializes a car and rebuilds its sprite record. */
  this_00 = arg1;
  CRT_Istream_Read(arg1,&arg1,4);
  uvalue1 = Game_UpdateIDMapEntry(DAT_0057c5cc,(intptr_t)arg1);
  *(uint32_t *)((intptr_t)self + 4) = uvalue1;
  CRT_Istream_Read(this_00,(intptr_t)self + 0xc,4);
  Car_LoadSpriteRecord(self,this_00);
  return;
}
