// Window_GadgetNotify_Text_SetTextColor: ported from Pizza Connection 2 at 0x52f910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f910
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Text_SetTextColor(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,3,0xd,arg2,0);
  return;
}
