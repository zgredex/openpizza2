// PersonnelPage_UpdateEmployeePanel: ported from Pizza Connection 2 at 0x4b10e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b10e0
#include "pc2_port.h"

void __cdecl PersonnelPage_UpdateEmployeePanel(void *arg1,uint32_t arg2,int *arg3)

{
  bool flag1;
  int value2;
  uint8_t *uptr3;
  int local_204;
  uint8_t local_200 [64];
  uint8_t local_1c0 [64];
  uint8_t local_180 [64];
  uint8_t local_140 [64];
  uint8_t local_100 [64];
  uint8_t local_c0 [64];
  uint8_t local_80 [64];
  uint8_t local_40 [64];
  
                    /* Fills one personnel page employee panel and ability chart. */
  flag1 = false;
  local_204 = 0;
  if (arg3 == (int *)0x0) {
    uptr3 = local_200;
    value2 = 8;
    do {
      String_Format(uptr3,&DAT_005630d0,DAT_00582e4c);
      uptr3 = uptr3 + 0x40;
      value2 = value2 + -1;
    } while (value2 != 0);
  }
  else {
    String_Format(local_1c0,&DAT_005630d0,DAT_00582e04);
    String_Format(local_100,&DAT_005630d0,DAT_005824d4);
    String_Format(local_80,&DAT_005630d0,DAT_00580c78);
    value2 = Game_GetRecordField814Value(*arg3);
    String_Format(local_200,&DAT_005630d0,value2);
    String_Format(local_180,&DAT_005686f4,*(uint32_t *)(*arg3 + 0x38));
    String_Format(local_140,&DAT_005630d0,
                  *(uint32_t *)(&DAT_005832a8 + (uint32_t)*(uint8_t *)(*arg3 + 0x824) * 4));
    value2 = Rating_GetComposite(*arg3);
    String_Format(local_c0,&DAT_005686f4,value2);
    String_Format(local_40,&DAT_005686f4,*(uint32_t *)(*arg3 + 0x3c));
    if (*arg3 != 0) {
      flag1 = true;
      local_204 = 1;
    }
  }
  switch(arg2) {
  case 0:
    UI_SetChildVisibleByID(arg1,0x1f54,local_204);
    if (flag1) {
      UI_ComposeOverlayWindowFromRecord(arg1,0x1f54,*arg3);
      Array_SetField14ByKey(arg1,0x1f54,1);
    }
    else {
      UI_RemoveObjectByKey(arg1,0x52f);
      UI_RemoveObjectByKey(arg1,0x58b);
      UI_RemoveObjectByKey(arg1,0x58c);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x534,local_200);
    Window_GadgetNotify_Text_SetText(arg1,0x535,local_1c0);
    Window_GadgetNotify_Text_SetText(arg1,0x537,local_180);
    Window_GadgetNotify_Text_SetText(arg1,0x536,local_140);
    Window_GadgetNotify_Text_SetText(arg1,0x530,local_100);
    Window_GadgetNotify_Text_SetText(arg1,0x533,local_c0);
    Window_GadgetNotify_Text_SetText(arg1,0x531,local_80);
    Window_GadgetNotify_Text_SetText(arg1,0x532,local_40);
    Personnel_DrawEmployeeAbilityChart(arg1,arg3,0x584,1.98844e-42,1.98984e-42);
    return;
  case 1:
    UI_SetChildVisibleByID(arg1,0x1f55,local_204);
    if (flag1) {
      UI_ComposeOverlayWindowFromRecord(arg1,0x1f55,*arg3);
      Array_SetField14ByKey(arg1,0x1f55,1);
    }
    else {
      UI_RemoveObjectByKey(arg1,0x538);
      UI_RemoveObjectByKey(arg1,0x58d);
      UI_RemoveObjectByKey(arg1,0x58e);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x53d,local_200);
    Window_GadgetNotify_Text_SetText(arg1,0x53e,local_1c0);
    Window_GadgetNotify_Text_SetText(arg1,0x540,local_180);
    Window_GadgetNotify_Text_SetText(arg1,0x53f,local_140);
    Window_GadgetNotify_Text_SetText(arg1,0x539,local_100);
    Window_GadgetNotify_Text_SetText(arg1,0x53c,local_c0);
    Window_GadgetNotify_Text_SetText(arg1,0x53a,local_80);
    Window_GadgetNotify_Text_SetText(arg1,0x53b,local_40);
    Personnel_DrawEmployeeAbilityChart(arg1,arg3,0x585,1.99125e-42,1.99265e-42);
    return;
  case 2:
    UI_SetChildVisibleByID(arg1,0x1f57,local_204);
    if (flag1) {
      UI_ComposeOverlayWindowFromRecord(arg1,0x1f57,*arg3);
      Array_SetField14ByKey(arg1,0x1f57,1);
    }
    else {
      UI_RemoveObjectByKey(arg1,0x541);
      UI_RemoveObjectByKey(arg1,0x58f);
      UI_RemoveObjectByKey(arg1,0x591);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x546,local_200);
    Window_GadgetNotify_Text_SetText(arg1,0x547,local_1c0);
    Window_GadgetNotify_Text_SetText(arg1,0x549,local_180);
    Window_GadgetNotify_Text_SetText(arg1,0x548,local_140);
    Window_GadgetNotify_Text_SetText(arg1,0x542,local_100);
    Window_GadgetNotify_Text_SetText(arg1,0x545,local_c0);
    Window_GadgetNotify_Text_SetText(arg1,0x543,local_80);
    Window_GadgetNotify_Text_SetText(arg1,0x544,local_40);
    Personnel_DrawEmployeeAbilityChart(arg1,arg3,0x587,1.99405e-42,1.99685e-42);
    return;
  case 3:
    UI_SetChildVisibleByID(arg1,0x1f56,local_204);
    if (flag1) {
      UI_ComposeOverlayWindowFromRecord(arg1,0x1f56,*arg3);
      Array_SetField14ByKey(arg1,0x1f56,1);
    }
    else {
      UI_RemoveObjectByKey(arg1,0x54a);
      UI_RemoveObjectByKey(arg1,0x590);
      UI_RemoveObjectByKey(arg1,0x592);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x54f,local_200);
    Window_GadgetNotify_Text_SetText(arg1,0x550,local_1c0);
    Window_GadgetNotify_Text_SetText(arg1,0x552,local_180);
    Window_GadgetNotify_Text_SetText(arg1,0x551,local_140);
    Window_GadgetNotify_Text_SetText(arg1,0x54b,local_100);
    Window_GadgetNotify_Text_SetText(arg1,0x54e,local_c0);
    Window_GadgetNotify_Text_SetText(arg1,0x54c,local_80);
    Window_GadgetNotify_Text_SetText(arg1,0x54d,local_40);
    Personnel_DrawEmployeeAbilityChart(arg1,arg3,0x586,1.99545e-42,1.99825e-42);
    return;
  case 4:
    UI_SetChildVisibleByID(arg1,0x1f59,local_204);
    if (flag1) {
      UI_ComposeOverlayWindowFromRecord(arg1,0x1f59,*arg3);
      Array_SetField14ByKey(arg1,0x1f59,1);
    }
    else {
      UI_RemoveObjectByKey(arg1,0x553);
      UI_RemoveObjectByKey(arg1,0x593);
      UI_RemoveObjectByKey(arg1,0x595);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x558,local_200);
    Window_GadgetNotify_Text_SetText(arg1,0x559,local_1c0);
    Window_GadgetNotify_Text_SetText(arg1,0x55b,local_180);
    Window_GadgetNotify_Text_SetText(arg1,0x55a,local_140);
    Window_GadgetNotify_Text_SetText(arg1,0x554,local_100);
    Window_GadgetNotify_Text_SetText(arg1,0x557,local_c0);
    Window_GadgetNotify_Text_SetText(arg1,0x555,local_80);
    Window_GadgetNotify_Text_SetText(arg1,0x556,local_40);
    Personnel_DrawEmployeeAbilityChart(arg1,arg3,0x58a,1.99965e-42,2.00246e-42);
    return;
  case 5:
    UI_SetChildVisibleByID(arg1,0x1f58,local_204);
    if (flag1) {
      UI_ComposeOverlayWindowFromRecord(arg1,0x1f58,*arg3);
      Array_SetField14ByKey(arg1,0x1f58,1);
    }
    else {
      UI_RemoveObjectByKey(arg1,0x55c);
      UI_RemoveObjectByKey(arg1,0x594);
      UI_RemoveObjectByKey(arg1,0x596);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x561,local_200);
    Window_GadgetNotify_Text_SetText(arg1,0x562,local_1c0);
    Window_GadgetNotify_Text_SetText(arg1,0x564,local_180);
    Window_GadgetNotify_Text_SetText(arg1,0x563,local_140);
    Window_GadgetNotify_Text_SetText(arg1,0x55d,local_100);
    Window_GadgetNotify_Text_SetText(arg1,0x560,local_c0);
    Window_GadgetNotify_Text_SetText(arg1,0x55e,local_80);
    Window_GadgetNotify_Text_SetText(arg1,0x55f,local_40);
    Personnel_DrawEmployeeAbilityChart(arg1,arg3,0x589,2.00105e-42,2.00386e-42);
    return;
  case 6:
    UI_SetChildVisibleByID(arg1,0x1f5a,local_204);
    if (flag1) {
      UI_ComposeOverlayWindowFromRecord(arg1,0x1f5a,*arg3);
      Array_SetField14ByKey(arg1,0x1f5a,1);
    }
    else {
      UI_RemoveObjectByKey(arg1,0x565);
      UI_RemoveObjectByKey(arg1,0x597);
      UI_RemoveObjectByKey(arg1,0x598);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x56a,local_200);
    Window_GadgetNotify_Text_SetText(arg1,0x56b,local_1c0);
    Window_GadgetNotify_Text_SetText(arg1,0x56d,local_180);
    Window_GadgetNotify_Text_SetText(arg1,0x56c,local_140);
    Window_GadgetNotify_Text_SetText(arg1,0x566,local_100);
    Window_GadgetNotify_Text_SetText(arg1,0x569,local_c0);
    Window_GadgetNotify_Text_SetText(arg1,0x567,local_80);
    Window_GadgetNotify_Text_SetText(arg1,0x568,local_40);
    Personnel_DrawEmployeeAbilityChart(arg1,arg3,0x588,2.00526e-42,2.00666e-42);
  }
  return;
}
