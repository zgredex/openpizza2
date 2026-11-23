// UI_DrawRectOutline: ported from Pizza Connection 2 at 0x521a50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521a50
#include "pc2_port.h"

void __thiscall
UI_DrawRectOutline(void *self,uint32_t *arg1,int arg2,uint32_t *arg3,int arg4,uint32_t arg5)

{
  int local_c [2];
  uint32_t local_4;
  
  local_c[0] = 0;
  local_4 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x68),arg5);
  UI_DrawLine(self,arg1,arg2,arg3,arg2,local_c);
  UI_DrawLine(self,arg3,arg2,arg3,arg4,local_c);
  UI_DrawLine(self,arg3,arg4,arg1,arg4,local_c);
  UI_DrawLine(self,arg1,arg4,arg1,arg2,local_c);
  return;
}
