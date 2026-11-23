// UI_GetButtonContext: ported from Pizza Connection 2 at 0x531b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531b90
#include "pc2_port.h"

void __thiscall UI_GetButtonContext(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,6,0x36,0,arg2);
  return;
}
