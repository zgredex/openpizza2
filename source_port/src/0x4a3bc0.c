// HeadquartersPage_FillCompetitorRows: ported from Pizza Connection 2 at 0x4a3bc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a3bc0
#include "pc2_port.h"

void __cdecl HeadquartersPage_FillCompetitorRows(void *arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int *ptr3;
  int *local_88;
  int local_84;
  char local_80 [128];
  
                    /* Fills the headquarters competitor rows. */
  if (arg3 < 5) {
    arg2 = 0;
  }
  else {
    arg3 = 4;
  }
  value2 = 0;
  ptr3 = &DAT_00568f2c;
  do {
    UI_RemoveObjectByKey(arg1,*ptr3);
    UI_RemoveObjectByKey(arg1,value2 + 0x23f1);
    ptr3 = ptr3 + 4;
    value2 = value2 + 1;
  } while ((intptr_t)ptr3 < 0x568f6c);
  if (arg2 < 6) {
    local_88 = &DAT_0057d24c + arg2;
    value2 = 0x23f1;
    ptr3 = &DAT_00568f30;
    local_84 = arg2;
    do {
      if (value2 + -0x23f1 == arg3) {
        return;
      }
      value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if ((local_84 != value1) && (*local_88 != 0)) {
        value1 = Game_GetPlayerBySlot(DAT_0057c670,local_84);
        Window_GadgetNotify_Text_SetTextColor(arg1,*ptr3,*(uint32_t *)(value1 + 0x1dc));
        Gadget_SetTextf(arg1,*ptr3,&DAT_005630d0,value1 + 8);
        Gadget_SetTextf(arg1,ptr3[2],&DAT_005686f4,*local_88);
        String_Format(local_80,(uint8_t *)s_LOGOS__0_d_spr_00568eb8,*(int *)(value1 + 0x1e0) + 1);
        UI_SetButtonSpriteByName(arg1,value2,local_80);
        UI_ShowChildByID(arg1,value2);
        UI_ShowChildByID(arg1,ptr3[-1]);
        Window_GadgetNotify_Button_SetState
                  (arg1,ptr3[-1],(uint32_t)(uint8_t)(&DAT_0057d240)[local_84]);
        value2 = value2 + 1;
        ptr3 = ptr3 + 4;
      }
      local_84 = local_84 + 1;
      local_88 = local_88 + 1;
    } while ((intptr_t)local_88 < 0x57d264);
  }
  return;
}
