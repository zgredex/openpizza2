// BranchStorageDistribution_Update: ported from Pizza Connection 2 at 0x4c1c00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c1c00
#include "pc2_port.h"

void __cdecl BranchStorageDistribution_Update(void *arg1)

{
  uint32_t *uptr1;
  int value2;
  void *self;
  int value3;
  int value4;
  uint32_t uvalue5;
  int value6;
  int64_t lvalue7;
  
                    /* Fills the storage distribution page and branch shares. */
  value2 = Get_Subobject4(DAT_0057d724);
  Gadget_SetText(arg1,0x1fed,value2);
  uptr1 = *(uint32_t **)
            (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x15c);
  Game_ResizeGlobalArray2(uptr1);
  value2 = 0x4b0;
  do {
    UI_ShowChildByID(arg1,value2 + -0x7a);
    UI_ShowChildByID(arg1,value2);
    UI_ShowChildByID(arg1,value2 + 100);
    value3 = value2 + -0x4af;
    value2 = value2 + 1;
  } while (value3 < 8);
  UI_ShowChildByID(arg1,0x435);
  if (uptr1 == (uint32_t *)0x0) {
    value2 = 0x4b0;
    do {
      UI_RemoveObjectByKey(arg1,value2 + -0x7a);
      UI_RemoveObjectByKey(arg1,value2);
      UI_RemoveObjectByKey(arg1,value2 + 100);
      value3 = value2 + -0x4af;
      value2 = value2 + 1;
    } while (value3 < 8);
    UI_RemoveObjectByKey(arg1,0x435);
  }
  else {
    if ((intptr_t)uptr1 < 9) {
      UI_RemoveObjectByKey(arg1,0x435);
      value2 = 8 - (intptr_t)uptr1;
      if (0 < value2) {
        value3 = 0x4b7;
        do {
          UI_RemoveObjectByKey(arg1,value3 + 100);
          UI_RemoveObjectByKey(arg1,value3);
          UI_RemoveObjectByKey(arg1,value3 + -0x7a);
          value3 = value3 + -1;
          value2 = value2 + -1;
        } while (value2 != 0);
      }
    }
    else {
      DAT_0057d720 = 0;
      Window_GadgetNotify_Slider_SetRange(arg1,0x435,0,((intptr_t)uptr1 * 5 + -0x28) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(arg1,0x435,DAT_0057d720 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x435,1);
    }
    DeliveryMenu_FillProductRows(arg1,DAT_0057d720);
  }
  if (*(char *)(DAT_0057d724 + 0x3c) == '\0') {
    UI_ShowChildByID(arg1,0x1fef);
    UI_ShowChildByID(arg1,0x1ff0);
    Gadget_SetTextf(arg1,0x1ff0,&DAT_005683a4,*(uint32_t *)(DAT_0057d724 + 0x40));
  }
  else {
    UI_RemoveObjectByKey(arg1,0x1fef);
    UI_RemoveObjectByKey(arg1,0x1ff0);
  }
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                              *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x218) + 0x28),(int *)0x0);
  value2 = Array_GetStride60(self,*(int *)(DAT_0057d724 + 0x30));
  value3 = Stats_GetAverageRecordValue(DAT_0057d724);
  value6 = 0;
  do {
    if (value2 == 0) {
      value4 = 0;
    }
    else {
      value4 = Game_GetRatingPercent(DAT_0057c670,value6,value3);
    }
    Rating_UpdateBarByKey(arg1,0x1fc8,value6,value4,DAT_00581048);
    value6 = value6 + 1;
  } while (value6 < 8);
  if (*(char *)(DAT_0057d724 + 0x3c) == '\0') {
    UI_ShowChildByID(arg1,0x1fef);
    uvalue5 = *(uint32_t *)(DAT_0057d724 + 0x40);
  }
  else {
    UI_RemoveObjectByKey(arg1,0x1fef);
    value2 = *(int *)(DAT_0057d724 + 0x34);
    value3 = Get_Field2C(DAT_0057d724);
    lvalue7 = Building_ComputeOperatingRevenue(self,value2,value3);
    uvalue5 = (uint32_t)lvalue7;
  }
  Gadget_SetTextf(arg1,0x1ff0,&DAT_005683a4,uvalue5);
  return;
}
