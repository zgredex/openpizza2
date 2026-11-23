// Window_GadgetNotify_Text_SetText: ported from Pizza Connection 2 at 0x52f9b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f9b0
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Text_SetText(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,3,0xe,0,arg2);
  return;
}
