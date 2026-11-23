// CityView_SelectBranch: ported from Pizza Connection 2 at 0x48f540.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48f540
#include "pc2_port.h"

void __cdecl CityView_SelectBranch(void *arg1,char arg2)

{
  void *pvVar1;
  void *self;
  int value2;
  
                    /* Selects a branch from the city view and enters it. */
  self = (void *)IDMap_Lookup((void *)(DAT_0057c694 + 0x148),DAT_0057c698,(int *)0x0);
  *(void **)((intptr_t)DAT_0057c670 + 0x9c) = self;
  Sound_SelectCurrentTrack(DAT_0057ba0c);
  Sound_StopSpeech(DAT_0057ba0c,(intptr_t)self);
  DAT_0057c698 = *(uint32_t *)((intptr_t)self + 0x3c);
  Window_GadgetNotify_Text_SetText(arg1,0x40f,(intptr_t)self + 4);
  Game_EnterBranchInterior(DAT_0057c670,(intptr_t)self);
  Branch_UpdateStarRating(arg1);
  pvVar1 = DAT_0057c670;
  if (*(int *)((intptr_t)DAT_0057c670 + 0x21c) != 0) {
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x21c) = 0;
    *(uint32_t *)((intptr_t)pvVar1 + 0x2da8) = 1;
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2e4) = 0;
    Game_DestroyRootWindow((intptr_t)DAT_0057c670);
    pvVar1 = DAT_0057c670;
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2c8) = *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2a8);
    *(uint32_t *)((intptr_t)pvVar1 + 0x2a8) = 1;
    value2 = SubMenu_BuildBranchInteriorPage((intptr_t)DAT_0057c670);
    Window_ShowWindowById(DAT_0057c5e0,value2);
  }
  if (*(int *)((intptr_t)DAT_0057c670 + 0x220) != 0) {
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x220) = 0;
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2e4) = 0;
    Game_DestroyRootWindow((intptr_t)DAT_0057c670);
    pvVar1 = DAT_0057c670;
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2c8) = *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2a8);
    *(uint32_t *)((intptr_t)pvVar1 + 0x2a8) = 1;
    value2 = SubMenu_BuildBranchInteriorPage((intptr_t)DAT_0057c670);
    Window_ShowWindowById(DAT_0057c5e0,value2);
  }
  if ((*(char *)((intptr_t)self + 0x16f5) == '\0') ||
     (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298) == 9)) {
    value2 = Game_CountObjectsByType(self,1);
    if ((value2 == 0) &&
       (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298) == 8)) {
      UI_QueueControlCommand(arg1,-0x18697,0x23,0);
    }
    else {
      RestaurantInfoPanel_UpdateTabButtons(*(void **)((intptr_t)DAT_0057c670 + 0x260));
    }
  }
  else {
    UI_QueueControlCommand(arg1,-0x18697,0x23,0);
  }
  if (arg2 != '\0') {
    UI_QueueControlCommand
              (*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x1864e,0x23,*(int *)((intptr_t)self + 0x3c));
  }
  return;
}
