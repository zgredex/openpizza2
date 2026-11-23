// Game_EnterSelectedBranch: ported from Pizza Connection 2 at 0x4ba440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ba440
#include "pc2_port.h"

void __cdecl Game_EnterSelectedBranch(void *arg1)

{
  void *pvVar1;
  int value2;
  
                    /* Enters the selected branch, retitles it, and rebuilds its submenu. */
  Window_GadgetNotify_Text_SetText(arg1,0x40f,(intptr_t)DAT_0057d6e8 + 4);
  *(void **)((intptr_t)DAT_0057c670 + 0x9c) = DAT_0057d6e8;
  Sound_SelectCurrentTrack(DAT_0057ba0c);
  Game_EnterBranchInterior(DAT_0057c670,(intptr_t)DAT_0057d6e8);
  Sound_StopSpeech(DAT_0057ba0c,(intptr_t)DAT_0057d6e8);
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
  value2 = Game_CountObjectsByType(DAT_0057d6e8,1);
  if ((value2 == 0) &&
     (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298) == 8)) {
    UI_QueueControlCommand(arg1,-0x18697,0x23,0);
  }
  else {
    BranchScreen_UpdateTabButtons(*(void **)((intptr_t)DAT_0057c670 + 0x260));
  }
  Branch_UpdateStarRating(arg1);
  UI_QueueControlCommand
            (*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18642,0x23,*(int *)((intptr_t)DAT_0057d6e8 + 0x3c))
  ;
  return;
}
