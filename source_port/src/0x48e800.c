// Screen_BranchDetail_Construct: ported from Pizza Connection 2 at 0x48e800.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48e800
#include "pc2_port.h"


void __cdecl Screen_BranchDetail_Construct(void *arg1)

{
  void *pvVar1;
  int value2;
  uint32_t uvalue3;
  int64_t lvalue4;
  int value5;
  
                    /* Builds the own-branch detail screen. */
  Array_SetField14ByKey(arg1,0x411,0);
  Array_SetField14ByKey(arg1,0x412,0);
  Array_SetField14ByKey(arg1,0x413,0);
  Array_SetField14ByKey(arg1,0x414,0);
  Array_SetField14ByKey(arg1,0x415,0);
  value5 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
  Sound_StartSpeech(DAT_0057ba0c,value5);
  UI_SetPosition(arg1,&LAB_0048e670,0);
  UI_AddUniquePair(arg1,0x3f5,0x131);
  UI_AddUniquePair(arg1,0x3f6,0x133);
  DAT_0057c694 = *(uint32_t *)
                  ((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  if (DAT_00568388 != -1) {
    UI_Group_RemoveAt(arg1,DAT_00568388);
  }
  value2 = Game_CountRecordsForSelectedPlayer(DAT_0057c670,*(int *)((intptr_t)DAT_0057c670 + 0x2f4),-1);
  if (value2 == 0) {
    DAT_00568388 = UI_Group_Create(arg1,0,4,0x3fa);
    Window_GadgetNotify_Button_SetState(arg1,0x3fb,0);
    UI_SetChildVisibleByID(arg1,0x3fb,0);
  }
  else {
    DAT_00568388 = UI_Group_Create(arg1,0,5,0x3fb);
    if ((*(int *)((intptr_t)DAT_0057c670 + 0x9c) == 0) &&
       (value2 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),
       *(int *)(value2 + 0x15c) != 0)) {
      uvalue3 = IDMap_Lookup((void *)(value2 + 0x148),0,(int *)0x0);
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x9c) = uvalue3;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
    }
  }
  DAT_0057c698 = *(uint32_t *)(value5 + 0x3c);
  Game_UpdateDateLabels(DAT_0057c670,arg1);
  Personnel_SetEmployeePhotoByKey
            (arg1,0x1f48,
             *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  if (value5 == 0) {
    value5 = DAT_00581328;
  }
  else {
    value5 = value5 + 4;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x40f,value5);
  MapBadgeAnim_SetWindow(*(void **)((intptr_t)DAT_0057c670 + 0x2d9c),arg1,0x430);
  pvVar1 = DAT_0057c670;
  value5 = 0;
  lvalue4 = __ftol();
  Sound_UpdateListener
            (*(void **)((intptr_t)pvVar1 + 0x2d9c),(uint32_t)lvalue4,(intptr_t)((uint64_t)lvalue4 >> 0x20),value5);
  Branch_UpdateStarRating(arg1);
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac) + 0xd0) == 0) {
    Mission_ShowObjectiveDialog(DAT_0057c670,'\x01');
  }
  return;
}
