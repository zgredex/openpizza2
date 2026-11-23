// BranchStats_UpdateRatingPage: ported from Pizza Connection 2 at 0x491d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x491d40
#include "pc2_port.h"

void __cdecl BranchStats_UpdateRatingPage(void *arg1)

{
  void *self;
  void *pvVar1;
  int value2;
  int value3;
  int *ptr4;
  int64_t lvalue5;
  
                    /* Refreshes the branch statistics and rating page. */
  self = *(void **)(DAT_0057c670 + 0x9c);
  value3 = 0;
  ptr4 = &DAT_00568628;
  do {
    Window_GadgetNotify_Button_SetState(arg1,value3 + 0x42c,(uint32_t)(*ptr4 == 1));
    ptr4 = ptr4 + 1;
    value3 = value3 + 1;
  } while ((intptr_t)ptr4 < 0x568638);
  if (*(char *)((intptr_t)self + 0x16f4) == '\0') {
    UI_ShowChildByID(arg1,0x44d);
    UI_ShowChildByID(arg1,0x4eb);
    Gadget_SetTextf(arg1,0x4eb,&DAT_005683a4,*(uint32_t *)((intptr_t)self + 0x14b0));
    Gadget_SetText(arg1,0x44f,DAT_00581278);
  }
  else {
    UI_RemoveObjectByKey(arg1,0x44d);
    Gadget_SetText(arg1,0x44f,DAT_00582624);
    value3 = *(int *)((intptr_t)self + 0x38);
    value2 = *(int *)((intptr_t)self + 0x16f0);
    pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                  (int *)0x0);
    lvalue5 = Building_ComputeOperatingRevenue(pvVar1,value2,value3);
    Gadget_SetTextf(arg1,0x4eb,&DAT_005683a4,(intptr_t)lvalue5);
  }
  Gadget_SetText(arg1,0x4ec,DAT_00582198);
  Chart_DrawRatingMatrix(arg1,0x4ed,DAT_0057c6b0,self,7.945979e-39);
  pvVar1 = self;
  value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  Chart_DrawGroupMatrix(arg1,0x429,value3,(intptr_t)pvVar1);
  value3 = 0;
  do {
    value2 = Branch_GetCustomerGroupRating(self,value3,1);
    Rating_UpdateBarByKey(arg1,0x4e2,value3,value2,DAT_00582998);
    value3 = value3 + 1;
  } while (value3 < 8);
  return;
}
