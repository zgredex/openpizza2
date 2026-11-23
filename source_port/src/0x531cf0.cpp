// UI_GetWindowObject: ported from Pizza Connection 2 at 0x531cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531cf0
#include "pc2_port.h"

void __thiscall UI_GetWindowObject(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,7,0x36,0,0);
  return;
}
