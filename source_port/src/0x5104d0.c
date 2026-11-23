// Game_MapInputIndex: ported from Pizza Connection 2 at 0x5104d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5104d0
#include "pc2_port.h"

void __thiscall Game_MapInputIndex(void *self,int arg1)

{
  if (arg1 == 8) {
    arg1 = 5;
  }
  Index_Map8To5(self,arg1);
  return;
}
