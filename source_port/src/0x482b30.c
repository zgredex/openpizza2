// UI_ShowAIStatusWindow: ported from Pizza Connection 2 at 0x482b30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482b30
#include "pc2_port.h"

void __fastcall UI_ShowAIStatusWindow(int arg1)

{
  void *pvVar1;
  int local_4;
  
                    /* Opens the cheat/debug AI status window. */
  if (*(int *)(arg1 + 0x268) == 0) {
    local_4 = arg1;
    pvVar1 = AI_DebugStatusWindow_Create(&local_4);
    *(void **)(arg1 + 0x268) = pvVar1;
    CheatMenu_InitCompanyPage(pvVar1);
    Window_ShowWindowById(DAT_0057c5e0,local_4);
  }
  return;
}
