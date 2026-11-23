// CompanyOverview_FillTotals: ported from Pizza Connection 2 at 0x4bd750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bd750
#include "pc2_port.h"

void __cdecl CompanyOverview_FillTotals(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int64_t lvalue6;
  uint32_t uvalue7;
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Fills the company-overview totals and statistics. */
  value5 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x218) + 8));
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x51b,value1 + 8);
    Personnel_SetEmployeePhotoByKey(arg1,0x2387,value1);
    value2 = Game_GetPlayerCity(value1);
    UI_ComposeOverlayWindowFromRecord(arg1,0x2386,*(int *)(value2 + 4));
    Window_GadgetNotify_Text_SetText(arg1,0x515,value2 + 0xc);
    value4 = *(int *)(value2 + 0xa0);
    if (0 < value4) {
      do {
        value3 = IDMap_Lookup((void *)(value2 + 0x8c),value5,(int *)0x0);
        value3 = *(int *)(value3 + 4);
        if (value3 == 0) {
          local_c = local_c + 1;
        }
        else if (value3 == 1) {
          local_8 = local_8 + 1;
        }
        else if (value3 == 2) {
          local_4 = local_4 + 1;
        }
        value5 = value5 + 1;
      } while (value5 < value4);
    }
    Gadget_SetTextf(arg1,0x236b,&DAT_005686f4,local_c);
    Gadget_SetTextf(arg1,0x236c,&DAT_005686f4,local_4);
    Gadget_SetTextf(arg1,0x236d,&DAT_005686f4,local_8);
    UI_PrintSignedValue(arg1,0x2348,*(int *)(value2 + 0x54) + *(int *)(value2 + 0x3c));
    UI_PrintSignedValue(arg1,0x2349,*(int *)(value2 + 0x58) + *(int *)(value2 + 0x40));
    UI_PrintSignedValue(arg1,0x234a,*(int *)(value2 + 0x5c) + *(int *)(value2 + 0x44));
    UI_PrintSignedValue(arg1,0x234b,*(int *)(value2 + 0x60) + *(int *)(value2 + 0x48));
    UI_PrintSignedValue(arg1,0x234c,*(int *)(value2 + 100) + *(int *)(value2 + 0x4c));
    UI_PrintSignedValue(arg1,0x234d,*(int *)(value2 + 0x68) + *(int *)(value2 + 0x50));
    Gadget_SetTextf(arg1,0x2379,&DAT_005686f4,*(uint32_t *)(value1 + 0x15c));
    Gadget_SetTextf(arg1,0x2389,&DAT_005686f4,*(uint32_t *)(value1 + 0x194));
    Stats_SumFilteredFloats3(value1,-1,-1,-1);
    lvalue6 = __ftol();
    Gadget_SetTextf(arg1,0x237a,&DAT_005683a4,(intptr_t)lvalue6);
    value1 = *(int *)(value1 + 0x48);
    value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    Gadget_SetTextf(arg1,0x2374,&DAT_005686f4,*(uint32_t *)(value5 + 0xc20 + value1 * 4));
    value5 = 0;
    self = *(void **)((intptr_t)DAT_0057c670 + 0x218);
    value1 = *(int *)((intptr_t)self + 0x8c);
    if (0 < value1) {
      do {
        value2 = Game_MapRecordToGlobal(self,value5);
        value4 = *(int *)(value2 + 0x110);
        value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
        if (value4 != value3) {
          value4 = *(int *)(value2 + 0x30);
          if (value4 == 0x17) {
            local_1c = local_1c + 1;
          }
          else if (value4 == 0x1d) {
            local_14 = local_14 + 1;
          }
          else if (value4 == 0x1e) {
            local_18 = local_18 + 1;
          }
        }
        value5 = value5 + 1;
      } while (value5 < value1);
    }
    Gadget_SetTextf(arg1,0x2380,&DAT_005686f4,local_1c);
    Gadget_SetTextf(arg1,0x2382,&DAT_005686f4,local_18);
    Gadget_SetTextf(arg1,0x2383,&DAT_005686f4,local_14);
    value1 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value5 = *(int *)(value1 + 0x48);
    value4 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value5 = *(int *)(value4 + 0xc20 + value5 * 4);
    if (*(void **)(value1 + 0x1d8) == (void *)0x0) {
      value4 = 0;
      uvalue7 = 0xff;
    }
    else {
      value4 = Game_CountFreeBuildingsByType(*(void **)(value1 + 0x1d8),0x1d);
      if (value4 == 0) {
        uvalue7 = 0xff;
      }
      else {
        uvalue7 = 0;
      }
    }
    Window_GadgetNotify_Text_SetTextColor(arg1,0x236f,uvalue7);
    Gadget_SetTextf(arg1,0x236f,&DAT_005686f4,value4);
    uvalue7 = 5000;
    value4 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(value4 + 0x134) == 0) {
      if (*(int *)(value4 + 0x98) == 0) {
        if ((*(int *)(value4 + 0x218) != 0) || (*(int *)(value4 + 0x17c) != 0)) {
          uvalue7 = 0x1d4c;
        }
      }
      else {
        uvalue7 = 0x9c4;
      }
    }
    else {
      uvalue7 = 0;
    }
    Gadget_SetTextf(arg1,0x235a,&DAT_0056a850,uvalue7);
    value4 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    value4 = Game_CountFilteredObjects(DAT_0057c670,6,0x1d,value4,value2);
    Gadget_SetTextf(arg1,0x235c,&DAT_005686f4,value4);
    value4 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    value4 = Game_CountFilteredObjects2(DAT_0057c670,6,0x1d,value4,value2);
    Gadget_SetTextf(arg1,0x2360,&DAT_005686f4,value4);
    if (*(void **)(value1 + 0x1d8) == (void *)0x0) {
      value1 = 0;
      uvalue7 = 0xff;
    }
    else {
      value1 = Game_CountFreeBuildingsByType(*(void **)(value1 + 0x1d8),0x1f);
      if (value1 == 0) {
        uvalue7 = 0xff;
      }
      else {
        uvalue7 = 0;
      }
    }
    Window_GadgetNotify_Text_SetTextColor(arg1,0x2372,uvalue7);
    Gadget_SetTextf(arg1,0x2372,&DAT_005686f4,value1);
    uvalue7 = 100000;
    value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(value1 + 0x158) == 0) {
      if (*(int *)(value1 + 0x23c) != 0) {
        uvalue7 = 150000;
      }
    }
    else {
      uvalue7 = 0;
    }
    Gadget_SetTextf(arg1,0x235e,&DAT_005683a4,uvalue7);
    value1 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
    value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    value1 = Game_CountFilteredObjects(DAT_0057c670,5,0x1f,value1,value4);
    Gadget_SetTextf(arg1,0x2362,&DAT_005686f4,value1);
    value1 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
    value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    value1 = Game_CountFilteredObjects2(DAT_0057c670,5,0x1f,value1,value4);
    Gadget_SetTextf(arg1,0x2364,&DAT_005686f4,value1);
    if (value5 < 5) {
      UI_RemoveObjectByKey(arg1,0x2357);
      UI_RemoveObjectByKey(arg1,0x236f);
      UI_RemoveObjectByKey(arg1,0x235a);
      UI_RemoveObjectByKey(arg1,0x235c);
      UI_RemoveObjectByKey(arg1,0x2360);
      UI_RemoveObjectByKey(arg1,0x236e);
      UI_RemoveObjectByKey(arg1,0x2359);
      UI_RemoveObjectByKey(arg1,0x235b);
      UI_RemoveObjectByKey(arg1,0x235f);
    }
    else {
      UI_ShowChildByID(arg1,0x2357);
      UI_ShowChildByID(arg1,0x236f);
      UI_ShowChildByID(arg1,0x235a);
      UI_ShowChildByID(arg1,0x235c);
      UI_ShowChildByID(arg1,0x2360);
      UI_ShowChildByID(arg1,0x236e);
      UI_ShowChildByID(arg1,0x2359);
      UI_ShowChildByID(arg1,0x235b);
      UI_ShowChildByID(arg1,0x235f);
    }
    if (5 < value5) {
      UI_ShowChildByID(arg1,0x2358);
      UI_ShowChildByID(arg1,0x2372);
      UI_ShowChildByID(arg1,0x235e);
      UI_ShowChildByID(arg1,0x2362);
      UI_ShowChildByID(arg1,0x2364);
      UI_ShowChildByID(arg1,0x2371);
      UI_ShowChildByID(arg1,0x235d);
      UI_ShowChildByID(arg1,0x2361);
      UI_ShowChildByID(arg1,0x2363);
      return;
    }
    UI_RemoveObjectByKey(arg1,0x2358);
    UI_RemoveObjectByKey(arg1,0x2372);
    UI_RemoveObjectByKey(arg1,0x235e);
    UI_RemoveObjectByKey(arg1,0x2362);
    UI_RemoveObjectByKey(arg1,0x2364);
    UI_RemoveObjectByKey(arg1,0x2371);
    UI_RemoveObjectByKey(arg1,0x235d);
    UI_RemoveObjectByKey(arg1,0x2361);
    UI_RemoveObjectByKey(arg1,0x2363);
  }
  return;
}
