// Gadget_SetButtonColors: ported from Pizza Connection 2 at 0x52f750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f750
#include "pc2_port.h"

void __thiscall
Gadget_SetButtonColors
          (void *self,int arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4)

{
  Window_GadgetNotify(self,arg1,2,0xd,arg2,0);
  Window_GadgetNotify(self,arg1,2,0x17,arg3,0);
  Window_GadgetNotify(self,arg1,2,0x15,arg4,0);
  return;
}
