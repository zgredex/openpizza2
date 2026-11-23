// IngredientDialog_FillRows: ported from Pizza Connection 2 at 0x483150.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483150
#include "pc2_port.h"

void __thiscall IngredientDialog_FillRows(void *self,int arg1)

{
  int value1;
  int value2;
  int local_4;
  
  local_4 = 0xd;
  value2 = *(int *)(*(int *)((intptr_t)self + 0x27c) + 0x14);
  if (value2 < 0xe) {
    local_4 = value2;
  }
  if (0 < local_4) {
    value2 = 0x451;
    do {
      value1 = arg1 + -0x451 + value2;
      Window_GadgetNotify_Button_SetState
                (*(void **)((intptr_t)self + 0x268),value2 + -0xd,
                 (uint32_t)(value1 == *(int *)((intptr_t)self + 0x28c)));
      value1 = IDMap_Lookup(*(void **)((intptr_t)self + 0x27c),value1,(int *)0x0);
      Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),value2,value1 + 4);
      Window_GadgetNotify_Text_SetTextColor
                (*(void **)((intptr_t)self + 0x268),value2,*(uint32_t *)(value1 + 0x54));
      if (*(char **)(value1 + 0x44) != (char *)0x0) {
        UI_SetObjectTextByKey(*(void **)((intptr_t)self + 0x268),value2 + -0xd,*(char **)(value1 + 0x44));
      }
      value1 = value2 + -0x450;
      value2 = value2 + 1;
    } while (value1 < local_4);
  }
  return;
}
