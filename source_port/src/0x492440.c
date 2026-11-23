// CompanyMenu_InitStylePage: ported from Pizza Connection 2 at 0x492440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x492440
#include "pc2_port.h"

void __cdecl CompanyMenu_InitStylePage(void *arg1)

{
                    /* Initializes the company style-selection page. */
  UI_Group_Create(arg1,0,3,0x1f4a);
  Window_GadgetNotify_Button_SetState(arg1,DAT_0057c6b8 + 0x1f4a,1);
  RenovationScreen_UpdatePage(arg1);
  return;
}
