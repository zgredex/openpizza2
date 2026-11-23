// UI_GetButtonSpriteRecord: ported from Pizza Connection 2 at 0x5319a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5319a0
#include "pc2_port.h"

void __thiscall UI_GetButtonSpriteRecord(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,6,0x38,0,0);
  return;
}
