// CityOverviewDialog_FillRows: ported from Pizza Connection 2 at 0x483530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483530
#include "pc2_port.h"

void __thiscall CityOverviewDialog_FillRows(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  bool flag5;
  
  value1 = *(int *)(*(int *)((intptr_t)self + 0x27c) + 0x14);
  if (value1 < 6) {
    value4 = 0;
  }
  else {
    value1 = 5;
    value4 = arg1;
  }
  if (0 < value1) {
    ptr2 = &DAT_00567e74;
    value3 = 0x3f0 - value4;
    arg1 = value1;
    do {
      flag5 = value4 != *(int *)((intptr_t)self + 0x284);
      if (flag5) {
        value1 = *ptr2;
      }
      else {
        value1 = *ptr2;
      }
      Window_GadgetNotify_Button_SetState(*(void **)((intptr_t)self + 0x268),value1,(uint32_t)!flag5);
      value1 = IDMap_Lookup(*(void **)((intptr_t)self + 0x27c),value4,(int *)0x0);
      Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),value4 + value3,value1 + 4);
      ptr2 = ptr2 + 1;
      value4 = value4 + 1;
      arg1 = arg1 + -1;
    } while (arg1 != 0);
  }
  return;
}
