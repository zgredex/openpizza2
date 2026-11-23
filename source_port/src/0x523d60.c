// Window_ShowWindowById: ported from Pizza Connection 2 at 0x523d60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523d60
#include "pc2_port.h"

void __thiscall Window_ShowWindowById(void *self,int arg1)

{
  void *this_00;
  int local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  this_00 = (void *)UI_FindWindowByID(self,arg1,(int *)0x0);
  if ((this_00 != (void *)0x0) && (*(int *)((intptr_t)this_00 + 0x4c) == 0)) {
    UI_SetWindowVisible(this_00,1);
    *(uint32_t *)((intptr_t)self + 0x83b8) = 1;
    DebugConsole_Printf(DAT_0057c1e0,0xff0000,(uint8_t *)s_show_window__d_005741f4,arg1);
    local_10 = *(int *)((intptr_t)this_00 + 8);
    local_c = *(uint32_t *)((intptr_t)this_00 + 0xc);
    local_8 = *(uint32_t *)((intptr_t)this_00 + 0x10);
    local_4 = *(uint32_t *)((intptr_t)this_00 + 0x14);
    Rect_Set1A4(self,&local_10);
  }
  return;
}
