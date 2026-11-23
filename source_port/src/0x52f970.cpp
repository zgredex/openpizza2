// Window_GadgetNotify_Text_GetHeight: ported from Pizza Connection 2 at 0x52f970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f970
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Text_GetHeight(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,3,0x11,0,0);
  return;
}
