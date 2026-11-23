// Window_GadgetNotify_Text_GetFont: ported from Pizza Connection 2 at 0x52f930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f930
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Text_GetFont(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,3,0x33,0,0);
  return;
}
