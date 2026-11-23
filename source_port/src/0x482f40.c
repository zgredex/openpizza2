// Mission_ShowObjectiveDialog: ported from Pizza Connection 2 at 0x482f40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482f40
#include "pc2_port.h"

void __thiscall Mission_ShowObjectiveDialog(void *self,char arg1)

{
  int value1;
  void *pvVar2;
  int *ptr3;
  int *ptr4;
  uint32_t uvalue5;
  char *cptr6;
  int local_104;
  char local_100 [256];
  
                    /* Shows the current mission objective dialog. */
  value1 = *(int *)(*(int *)((intptr_t)self + 0x224) + 0xac);
  if (*(int *)(value1 + 0xd4) < 10) {
    if (arg1 != '\0') {
      if (*(uint32_t **)((intptr_t)self + 0x26c) != (uint32_t *)0x0) {
        Window_DestroyChild(DAT_0057c5e0,*(uint32_t **)((intptr_t)self + 0x26c));
      }
      pvVar2 = MissionHintWindow_Create(&local_104);
      *(void **)((intptr_t)self + 0x26c) = pvVar2;
    }
    value1 = *(int *)(value1 + 0xd4);
    if (value1 == 0) {
      uvalue5 = DAT_00582ab8;
    }
    else {
      uvalue5 = DAT_005819b8;
    }
    Gadget_SetText(*(void **)((intptr_t)self + 0x26c),0x433,uvalue5);
    Window_GadgetNotify_Text_SetText
              (*(void **)((intptr_t)self + 0x26c),0x43a,*(uint32_t *)(&DAT_0058335c + value1 * 4));
    Window_GadgetNotify_Text_SetText
              (*(void **)((intptr_t)self + 0x26c),0x439,*(uint32_t *)(&DAT_005834ac + value1 * 4));
    Sound_PlayTutorialSpeech(DAT_0057ba0c,value1,'\0','\x01');
    ptr4 = &DAT_00567da4;
    ptr3 = (int *)(&DAT_00567dfc + value1 * 0xc);
    do {
      if (*ptr3 == 0) {
        UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x26c),*ptr4);
      }
      else {
        UI_ShowChildByID(*(void **)((intptr_t)self + 0x26c),*ptr4);
        String_Format(local_100,(uint8_t *)s__s_spr_005680ec,
                      *(uint32_t *)(&DAT_00567dd4 + *ptr3 * 4));
        UI_SetButtonSpriteByName(*(void **)((intptr_t)self + 0x26c),*ptr4,local_100);
      }
      ptr4 = ptr4 + 1;
      ptr3 = ptr3 + 1;
    } while ((intptr_t)ptr4 < 0x567db0);
    if (*(int *)(&DAT_00567db0 + value1 * 4) == 1) {
      cptr6 = s_rb01_00_spr_005680e0;
    }
    else {
      cptr6 = s_rb03_00_spr_005680d4;
    }
    UI_SetButtonSpriteByName(*(void **)((intptr_t)self + 0x26c),0x46a,cptr6);
    if (arg1 != '\0') {
      Window_ShowWindowById(DAT_0057c5e0,local_104);
    }
  }
  else if (*(int *)((intptr_t)self + 0x26c) != 0) {
    Game_DestroyEventWindow((intptr_t)self);
    return;
  }
  return;
}
