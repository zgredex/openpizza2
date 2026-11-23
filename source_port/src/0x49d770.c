// PizzaContestRecipePage_Update: ported from Pizza Connection 2 at 0x49d770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d770
#include "pc2_port.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl PizzaContestRecipePage_Update(void *arg1)

{
  int value1;
  
                    /* Fills the pizza-contest recipe page. */
  DAT_00568af4 = 0xffffffff;
  DAT_0057ca2c = 0;
  *(uint32_t *)(DAT_0057c5e0 + 0x831c) = 1;
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,6,0x4eb);
  Window_GadgetNotify_Button_SetState(arg1,*(int *)(&DAT_00568af8 + _DAT_00568af8 * 4),1);
  UI_Group_Create(arg1,1,0xc,0x4ed);
  UI_SetPosition(arg1,&LAB_0049d2b0,0);
  DAT_0057cac4 = *(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) +
                         0x1d4);
  if (*(int *)(DAT_0057c670 + 0x98) != DAT_0057cac4) {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x18670,0x23,DAT_0057cac4);
  }
  value1 = 0x509;
  do {
    Array_SetField14ByKey(arg1,value1,0);
    value1 = value1 + 1;
  } while (value1 < 0x515);
  value1 = 0;
  do {
    UI_SetChildLabelText(arg1,value1 + 0x4ed,1,(char *)0x0);
    value1 = value1 + 1;
  } while (value1 < 0xc);
  if (DAT_0057cac4 == 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x448,DAT_00582d50);
    DAT_0057cab8 = 0;
    WarehousePanel_UpdatePage(arg1);
    RecipeEdit_UpdateRatingBars(arg1);
    return;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x448,DAT_0057cac4 + 4);
  DAT_0057cab8 = Game_CountRecordsWithoutFlag(DAT_0057cac4);
  WarehousePanel_UpdatePage(arg1);
  RecipeEdit_UpdateRatingBars(arg1);
  return;
}
