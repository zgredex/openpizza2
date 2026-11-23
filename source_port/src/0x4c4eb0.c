// SubMenu_Police_HandleControl: ported from Pizza Connection 2 at 0x4c4eb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c4eb0
#include "pc2_port.h"

void __cdecl SubMenu_Police_HandleControl(void *arg1,int arg2,int arg3)

{
  int value1;
  
                    /* Handles police submenu controls and bribe amounts. */
  if (arg3 == 1) {
    if (arg2 == 8000) {
      UI_ShowHelpTopicDialog(-0x51);
    }
    else if (arg2 == 0x1fee) {
      value1 = *(int *)((intptr_t)DAT_0057dcf4 + *(int *)((intptr_t)DAT_0057dcf8 + 0x48) * 4 + 0xcb0);
      if (999 < value1) {
        City_SetPlayerAdvertisingBudget
                  (DAT_0057dcf4,*(int *)((intptr_t)DAT_0057dcf8 + 0x48),value1 + -1000);
        PolicePage_FillContributionStats(arg1);
        return;
      }
    }
    else if (arg2 == 0x1fef) {
      Game_CanAffordWithCurrency(DAT_0057dcf8,0x15,1000.0,'\0',0xffffffff);
      City_SetPlayerAdvertisingBudget
                (DAT_0057dcf4,*(int *)((intptr_t)DAT_0057dcf8 + 0x48),
                 *(int *)((intptr_t)DAT_0057dcf4 + *(int *)((intptr_t)DAT_0057dcf8 + 0x48) * 4 + 0xcb0) + 1000
                );
      PolicePage_FillContributionStats(arg1);
      return;
    }
  }
  else if ((arg3 == 0x23) && (arg2 == -0x1863b)) {
    PolicePage_FillContributionStats(arg1);
    return;
  }
  return;
}
