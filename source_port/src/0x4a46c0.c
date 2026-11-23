// CompanyOverview_UpdateCityInfo: ported from Pizza Connection 2 at 0x4a46c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a46c0
#include "pc2_port.h"

void __cdecl CompanyOverview_UpdateCityInfo(void *arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  int value4;
  uint32_t uvalue5;
  
  pvVar1 = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value2 = Game_GetPlayerCity((intptr_t)pvVar1);
  value4 = *(int *)(value2 + 0x68);
  value2 = *(int *)(value2 + 0x50);
  value3 = Game_CountActiveObjectsByType(pvVar1,0x17);
  pvVar1 = *(void **)((intptr_t)pvVar1 + 0x1d8);
  value4 = (((value4 + value2) * -0x1e + 100) * 500) / 100;
  Gadget_SetTextf(arg1,0x1f74,&DAT_005686f4,value4);
  Gadget_SetTextf(arg1,0x1f78,&DAT_005686f4,value4 * value3);
  Gadget_SetTextf(arg1,0x1f7a,&DAT_005686f4,value3);
  value4 = Game_CountFreeSlots(DAT_0057c670,0x17);
  if (value4 == 0) {
    uvalue5 = 0xff;
  }
  else {
    uvalue5 = 0;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1fbc,uvalue5);
  Gadget_SetTextf(arg1,0x1fbc,&DAT_005686f4,value4);
  value4 = Game_CountFreeBuildingsByType(pvVar1,0x17);
  if (value4 == 0) {
    uvalue5 = 0xff;
  }
  else {
    uvalue5 = 0;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1f59,uvalue5);
  Gadget_SetTextf(arg1,0x1f59,&DAT_005686f4,value4);
  return;
}
