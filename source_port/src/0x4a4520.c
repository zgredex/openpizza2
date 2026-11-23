// BranchWindow_InitPriceRows: ported from Pizza Connection 2 at 0x4a4520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a4520
#include "pc2_port.h"

void __cdecl BranchWindow_InitPriceRows(void *arg1)

{
  void *self;
  int value1;
  int value2;
  uint8_t *uptr3;
  int value4;
  
                    /* Fills the branch price page and enables upgrade buttons. */
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value4 = *(int *)((intptr_t)self + 0x48);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value1 = *(int *)((intptr_t)self + 100);
  value4 = *(int *)(value2 + 0xc20 + value4 * 4);
  Gadget_SetTextf(arg1,0x1f82,&DAT_005686f4,value1);
  uptr3 = Economy_GetModifier(self,0x17,0);
  Gadget_SetTextf(arg1,0x1f68,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x17,1);
  Gadget_SetTextf(arg1,0x1f67,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x17,2);
  Gadget_SetTextf(arg1,0x1f54,&DAT_005686f4,uptr3);
  if (value4 < 3) {
LAB_004a4611:
    UI_RemoveObjectByKey(arg1,0x1f7b);
    UI_RemoveObjectByKey(arg1,0x1f7c);
    UI_RemoveObjectByKey(arg1,0x1fdf);
    UI_RemoveObjectByKey(arg1,0x1f4d);
  }
  else {
    if (value1 == 2) {
      if (value4 < 4) goto LAB_004a4611;
    }
    else if (value1 == 3) goto LAB_004a4611;
    UI_ShowChildByID(arg1,0x1f7b);
    UI_ShowChildByID(arg1,0x1f7c);
    UI_ShowChildByID(arg1,0x1fdf);
    UI_ShowChildByID(arg1,0x1f4d);
  }
  Gadget_SetTextf(arg1,0x1fdf,(uint8_t *)s__s__d_00568964,DAT_00581044);
  value4 = Game_ComputeActionCost((intptr_t)self);
  if (*(int *)(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8) + 0x180) != 0) {
    value4 = (value4 * 0xf) / 10;
  }
  Gadget_SetTextf(arg1,0x1f7c,&DAT_005683a4,value4);
  return;
}
