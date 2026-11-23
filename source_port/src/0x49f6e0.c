// Screen_RecipeMenu_Construct: ported from Pizza Connection 2 at 0x49f6e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f6e0
#include "pc2_port.h"


void __cdecl Screen_RecipeMenu_Construct(void *arg1)

{
  uint64_t uvalue1;
  int value2;
  uint32_t uvalue3;
  uint32_t *uptr4;
  
                    /* Builds the recipe-book screen and loads the current recipe. */
  Array_SetField14ByKey(arg1,0x411,0);
  Array_SetField14ByKey(arg1,0x412,0);
  Array_SetField14ByKey(arg1,0x413,0);
  Array_SetField14ByKey(arg1,0x414,0);
  Array_SetField14ByKey(arg1,0x415,0);
  UI_SetPosition(arg1,&LAB_0049f200,0);
  UI_AddUniquePair(arg1,0x3f5,0x131);
  UI_AddUniquePair(arg1,0x3f6,0x133);
  value2 = Game_CountRecordsForSelectedPlayer(DAT_0057c670,*(int *)((intptr_t)DAT_0057c670 + 0x2f4),-1);
  if (value2 == 0) {
    UI_Group_Create(arg1,0,4,0x3fc);
    Window_GadgetNotify_Button_SetState(arg1,0x3fb,0);
    UI_SetChildVisibleByID(arg1,0x3fb,0);
  }
  else {
    UI_Group_Create(arg1,0,5,0x3fc);
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
  DAT_0057cd98 = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value2 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298);
  if (value2 == 10) {
    uptr4 = *(uint32_t **)((intptr_t)DAT_0057c670 + 0x98);
  }
  else if ((value2 < 6) || (8 < value2)) {
    uptr4 = *(uint32_t **)((intptr_t)DAT_0057c670 + 0x98);
    if (uptr4 == (uint32_t *)0x0) {
      uptr4 = (uint32_t *)
               IDMap_Lookup((void *)((intptr_t)DAT_0057cd98 + 0x110),DAT_0057cd9c,(int *)0x0);
    }
    else {
      DAT_0057cd9c = Game_FindCompanyIndex(DAT_0057cd98,(intptr_t)uptr4);
    }
  }
  else {
    uptr4 = *(uint32_t **)((intptr_t)DAT_0057cd98 + 0x1d4);
  }
  RecipeMenu_SetCurrentRecipe(arg1,uptr4);
  if (uptr4 == (uint32_t *)0x0) {
    uptr4 = DAT_00581ad0;
  }
  else {
    *(uint32_t **)((intptr_t)DAT_0057c670 + 0x98) = uptr4;
    uptr4 = uptr4 + 1;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x40f,uptr4);
  uvalue3 = Game_HasIdleOtherPlayer(DAT_0057c670);
  if (((char)uvalue3 == '\0') ||
     (*(int *)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x50)
      == -1)) {
    UI_RemoveObjectByKey(arg1,0x434);
    UI_RemoveObjectByKey(arg1,0x435);
    UI_RemoveObjectByKey(arg1,0x437);
  }
  else {
    value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    UI_ShowChildByID(arg1,0x434);
    UI_ShowChildByID(arg1,0x435);
    UI_ShowChildByID(arg1,0x437);
    Gadget_SetTextf(arg1,0x435,(uint8_t *)s__d__s_00568324,*(uint32_t *)(value2 + 0x114c));
  }
  MapBadgeAnim_SetWindow(*(void **)((intptr_t)DAT_0057c670 + 0x2d9c),arg1,0x1f42);
  uvalue1 = *(uint64_t *)
           (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x108);
  Sound_SetListenerPosition
            (*(void **)((intptr_t)DAT_0057c670 + 0x2d9c),(intptr_t)uvalue1,(intptr_t)((uint64_t)uvalue1 >> 0x20),0);
  UI_SetChildLabelText(arg1,0x43b,1,(char *)0x0);
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac) + 0xd0) == 0) {
    Mission_ShowObjectiveDialog(DAT_0057c670,'\x01');
  }
  value2 = 0x1f47;
  do {
    UI_RemoveObjectByKey(arg1,value2);
    value2 = value2 + 1;
  } while (value2 < 0x1fa6);
  return;
}
