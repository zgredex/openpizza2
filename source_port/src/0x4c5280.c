// PestMenu_FillPricesAndCounts: ported from Pizza Connection 2 at 0x4c5280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c5280
#include "pc2_port.h"

void __cdecl PestMenu_FillPricesAndCounts(void *arg1)

{
  void *self;
  int value1;
  
  self = *(void **)(*(int *)(DAT_0057c670 + 0x9c) + 0x16f0);
  Gadget_SetText(arg1,0x1f76,DAT_00581b1c);
  Gadget_SetText(arg1,0x1f51,DAT_00581b1c);
  value1 = Game_CountFreeBuildingsByType(self,0x1a);
  Gadget_SetTextf(arg1,0x1f55,&DAT_005686f4,value1);
  value1 = Game_CountFreeBuildingsByType(self,0x1c);
  Gadget_SetTextf(arg1,0x1f5c,&DAT_005686f4,value1);
  value1 = Game_CountFreeBuildingsByType(self,0x1b);
  Gadget_SetTextf(arg1,0x1f5d,&DAT_005686f4,value1);
  Gadget_SetTextf(arg1,0x1f75,&DAT_005683a4,1000);
  Gadget_SetTextf(arg1,0x1f4f,&DAT_005683a4,10000);
  return;
}
