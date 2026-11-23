// Gadget_SetTextf: ported from Pizza Connection 2 at 0x52f080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f080
#include "pc2_port.h"

void __cdecl Gadget_SetTextf(void *arg1,int arg2,uint8_t *arg3,uint32_t arg4)

{
  uint8_t local_400 [1024];
  
  CRT_Vsprintf(local_400,arg3,&arg4);
  Window_GadgetNotify(arg1,arg2,0,0xe,0,local_400);
  return;
}
