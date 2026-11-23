// Gadget_GetSpriteFrames: ported from Pizza Connection 2 at 0x52f0d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f0d0
#include "pc2_port.h"

void __thiscall Gadget_GetSpriteFrames(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,0,0x42,0,0);
  return;
}
