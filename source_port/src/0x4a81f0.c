// Window_UpdateConstructionOrderPage: ported from Pizza Connection 2 at 0x4a81f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a81f0
#include "pc2_port.h"

void __cdecl Window_UpdateConstructionOrderPage(void *arg1)

{
  int value1;
  int value2;
  int value3;
  bool flag4;
  int64_t lvalue5;
  uint32_t uvalue6;
  uint8_t local_20 [32];
  
                    /* Updates the construction-order page. */
  StringTable_SortIndexArray(&DAT_0057d29c,&DAT_0057d404);
  IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
  value1 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  DAT_0057d56c = (void *)Player_GetFirstRecordType1(value1);
  flag4 = *(int *)((intptr_t)DAT_0057d56c + 4) != 0;
  if (flag4) {
    uvalue6 = DAT_005820c8;
  }
  else {
    uvalue6 = DAT_00580f1c;
  }
  DAT_0057d298 = !flag4;
  Gadget_SetText(arg1,0x1f43,uvalue6);
  Gadget_SetText(arg1,0x482,
                 *(uint32_t *)
                  (&DAT_00583504 + (&DAT_0057d404)[*(int *)((intptr_t)DAT_0057d56c + 0x10)] * 4));
  Window_GadgetNotify_Button_SetState(arg1,0x43a,*(uint32_t *)((intptr_t)DAT_0057d56c + 0x14) & 8);
  Window_GadgetNotify_Button_SetState(arg1,0x43b,*(uint32_t *)((intptr_t)DAT_0057d56c + 0x14) & 4);
  Window_GadgetNotify_Button_SetState(arg1,0x43c,*(uint32_t *)((intptr_t)DAT_0057d56c + 0x14) & 2);
  Window_GadgetNotify_Button_SetState(arg1,0x43d,*(uint32_t *)((intptr_t)DAT_0057d56c + 0x14) & 1);
  if (*(int *)((intptr_t)DAT_0057d56c + 0x18) == 0) {
    uvalue6 = DAT_00580f68;
  }
  else {
    DAT_0057d570 = Personnel_GetTrainingLevel(*(int *)((intptr_t)DAT_0057d56c + 0x18));
    uvalue6 = *(uint32_t *)(&DAT_00583540 + *(int *)((intptr_t)DAT_0057d56c + 0x18) * 4);
  }
  Gadget_SetText(arg1,0x48b,uvalue6);
  if (*(int *)((intptr_t)DAT_0057d56c + 0x1c) == -1) {
    value2 = DAT_00582634;
  }
  else {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)DAT_0057d56c + 0x1c));
    value2 = value2 + 8;
  }
  Gadget_SetText(arg1,0x48e,value2);
  Window_GadgetNotify_Slider_SetRange(arg1,0x42c,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x42c,*(uint32_t *)((intptr_t)DAT_0057d56c + 0x20),0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x42c,1);
  String_Format(local_20,&DAT_005683a4,*(uint32_t *)((intptr_t)DAT_0057d56c + 0x20));
  Window_GadgetNotify_Text_SetText(arg1,0x490,local_20);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  lvalue5 = GamePlan_ComputeEffectValue(DAT_0057d56c,value2);
  String_Format(local_20,&DAT_005686f4,(intptr_t)lvalue5);
  Window_GadgetNotify_Text_SetText(arg1,0x491,local_20);
  value2 = 0;
  do {
    value3 = GamePlan_ComputeCategoryEffect(DAT_0057d56c,*(int *)(value1 + 0x48),value2);
    value3 = Math_PiecewiseLinear(value3);
    Rating_UpdateBarByKey(arg1,0x519,value2,value3,DAT_00582858);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
