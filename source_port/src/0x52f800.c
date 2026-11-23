// Gadget_SetButtonState: ported from Pizza Connection 2 at 0x52f800.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f800
#include "pc2_port.h"

void __thiscall Gadget_SetButtonState(void *self,int arg1,int arg2)

{
  if (arg2 == 0) {
    Window_GadgetNotify(self,arg1,2,0,0,0);
    return;
  }
  Window_GadgetNotify(self,arg1,2,0,1,0);
  return;
}
