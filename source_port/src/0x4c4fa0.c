// CityInfo_InitQuarterPanel: ported from Pizza Connection 2 at 0x4c4fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c4fa0
#include "pc2_port.h"


void __cdecl CityInfo_InitQuarterPanel(void *arg1)

{
  uint8_t flag1;
  bool flag2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  int *ptr8;
  uint32_t local_48 [7];
  int local_2c [8];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Fills the city info quarter labels or traffic grid. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558b98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct(local_48,0);
  local_4 = 0;
  value3 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value3 = *(int *)(value3 + 0x10c0);
  flag1 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 7);
  uvalue7 = (uint32_t)*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8);
  value4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  uvalue5 = City_GetLocalizedName(value4);
  Window_GadgetNotify_Text_SetText(arg1,0x1f56,uvalue5);
  if (value3 < 1) {
    UI_RemoveObjectByKey(arg1,0x1f44);
    UI_RemoveObjectByKey(arg1,0x1f46);
    UI_RemoveObjectByKey(arg1,0x1f47);
    Window_GadgetNotify_Text_SetText(arg1,0x1f45,DAT_00581ae0);
    ptr8 = local_2c;
    for (value3 = 8; value3 != 0; value3 = value3 + -1) {
      *ptr8 = 0;
      ptr8 = ptr8 + 1;
    }
    value3 = 0;
    if (0 < *(int *)(DAT_0057c670 + 0x50)) {
      do {
        value4 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value3,(int *)0x0);
        flag2 = Object_IsState10(value4);
        if (flag2) {
          List_Add(local_48,value4);
          value4 = *(int *)(value4 + 0x30);
          if ((-1 < value4) && (value4 < 9)) {
            local_2c[value4] = local_2c[value4] + 1;
          }
        }
        value3 = value3 + 1;
      } while (value3 < *(int *)(DAT_0057c670 + 0x50));
    }
    CustomerGroups_DrawTrafficGrid(arg1,0x1f4a,local_2c);
  }
  else {
    value3 = (uint32_t)flag1 + value3;
    if (0x18 < value3) {
      uvalue6 = (value3 - 1U) / 0x18;
      value3 = value3 + uvalue6 * -0x18;
      do {
        uvalue7 = uvalue7 + 1;
        if (3 < (intptr_t)uvalue7) {
          uvalue7 = 0;
        }
        uvalue6 = uvalue6 - 1;
      } while (uvalue6 != 0);
    }
    UI_ShowChildByID(arg1,0x1f44);
    UI_ShowChildByID(arg1,0x1f46);
    UI_ShowChildByID(arg1,0x1f47);
    Gadget_SetTextf(arg1,0x1f45,(uint8_t *)s__d_Quarter__d_0056af2c,uvalue7 + 1);
    Gadget_SetTextf(arg1,0x1f47,(uint8_t *)s__02d_00_0056af24,value3);
  }
  local_4 = 0xffffffff;
  List_Node_Destroy(local_48);
  ExceptionList = local_c;
  return;
}
