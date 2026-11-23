// Branch_ApplyProductSales: ported from Pizza Connection 2 at 0x4fe420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fe420
#include "pc2_port.h"

void __thiscall Branch_ApplyProductSales(void *self,void *arg1)

{
  void *this_00;
  int value1;
  int value2;
  char *cptr3;
  char *cptr4;
  uint32_t local_1a0 [12];
  char local_16e [366];
  
                    /* Applies branch product sales or its fallback charges. */
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x30));
  if (*(int *)((intptr_t)self + *(int *)((intptr_t)this_00 + 0x4c) * 0x168 + 0x114) == 0) {
    Array_Copy68(arg1,local_1a0);
    if ((*(uint8_t *)((intptr_t)arg1 + 0x1894) & 2) != 0) {
      Branch_AssignEntranceAndCustomerSlots(self,arg1,(intptr_t)local_1a0);
      Game_CanAffordWithCurrency(this_00,9,750.0,'\0',0xffffffff);
    }
    if ((*(uint8_t *)((intptr_t)arg1 + 0x1894) & 0x20) != 0) {
      Branch_AutoTunePrice(arg1);
      Game_CanAffordWithCurrency(this_00,9,350.0,'\0',0xffffffff);
    }
    Array_ClearStride34((intptr_t)arg1);
    return;
  }
  Array_Copy68(arg1,local_1a0);
  value2 = 0;
  value1 = 0;
  cptr4 = (char *)((intptr_t)arg1 + 0x1a08);
  do {
    if (cptr4[value1] != '\0') {
      value2 = value2 + 1;
    }
    value1 = value1 + 1;
  } while (value1 < 0x18);
  if (2 < value2) {
    value1 = 0;
    cptr3 = local_16e;
    do {
      if ((*cptr3 == '\0') && (*cptr4 != '\0')) {
        if (value1 < 8) {
          return;
        }
        break;
      }
      value1 = value1 + 1;
      cptr3 = cptr3 + 0x34;
      cptr4 = cptr4 + 3;
    } while (value1 < 8);
    Branch_AssignEntranceAndCustomerSlots(self,arg1,(intptr_t)local_1a0);
    Game_RefreshObjectCategoryBins(arg1);
    Game_UpdateMusicTheme((intptr_t)arg1,(intptr_t)local_1a0);
    Game_TryBuyCompletedHouse(self,arg1,(intptr_t)local_1a0);
    Array_ClearStride34((intptr_t)arg1);
    value1 = Company_RemoveAttachedBuildingObjects(arg1);
    if (value1 != 0) {
      Branch_AutoTunePrice(arg1);
    }
  }
  return;
}
