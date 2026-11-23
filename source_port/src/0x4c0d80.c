// BranchStoragePanel_Update: ported from Pizza Connection 2 at 0x4c0d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c0d80
#include "pc2_port.h"

void __cdecl BranchStoragePanel_Update(void *arg1)

{
  void *self;
  void *this_00;
  int value1;
  int *ptr2;
  int value3;
  void *pvVar4;
  int value5;
  double fVar6;
  int64_t lvalue7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  float local_c;
  
                    /* Fills a branch's storage/supplier card. */
  self = arg1;
  value3 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  local_c = 0.0;
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4)
                                 ,(int *)0x0);
  value5 = 0;
  do {
    value1 = Array_GetStride60(this_00,value5);
    fVar6 = BuildingValue_Compute(value3,this_00,value1);
    if ((double)local_c < fVar6) {
      local_c = (float)fVar6;
    }
    value5 = value5 + 1;
  } while (value5 < 5);
  DAT_0057d714 = *(int *)(DAT_0057d718 + 0x30);
  ptr2 = (int *)Array_GetStride60(this_00,DAT_0057d714);
  BuildingValue_Compute(value3,this_00,(intptr_t)ptr2);
  if (ptr2 == (int *)0x0) {
    Window_GadgetNotify_Text_SetText(arg1,0x1f41,DAT_00581a2c);
    Window_GadgetNotify_Slider_SetValue(arg1,0x54e,0,0);
    uvalue9 = 0;
    uvalue8 = 0;
  }
  else {
    Window_GadgetNotify_Text_SetText(arg1,0x1f41,ptr2 + 0x11);
    Window_GadgetNotify_Slider_SetValue(arg1,0x54e,*ptr2 / 10,0);
    uvalue9 = 0;
    lvalue7 = __ftol();
    uvalue8 = (uint32_t)lvalue7;
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x54f,uvalue8,uvalue9);
  value3 = Get_Field2C(DAT_0057d718);
  if (value3 == 0) {
    pvVar4 = (void *)0x21;
    arg1 = (void *)0x1e;
  }
  else if (value3 == 1) {
    pvVar4 = (void *)0x42;
    arg1 = (void *)0x3c;
  }
  else if (value3 == 2) {
    arg1 = (void *)0x5f;
    pvVar4 = (void *)0x64;
  }
  else {
    pvVar4 = arg1;
  }
  value3 = Stats_GetAverageRecordValue(DAT_0057d718);
  value5 = Storage_GetFillPercent(DAT_0057d718);
  Window_GadgetNotify_Slider_SetValue(self,0x544,pvVar4,0);
  Window_GadgetNotify_Slider_SetValue(self,0x545,arg1,0);
  Window_GadgetNotify_Slider_SetValue(self,0x548,value3,0);
  Window_GadgetNotify_Slider_SetValue(self,0x549,value5,0);
  if (DAT_0057d718 != 0) {
    value5 = Get_Subobject4(DAT_0057d718);
    Gadget_SetText(self,0x53c,value5);
  }
  if (*(char *)(DAT_0057d718 + 0x3c) == '\0') {
    UI_ShowChildByID(self,0x53f);
    uvalue8 = *(uint32_t *)(DAT_0057d718 + 0x40);
  }
  else {
    UI_RemoveObjectByKey(self,0x53f);
    value5 = *(int *)(DAT_0057d718 + 0x34);
    value1 = Get_Field2C(DAT_0057d718);
    lvalue7 = Building_ComputeOperatingRevenue(this_00,value5,value1);
    uvalue8 = (uint32_t)lvalue7;
  }
  Gadget_SetTextf(self,0x540,&DAT_005683a4,uvalue8);
  value5 = 0;
  do {
    if (ptr2 == (int *)0x0) {
      value1 = 0;
    }
    else {
      value1 = Game_GetRatingPercent(DAT_0057c670,value5,value3);
    }
    Rating_UpdateBarByKey(self,0x23af,value5,value1,DAT_00581048);
    value5 = value5 + 1;
  } while (value5 < 8);
  return;
}
