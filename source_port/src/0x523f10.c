// Window_HideWindowById: ported from Pizza Connection 2 at 0x523f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523f10
#include "pc2_port.h"

void __thiscall Window_HideWindowById(void *self,int arg1)

{
  void *this_00;
  int local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  this_00 = (void *)UI_FindWindowByID(self,arg1,(int *)0x0);
  if ((this_00 != (void *)0x0) && (*(int *)((intptr_t)this_00 + 0x4c) != 0)) {
    local_10 = *(int *)((intptr_t)this_00 + 8);
    local_c = *(uint32_t *)((intptr_t)this_00 + 0xc);
    local_8 = *(uint32_t *)((intptr_t)this_00 + 0x10);
    local_4 = *(uint32_t *)((intptr_t)this_00 + 0x14);
    Rect_Set1A4(self,&local_10);
    *(uint32_t *)((intptr_t)self + 0x83b8) = 1;
    UI_SetWindowVisible(this_00,0);
    if ((*(void **)((intptr_t)self + 0x82c8) == this_00) && (*(int **)((intptr_t)self + 0x82d4) != (int *)0x0)
       ) {
      (**(code **)(**(int **)((intptr_t)self + 0x82d4) + 0xc))(5,0,(intptr_t)self + 0x835c);
      *(uint32_t *)((intptr_t)self + 0x22c) = 0;
      *(uint32_t *)((intptr_t)self + 0x224) = 0;
    }
    UI_ForgetChildById(self,(intptr_t)this_00);
    DebugConsole_Printf(DAT_0057c1e0,0xff0000,(uint8_t *)s_hide_window__d_0057421c,arg1);
  }
  return;
}
