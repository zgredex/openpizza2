// Gadget_SetButtonTextLayout: ported from Pizza Connection 2 at 0x52f7a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f7a0
#include "pc2_port.h"

void __thiscall
Gadget_SetButtonTextLayout
          (void *self,int arg1,uint32_t arg2,uint16_t arg3,uint16_t arg4,
          uint16_t arg5,uint16_t arg6)

{
  uint16_t local_10;
  uint16_t local_e;
  uint16_t local_c;
  uint16_t local_a;
  uint32_t local_8;
  
  local_e = arg4;
  local_10 = arg3;
  local_a = arg6;
  local_c = arg5;
  local_8 = arg2;
  Window_GadgetNotify(self,arg1,2,0xd8,0,&local_10);
  return;
}
