// LeaseBuilding_UpdatePage: ported from Pizza Connection 2 at 0x4be490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4be490
#include "pc2_port.h"

void __cdecl LeaseBuilding_UpdatePage(void *arg1)

{
  int value1;
  void *self;
  uint32_t uvalue2;
  
                    /* Refreshes the building-lease page and offers. */
  value1 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value1 + 8));
  Window_GadgetNotify_Text_SetText(arg1,0x501,(intptr_t)self + 8);
  Personnel_SetEmployeePhotoByKey(arg1,0x1f4d,(intptr_t)self);
  DAT_0057d700 = Game_FindRecordByField34(self,value1);
  uvalue2 = 100000;
  value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value1 + 0x158) == 0) {
    if (*(int *)(value1 + 0x23c) != 0) {
      uvalue2 = 150000;
    }
  }
  else {
    uvalue2 = 0;
  }
  Gadget_SetTextf(arg1,0x1f5e,&DAT_005683a4,uvalue2);
  StockPage_FillStorageDetails(arg1);
  return;
}
