// Glossary_InitIngredientPage: ported from Pizza Connection 2 at 0x4af370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4af370
#include "pc2_port.h"

void __cdecl Glossary_InitIngredientPage(void *arg1)

{
  int value1;
  
                    /* Initializes the ingredient glossary page and category groups. */
  value1 = 4000;
  do {
    Array_SetField14ByKey(arg1,value1,0);
    value1 = value1 + 1;
  } while (value1 < 0xfb2);
  UI_Group_Create(arg1,0,0x12,0x42c);
  UI_Group_Create(arg1,0,4,0x3f9);
  Window_GadgetNotify_Button_SetState(arg1,0x3fa,1);
  Window_GadgetNotify_Slider_SetRange(arg1,0x3f6,0,0xd,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x3f6,DAT_0057d650,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x3f6,1);
  Glossary_ShowIngredientDetail(arg1);
  Glossary_IngredientList_Update(arg1,DAT_0057d650);
  return;
}
