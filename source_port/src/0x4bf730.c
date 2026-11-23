// SyndicateMenu_FillStaffCounts: ported from Pizza Connection 2 at 0x4bf730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bf730
#include "pc2_port.h"

void __cdecl SyndicateMenu_FillStaffCounts(void *arg1)

{
  void *self;
  void *this_00;
  int value1;
  int value2;
  int value3;
  int value4;
  uint32_t uvalue5;
  
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  Gadget_SetTextf(arg1,0x1f93,(uint8_t *)s__s__d_00568964,DAT_00580d98);
  this_00 = *(void **)((intptr_t)self + 0x1d8);
  value1 = Game_CountFreeBuildingsByType(this_00,0x1f);
  Gadget_SetTextf(arg1,0x1f59,&DAT_005686f4,value1);
  value2 = AI_CountActiveTargetsByState(self,0x1f);
  Gadget_SetTextf(arg1,0x1f58,&DAT_005686f4,value2);
  value3 = Game_CountActiveObjectsByType(self,0x1f);
  value4 = Game_GetLevelReward(self,0x1f);
  if (value3 < value4) {
    uvalue5 = 0;
  }
  else {
    uvalue5 = 0xff;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1f95,uvalue5);
  Gadget_SetTextf(arg1,0x1f95,&DAT_005686f4,value4);
  Gadget_SetTextf(arg1,0x1f57,&DAT_005686f4,(value3 - value2) - value1);
  value1 = Game_CountFreeBuildingsByType(this_00,0x1e);
  Gadget_SetTextf(arg1,0x1f54,&DAT_005686f4,value1);
  value2 = AI_CountActiveTargetsByState(self,0x1e);
  Gadget_SetTextf(arg1,0x1f52,&DAT_005686f4,value2);
  value3 = Game_CountActiveObjectsByType(self,0x1e);
  value4 = Game_GetLevelReward(self,0x1e);
  if (value3 < value4) {
    uvalue5 = 0;
  }
  else {
    uvalue5 = 0xff;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1f94,uvalue5);
  Gadget_SetTextf(arg1,0x1f94,&DAT_005686f4,value4);
  Gadget_SetTextf(arg1,0x1f50,&DAT_005686f4,(value3 - value2) - value1);
  value1 = Game_CountFreeBuildingsByType(this_00,0x1d);
  Gadget_SetTextf(arg1,0x1f8e,&DAT_005686f4,value1);
  value2 = AI_CountActiveTargetsByState(self,0x1d);
  Gadget_SetTextf(arg1,0x1f8d,&DAT_005686f4,value2);
  value3 = Game_CountActiveObjectsByType(self,0x1d);
  value4 = Game_GetLevelReward(self,0x1d);
  if (value3 < value4) {
    uvalue5 = 0;
  }
  else {
    uvalue5 = 0xff;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1f96,uvalue5);
  Gadget_SetTextf(arg1,0x1f96,&DAT_005686f4,value4);
  Gadget_SetTextf(arg1,0x1f8c,&DAT_005686f4,(value3 - value2) - value1);
  return;
}
