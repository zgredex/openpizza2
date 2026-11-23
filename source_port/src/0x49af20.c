// AdvertisingMenu_UpdatePage: ported from Pizza Connection 2 at 0x49af20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49af20
#include "pc2_port.h"

void __cdecl AdvertisingMenu_UpdatePage(void *arg1)

{
  void *self;
  int value1;
  int value2;
  uint32_t uvalue3;
  
                    /* Refreshes the advertising page tabs and group prices. */
  DAT_0057ca34 = *(uint32_t *)(DAT_0057c670 + 0x2f4);
  uvalue3 = (uint32_t)*(uint16_t *)
                 (*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x5c);
  UI_Group_Create(arg1,0,3,0x436);
  Window_GadgetNotify_Button_SetState(arg1,DAT_0057ca30 + 0x436,1);
  UI_Group_Create(arg1,1,8,0x45b);
  AdvertisingScreen_UpdateGroupPrices(arg1);
  Window_GadgetNotify_Button_SetState(arg1,0x434,uvalue3 & 0x10);
  Window_GadgetNotify_Button_SetState(arg1,0x435,uvalue3 & 0x20);
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  if (*(int *)(value1 + 0xc20 + value2 * 4) < 3) {
    UI_SetChildVisibleByID(arg1,0x434,0);
    UI_SetChildVisibleByID(arg1,0x435,0);
    UI_SetChildVisibleByID(arg1,0x43d,0);
    UI_SetChildVisibleByID(arg1,0x43e,0);
    UI_SetChildVisibleByID(arg1,0x43f,0);
  }
  self = *(void **)(DAT_0057c670 + 0x98);
  if (self == (void *)0x0) {
    value1 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x4e9,value1,0,0);
      value1 = value1 + 1;
    } while (value1 < 8);
    return;
  }
  value1 = 0;
  do {
    value2 = Game_MapInputIndex(self,value1);
    Rating_UpdateBarByKey(arg1,0x4e9,value1,value2,DAT_0058155c);
    value1 = value1 + 1;
  } while (value1 < 8);
  return;
}
