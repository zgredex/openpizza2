// Gadget_SetText: ported from Pizza Connection 2 at 0x52f830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f830
#include "pc2_port.h"

void __thiscall Gadget_SetText(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,2,0xe,0,arg2);
  return;
}
