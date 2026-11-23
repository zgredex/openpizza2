// BranchRatingPanel_Update: ported from Pizza Connection 2 at 0x4bbfd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bbfd0
#include "pc2_port.h"


void __cdecl BranchRatingPanel_Update(void *arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  int *ptr4;
  int value5;
  
                    /* Updates the branch rating panel and customer-group bars. */
  UI_SetPosition(arg1,&LAB_004bbfb0,0);
  UI_AddUniquePair(arg1,0x1f43,0x131);
  UI_AddUniquePair(arg1,0x1f45,0x133);
  if (DAT_0057d6f8 != (void *)0x0) {
    UI_ReleaseRefCount(DAT_0057c5e0,(intptr_t)DAT_0057d6f8);
  }
  DAT_0057d6f8 = (void *)UI_LoadFontByName(DAT_0057c5e0,s_VERDANA7_fnt_00563ec8);
  value2 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
  pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value2 + 8));
  DAT_0057d6f0 = (void *)IDMap_Lookup((void *)((intptr_t)pvVar1 + 0x148),*(int *)(value2 + 0x2c),
                                      (int *)0x0);
  DAT_0057d6f4 = *(uint32_t *)((intptr_t)DAT_0057d6f0 + 0x3c);
  Gadget_SetText(arg1,0x1f44,DAT_005818d4);
  Window_GadgetNotify_Text_SetText(arg1,0x1f41,(intptr_t)DAT_0057d6f0 + 4);
  pvVar1 = Player_FindRecordByCityId(pvVar1,(intptr_t)DAT_0057d6f0);
  if (pvVar1 == (void *)0x0) {
    UI_RemoveObjectByKey(arg1,0x1f46);
    Window_GadgetNotify_Text_SetText(arg1,0x1f64,DAT_00582a7c);
  }
  else {
    UI_ShowChildByID(arg1,0x1f46);
    Get_Subobject4((intptr_t)pvVar1);
    Gadget_SetTextf(arg1,0x1f64,(uint8_t *)s__s__s_00563314,DAT_00581a4c);
  }
  Chart_DrawRatingMatrix(arg1,0x1f5a,DAT_0057d6f8,DAT_0057d6f0,7.958983e-39);
  pvVar1 = DAT_0057d6f0;
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  Chart_DrawGroupMatrix(arg1,0x1f49,value2,(intptr_t)pvVar1);
  value2 = 0;
  ptr4 = &DAT_0056aa68;
  do {
    Window_GadgetNotify_Button_SetState(arg1,value2 + 0x1f56,(uint32_t)(*ptr4 == 1));
    ptr4 = ptr4 + 1;
    value2 = value2 + 1;
  } while ((intptr_t)ptr4 < 0x56aa78);
  value2 = 0;
  do {
    value5 = DAT_00582998;
    value3 = Branch_GetCustomerGroupRating(DAT_0057d6f0,value2,1);
    Rating_UpdateBarByKey(arg1,0x5be,value2,value3,value5);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
