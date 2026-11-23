// UI_GetButtonSprite: ported from Pizza Connection 2 at 0x531980.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531980
#include "pc2_port.h"

uint32_t __thiscall UI_GetButtonSprite(void *self,int arg1)

{
  int value1;
  
  value1 = Window_GadgetNotify(self,arg1,6,0x38,0,0);
  if (value1 == 0) {
    return 0;
  }
  return *(uint32_t *)(value1 + 0x40);
}
