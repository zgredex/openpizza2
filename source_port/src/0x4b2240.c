// StatisticsPersonnel_UpdateWindow: ported from Pizza Connection 2 at 0x4b2240.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b2240
#include "pc2_port.h"


void __cdecl StatisticsPersonnel_UpdateWindow(void *arg1)

{
  uint32_t uvalue1;
  void *self;
  int value2;
  int value3;
  int local_24;
  uint8_t local_20 [32];
  
                    /* Refreshes the personnel statistics window. */
  local_24 = 0;
  UI_SetPosition(arg1,&LAB_004b0d20,0);
  if (DAT_0057d690 != 0) {
    UI_ReleaseRefCount(DAT_0057c5e0,DAT_0057d690);
  }
  DAT_0057d690 = UI_LoadFontByName(DAT_0057c5e0,s_VERDANA10_fnt_00563e64);
  DAT_0057d68c = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  DAT_0057d688 = 0;
  Window_GadgetNotify_Text_SetText(arg1,0x1389,DAT_00582d28);
  uvalue1 = 500;
  value3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value3 + 0xe0) == 0) {
    if (*(int *)(value3 + 0x1c4) != 0) {
      uvalue1 = 0x2ee;
    }
  }
  else {
    uvalue1 = 0;
  }
  String_Format(local_20,DAT_00581eb8,uvalue1);
  Gadget_SetText(arg1,0x485,local_20);
  String_Format(local_20,(uint8_t *)s___d___00568730,0x32);
  Gadget_SetText(arg1,0x484,local_20);
  value3 = 6000;
  do {
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,value3,1);
    value3 = value3 + 1;
  } while (value3 < 0x178c);
  self = *(void **)(DAT_0057c670 + 0x9c);
  if (self != (void *)0x0) {
    DAT_0056a6d8 = *(int *)((intptr_t)self + 0x3c);
  }
  if (DAT_0056a6d8 == -1) {
    if (0 < *(int *)(DAT_0057d68c + 0x15c)) {
LAB_004b23a2:
      DAT_0056a6d8 = 0;
      self = (void *)IDMap_Lookup((void *)(DAT_0057d68c + 0x148),0,(int *)0x0);
    }
    if (self != (void *)0x0) goto LAB_004b23bb;
LAB_004b23e5:
    Gadget_SetText(arg1,0x1f5f,DAT_00581328);
  }
  else {
    self = (void *)IDMap_Lookup((void *)(DAT_0057d68c + 0x148),DAT_0056a6d8,(int *)0x0);
    if (self == (void *)0x0) {
      if (0 < *(int *)(DAT_0057d68c + 0x15c)) goto LAB_004b23a2;
      goto LAB_004b23e5;
    }
LAB_004b23bb:
    local_24 = Game_CountObjectsByType(self,0xffffffff);
    Gadget_SetText(arg1,0x1f5f,(intptr_t)self + 4);
    if (0 < local_24) {
      value3 = 1;
      goto LAB_004b23fa;
    }
  }
  value3 = 0;
