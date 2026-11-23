// Window_GadgetNotify_Text_SetMode: ported from Pizza Connection 2 at 0x52fa20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fa20
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Text_SetMode(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,3,0x1f,arg2,0);
  return;
}
