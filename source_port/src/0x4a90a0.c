// Screen_GameView_Construct: ported from Pizza Connection 2 at 0x4a90a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a90a0
#include "pc2_port.h"


void __cdecl Screen_GameView_Construct(void *arg1)

{
  uint64_t uvalue1;
  int value2;
  uint32_t uvalue3;
  int value4;
  
                    /* Builds the standard isometric game-view frame. */
  Array_SetField14ByKey(arg1,0x411,0);
  Array_SetField14ByKey(arg1,0x412,0);
  Array_SetField14ByKey(arg1,0x413,0);
  Array_SetField14ByKey(arg1,0x414,0);
  Array_SetField14ByKey(arg1,0x415,0);
  if (DAT_005692d0 != -1) {
    UI_Group_RemoveAt(arg1,DAT_005692d0);
  }
  UI_SetPosition(arg1,&LAB_004a9080,0);
  value2 = Game_CountRecordsForSelectedPlayer(DAT_0057c670,*(int *)((intptr_t)DAT_0057c670 + 0x2f4),-1);
  if (value2 == 0) {
    DAT_005692d0 = UI_Group_Create(arg1,0,4,0x3fa);
    Window_GadgetNotify_Button_SetState(arg1,0x3fb,0);
    UI_SetChildVisibleByID(arg1,0x3fb,0);
  }
  else {
    DAT_005692d0 = UI_Group_Create(arg1,0,5,0x3fa);
    if ((*(int *)((intptr_t)DAT_0057c670 + 0x9c) == 0) &&
       (value2 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),
       *(int *)(value2 + 0x15c) != 0)) {
      uvalue3 = IDMap_Lookup((void *)(value2 + 0x148),0,(int *)0x0);
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x9c) = uvalue3;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
    }
  }
  Game_UpdateDateLabels(DAT_0057c670,arg1);
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  Window_GadgetNotify_Text_SetText(arg1,0x40f,value2 + 4);
  value2 = *(int *)((intptr_t)DAT_0057c670 + 900);
  if (value2 == 0) {
    UI_RemoveObjectByKey(arg1,0x1f4e);
    UI_RemoveObjectByKey(arg1,0x1f4f);
  }
  else {
    value4 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    Window_GadgetNotify_Text_SetText(arg1,0x1f4f,value4 + 4);
    UI_ShowChildByID(arg1,0x1f4e);
    UI_ShowChildByID(arg1,0x1f4f);
    if (0 < value2) goto LAB_004a925f;
  }
  UI_RemoveObjectByKey(arg1,0x1f4b);
LAB_004a925f:
  value4 = Game_GetSpeedSetting((intptr_t)DAT_0057c670);
  if (value4 <= value2) {
    UI_RemoveObjectByKey(arg1,0x1f49);
  }
  MapBadgeAnim_SetWindow(*(void **)((intptr_t)DAT_0057c670 + 0x2d9c),arg1,0x430);
  uvalue1 = *(uint64_t *)
           (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x108);
  Sound_SetListenerPosition
            (*(void **)((intptr_t)DAT_0057c670 + 0x2d9c),(intptr_t)uvalue1,(intptr_t)((uint64_t)uvalue1 >> 0x20),0);
  Personnel_SetEmployeePhotoByKey
            (arg1,0x1f48,
             *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac) + 0xd0) == 0) {
    Mission_ShowObjectiveDialog(DAT_0057c670,'\x01');
  }
  return;
}
