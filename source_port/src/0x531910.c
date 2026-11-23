// UI_SetButtonSpriteByName: ported from Pizza Connection 2 at 0x531910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531910
#include "pc2_port.h"

void __thiscall UI_SetButtonSpriteByName(void *self,int arg1,char *arg2)

{
  int value1;
  uint32_t local_44 [17];
  
  value1 = Window_LoadSpriteCached(*(void **)((intptr_t)self + 0x134),arg2,(uint32_t *)0x0,local_44);
  if (value1 == 0) {
    return;
  }
  Window_GadgetNotify(self,arg1,6,0x37,1,local_44);
  return;
}
