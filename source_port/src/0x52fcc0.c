// Window_GadgetNotify_Slider_SetGradientColors: ported from Pizza Connection 2 at 0x52fcc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fcc0
#include "pc2_port.h"

void __thiscall
Window_GadgetNotify_Slider_SetGradientColors(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,5,0x1b,0,arg2);
  return;
}
