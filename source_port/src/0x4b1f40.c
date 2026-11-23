// PersonnelPlan_LayoutEmployeeList: ported from Pizza Connection 2 at 0x4b1f40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b1f40
#include "pc2_port.h"

void __cdecl
PersonnelPlan_LayoutEmployeeList(void *arg1,int arg2,int arg3,int arg4,int arg5)

{
  void *self;
  void *this_00;
  int value1;
  int *ptr2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t local_1c;
  uint32_t local_18;
  int local_14;
  void *local_10;
  int local_c;
  
                    /* Lays out the personnel-plan employee rows and sliders. */
  self = arg1;
  this_00 = (void *)IDMap_Lookup((void *)(arg3 + 0x148),arg4,(int *)0x0);
  if (this_00 == (void *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = Game_CountObjectsByType(this_00,0xffffffff);
  }
  value4 = 6000;
  do {
    UI_RemoveObjectByKey(arg1,value4);
    value4 = value4 + 1;
  } while (value4 < 0x178c);
  value4 = 51000;
  do {
    value1 = Array_GetRecordByKeyPtr(arg1,value4 + -1000);
    if (value1 != 0) {
      UI_RemoveObject(arg1,value4 + -1000);
    }
    value1 = Array_GetRecordByKeyPtr(arg1,value4);
    if (value1 != 0) {
      UI_RemoveObject(arg1,value4);
    }
    value1 = value4 + -50999;
    value4 = value4 + 1;
  } while (value1 < 7);
  if (local_14 < 8) {
    arg2 = 0;
  }
  else {
    local_14 = 7;
  }
  if (0 < local_14) {
    local_c = 0;
    arg1 = (void *)0x1770;
    value4 = 50000;
    do {
      value1 = arg2 + -50000 + value4;
      if (value1 == arg5) {
        UI_ShowChildByID(self,value1 + (0x1794 - arg2));
      }
      else {
        UI_RemoveObjectByKey(self,(0x1794 - arg2) + value1);
      }
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)this_00 + 0x1500),value1,(int *)0x0);
      uvalue5 = ptr2[1] + 1U & 7;
      Array_GetPairByKey(self,0x45a,&arg3,&arg4);
      arg4 = arg4 + 1 + local_c;
      arg3 = arg3 + 1 + uvalue5 * 0x14;
      switch(*(uint8_t *)(*ptr2 + 0x824)) {
      case 0:
        local_10 = (void *)((intptr_t)arg1 + 2);
        local_1c = UI_GetButtonSprite(self,0x1792);
        value1 = 0x1793;
        break;
      case 1:
        local_10 = arg1;
        local_1c = UI_GetButtonSprite(self,0x178c);
        value1 = 0x178d;
        break;
      case 2:
        local_10 = (void *)((intptr_t)arg1 + 1);
        local_1c = UI_GetButtonSprite(self,0x1790);
        value1 = 0x1791;
        break;
      case 3:
        local_10 = (void *)((intptr_t)arg1 + 3);
        local_1c = UI_GetButtonSprite(self,0x178e);
        value1 = 0x178f;
        break;
      default:
        goto switchD_004b20b3_default;
      }
      local_18 = UI_GetButtonSprite(self,value1);
switchD_004b20b3_default:
      UI_ShowChildByID(self,(intptr_t)local_10);
      Window_GadgetNotify_Slider_SetRange(self,(intptr_t)local_10,0,7,0);
      Window_GadgetNotify_Slider_SetValue(self,(intptr_t)local_10,uvalue5,0);
      if (uvalue5 == 0) {
        value1 = arg3 + 0x8c;
      }
      else {
        value1 = arg3 + -0x14;
      }
      UI_CreateMovieWindow(self,value4,value1,arg4,local_1c,0);
      value1 = value4 + 1000;
      if (uvalue5 < 7) {
        value3 = arg3 + 0x14;
      }
      else {
        value3 = arg3 + -0x8c;
      }
      UI_CreateMovieWindow(self,value1,value3,arg4,local_18,0);
      value3 = Get_FieldF0((intptr_t)self);
      UI_MoveElementToIndex(self,value4,value3 + -1);
      value3 = Get_FieldF0((intptr_t)self);
      UI_MoveElementToIndex(self,value1,value3 + -1);
      Array_SetField14ByKey(self,value4,0);
      Array_SetField14ByKey(self,value1,0);
      local_c = local_c + 10;
      arg1 = (void *)((intptr_t)arg1 + 4);
      value1 = value4 + -49999;
      value4 = value4 + 1;
    } while (value1 < local_14);
  }
  return;
}
