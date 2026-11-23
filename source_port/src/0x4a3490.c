// HeadquartersPanel_UpdateStaffCosts: ported from Pizza Connection 2 at 0x4a3490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a3490
#include "pc2_port.h"

void __cdecl HeadquartersPanel_UpdateStaffCosts(void *arg1)

{
  void *self;
  int value1;
  int value2;
  uint8_t *uptr3;
  
                    /* Fills headquarters salary, tax, and building-count costs. */
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = Game_ComputePlayerSalary((intptr_t)self);
  if (value2 == -1) {
    UI_RemoveObjectByKey(arg1,0x1f84);
    UI_RemoveObjectByKey(arg1,0x1f85);
    UI_RemoveObjectByKey(arg1,0x1f86);
  }
  else {
    value1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(value1 + 0xa0) == 0) {
      if (*(int *)(value1 + 0x184) != 0) {
        value2 = (value2 * 0xf) / 10;
      }
    }
    else {
      value2 = 0;
    }
    Gadget_SetTextf(arg1,0x1f84,(uint8_t *)s__s__d_00568964,DAT_00581180);
    Gadget_SetTextf(arg1,0x1f85,&DAT_005683a4,value2);
  }
  value2 = Game_ComputePlayerTax((intptr_t)self);
  if (value2 == -1) {
    UI_RemoveObjectByKey(arg1,0x1f72);
    UI_RemoveObjectByKey(arg1,0x1f73);
    UI_RemoveObjectByKey(arg1,0x1f74);
  }
  else {
    value1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(value1 + 0xa4) == 0) {
      if (*(int *)(value1 + 0x188) != 0) {
        value2 = (value2 * 0xf) / 10;
      }
    }
    else {
      value2 = 0;
    }
    Gadget_SetTextf(arg1,0x1f72,(uint8_t *)s__s__d_00568964,DAT_00581a0c);
    Gadget_SetTextf(arg1,0x1f73,&DAT_005683a4,value2);
  }
  uptr3 = Economy_GetModifier(self,0x1e,0);
  Gadget_SetTextf(arg1,0x1f77,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x1e,1);
  Gadget_SetTextf(arg1,0x1f76,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x1e,2);
  Gadget_SetTextf(arg1,0x1f78,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x1d,0);
  Gadget_SetTextf(arg1,0x1f7d,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x1d,1);
  Gadget_SetTextf(arg1,0x1f7c,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x1d,2);
  Gadget_SetTextf(arg1,0x1f7e,&DAT_005686f4,uptr3);
  SyndicateMenu_FillStaffCounts(arg1);
  CompetitorWindow_InitStatsPanel(arg1);
  return;
}
