// Window_GadgetNotify_Text_ResetScroll: ported from Pizza Connection 2 at 0x52f990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f990
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Text_ResetScroll(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,3,0x13,arg2,0);
  return;
}
