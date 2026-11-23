// Window_GadgetNotify_Input_SetNormalColor: ported from Pizza Connection 2 at 0x52fb40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fb40
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Input_SetNormalColor(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,4,0xd,arg2,0);
  return;
}
