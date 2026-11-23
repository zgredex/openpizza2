// UI_ShowScrollingListDialog: ported from Pizza Connection 2 at 0x483210.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483210
#include "pc2_port.h"

void __thiscall
UI_ShowScrollingListDialog
          (void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3,int arg4,
          int arg5,uint32_t arg6)

{
  void *this_00;
  int value1;
  int value2;
  void *local_4;
  
                    /* Shows a scrolling list dialog and fills its rows. */
  if (*(int *)((intptr_t)self + 0x268) == 0) {
    local_4 = self;
    this_00 = UI_CreateScrollListWindow((int *)&local_4);
    *(uint32_t *)((intptr_t)self + 0x270) = arg6;
    *(uint32_t *)((intptr_t)self + 0x274) = arg1;
    *(int *)((intptr_t)self + 0x28c) = arg5;
    *(void **)((intptr_t)self + 0x268) = this_00;
    *(uint32_t *)((intptr_t)self + 0x278) = 0xffffffff;
    *(int *)((intptr_t)self + 0x27c) = arg4;
    *(int *)((intptr_t)self + 0x284) = arg5 + -6;
    if (*(int *)(arg4 + 0x14) < arg5 + 7) {
      *(int *)((intptr_t)self + 0x284) = *(int *)(arg4 + 0x14) + -0xd;
    }
    if (*(int *)((intptr_t)self + 0x284) < 0) {
      *(uint32_t *)((intptr_t)self + 0x284) = 0;
    }
    *(uint32_t *)((intptr_t)self + 0x280) = *(uint32_t *)((intptr_t)self + 0x284);
    Window_GadgetNotify_Text_SetText(this_00,0x440,arg2);
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x441,arg3);
    value1 = *(int *)(*(int *)((intptr_t)self + 0x27c) + 0x14);
    if (value1 < 0xe) {
      UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),0x42d);
      value2 = 0x450;
      value1 = 0x450 - (0xd - value1);
      if (value1 < 0x450) {
        do {
          UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),value2);
          UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),value2 + 0xd);
          value2 = value2 + -1;
        } while (value1 < value2);
      }
    }
    else {
      Window_GadgetNotify_Slider_SetRange
                (*(void **)((intptr_t)self + 0x268),0x42d,0,(value1 * 5 + -0x41) * 0x14,1);
      Window_GadgetNotify_Slider_SetValue
                (*(void **)((intptr_t)self + 0x268),0x42d,*(int *)((intptr_t)self + 0x280) * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(*(void **)((intptr_t)self + 0x268),0x42d,1);
    }
    IngredientDialog_FillRows(self,*(int *)((intptr_t)self + 0x280));
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x443,0x1b);
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)local_4);
  }
  return;
}
