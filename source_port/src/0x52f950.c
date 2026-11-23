// Window_GadgetNotify_Text_GetLineCount: ported from Pizza Connection 2 at 0x52f950.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f950
#include "pc2_port.h"

void __thiscall Window_GadgetNotify_Text_GetLineCount(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,3,0x10,0,0);
  return;
}
