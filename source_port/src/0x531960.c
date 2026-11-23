// UI_SetButtonColorVariant: ported from Pizza Connection 2 at 0x531960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531960
#include "pc2_port.h"

void __thiscall UI_SetButtonColorVariant(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,6,0x39,arg2,0);
  return;
}
