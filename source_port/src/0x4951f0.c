// PersonnelOverview_Refresh: ported from Pizza Connection 2 at 0x4951f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4951f0
#include "pc2_port.h"


void __cdecl PersonnelOverview_Refresh(void *arg1,int arg2)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  int *ptr4;
  int value5;
  int value6;
  uint32_t unaff_EDI;
  
                    /* Refreshes the personnel overview from the selected building. */
  value5 = *(int *)(DAT_0057c670 + 0x21c);
  if ((value5 != 0) && ((char)arg2 != '\0')) {
    value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)(value5 + 0x50),(int *)0x0);
    switch(*(uint8_t *)(value2 + 0x824)) {
    case 0:
      arg2 = 0x11;
      break;
    case 1:
      arg2 = 0x12;
      break;
    case 2:
      arg2 = 0x13;
      break;
    case 3:
      arg2 = 0x14;
      break;
    default:
    }
    Sound_ProcessEvent(DAT_0057ba0c,arg2,6,*(int *)(value5 + 0x24) == 0);
    switch(*(uint8_t *)(value2 + 0x824)) {
    case 0:
      DAT_0057c6d8 = 0;
      break;
    case 1:
      DAT_0057c6d8 = 1;
      break;
    case 2:
      DAT_0057c6d8 = 2;
      break;
    case 3:
      DAT_0057c6d8 = 3;
    }
  }
  UI_SetPosition(arg1,&LAB_00494970,0);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,5,0x1fa4);
  if (*(int *)(DAT_0057c670 + 0x290) == 4) {
    UI_RemoveObjectByKey(arg1,0x1f77);
    UI_RemoveObjectByKey(arg1,0x1f78);
    value2 = 0x1f79;
  }
  else {
    value2 = *(int *)(DAT_0057c670 + 0x9c);
    if ((value2 == 0) ||
       (value1 = *(int *)(value2 + 0x30), value6 = Game_GetCurrentPlayerCompanyName(DAT_0057c670),
       value1 != value6)) {
      uvalue3 = IDMap_Lookup((void *)(*(int *)(DAT_0057c670 + 0x200 +
                                            *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x148),0,
                           (int *)0x0);
      *(uint32_t *)(DAT_0057c670 + 0x9c) = uvalue3;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
      value2 = *(int *)(DAT_0057c670 + 0x9c);
    }
    Gadget_SetTextf(arg1,0x1f78,(uint8_t *)(value2 + 4),unaff_EDI);
    UI_RemoveObjectByKey(arg1,0x1f45);
    value2 = 0x1f76;
  }
  UI_RemoveObjectByKey(arg1,value2);
  value2 = Game_GetPlayerFieldC20
                    (*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
  if ((value2 < 2) && (UI_RemoveObjectByKey(arg1,0x1f76), DAT_0057c6d8 == 4)) {
    DAT_0057c6d8 = 0;
  }
  Game_RebuildObjectTypeLists();
  if (value5 == 0) {
    value5 = DAT_0057c6d8;
  }
  else {
    value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)(value5 + 0x50),(int *)0x0);
    DAT_0057c6dc = 0;
    arg2 = 0;
    value5 = DAT_0057c6d8;
    do {
      value6 = 0;
      value1 = *(int *)((&DAT_0057c6e0)[value5] + 0x14);
      if (0 < value1) {
        do {
          ptr4 = (int *)IDMap_Lookup((void *)(&DAT_0057c6e0)[value5],value6,(int *)0x0);
          if (*ptr4 == value2) {
            arg2 = 5;
            DAT_0057c6d8 = value5;
            DAT_0057c6dc = value6;
            goto LAB_00495465;
          }
          value6 = value6 + 1;
        } while (value6 < value1);
        value5 = DAT_0057c6d8;
      }
LAB_00495465:
      arg2 = arg2 + 1;
    } while (arg2 < 4);
  }
  if (*(int *)((&DAT_0057c6e0)[value5] + 0x14) == 0) {
    value2 = 0;
    ptr4 = &DAT_0057c6e0;
    do {
      if (0 < *(int *)(*ptr4 + 0x14)) {
        DAT_0057c6dc = 0;
        value5 = value2;
        DAT_0057c6d8 = value2;
        break;
      }
      ptr4 = ptr4 + 1;
      value2 = value2 + 1;
    } while ((intptr_t)ptr4 < 0x57c6f0);
  }
  Window_GadgetNotify_Button_SetState(arg1,value5 + 0x1fa4,1);
  PersonnelPage_UpdateEmployee(arg1);
  return;
}
