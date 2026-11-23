// UI_DrawChildSprite: ported from Pizza Connection 2 at 0x521740.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521740
#include "pc2_port.h"

void __thiscall
UI_DrawChildSprite(void *self,uint32_t *arg1,int arg2,uint32_t *arg3,int arg4,uint32_t arg5)

{
  int local_c [3];
  
  local_c[0] = 0;
  local_c[2] = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x68),arg5);
  local_c[1] = 0;
  UI_DrawLine(self,arg1,arg2,arg3,arg4,local_c);
  return;
}
