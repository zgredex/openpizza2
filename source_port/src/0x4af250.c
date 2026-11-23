// Glossary_IngredientList_Update: ported from Pizza Connection 2 at 0x4af250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4af250
#include "pc2_port.h"

void __cdecl Glossary_IngredientList_Update(void *arg1,int arg2)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  
                    /* Refreshes the glossary ingredient grid and selected row. */
  uptr2 = (uint32_t *)(&DAT_00569f94 + arg2 * 0xc);
  value3 = 0x42c;
  arg2 = arg2 * 3;
  do {
    Window_GadgetNotify_Button_SetState(arg1,value3,(uint32_t)(arg2 == DAT_0057d654));
    if (arg2 < 0x38) {
      UI_SetChildVisibleByID(arg1,value3,1);
      UI_SetChildVisibleByID(arg1,value3 + 0xb74,1);
      UI_SetButtonRecordVariant(arg1,value3 + 0xb74,*uptr2);
    }
    else {
      UI_SetChildVisibleByID(arg1,value3,0);
      UI_SetChildVisibleByID(arg1,value3 + 0xb74,0);
    }
    uptr2 = uptr2 + 1;
    arg2 = arg2 + 1;
    value1 = value3 + -0x42b;
    value3 = value3 + 1;
  } while (value1 < 0x12);
  return;
}
