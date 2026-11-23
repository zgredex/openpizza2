// Window_GadgetNotify_Slider_SetValue: ported from Pizza Connection 2 at 0x52fd70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fd70
#include "pc2_port.h"

void __thiscall
Window_GadgetNotify_Slider_SetValue(void *self,int arg1,uint32_t arg2,uint32_t arg3)

{
  Window_GadgetNotify(self,arg1,5,0x25,arg2,arg3);
  return;
}
