// PersonnelPlan_WindowProc: ported from Pizza Connection 2 at 0x4936a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4936a0
#include "pc2_port.h"

void __cdecl PersonnelPlan_WindowProc(void *arg1,int arg2,uint32_t arg3,int arg4)

{
  int value1;
  int *ptr2;
  uint32_t uvalue3;
  uint32_t *uptr4;
  void *pvVar5;
  int value6;
  int value7;
  int value8;
  int value9;
  int local_104;
  uint8_t local_100 [256];
  
                    /* Handles input for the staff-planning page and edits employee attributes. */
  switch(arg3) {
  case 1:
    if ((DAT_0056872c == -1) && (arg2 < 8000)) {
      return;
    }
    if (*(int *)((intptr_t)DAT_0057c670 + 0x268) != 0) {
      Game_CloseSelectionDialog((intptr_t)DAT_0057c670);
    }
    if (arg2 < 0x485) {
      if (arg2 != 0x484) {
        switch(arg2) {
        case 0x44f:
          pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0)
          ;
          value1 = Game_CountObjectsByType(pvVar5,0xffffffff);
          DAT_0056872c = DAT_0056872c + -1;
          if (DAT_0056872c == -1) {
            DAT_0056872c = value1 + -1;
          }
          PersonnelPlan_UpdateEmployeeDetail
                    (arg1,(intptr_t)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
          if ((7 < value1) && (DAT_0057c6d4 = DAT_0056872c, value1 < DAT_0056872c + 7)) {
            DAT_0057c6d4 = value1 + -7;
          }
          Window_GadgetNotify_Slider_SetValue(arg1,0x451,DAT_0057c6d4 * 100,0);
          PersonnelPlan_LayoutEmployeeList
                    (arg1,DAT_0057c6d4,(intptr_t)DAT_0057c6d0,DAT_00568728,DAT_0056872c);
          return;
        case 0x450:
          pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0)
          ;
          value1 = Game_CountObjectsByType(pvVar5,0xffffffff);
          DAT_0056872c = DAT_0056872c + 1;
          if (DAT_0056872c == value1) {
            DAT_0056872c = 0;
          }
          PersonnelPlan_UpdateEmployeeDetail
                    (arg1,(intptr_t)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
          if ((7 < value1) && (DAT_0057c6d4 = DAT_0056872c, value1 < DAT_0056872c + 7)) {
            DAT_0057c6d4 = value1 + -7;
          }
          Window_GadgetNotify_Slider_SetValue(arg1,0x451,DAT_0057c6d4 * 100,0);
          PersonnelPlan_LayoutEmployeeList
                    (arg1,DAT_0057c6d4,(intptr_t)DAT_0057c6d0,DAT_00568728,DAT_0056872c);
          return;
        default:
          return;
        case 0x47f:
          value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
          ptr2 = (int *)IDMap_Lookup((void *)(value1 + 0x1500),DAT_0056872c,(int *)0x0);
          value1 = Game_GetRecordField814Value(*ptr2);
          String_Format(local_100,DAT_00581334,value1);
          Game_ShowQuestionDialog
                    (DAT_0057c670,0xfffe79ba,DAT_00581fe4,local_100,0xffffffff,0,-1,'\0');
          return;
        case 0x480:
          goto switchD_0049378c_caseD_480;
        case 0x483:
          value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
          ptr2 = (int *)IDMap_Lookup((void *)(value1 + 0x1500),DAT_0056872c,(int *)0x0);
          value1 = Rating_AdjustA(*ptr2);
          if (99 < value1) {
            return;
          }
          value6 = Game_GetCostForType((void *)*ptr2,3);
          value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
          if (*(int *)(value1 + 0xdc) == 0) {
            if (*(int *)(value1 + 0x1c0) != 0) {
              value6 = (value6 * 0xf) / 10;
            }
          }
          else {
            value6 = 0;
          }
          String_Format(local_100,DAT_005829a4,value6);
          Game_ShowQuestionDialog
                    (DAT_0057c670,0xfffe796b,DAT_00581fe4,local_100,0xffffffff,0,-1,'\0');
          return;
        }
      }
      value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      ptr2 = (int *)IDMap_Lookup((void *)(value1 + 0x1500),DAT_0056872c,(int *)0x0);
      pvVar5 = (void *)*ptr2;
      if (99 < *(int *)((intptr_t)pvVar5 + 0xc)) {
        return;
      }
      switch(*(uint8_t *)((intptr_t)pvVar5 + 0x824)) {
      case 0:
        local_104 = 6;
        break;
      case 1:
        local_104 = 8;
        break;
      case 2:
        local_104 = 7;
        break;
      case 3:
        local_104 = 0xd;
        break;
      default:
      }
      value1 = Game_GetCostForType(pvVar5,1);
      uvalue3 = Game_CanAffordWithCurrency(DAT_0057c6d0,local_104,(float)value1,'\x01',0xffffffff);
      if ((char)uvalue3 != '\0') {
        BuildingValue_ApplyUpgrade((void *)*ptr2,1);
        String_Format(local_100,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x3c));
        Window_GadgetNotify_Text_SetText(arg1,0x529,local_100);
        PersonnelPlan_UpdateEmployeeDetail(arg1,(intptr_t)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c)
        ;
        return;
      }
      uvalue3 = DAT_005828c0;
    }
    else {
      if (arg2 < 0x1f41) {
        if (arg2 == 8000) {
          UI_ShowHelpTopicDialog(-0x51);
          return;
        }
        if (arg2 == 0x485) {
          value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
          ptr2 = (int *)IDMap_Lookup((void *)(value1 + 0x1500),DAT_0056872c,(int *)0x0);
          value1 = Rating_AdjustB(*ptr2);
          if (99 < value1) {
            return;
          }
          value6 = Game_GetCostForType((void *)*ptr2,2);
          value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
          if (*(int *)(value1 + 0xe0) == 0) {
            if (*(int *)(value1 + 0x1c4) != 0) {
              value6 = (value6 * 0xf) / 10;
            }
          }
          else {
            value6 = 0;
          }
          String_Format(local_100,DAT_00582dd8,value6);
          Game_ShowQuestionDialog
                    (DAT_0057c670,0xfffe796c,DAT_00581fe4,local_100,0xffffffff,0,-1,'\0');
          return;
        }
        if (arg2 != 5000) {
          return;
        }
        value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
        uptr4 = (uint32_t *)IDMap_Lookup((void *)(value1 + 0x1500),DAT_0056872c,(int *)0x0);
        if (arg4 == 0) {
          Game_SetRecordOpenState((void *)*uptr4,2);
          return;
        }
        Game_SetRecordOpenState((void *)*uptr4,1);
        return;
      }
      if (arg2 != 0x2333) {
        return;
      }
      pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                    *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
      value1 = Game_CountObjectsByType2(pvVar5,0xffffffff);
      if (0 < value1) {
        Game_DestroyRootWindow((intptr_t)DAT_0057c670);
        pvVar5 = DAT_0057c670;
        *(uint32_t *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x2b8) =
             *(uint32_t *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298);
        *(uint32_t *)((intptr_t)pvVar5 + *(int *)((intptr_t)pvVar5 + 0x290) * 4 + 0x298) = 0xb;
        pvVar5 = SubMenu_CreateBuildingPage(DAT_0057c670);
        Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar5);
        return;
      }
      uvalue3 = DAT_00580bf4;
    }
    goto LAB_004940a5;
  case 0x18:
    if (*(int *)((intptr_t)DAT_0057c670 + 0x268) != 0) {
      Game_CloseSelectionDialog((intptr_t)DAT_0057c670);
    }
    if (arg2 == 0x451) {
      DAT_0057c6d4 = arg4 / 100;
      return;
    }
    if ((5999 < arg2) && (arg2 < 0x178c)) {
      pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      value1 = IDMap_Lookup((void *)((intptr_t)pvVar5 + 0x1500),(arg2 + -6000 >> 2) + DAT_0057c6d4,
                           (int *)0x0);
      value6 = Window_GadgetNotify_Slider_GetValue(arg1,arg2,0);
      *(uint32_t *)(value1 + 4) = value6 - 1U & 7;
      Stats_ResetAverages(pvVar5);
      return;
    }
    break;
  case 0x19:
    if (*(int *)((intptr_t)DAT_0057c670 + 0x268) != 0) {
      Game_CloseSelectionDialog((intptr_t)DAT_0057c670);
    }
    if (arg2 < 0x177e) {
      if (arg2 == 0x177d) goto switchD_004946c9_caseD_1779;
      if (0x1776 < arg2) {
        switch(arg2) {
        case 0x1777:
        case 0x177b:
          goto switchD_004946c9_caseD_1777;
        case 0x1778:
        case 0x177c:
          goto switchD_004946c9_caseD_1778;
        case 0x1779:
          goto switchD_004946c9_caseD_1779;
        case 0x177a:
          goto switchD_004946c9_caseD_177a;
        default:
          goto switchD_004936c0_caseD_2;
        }
      }
      if (arg2 != 0x1776) {
        if (arg2 < 0x1773) {
          if (arg2 == 0x1772) goto switchD_004946c9_caseD_177a;
          if (arg2 == 0x451) {
            PersonnelPlan_LayoutEmployeeList
                      (arg1,arg4 / 100,(intptr_t)DAT_0057c6d0,DAT_00568728,DAT_0056872c);
            return;
          }
          if (arg2 != 6000) {
            if (arg2 != 0x1771) {
              return;
            }
            goto switchD_004946c9_caseD_1779;
          }
        }
        else {
          if (arg2 == 0x1773) goto switchD_004946c9_caseD_1777;
          if (arg2 != 0x1774) {
            if (arg2 != 0x1775) {
              return;
            }
            goto switchD_004946c9_caseD_1779;
          }
        }
switchD_004946c9_caseD_1778:
        value1 = arg2 + -6000;
        goto LAB_00494704;
      }
switchD_004946c9_caseD_177a:
      value1 = arg2 + -0x1772;
    }
    else {
      switch(arg2) {
      case 0x177e:
      case 0x1782:
      case 0x1786:
      case 0x178a:
        goto switchD_004946c9_caseD_177a;
      case 0x177f:
      case 0x1783:
      case 0x1787:
      case 0x178b:
switchD_004946c9_caseD_1777:
        value1 = arg2 + -0x1773;
        break;
      case 0x1780:
      case 0x1784:
      case 0x1788:
        goto switchD_004946c9_caseD_1778;
      case 0x1781:
      case 0x1785:
      case 0x1789:
switchD_004946c9_caseD_1779:
        value1 = arg2 + -0x1771;
        break;
      default:
        goto switchD_004936c0_caseD_2;
      }
    }