LAB_004b23fa:
  UI_SetChildVisibleByID(arg1,0x44f,value3);
  UI_SetChildVisibleByID(arg1,0x450,value3);
  UI_SetChildVisibleByID(arg1,0x52c,value3);
  UI_SetChildVisibleByID(arg1,0x52e,value3);
  UI_SetChildVisibleByID(arg1,0x52d,value3);
  UI_SetChildVisibleByID(arg1,0x527,value3);
  UI_SetChildVisibleByID(arg1,0x52a,value3);
  UI_SetChildVisibleByID(arg1,0x528,value3);
  UI_SetChildVisibleByID(arg1,0x529,value3);
  UI_SetChildVisibleByID(arg1,0x451,value3);
  UI_SetChildVisibleByID(arg1,0x47f,value3);
  UI_SetChildVisibleByID(arg1,0x52f,value3);
  UI_SetChildVisibleByID(arg1,0x538,value3);
  UI_SetChildVisibleByID(arg1,0x541,value3);
  UI_SetChildVisibleByID(arg1,0x54a,value3);
  UI_SetChildVisibleByID(arg1,0x553,value3);
  UI_SetChildVisibleByID(arg1,0x55c,value3);
  UI_SetChildVisibleByID(arg1,0x565,value3);
  value2 = 0x178c;
  do {
    UI_RemoveObjectByKey(arg1,value2);
    value2 = value2 + 1;
  } while (value2 < 0x1794);
  value2 = 0x57d;
  do {
    Array_SetField14ByKey(arg1,value2,0);
    value2 = value2 + 1;
  } while (value2 < 0x584);
  UI_RemoveObjectByKey(arg1,5000);
  UI_RemoveObjectByKey(arg1,0x1389);
  UI_SetChildVisibleByID(arg1,0x1f53,value3);
  if (local_24 != 0) {
    if ((DAT_0056a6d0 == -1) ||
       (value3 = IDMap_Lookup((void *)((intptr_t)self + 0x1500),DAT_0056a6d0,(int *)0x0), value3 == 0)) {
      DAT_0056a6d0 = 0;
    }
    if (local_24 < 8) {
      UI_RemoveObjectByKey(arg1,0x451);
      for (; local_24 < 7; local_24 = local_24 + 1) {
        PersonnelPage_UpdateEmployeePanel(arg1,local_24,(int *)0x0);
        UI_RemoveObjectByKey(arg1,local_24 + 0x1794);
      }
    }
    else {
      if (-1 < DAT_0056a6d0) {
        DAT_0057d688 = DAT_0056a6d0;
      }
      if (local_24 < DAT_0057d688 + 7) {
        DAT_0057d688 = local_24 + -7;
      }
      Window_GadgetNotify_Slider_SetRange(arg1,0x451,0,(local_24 * 5 + -0x23) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(arg1,0x451,DAT_0057d688 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x451,1);
    }
    PersonnelPlan_LayoutEmployeeList(arg1,DAT_0057d688,DAT_0057d68c,DAT_0056a6d8,DAT_0056a6d0);
    Personnel_UpdateEmployeeRows(arg1);
    PersonnelPlan_UpdateEmployeeDetail(arg1,DAT_0057d68c,DAT_0056a6d8,'\x01',DAT_0056a6d0);
    value3 = 0;
    do {
      value2 = Stats_GetAverage8(self,value3);
      Rating_UpdateBarByKey(arg1,0x518,value3,value2,DAT_005826d8);
      value3 = value3 + 1;
    } while (value3 < 8);
    value3 = *(int *)(DAT_0057d68c + 0x48);
    value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x34),(int *)0x0);
    if (*(int *)(value2 + 0xc20 + value3 * 4) < 2) {
      UI_RemoveObjectByKey(arg1,5000);
      UI_RemoveObjectByKey(arg1,0x1389);
      UI_RemoveObjectByKey(arg1,0x480);
      UI_RemoveObjectByKey(arg1,0x483);
      UI_RemoveObjectByKey(arg1,0x484);
      UI_RemoveObjectByKey(arg1,0x485);
    }
    return;
  }
  value3 = 51000;
  do {
    value2 = Array_GetRecordByKeyPtr(arg1,value3 + -1000);
    if (value2 != 0) {
      UI_RemoveObject(arg1,value3 + -1000);
    }
    value2 = Array_GetRecordByKeyPtr(arg1,value3);
    if (value2 != 0) {
      UI_RemoveObject(arg1,value3);
    }
    value2 = value3 + -50999;
    value3 = value3 + 1;
  } while (value2 < 7);
  value3 = 6000;
  do {
    UI_RemoveObjectByKey(arg1,value3);
    value3 = value3 + 1;
  } while (value3 < 0x178c);
  value3 = 0x1794;
  do {
    UI_RemoveObjectByKey(arg1,value3);
    value3 = value3 + 1;
  } while (value3 < 0x179b);
  Window_GadgetNotify_Slider_SetRange(arg1,0x453,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x455,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x457,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x459,0,100,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x453,0,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x455,0,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x457,0,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x459,0,0);
  DAT_0056a6d0 = 0xffffffff;
  Window_GadgetNotify_Text_SetText(arg1,0x472,DAT_00581b30);
  Window_GadgetNotify_Text_SetText(arg1,0x578,DAT_00581b30);
  value3 = 0;
  do {
    PersonnelPage_UpdateEmployeePanel(arg1,value3,(int *)0x0);
    value3 = value3 + 1;
  } while (value3 < 7);
  value3 = 0;
  do {
    Rating_UpdateBarByKey(arg1,0x518,value3,0,0);
    value3 = value3 + 1;
  } while (value3 < 8);
  return;
}
