// MusicMenu_Init: ported from Pizza Connection 2 at 0x490b00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x490b00
#include "pc2_port.h"


void __cdecl MusicMenu_Init(void *arg1)

{
                    /* Initializes the music selection submenu page. */
  *(uint32_t *)(DAT_0057c5e0 + 0x831c) = 1;
  DAT_0057c6ac = *(uint32_t *)(DAT_0057c670 + 0x354);
  UI_SetPosition(arg1,&LAB_004900e0,0);
  UI_Group_Create(arg1,0,6,0x3f4);
  Window_GadgetNotify_Button_SetState(arg1,*(int *)(&DAT_00568408 + DAT_0057c6a8 * 4),1);
  UI_Group_Create(arg1,1,0xc,0x596);
  FurnitureMenu_UpdatePage(arg1);
  return;
}
