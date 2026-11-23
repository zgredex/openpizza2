// UI_DisableButton: ported from Pizza Connection 2 at 0x52ff80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ff80
#include "pc2_port.h"

void __thiscall UI_DisableButton(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,1,3,3,0);
  return;
}
