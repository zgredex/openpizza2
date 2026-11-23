// BranchInfoPanel_Update: ported from Pizza Connection 2 at 0x4c47d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c47d0
#include "pc2_port.h"

void __cdecl BranchInfoPanel_Update(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  uint8_t local_20 [32];
  
                    /* Fills the branch/plan info card and rating rows. */
  StringTable_SortIndexArray((int *)&DAT_0057da20,(int *)&DAT_0057db88);
  value3 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value3 + 8));
  DAT_0057dcf0 = (void *)Game_FindPlanByTarget(self,value3);
  value1 = IDMap_Lookup((void *)((intptr_t)self + 0x148),*(int *)((intptr_t)DAT_0057dcf0 + 0xc),(int *)0x0);
  Window_GadgetNotify_Text_SetText(arg1,0x1f42,value1 + 4);
  Window_GadgetNotify_Text_SetText(arg1,0x41b,(intptr_t)self + 8);
  value1 = 0x41d;
  Window_GadgetNotify_Text_SetText(arg1,0x41d,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(arg1,0x41e,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(arg1,0x41f,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(arg1,0x420,DAT_00582e4c);
  if ((*(uint8_t *)((intptr_t)DAT_0057dcf0 + 0x14) & 8) != 0) {
    value1 = 0x41e;
    Window_GadgetNotify_Text_SetText(arg1,0x41d,DAT_00582ad8);
  }
  value2 = value1;
  if ((*(uint8_t *)((intptr_t)DAT_0057dcf0 + 0x14) & 4) != 0) {
    value2 = value1 + 1;
    Window_GadgetNotify_Text_SetText(arg1,value1,DAT_00581a50);
  }
  value1 = value2;
  if ((*(uint8_t *)((intptr_t)DAT_0057dcf0 + 0x14) & 2) != 0) {
    value1 = value2 + 1;
    Window_GadgetNotify_Text_SetText(arg1,value2,DAT_00580e7c);
  }
  value2 = value1;
  if ((*(uint8_t *)((intptr_t)DAT_0057dcf0 + 0x14) & 1) != 0) {
    value2 = value1 + 1;
    Window_GadgetNotify_Text_SetText(arg1,value1,DAT_00581f80);
  }
  if (*(int *)((intptr_t)DAT_0057dcf0 + 0x14) == 0) {
    Window_GadgetNotify_Text_SetText(arg1,value2,DAT_005826e4);
  }
  if (*(int *)((intptr_t)DAT_0057dcf0 + 0x18) == 0) {
    uvalue4 = DAT_00580f68;
  }
  else {
    uvalue4 = *(uint32_t *)(&DAT_00583540 + *(int *)((intptr_t)DAT_0057dcf0 + 0x18) * 4);
  }
  Window_GadgetNotify_Text_SetText(arg1,0x422,uvalue4);
  if (*(int *)((intptr_t)DAT_0057dcf0 + 0x1c) == -1) {
    value1 = DAT_00582634;
  }
  else {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)DAT_0057dcf0 + 0x1c));
    value1 = value1 + 8;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x424,value1);
  Window_GadgetNotify_Text_SetText
            (arg1,0x4b8,
             *(uint32_t *)
              (&DAT_00583504 + *(int *)(&DAT_0057db88 + *(int *)((intptr_t)DAT_0057dcf0 + 0x10) * 4) * 4)
            );
  Gadget_SetText(arg1,0x417,DAT_005824c4);
  value3 = *(int *)(value3 + 8);
  value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (value3 == value1) {
    Window_GadgetNotify_Text_SetText(arg1,0x425,DAT_005829f4);
    String_Format(local_20,&DAT_005683a4,0xdac);
    Window_GadgetNotify_Text_SetText(arg1,0x426,local_20);
    Window_GadgetNotify_Text_SetText(arg1,0x425,DAT_005829e8);
    uvalue4 = DAT_00582f00;
  }
  else {
    Window_GadgetNotify_Text_SetText(arg1,0x425,DAT_00581b28);
    String_Format(local_20,&DAT_005683a4,*(int *)((intptr_t)DAT_0057dcf0 + 0x20) * 10);
    Window_GadgetNotify_Text_SetText(arg1,0x426,local_20);
    Window_GadgetNotify_Text_SetText(arg1,0x425,DAT_00582f98);
    uvalue4 = DAT_00582708;
  }
  Gadget_SetText(arg1,0x417,uvalue4);
  value3 = 0;
  do {
    value1 = GamePlan_ComputeCategoryEffect(DAT_0057dcf0,*(int *)((intptr_t)self + 0x48),value3);
    value1 = Math_PiecewiseLinear(value1);
    Rating_UpdateBarByKey(arg1,0x4ae,value3,value1,DAT_00582858);
    value3 = value3 + 1;
  } while (value3 < 8);
  return;
}
