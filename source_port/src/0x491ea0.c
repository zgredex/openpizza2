// BuildingInfoMenu_Init: ported from Pizza Connection 2 at 0x491ea0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x491ea0
#include "pc2_port.h"


void __cdecl BuildingInfoMenu_Init(void *arg1)

{
                    /* Initializes the building-info submenu page. */
  UI_SetPosition(arg1,&LAB_00491990,0);
  if (DAT_0057c6b0 != 0) {
    UI_ReleaseRefCount(DAT_0057c5e0,DAT_0057c6b0);
  }
  DAT_0057c6b0 = UI_LoadFontByName(DAT_0057c5e0,s_VERDANA7_fnt_00563ec8);
  BranchStats_UpdateRatingPage(arg1);
  return;
}
