// GameView_SetupZoomedViewport: ported from Pizza Connection 2 at 0x4859c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4859c0
#include "pc2_port.h"

void __thiscall GameView_SetupZoomedViewport(void *self,void *arg1)

{
  int value1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  
                    /* Prepares the zoomed in-game viewport and surfaces. */
  DAT_0057c674 = arg1;
  value1 = Object_GetId((intptr_t)arg1);
  uptr2 = UI_CreateBitmapGadget(arg1,0x2a,0,0,DAT_00571958,DAT_0057195c,0x10);
  UI_MoveElementToIndex(arg1,0x2a,0);
  UI_BringWindowToFront(DAT_0057c5e0,value1);
  Array_SetField14ByKey(arg1,0x2a,1);
  DAT_00580a50 = *(uint32_t *)((intptr_t)self + 0x2da0);
  DAT_00571950 = DAT_00571958 << ((uint8_t)DAT_00580a50 & 0x1f);
  DAT_00571954 = DAT_0057195c << ((uint8_t)DAT_00580a50 & 0x1f);
  uvalue5 = 0;
  uvalue4 = 0;
  uvalue3 = Object_GetActiveValue((intptr_t)uptr2);
  Game_ResizeZoomSurfaces(DAT_0057c5cc,DAT_0057c5c8,DAT_00571950,DAT_00571954,uvalue3,uvalue4,uvalue5);
  return;
}