LAB_00494704:
    value9 = (intptr_t)(value1 + (value1 >> 0x1f & 3U)) >> 2;
    value6 = value9 * 10 + 0xe1;
    value7 = Window_GadgetNotify_Slider_GetValue(arg1,arg2,0);
    value1 = value7 * 0x14;
    if (value7 < 1) {
      value8 = value1 + 0xbd;
    }
    else {
      value8 = value1 + 0x1d;
    }
    UI_SetObjectRangeByKey(arg1,value9 + 50000,value8,value6);
    if (value7 < 7) {
      value1 = value1 + 0x45;
    }
    else {
      value1 = value1 + -0x5b;
    }
    UI_SetObjectRangeByKey(arg1,value9 + 51000,value1,value6);
    break;
  case 0x1a:
    if (*(int *)((intptr_t)DAT_0057c670 + 0x268) != 0) {
      Game_CloseSelectionDialog((intptr_t)DAT_0057c670);
    }
    value1 = arg2 + -6000;
    switch(value1) {
    case 0:
    case 4:
    case 8:
    case 0xc:
    case 0x10:
    case 0x14:
    case 0x18:
      value6 = (intptr_t)(value1 + (value1 >> 0x1f & 3U)) >> 2;
      value1 = 0;
      do {
        UI_RemoveObjectByKey(arg1,value1 + 0x1794);
        value1 = value1 + 1;
      } while (value1 < 7);
      UI_ShowChildByID(arg1,value6 + 0x1794);
      DAT_0056872c = value6 + DAT_0057c6d4;
      break;
    case 1:
    case 5:
    case 9:
    case 0xd:
    case 0x11:
    case 0x15:
    case 0x19:
      value6 = (intptr_t)(arg2 + -0x1771 + (arg2 + -0x1771 >> 0x1f & 3U)) >> 2;
      value1 = 0;
      do {
        UI_RemoveObjectByKey(arg1,value1 + 0x1794);
        value1 = value1 + 1;
      } while (value1 < 7);
      UI_ShowChildByID(arg1,value6 + 0x1794);
      DAT_0056872c = value6 + DAT_0057c6d4;
      break;
    case 2:
    case 6:
    case 10:
    case 0xe:
    case 0x12:
    case 0x16:
    case 0x1a:
      value1 = arg2 + -0x1772 + (arg2 + -0x1772 >> 0x1f & 3U);
      value6 = 0;
      do {
        UI_RemoveObjectByKey(arg1,value6 + 0x1794);
        value6 = value6 + 1;
      } while (value6 < 7);
      goto LAB_0049455e;
    case 3:
    case 7:
    case 0xb:
    case 0xf:
    case 0x13:
    case 0x17:
    case 0x1b:
      value1 = arg2 + -0x1773 + (arg2 + -0x1773 >> 0x1f & 3U);
      value6 = 0;
      do {
        UI_RemoveObjectByKey(arg1,value6 + 0x1794);
        value6 = value6 + 1;
      } while (value6 < 7);
LAB_0049455e:
      UI_ShowChildByID(arg1,(value1 >> 2) + 0x1794);
      DAT_0056872c = (value1 >> 2) + DAT_0057c6d4;
      break;
    default:
      goto switchD_00494441_default;
    }
    PersonnelPlan_UpdateEmployeeDetail(arg1,(intptr_t)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
switchD_00494441_default:
    if (((5999 < arg2) && (arg2 < 0x178c)) &&
       (ptr2 = (int *)IDMap_Lookup((void *)(*(int *)((intptr_t)DAT_0057c670 + 0x9c) + 0x1500),
                                     DAT_0056872c,(int *)0x0), ptr2 != (int *)0x0)) {
      Game_GetRecordByField814(*ptr2);
      return;
    }
    break;
  case 0x1b:
    if (arg2 == 0x2332) {
      value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      ptr2 = (int *)IDMap_Lookup((void *)(value1 + 0x1500),DAT_0056872c,(int *)0x0);
      if (ptr2 != (int *)0x0) {
        value1 = Game_GetRecordByField814(*ptr2);
        Game_OpenObjectView(DAT_0057c670,value1);
        return;
      }
    }
    break;
  case 0x23:
    switch(arg2) {
    case -0x18696:
      pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar5 + 0x1500),DAT_0056872c,(int *)0x0);
      local_104 = Game_GetCostForType((void *)*uptr4,0);
      value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(value1 + 0xdc) == 0) {
        if (*(int *)(value1 + 0x1c0) != 0) {
          local_104 = (local_104 * 0xf) / 10;
        }
      }
      else {
        local_104 = 0;
      }
      uvalue3 = Game_CanAfford(pvVar5,0xb,(float)local_104,'\x01',-1);
      if ((char)uvalue3 != '\0') {
        BuildingValue_ApplyUpgrade((void *)*uptr4,0);
        PersonnelPlan_UpdateEmployeeDetail(arg1,(intptr_t)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c)
        ;
        value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
        value6 = *(int *)(value1 + 0xdc);
joined_r0x0049408a:
        if (value6 != 0) {
          *(int *)(value1 + 0xdc) = *(int *)(value1 + 0xdc) + -1;
          return;
        }
        if (*(int *)(value1 + 0x1c0) == 0) {
          return;
        }
        *(int *)(value1 + 0x1c0) = *(int *)(value1 + 0x1c0) + -1;
        return;
      }
      break;
    case -0x18695:
      pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar5 + 0x1500),DAT_0056872c,(int *)0x0);
      local_104 = Game_GetCostForType((void *)*uptr4,3);
      value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(value1 + 0xdc) == 0) {
        if (*(int *)(value1 + 0x1c0) != 0) {
          local_104 = (local_104 * 0xf) / 10;
        }
      }
      else {
        local_104 = 0;
      }
      uvalue3 = Game_CanAfford(pvVar5,0xb,(float)local_104,'\x01',-1);
      if ((char)uvalue3 != '\0') {
        BuildingValue_ApplyUpgrade((void *)*uptr4,3);
        PersonnelPlan_UpdateEmployeeDetail(arg1,(intptr_t)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c)
        ;
        value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
        value6 = *(int *)(value1 + 0xdc);
        goto joined_r0x0049408a;
      }
      break;
    case -0x18694:
      value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      uptr4 = (uint32_t *)IDMap_Lookup((void *)(value1 + 0x1500),DAT_0056872c,(int *)0x0);
      local_104 = Game_GetCostForType((void *)*uptr4,2);
      value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(value1 + 0xe0) == 0) {
        if (*(int *)(value1 + 0x1c4) != 0) {
          local_104 = (local_104 * 0xf) / 10;
        }
      }
      else {
        local_104 = 0;
      }
      pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      uvalue3 = Game_CanAfford(pvVar5,0xb,(float)local_104,'\x01',-1);
      if ((char)uvalue3 != '\0') {
        BuildingValue_ApplyUpgrade((void *)*uptr4,2);
        value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
        if (*(int *)(value1 + 0xe0) == 0) {
          if (*(int *)(value1 + 0x1c4) != 0) {
            *(int *)(value1 + 0x1c4) = *(int *)(value1 + 0x1c4) + -1;
          }
        }
        else {
          *(int *)(value1 + 0xe0) = *(int *)(value1 + 0xe0) + -1;
        }
        PersonnelPlan_UpdateEmployeeDetail(arg1,(intptr_t)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c)
        ;
        uvalue3 = 500;
        value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
        if (*(int *)(value1 + 0xe0) == 0) {
          if (*(int *)(value1 + 0x1c4) != 0) {
            uvalue3 = 0x2ee;
          }
        }
        else {
          uvalue3 = 0;
        }
        String_Format(local_100,DAT_00581eb8,uvalue3);
        Gadget_SetText(arg1,0x485,local_100);
        return;
      }
      break;
    case -0x18693:
      if (*(int *)((intptr_t)DAT_0057c670 + 0x9c) == 0) {
        return;
      }
      Window_UpdateStaffPlanPage(arg1,*(int *)((intptr_t)DAT_0057c670 + 0x2d8) == 0x1d,'\0');
      return;
    default:
      goto switchD_004936c0_caseD_2;
    case -0x1864e:
      if (arg4 == -1) {
        return;
      }
      value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),arg4,(int *)0x0);
      if (value1 == 0) {
        return;
      }
      DAT_00568728 = *(int *)(value1 + 0x3c);
    case -0x1863b:
      Window_UpdateStaffPlanPage(arg1,*(int *)((intptr_t)DAT_0057c670 + 0x2d8) == 0x1d,'\0');
      return;
    case -0x18646:
      pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)pvVar5 + 0x1500),DAT_0056872c,(int *)0x0);
      Branch_RemoveStaffMember(pvVar5,ptr2,1);
      Window_UpdateStaffPlanPage(arg1,*(int *)((intptr_t)DAT_0057c670 + 0x2d8) == 0x1d,'\0');
      return;
    }
    uvalue3 = DAT_005828c0;
LAB_004940a5:
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_005825a4,uvalue3,0);
    return;
  }
switchD_004936c0_caseD_2:
  return;
switchD_0049378c_caseD_480:
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
  ptr2 = (int *)IDMap_Lookup((void *)(value1 + 0x1500),DAT_0056872c,(int *)0x0);
  value1 = Rating_ClampAdjusted(*ptr2);
  if (99 < value1) {
    return;
  }
  value6 = Game_GetCostForType((void *)*ptr2,0);
  value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value1 + 0xdc) == 0) {
    if (*(int *)(value1 + 0x1c0) != 0) {
      value6 = (value6 * 0xf) / 10;
    }
  }
  else {
    value6 = 0;
  }
  String_Format(local_100,DAT_005829a4,value6);
  Game_ShowQuestionDialog(DAT_0057c670,0xfffe796a,DAT_00581fe4,local_100,0xffffffff,0,-1,'\0');
  return;
}
