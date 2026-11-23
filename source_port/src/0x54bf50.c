// Sound_SetListenerPosition: ported from Pizza Connection 2 at 0x54bf50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54bf50
#include "pc2_port.h"

void __thiscall
Sound_SetListenerPosition(void *self,uint32_t arg1,uint32_t arg2,int arg3)

{
  int64_t lvalue1;
  
  lvalue1 = __ftol();
  Sound_UpdateListener(self,(uint32_t)lvalue1,(intptr_t)((uint64_t)lvalue1 >> 0x20),arg3);
  return;
}
