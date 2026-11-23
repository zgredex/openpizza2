// Sprite_BlitOwnedRLE: ported from Pizza Connection 2 at 0x53d690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d690
#include "pc2_port.h"

void __thiscall Sprite_BlitOwnedRLE(void *self,void *arg1,int arg2,int arg3)

{
  Sprite_BlitRLEOpaque(self,arg1,*(uint8_t **)((intptr_t)self + 0x2c),0,arg2,arg3,0xfffffffe,0);
  return;
}
