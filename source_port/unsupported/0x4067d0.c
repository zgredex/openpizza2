// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x4067d0.c:32:33: error: use of undeclared identifier 'Game_WindowProc'; did you mean 'UI_SetWindowProc'?
// UI_Init: ported from Pizza Connection 2 at 0x4067d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4067d0
#include "pc2_port.h"

void __fastcall UI_Init(uint32_t arg1)

{
  void *self;
  uint32_t *uptr1;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00557d1b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (DAT_0057c5e0 != (uint32_t *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)*DAT_0057c5e0)(1,arg1);
  }
  self = operator_new(0x83e8);
  uStack_4 = 0;
  if (self == (void *)0x0) {
    DAT_0057c5e0 = (uint32_t *)0x0;
  }
  else {
    DAT_0057c5e0 = UI_Manager_Construct(self,DAT_0057c5c8,DAT_0057c5d0,DAT_0057c5d8,800,600,0);
  }
  uStack_4 = 0xffffffff;
  UI_SetWindowProc(DAT_0057c5e0,Game_WindowProc);
  UI_SetEventCallback(DAT_0057c5e0,&LAB_00405640);
  UI_CreateContextMenu(DAT_0057c5e0,s_rklick_00563c44);
  UI_SetChildPosition(DAT_0057c5e0,0xc0c0c0,0xffff00);
  uptr1 = (uint32_t *)UI_GetTheme((intptr_t)DAT_0057c5e0);
  UI_SetFontName(DAT_0057c5e0,&DAT_00563c40);
  UI_SetLayoutParams(DAT_0057c5e0,0,0x20);
  *uptr1 = s_default_font_00563b80;
  uptr1[4] = 0xffffff;
  uptr1[5] = 0x800000;
  uptr1[6] = 0x80;
  uptr1[1] = 0x808080;
  uptr1[2] = 0xffffff;
  uptr1[3] = 0xff0000;
  uptr1[9] = s_Abbruch_00563c38;
  uptr1[10] = &DAT_00563c34;
  ExceptionList = pvStack_c;
  return;
}
