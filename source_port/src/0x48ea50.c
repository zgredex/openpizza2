// Game_ReturnToPlayScreen: ported from Pizza Connection 2 at 0x48ea50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48ea50
#include "pc2_port.h"

void Game_ReturnToPlayScreen(void)

{
  void *self;
  void *pvVar1;
  
                    /* Destroys the current menu and returns to the play screen. */
  pvVar1 = DAT_0057c670;
  self = *(void **)((intptr_t)DAT_0057c670 + 0x260);
  *(uint32_t *)((intptr_t)DAT_0057c670 + 0x21c) = 0;
  *(uint32_t *)((intptr_t)pvVar1 + 0x2da8) = 1;
  pvVar1 = DAT_0057c670;
  *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2c8) = *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2a8);
  *(uint32_t *)((intptr_t)pvVar1 + 0x2a8) = 1;
  Game_DestroyRootWindow((intptr_t)DAT_0057c670);
  SubMenu_CreateBuildingPage(DAT_0057c670);
  Window_GadgetNotify_Button_SetState(self,0x3f4,1);
  Array_ToggleObjectActive(self,0x3f4,1);
  Window_GadgetNotify_Button_SetState(self,0x3fd,0);
  Array_ToggleObjectActive(self,0x3fd,0);
  UI_SetChildVisibleByID(self,0x3fd,0);
  return;
}
