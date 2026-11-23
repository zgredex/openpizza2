// BauenPage_ResetBuildingSlots: ported from Pizza Connection 2 at 0x4a5420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a5420
#include "pc2_port.h"

void __cdecl BauenPage_ResetBuildingSlots(void *arg1)

{
  Array_SetField14ByKey(arg1,0x1f79,0);
  Array_SetField14ByKey(arg1,0x1f7a,0);
  Array_SetField14ByKey(arg1,0x1f7b,0);
  Array_SetField14ByKey(arg1,0x1f7c,0);
  UI_SetChildLabelText(arg1,0x1f68,1,(char *)0x0);
  UI_SetChildLabelText(arg1,0x1f69,1,(char *)0x0);
  UI_SetChildLabelText(arg1,0x1f6a,1,(char *)0x0);
  UI_SetChildLabelText(arg1,0x1f6b,1,(char *)0x0);
  UI_RemoveProfileStatElements(arg1);
  UI_DrawNeighborhoodCustomerIcons(arg1,0x43f);
  return;
}
