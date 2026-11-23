// Window_GadgetNotify_Text_SetLayout: ported from Pizza Connection 2 at 0x52f9d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f9d0
#include "pc2_port.h"

void __thiscall
Window_GadgetNotify_Text_SetLayout
          (void *self,int arg1,uint32_t arg2,uint16_t arg3,uint16_t arg4,
          uint32_t arg5)

{
  uint16_t local_10;
  uint16_t local_e;
  uint32_t local_8;
  uint32_t local_4;
  
  local_10 = arg3;
  local_8 = arg2;
  local_e = arg4;
  local_4 = arg5;
  Window_GadgetNotify(self,arg1,3,0xd8,0,&local_10);
  return;
}
