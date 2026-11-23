// UI_DrawNeighborhoodCustomerIcons: ported from Pizza Connection 2 at 0x4a53e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a53e0
#include "pc2_port.h"

void __cdecl UI_DrawNeighborhoodCustomerIcons(void *arg1,int arg2)

{
  uint32_t local_20 [8];
  
  if (*(int *)((intptr_t)DAT_0057c670 + 0x218) != 0) {
    Game_CountNearbyTypesAroundRect(DAT_0057c670,*(int *)((intptr_t)DAT_0057c670 + 0x218),0x78,local_20);
    CustomerGroups_DrawCountRow(arg1,arg2,(intptr_t)local_20);
  }
  return;
}
