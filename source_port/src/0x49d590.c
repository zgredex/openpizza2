// WarehousePanel_UpdatePage: ported from Pizza Connection 2 at 0x49d590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d590
#include "pc2_port.h"

void __cdecl WarehousePanel_UpdatePage(void *arg1)

{
  int value1;
  int value2;
  int value3;
  
                    /* Refreshes the warehouse/stock ingredient slots. */
  if (DAT_0057cac8 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057cac8)(1);
    DAT_0057cac8 = (uint32_t *)0x0;
  }
  DAT_0057cac8 = Ingredient_CollectByCategory(DAT_0057c670,DAT_00568af8);
  value2 = DAT_0057cac8[5];
  DAT_0057cad0 = 0;
  value3 = 0x4ed;
  do {
    UI_ShowChildByID(arg1,value3 + 0x1c);
    UI_ShowChildByID(arg1,value3);
    value1 = value3 + -0x4ec;
    value3 = value3 + 1;
  } while (value1 < 0xc);
  if (value2 < 0xd) {
    UI_RemoveObjectByKey(arg1,0x428);
    value2 = 0xc - value2;
    if (0 < value2) {
      value3 = 0x4f8;
      do {
        UI_RemoveObjectByKey(arg1,value3 + 0x1c);
        UI_RemoveObjectByKey(arg1,value3);
        value3 = value3 + -1;
        value2 = value2 + -1;
      } while (value2 != 0);
    }
  }
  else {
    UI_ShowChildByID(arg1,0x428);
    value3 = DAT_00568af4;
    if (value2 < DAT_00568af4 + 0xc) {
      value3 = value2 + -9;
    }
    DAT_0057cad0 = value3 / 3;
    Window_GadgetNotify_Slider_SetRange(arg1,0x428,0,((value2 + -0xc) / 3 + 1) * 100,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x428,DAT_0057cad0 * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x428,1);
  }
  ContestRecipePage_FillIngredientDetails(arg1,-1);
  RecipeComparison_InitRecipeRows(arg1,DAT_0057cad0);
  return;
}
