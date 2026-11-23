// BuildingMarket_ShowSelectedBuildingInfo: ported from Pizza Connection 2 at 0x4a6fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a6fc0
#include "pc2_port.h"

void __cdecl BuildingMarket_ShowSelectedBuildingInfo(void *arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int *ptr4;
  int local_28;
  int local_24;
  uint8_t local_20 [32];
  
  if (DAT_0057d27c != 0) {
    switch(*(uint32_t *)(DAT_0057d27c + 4)) {
    default:
      DAT_0057d294 = 0;
      uvalue2 = DAT_00582020;
      break;
    case 0x15:
    case 0x1e:
      DAT_0057d294 = 1;
      uvalue2 = DAT_00582008;
      break;
    case 0x16:
    case 0x1f:
      DAT_0057d294 = 2;
      uvalue2 = DAT_00582f40;
    }
    String_Format(local_20,&DAT_005630d0,uvalue2);
    if (DAT_0057d280 == 0) {
      value3 = 1;
      Window_GadgetNotify_Text_SetText(arg1,0x4f6,local_20);
      Window_GadgetNotify_Text_SetText(arg1,0x1f41,DAT_00582e4c);
      uvalue2 = DAT_005816bc;
    }
    else {
      value3 = 3;
      Window_GadgetNotify_Text_SetText(arg1,0x4f6,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(arg1,0x1f41,local_20);
      uvalue2 = DAT_005816b0;
    }
    Window_GadgetNotify_Text_SetText(arg1,0x1f4d,uvalue2);
    ptr4 = (int *)0x0;
    value1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    Game_ComputeTradeOffers(DAT_0057d290,DAT_0057d27c,value3,&local_28,&local_24,value1,ptr4);
    String_Format(local_20,&DAT_005683a4,local_28);
    Window_GadgetNotify_Text_SetText(arg1,0x4f9,local_20);
    *(int *)(DAT_0057c670 + 0x218) = DAT_0057d27c;
    Game_CenterViewOnObject(DAT_0057d27c);
    Submenu_SetObjectPicture(arg1,*(int *)(DAT_0057d27c + 0x20),1,0x1f57,-1,DAT_0057d27c);
  }
  return;
}
