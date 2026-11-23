// CityOverviewDialog_Show: ported from Pizza Connection 2 at 0x4835c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4835c0
#include "pc2_port.h"

void __thiscall
CityOverviewDialog_Show
          (void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4,
          uint32_t arg5,uint32_t arg6)

{
  void *this_00;
  int value1;
  int *ptr2;
  int value3;
  void *local_4;
  
                    /* Shows the city-overview list dialog. */
  if (*(int *)((intptr_t)self + 0x268) == 0) {
    local_4 = self;
    this_00 = RecipeSelectPopup_CreateWindow((int *)&local_4);
    *(uint32_t *)((intptr_t)self + 0x274) = arg1;
    *(uint32_t *)((intptr_t)self + 0x270) = arg6;
    *(uint32_t *)((intptr_t)self + 0x27c) = arg4;
    *(void **)((intptr_t)self + 0x268) = this_00;
    *(uint32_t *)((intptr_t)self + 0x278) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x284) = arg5;
    *(uint32_t *)((intptr_t)self + 0x280) = 0;
    Window_GadgetNotify_Text_SetText(this_00,0x3e9,arg2);
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x3ea,arg3);
    value3 = *(int *)(*(int *)((intptr_t)self + 0x27c) + 0x14);
    if (value3 < 6) {
      value3 = 5 - value3;
      UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),1000);
      if (0 < value3) {
        value1 = 0x3f4;
        ptr2 = &DAT_00567e84;
        do {
          UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),value1);
          UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),*ptr2);
          value1 = value1 + -1;
          ptr2 = ptr2 + -1;
          value3 = value3 + -1;
        } while (value3 != 0);
      }
    }
    else {
      *(int *)((intptr_t)self + 0x280) = *(int *)((intptr_t)self + 0x284);
      if (*(int *)(*(int *)((intptr_t)self + 0x27c) + 0x14) < *(int *)((intptr_t)self + 0x284) + 5) {
        *(int *)((intptr_t)self + 0x280) = value3 + -5;
      }
      Window_GadgetNotify_Slider_SetRange(*(void **)((intptr_t)self + 0x268),1000,0,(value3 + -5) * 100,1)
      ;
      Window_GadgetNotify_Slider_SetValue
                (*(void **)((intptr_t)self + 0x268),1000,*(int *)((intptr_t)self + 0x280) * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(*(void **)((intptr_t)self + 0x268),1000,1);
    }
    CityOverviewDialog_FillRows(self,*(int *)((intptr_t)self + 0x280));
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)local_4);
  }
  return;
}
