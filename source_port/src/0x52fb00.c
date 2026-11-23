// Window_GadgetNotify_Input_SetFilter: ported from Pizza Connection 2 at 0x52fb00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fb00
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Input_SetFilter(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,4,0x1d,arg2,0);
  return;
}
