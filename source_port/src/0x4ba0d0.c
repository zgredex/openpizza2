// Screen_BranchView_Init: ported from Pizza Connection 2 at 0x4ba0d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ba0d0
#include "pc2_port.h"


void __cdecl Screen_BranchView_Init(void *arg1)

{
  void *pvVar1;
  int64_t lvalue2;
  int value3;
  
                    /* Initializes the branch-view screen. */
  Array_SetField14ByKey(arg1,0x411,0);
  Array_SetField14ByKey(arg1,0x412,0);
  Array_SetField14ByKey(arg1,0x413,0);
  Array_SetField14ByKey(arg1,0x414,0);
  Array_SetField14ByKey(arg1,0x415,0);
  DAT_0057d6e8 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
  Sound_StartSpeech(DAT_0057ba0c,DAT_0057d6e8);
  UI_AddUniquePair(arg1,0x3f5,0x131);
  UI_AddUniquePair(arg1,0x3f6,0x133);
  UI_SetPosition(arg1,&LAB_004ba090,0);
  UI_Group_Create(arg1,0,5,0x3fb);
  Game_UpdateDateLabels(DAT_0057c670,arg1);
  if (DAT_0057d6e8 != 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_0057d6e8 + 4);
  }
  Personnel_SetEmployeePhotoByKey
            (arg1,0x1f48,
             *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  MapBadgeAnim_SetWindow(*(void **)((intptr_t)DAT_0057c670 + 0x2d9c),arg1,0x430);
  pvVar1 = DAT_0057c670;
  value3 = 0;
  lvalue2 = __ftol();
  Sound_UpdateListener
            (*(void **)((intptr_t)pvVar1 + 0x2d9c),(uint32_t)lvalue2,(intptr_t)((uint64_t)lvalue2 >> 0x20),value3);
  Branch_UpdateStarRating(arg1);
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac) + 0xd0) == 0) {
    Mission_ShowObjectiveDialog(DAT_0057c670,'\x01');
  }
  return;
}
