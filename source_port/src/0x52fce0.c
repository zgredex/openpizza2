// Window_GadgetNotify_Slider_SetChangeNotify: ported from Pizza Connection 2 at 0x52fce0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fce0
#include "pc2_port.h"

void __thiscall
Window_GadgetNotify_Slider_SetChangeNotify(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,5,0x1c,arg2,0);
  return;
}
