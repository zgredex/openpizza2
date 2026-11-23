// Window_GadgetNotify_Input_GetText: ported from Pizza Connection 2 at 0x52fbe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fbe0
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Input_GetText(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,4,0xf,0,0);
  return;
}
