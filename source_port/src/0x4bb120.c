// StarAward_Fill: ported from Pizza Connection 2 at 0x4bb120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bb120
#include "pc2_port.h"

void __cdecl StarAward_Fill(void *arg1,char arg2)

{
  void *self;
  int value1;
  int value2;
  void *this_00;
  int value3;
  int value4;
  uint32_t extraout_EDX;
  uint32_t unaff_EDI;
  uint32_t uvalue5;
  char *cptr6;
  
                    /* Evaluates and fills the mayor's star award page. */
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                              (int *)0x0);
  value4 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                  0x48);
  value1 = Game_GetMostAdvancedCompany((intptr_t)self);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (value1 == value2) {
    if (arg2 == '\0') goto LAB_004bb1a6;
    uvalue5 = 0xe;
  }
  else if (*(int *)((intptr_t)self + value4 * 4 + 0xcc8) < 0x28) {
    if (arg2 == '\0') goto LAB_004bb1a6;
    uvalue5 = 0xd;
  }
  else {
    if (arg2 == '\0') goto LAB_004bb1a6;
    uvalue5 = 0;
  }
  Sound_ProcessEvent(DAT_0057ba0c,0x18,uvalue5,'\x01');
LAB_004bb1a6:
  value1 = Game_GetPlayerBySlot(DAT_0057c670,value1);
  if (value1 == 0) {
    value2 = DAT_00582adc;
  }
  else {
    value2 = value1 + 8;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x1fc9,value2);
  Personnel_SetEmployeePhotoByKey(arg1,0x1ff3,value1);
  Gadget_SetTextf(arg1,0x1fd3,&DAT_005683a4,*(uint32_t *)((intptr_t)self + value4 * 4 + 0xdac));
  value1 = *(int *)((intptr_t)self + value4 * 4 + 0xcc8);
  value2 = 0x3c - value1;
  if (value2 / 2 < 0) {
    cptr6 = s__d____00568834;
  }
  else {
    cptr6 = s___d____005692f8;
  }
  Gadget_SetTextf(arg1,0x1fac,(uint8_t *)cptr6,value2 / 2);
  Gadget_SetTextf(arg1,0x1fb0,&DAT_005686f4,((intptr_t)(value2 + (value2 >> 0x1f & 7U)) >> 3) + 0x4b);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1fa8,value1,0);
  value1 = *(int *)((intptr_t)DAT_0057c670 + 0x21c);
  if (*(int *)(value1 + 0xa4) == 0xc) {
    UI_ShowChildByID(arg1,0x1fd6);
    UI_ShowChildByID(arg1,0x1fd9);
    UI_ShowChildByID(arg1,0x1fda);
    UI_ShowChildByID(arg1,0x1fdd);
    UI_ShowChildByID(arg1,0x1fde);
    value1 = *(int *)(value1 + 0xfc);
    value2 = *(int *)(value1 + 0x2c);
    value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value1 + 8));
    this_00 = (void *)IDMap_Lookup((void *)(value1 + 0x148),value2,(int *)0x0);
    if (this_00 == (void *)0x0) {
      Gadget_SetTextf(arg1,0x1fd7,&DAT_00568310,unaff_EDI);
      Window_GadgetNotify_Text_SetText(arg1,0x1fda,&DAT_00579aec);
      value1 = 0;
    }
    else {
      Gadget_SetTextf(arg1,0x1fd7,(uint8_t *)((intptr_t)this_00 + 4),unaff_EDI);
      Window_GadgetNotify_Text_SetText(arg1,0x1fda,DAT_005829ac);
      value1 = Stats_GetAverage8(this_00,5);
      value2 = Branch_ComputeBuildingRating(this_00,extraout_EDX,5);
      value3 = Branch_GetMenuRating(this_00,5);
      value1 = (value3 + value1 + value2) / 3;
    }
    Gadget_SetTextf(arg1,0x1fde,&DAT_005686f4,value1);
  }
  else {
    Window_GadgetNotify_Text_SetText(arg1,0x1fd7,DAT_00580b7c);
    UI_RemoveObjectByKey(arg1,0x1fd6);
    UI_RemoveObjectByKey(arg1,0x1fd9);
    UI_RemoveObjectByKey(arg1,0x1fda);
    UI_RemoveObjectByKey(arg1,0x1fdd);
    UI_RemoveObjectByKey(arg1,0x1fde);
  }
  value1 = Stats_SumSixSlotValues(self,0,value4);
  Gadget_SetTextf(arg1,0x1ff1,&DAT_005686f4,value1);
  value1 = Stats_SumSixSlotValues(self,0,-1);
  Gadget_SetTextf(arg1,0x1ff2,&DAT_005686f4,value1);
  value1 = Stats_SumSixSlotValues(self,1,value4);
  Gadget_SetTextf(arg1,0x1fe3,&DAT_005686f4,value1);
  value1 = Stats_SumSixSlotValues(self,1,-1);
  Gadget_SetTextf(arg1,0x1fe4,&DAT_005686f4,value1);
  value1 = Stats_SumSixSlotValues(self,2,value4);
  Gadget_SetTextf(arg1,0x1fe6,&DAT_005686f4,value1);
  value1 = Stats_SumSixSlotValues(self,2,-1);
  Gadget_SetTextf(arg1,0x1fe7,&DAT_005686f4,value1);
  value4 = Stats_SumSixSlotValues(self,3,value4);
  Gadget_SetTextf(arg1,0x1fe9,&DAT_005686f4,value4);
  value4 = Stats_SumSixSlotValues(self,3,-1);
  Gadget_SetTextf(arg1,0x1fea,&DAT_005686f4,value4);
  return;
}
