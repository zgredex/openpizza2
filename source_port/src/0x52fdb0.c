// Window_GadgetNotify_Slider_AttachValueText: ported from Pizza Connection 2 at 0x52fdb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fdb0
#include "pc2_port.h"

void __thiscall
Window_GadgetNotify_Slider_AttachValueText
          (void *self,int arg1,uint32_t arg2,uint32_t arg3)

{
  Window_GadgetNotify(self,arg1,5,0x27,arg2,arg3);
  return;
}
