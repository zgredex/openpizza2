// AdvertisingScreen_UpdatePlan: ported from Pizza Connection 2 at 0x497180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x497180
#include "pc2_port.h"

void __cdecl AdvertisingScreen_UpdatePlan(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int64_t lvalue3;
  uint32_t uvalue4;
  uint8_t local_20 [32];
  
                    /* Fills the advertising/city-plan editor. */
  StringTable_SortIndexArray(&DAT_0057c71c,&DAT_0057c884);
  value1 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
  self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  DAT_0057c9ec = (void *)Player_FindRecordType2ByKey(self,*(int *)(value1 + 0x3c));
  *(uint32_t *)((intptr_t)DAT_0057c9ec + 0xc) = *(uint32_t *)(value1 + 0x3c);
  DAT_0057c718 = *(int *)((intptr_t)DAT_0057c9ec + 4) == 0;
  if ((bool)DAT_0057c718) {
    uvalue4 = DAT_00580f1c;
  }
  else {
    uvalue4 = DAT_005820c8;
  }
  Gadget_SetText(arg1,0x1f47,uvalue4);
  Gadget_SetText(arg1,0x482,
                 *(uint32_t *)
                  (&DAT_00583504 + (&DAT_0057c884)[*(int *)((intptr_t)DAT_0057c9ec + 0x10)] * 4));
  Window_GadgetNotify_Button_SetState(arg1,0x43a,*(uint32_t *)((intptr_t)DAT_0057c9ec + 0x14) & 8);
  Window_GadgetNotify_Button_SetState(arg1,0x43b,*(uint32_t *)((intptr_t)DAT_0057c9ec + 0x14) & 4);
  Window_GadgetNotify_Button_SetState(arg1,0x43c,*(uint32_t *)((intptr_t)DAT_0057c9ec + 0x14) & 2);
  Window_GadgetNotify_Button_SetState(arg1,0x43d,*(uint32_t *)((intptr_t)DAT_0057c9ec + 0x14) & 1);
  if (*(int *)((intptr_t)DAT_0057c9ec + 0x18) == 0) {
    uvalue4 = DAT_00580f68;
  }
  else {
    DAT_0057c9f0 = Supplier_GetValuePlusOne(*(int *)((intptr_t)DAT_0057c9ec + 0x18));
    uvalue4 = *(uint32_t *)(&DAT_00583540 + *(int *)((intptr_t)DAT_0057c9ec + 0x18) * 4);
  }
  Gadget_SetText(arg1,0x48b,uvalue4);
  if (*(int *)((intptr_t)DAT_0057c9ec + 0x1c) == -1) {
    value1 = DAT_00582634;
  }
  else {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)DAT_0057c9ec + 0x1c));
    value1 = value1 + 8;
  }
  Gadget_SetText(arg1,0x48e,value1);
  Window_GadgetNotify_Slider_SetRange(arg1,0x1f44,0,5000,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f44,*(uint32_t *)((intptr_t)DAT_0057c9ec + 0x20),0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1f44,1);
  String_Format(local_20,&DAT_005683a4,*(uint32_t *)((intptr_t)DAT_0057c9ec + 0x20));
  Window_GadgetNotify_Text_SetText(arg1,0x1f45,local_20);
  value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  lvalue3 = GamePlan_ComputeEffectValue(DAT_0057c9ec,value1);
  String_Format(local_20,&DAT_005686f4,(intptr_t)lvalue3);
  Window_GadgetNotify_Text_SetText(arg1,0x1f46,local_20);
  value1 = 0;
  do {
    value2 = GamePlan_ComputeCategoryEffect(DAT_0057c9ec,*(int *)((intptr_t)self + 0x48),value1);
    value2 = Math_PiecewiseLinear(value2);
    Rating_UpdateBarByKey(arg1,0x519,value1,value2,DAT_00582858);
    value1 = value1 + 1;
  } while (value1 < 8);
  return;
}
