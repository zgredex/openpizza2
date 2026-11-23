// Window_UpdateStaffPlanPage: ported from Pizza Connection 2 at 0x493110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x493110
#include "pc2_port.h"


void __cdecl Window_UpdateStaffPlanPage(void *arg1,char arg2,char arg3)

{
  uint32_t uvalue1;
  uint8_t flag2;
  uint32_t extraout_var;
  int value3;
  int *ptr4;
  uint32_t uvalue5;
  int value6;
  int value7;
  uint8_t local_20 [32];
  
                    /* Updates the staff-plan page for the selected branch. */
  value6 = *(int *)(DAT_0057c670 + 0x21c);
  if ((value6 != 0) && (arg3 != '\0')) {
    flag2 = Game_GetObjectStatusLevel(value6);
    Sound_ProcessEvent(DAT_0057ba0c,*(int *)(value6 + 0x30),CONCAT31(extraout_var,flag2),
                       *(int *)(value6 + 0x24) == 0);
  }
  DAT_0057c6d0 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  Window_GadgetNotify_Text_SetText(arg1,0x1389,DAT_00582d28);
  value6 = 6000;
  do {
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,value6,1);
    value6 = value6 + 1;
  } while (value6 < 0x178c);
  if (arg2 == '\0') {
    _param_3 = *(void **)(DAT_0057c670 + 0x9c);
  }
  else {
    value6 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),
                         *(int *)(*(int *)(DAT_0057c670 + 0x21c) + 0x50),(int *)0x0);
    _param_3 = (void *)0x0;
    if (value6 == 0) goto LAB_00493269;
    _param_3 = (void *)IDMap_Lookup((void *)(DAT_0057c6d0 + 0x148),*(int *)(value6 + 0x820),
                                    (int *)0x0);
    if (_param_3 == (void *)0x0) {
      _param_3 = *(void **)(DAT_0057c670 + 0x9c);
    }
    value7 = 0;
    value3 = Game_CountObjectsByType(_param_3,0xffffffff);
    if (0 < value3) {
      do {
        ptr4 = (int *)IDMap_Lookup((void *)((intptr_t)_param_3 + 0x1500),value7,(int *)0x0);
        if (*ptr4 == value6) {
          DAT_0056872c = value7;
        }
        value7 = value7 + 1;
        value3 = Game_CountObjectsByType(_param_3,0xffffffff);
      } while (value7 < value3);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x1f41,(intptr_t)_param_3 + 4);
  }
  if (_param_3 != (void *)0x0) {
    DAT_00568728 = *(int *)((intptr_t)_param_3 + 0x3c);
  }
