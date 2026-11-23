// CompanyInfo_FillActions: ported from Pizza Connection 2 at 0x4a2a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a2a10
#include "pc2_port.h"


void __cdecl CompanyInfo_FillActions(void *arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int64_t lvalue5;
  
                    /* Fills the company profile actions and budget by level. */
  value4 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value1 = Game_GetPlayerFieldC20(value4);
  value3 = 0x43c;
  do {
    UI_RemoveObjectByKey(arg1,value3);
    value3 = value3 + 1;
  } while (value3 < 0x448);
  uvalue2 = (uint32_t)(value1 < 6);
  UI_SetChildVisibleByID(arg1,0x451,uvalue2);
  UI_SetChildVisibleByID(arg1,0x456,uvalue2);
  UI_SetChildVisibleByID(arg1,0x458,uvalue2);
  UI_SetChildVisibleByID(arg1,0x457,uvalue2);
  UI_SetChildVisibleByID(arg1,0x459,uvalue2);
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(*(int *)(value4 + 0x1d8) + 0x28),(int *)0x0);
  lvalue5 = Stats_GetCombinedValue(4,value1);
  DAT_0057d010 = (intptr_t)lvalue5;
  switch(value1) {
  case 1:
    Window_GadgetNotify_Text_SetText(arg1,0x451,DAT_00580d94);
    Window_GadgetNotify_Text_SetText(arg1,0x456,DAT_00580db4);
    Window_GadgetNotify_Text_SetText(arg1,0x458,DAT_00580d5c);
    Window_GadgetNotify_Text_SetText(arg1,0x457,DAT_00580d78);
    Window_GadgetNotify_Text_SetText(arg1,0x459,DAT_00580d10);
    UI_SetButtonSpriteByName(arg1,0x43c,PTR_s_newwerbung_spr_00568df4);
    UI_SetButtonSpriteByName(arg1,0x43d,PTR_s_newkonkurent_spr_00568df8);
    UI_SetButtonSpriteByName(arg1,0x43e,PTR_s_newgangster_spr_00568dfc);
    UI_SetButtonSpriteByName(arg1,0x43f,PTR_s_newpolizei_spr_00568e00);
    UI_SetButtonSpriteByName(arg1,0x440,PTR_s_newaergern_spr_00568e04);
    value4 = 0x43c;
    do {
      UI_ShowChildByID(arg1,value4);
      value4 = value4 + 1;
    } while (value4 < 0x441);
    break;
  case 2:
    Window_GadgetNotify_Text_SetText(arg1,0x451,DAT_00580d0c);
    Window_GadgetNotify_Text_SetText(arg1,0x456,DAT_00580d34);
    Window_GadgetNotify_Text_SetText(arg1,0x458,((uint32_t)((DAT_00580cc8) >> 32)));
    Window_GadgetNotify_Text_SetText(arg1,0x457,DAT_00580ce8);
    Window_GadgetNotify_Text_SetText(arg1,0x459,DAT_00580b90);
    UI_SetButtonSpriteByName(arg1,0x43c,PTR_s_newwerbung_spr_00568df4);
    UI_SetButtonSpriteByName(arg1,0x43d,PTR_s_newmanager_spr_00568e08);
    UI_SetButtonSpriteByName(arg1,0x43e,PTR_s_newrezeptauto_spr_00568e0c);
    UI_SetButtonSpriteByName(arg1,0x43f,PTR_s_newgangster_spr_00568dfc);
    UI_SetButtonSpriteByName(arg1,0x440,PTR_s_newaergern_spr_00568e04);
    value4 = 0x43c;
    do {
      UI_ShowChildByID(arg1,value4);
      value4 = value4 + 1;
    } while (value4 < 0x441);
    break;
  case 3:
    Window_GadgetNotify_Text_SetText(arg1,0x451,DAT_00580b9c);
    Window_GadgetNotify_Text_SetText(arg1,0x456,DAT_00580b78);
    Window_GadgetNotify_Text_SetText(arg1,0x458,DAT_00580b84);
    Window_GadgetNotify_Text_SetText(arg1,0x457,DAT_00580b68);
    UI_RemoveObjectByKey(arg1,0x459);
    UI_SetButtonSpriteByName(arg1,0x43c,PTR_s_newgangster_spr_00568dfc);
    UI_SetButtonSpriteByName(arg1,0x43d,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x43e,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x43f,PTR_s_newaergern_spr_00568e04);
    value4 = 0x43c;
    do {
      UI_ShowChildByID(arg1,value4);
      value4 = value4 + 1;
    } while (value4 < 0x440);
    break;
  case 4:
    Window_GadgetNotify_Text_SetText(arg1,0x451,DAT_00580b6c);
    Window_GadgetNotify_Text_SetText(arg1,0x456,DAT_00580b50);
    Window_GadgetNotify_Text_SetText(arg1,0x458,DAT_00580b58);
    Window_GadgetNotify_Text_SetText(arg1,0x457,DAT_00580b30);
    Window_GadgetNotify_Text_SetText(arg1,0x459,DAT_00580b4c);
    UI_SetButtonSpriteByName(arg1,0x43c,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x43d,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x43e,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x43f,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x440,PTR_s_newaergern_spr_00568e04);
    value4 = 0x43c;
    do {
      UI_ShowChildByID(arg1,value4);
      value4 = value4 + 1;
    } while (value4 < 0x441);
    break;
  case 5:
    Window_GadgetNotify_Text_SetText(arg1,0x451,DAT_00580b48);
    Window_GadgetNotify_Text_SetText(arg1,0x456,DAT_00580b04);
    Window_GadgetNotify_Text_SetText(arg1,0x458,DAT_00580b1c);
    Window_GadgetNotify_Text_SetText(arg1,0x457,DAT_00580af0);
    Window_GadgetNotify_Text_SetText(arg1,0x459,DAT_00580afc);
    UI_SetButtonSpriteByName(arg1,0x43c,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x43d,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x43e,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x43f,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(arg1,0x440,PTR_s_newaergern_spr_00568e04);
    value4 = 0x43c;
    do {
      UI_ShowChildByID(arg1,value4);
      value4 = value4 + 1;
    } while (value4 < 0x441);
  }
  value4 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value4 + 0x150) == 0) {
    if (*(int *)(value4 + 0x160) == 0) {
      if (*(int *)(value4 + 0x234) != 0) {
        DAT_0057d010 = (DAT_0057d010 * 0xf) / 10;
      }
    }
    else {
      DAT_0057d010 = DAT_0057d010 / 2;
    }
  }
  else {
    DAT_0057d010 = 0;
  }
  if (5 < value1) {
LAB_004a3017:
    UI_RemoveObjectByKey(arg1,0x44d);
    UI_RemoveObjectByKey(arg1,0x44f);
    UI_RemoveObjectByKey(arg1,0x450);
    AttackMenu_InitCompetitorRows(arg1);
    return;
  }
  if ((char)DAT_0057bb3c == '\0') {
    UI_ShowChildByID(arg1,0x44d);
    UI_ShowChildByID(arg1,0x44f);
    UI_ShowChildByID(arg1,0x450);
    Gadget_SetTextf(arg1,0x44f,&DAT_005683a4,DAT_0057d010);
  }
  else {
    if (DAT_0057bb38 <= value1) goto LAB_004a3017;
    UI_ShowChildByID(arg1,0x44d);
    UI_ShowChildByID(arg1,0x44f);
    UI_ShowChildByID(arg1,0x450);
    Gadget_SetTextf(arg1,0x44f,&DAT_005683a4,DAT_0057d010);
  }
  Gadget_SetTextf(arg1,0x450,(uint8_t *)s__d__s_00568324,4);
  AttackMenu_InitCompetitorRows(arg1);
  return;
}
