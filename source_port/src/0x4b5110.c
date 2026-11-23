// Screen_Statistics_Construct: ported from Pizza Connection 2 at 0x4b5110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b5110
#include "pc2_port.h"


void __cdecl Screen_Statistics_Construct(void *arg1)

{
  uint64_t uvalue1;
  int value2;
  uint32_t uvalue3;
  bool flag4;
  
                    /* Builds the tabbed statistics screen. */
  Array_SetField14ByKey(arg1,0x411,0);
  Array_SetField14ByKey(arg1,0x412,0);
  Array_SetField14ByKey(arg1,0x413,0);
  Array_SetField14ByKey(arg1,0x414,0);
  Array_SetField14ByKey(arg1,0x415,0);
  UI_SetPosition(arg1,&LAB_004b50f0,0);
  UI_AddUniquePair(arg1,0x3f5,0x131);
  UI_AddUniquePair(arg1,0x3f6,0x133);
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac) + 0xd0) == 0) {
    Mission_ShowObjectiveDialog(DAT_0057c670,'\x01');
  }
  DAT_0057d6ac = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  if (DAT_0056a800 != -1) {
    UI_Group_RemoveAt(arg1,DAT_0056a800);
  }
  value2 = Game_CountRecordsForSelectedPlayer(DAT_0057c670,*(int *)((intptr_t)DAT_0057c670 + 0x2f4),-1);
  if (value2 == 0) {
    DAT_0056a800 = UI_Group_Create(arg1,0,4,0x3fd);
    Window_GadgetNotify_Button_SetState(arg1,0x3fb,0);
    UI_SetChildVisibleByID(arg1,0x3fb,0);
  }
  else {
    DAT_0056a800 = UI_Group_Create(arg1,0,5,0x3fd);
    if ((*(int *)((intptr_t)DAT_0057c670 + 0x9c) == 0) &&
       (value2 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),
       *(int *)(value2 + 0x15c) != 0)) {
      uvalue3 = IDMap_Lookup((void *)(value2 + 0x148),0,(int *)0x0);
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x9c) = uvalue3;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
    }
  }
  Game_UpdateDateLabels(DAT_0057c670,arg1);
  Personnel_SetEmployeePhotoByKey
            (arg1,0x1f46,
             *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  value2 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
  if (value2 == 0) {
    if (*(int *)(DAT_0057d6ac + 0x15c) < 1) {
      Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_00581328);
      DAT_0057d6a8 = 0xffffffff;
      goto LAB_004b5342;
    }
    DAT_0057d6a8 = 0;
    value2 = IDMap_Lookup((void *)(DAT_0057d6ac + 0x148),0,(int *)0x0);
  }
  else {
    DAT_0057d6a8 = *(uint32_t *)(value2 + 0x3c);
  }
  Window_GadgetNotify_Text_SetText(arg1,0x40f,value2 + 4);
LAB_004b5342:
  flag4 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298) != 5;
  if (flag4) {
    UI_ShowChildByID(arg1,0x3f5);
    UI_ShowChildByID(arg1,0x3f6);
  }
  else {
    Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_005819dc);
    UI_RemoveObjectByKey(arg1,0x3f5);
    UI_RemoveObjectByKey(arg1,0x3f6);
  }
  Array_SetField14ByKey(arg1,0x40c,(uint32_t)flag4);
  MapBadgeAnim_SetWindow(*(void **)((intptr_t)DAT_0057c670 + 0x2d9c),arg1,0x1f42);
  uvalue1 = *(uint64_t *)
           (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x108);
  Sound_SetListenerPosition
            (*(void **)((intptr_t)DAT_0057c670 + 0x2d9c),(intptr_t)uvalue1,(intptr_t)((uint64_t)uvalue1 >> 0x20),0);
  value2 = 0x1f47;
  do {
    UI_RemoveObjectByKey(arg1,value2);
    value2 = value2 + 1;
  } while (value2 < 0x1fa6);
  return;
}
