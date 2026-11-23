// CheatMenu_InitCompanyPage: ported from Pizza Connection 2 at 0x4c5fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c5fc0
#include "pc2_port.h"

void __cdecl CheatMenu_InitCompanyPage(void *arg1)

{
                    /* Initializes the cheat/debug company page. */
  UI_DisableButton(arg1,0x1f50);
  UI_DisableButton(arg1,0x1f51);
  UI_DisableButton(arg1,0x1f57);
  UI_DisableButton(arg1,0x1f58);
  AIStatus_UpdateCompanyPanel(arg1);
  return;
}
