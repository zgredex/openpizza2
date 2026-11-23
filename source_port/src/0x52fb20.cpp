// Window_GadgetNotify_Input_GetFilter: ported from Pizza Connection 2 at 0x52fb20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fb20
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Input_GetFilter(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,4,0x1e,0,0);
  return;
}