LAB_00493269:
  value3 = Game_CountObjectsByType(_param_3,0xffffffff);
  uvalue1 = (uint32_t)(0 < value3);
  UI_SetChildVisibleByID(arg1,0x44f,uvalue1);
  UI_SetChildVisibleByID(arg1,0x450,uvalue1);
  UI_SetChildVisibleByID(arg1,0x52c,uvalue1);
  UI_SetChildVisibleByID(arg1,0x52e,uvalue1);
  UI_SetChildVisibleByID(arg1,0x52d,uvalue1);
  UI_SetChildVisibleByID(arg1,0x527,uvalue1);
  UI_SetChildVisibleByID(arg1,0x52a,uvalue1);
  UI_SetChildVisibleByID(arg1,0x528,uvalue1);
  UI_SetChildVisibleByID(arg1,0x529,uvalue1);
  UI_SetChildVisibleByID(arg1,0x451,uvalue1);
  UI_SetChildVisibleByID(arg1,0x47f,uvalue1);
  UI_SetChildVisibleByID(arg1,0x52f,uvalue1);
  UI_SetChildVisibleByID(arg1,0x538,uvalue1);
  UI_SetChildVisibleByID(arg1,0x541,uvalue1);
  UI_SetChildVisibleByID(arg1,0x54a,uvalue1);
  UI_SetChildVisibleByID(arg1,0x553,uvalue1);
  UI_SetChildVisibleByID(arg1,0x55c,uvalue1);
  UI_SetChildVisibleByID(arg1,0x565,uvalue1);
  uvalue5 = 500;
  value6 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value6 + 0xe0) == 0) {
    if (*(int *)(value6 + 0x1c4) != 0) {
      uvalue5 = 0x2ee;
    }
  }
  else {
    uvalue5 = 0;
  }
  String_Format(local_20,DAT_00581eb8,uvalue5);
  Gadget_SetText(arg1,0x485,local_20);
  String_Format(local_20,(uint8_t *)s___d___00568730,0x32);
  Gadget_SetText(arg1,0x484,local_20);
  value6 = 0x178c;
  do {
    UI_RemoveObjectByKey(arg1,value6);
    value6 = value6 + 1;
  } while (value6 < 0x1794);
  UI_RemoveObjectByKey(arg1,5000);
  UI_RemoveObjectByKey(arg1,0x1389);
  UI_SetChildVisibleByID(arg1,0x2332,(uint32_t)(0 < value3));
  if (value3 == 0) {
    value6 = 51000;
    do {
      value3 = Array_GetRecordByKeyPtr(arg1,value6 + -1000);
      if (value3 != 0) {
        UI_RemoveObject(arg1,value6 + -1000);
      }
      value3 = Array_GetRecordByKeyPtr(arg1,value6);
      if (value3 != 0) {
        UI_RemoveObject(arg1,value6);
      }
      value3 = value6 + -50999;
      value6 = value6 + 1;
    } while (value3 < 7);
    value6 = 6000;
    do {
      UI_RemoveObjectByKey(arg1,value6);
      value6 = value6 + 1;
    } while (value6 < 0x178c);
    value6 = 0x1794;
    do {
      UI_RemoveObjectByKey(arg1,value6);
      value6 = value6 + 1;
    } while (value6 < 0x179b);
    Window_GadgetNotify_Slider_SetValue(arg1,0x2329,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232b,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232d,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232f,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,9000,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232a,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232c,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232e,0,0);
    DAT_0056872c = 0xffffffff;
    Window_GadgetNotify_Text_SetText(arg1,0x52b,DAT_00582680);
    Window_GadgetNotify_Text_SetText(arg1,0x472,DAT_00581b30);
    value6 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x518,value6,0,0);
      value6 = value6 + 1;
    } while (value6 < 8);
    return;
  }
  if ((DAT_0056872c == -1) ||
     (value6 = IDMap_Lookup((void *)((intptr_t)_param_3 + 0x1500),DAT_0056872c,(int *)0x0), value6 == 0)) {
    DAT_0056872c = 0;
  }
  if (value3 < 8) {
    UI_RemoveObjectByKey(arg1,0x451);
    for (; value3 < 7; value3 = value3 + 1) {
      UI_RemoveObjectByKey(arg1,value3 + 0x1794);
    }
    DAT_0057c6d4 = 0;
  }
  else {
    if (value3 < DAT_0057c6d4 + 7) {
      DAT_0057c6d4 = value3 + -7;
    }
    if (DAT_0057c6d4 < 0) {
      DAT_0057c6d4 = 0;
    }
    Window_GadgetNotify_Slider_SetRange(arg1,0x451,0,(value3 * 5 + -0x23) * 0x14,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x451,DAT_0057c6d4 * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x451,1);
  }
  value6 = 0;
  PersonnelPlan_LayoutEmployeeList(arg1,DAT_0057c6d4,DAT_0057c6d0,DAT_00568728,DAT_0056872c);
  PersonnelPlan_UpdateEmployeeDetail(arg1,DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
  do {
    value3 = DAT_005826d8;
    value7 = Stats_GetAverage8(_param_3,value6);
    Rating_UpdateBarByKey(arg1,0x518,value6,value7,value3);
    value6 = value6 + 1;
  } while (value6 < 8);
  return;
}
