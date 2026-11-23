// Window_GadgetNotify_Slider_SetRange: ported from Pizza Connection 2 at 0x52fd00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fd00
#include "pc2_port.h"

void __thiscall
Window_GadgetNotify_Slider_SetRange(void *self,int arg1,int arg2,int arg3,int arg4)

{
  bool flag1;
  
  Window_GadgetNotify(self,arg1,5,0x21,arg2,0);
  Window_GadgetNotify(self,arg1,5,0x23,arg3,0);
  flag1 = arg2 < arg3;
  if (arg4 != 0) {
    flag1 = !flag1;
  }
  Window_GadgetNotify(self,arg1,5,0x28,(uint32_t)!flag1,0);
  return;
}
