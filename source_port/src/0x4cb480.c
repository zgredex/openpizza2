// FreePlaySetup_RefreshPlayerProfiles: ported from Pizza Connection 2 at 0x4cb480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb480
#include "pc2_port.h"

void __cdecl FreePlaySetup_RefreshPlayerProfiles(void *arg1)

{
  uint32_t uvalue1;
  int *ptr2;
  int value3;
  int value4;
  
                    /* Shows or hides free-play player-profile slots. */
  value3 = 0;
  value4 = 1;
  ptr2 = &DAT_0057bdd4;
  do {
    if (*ptr2 != 0) {
      value3 = value3 + 1;
    }
    FreePlaySetup_SetOpponentSlotEnabled(arg1,value4,(uint32_t)(*ptr2 != 0));
    ptr2 = ptr2 + 0x30;
    value4 = value4 + 1;
  } while ((intptr_t)ptr2 < 0x57c194);
  uvalue1 = (uint32_t)(0 < value3);
  UI_SetChildVisibleByID(arg1,0x4a3,uvalue1);
  UI_SetChildVisibleByID(arg1,0x439,uvalue1);
  UI_SetChildVisibleByID(arg1,0x48b,uvalue1);
  UI_SetChildVisibleByID(arg1,0x48c,uvalue1);
  UI_SetChildVisibleByID(arg1,0x48d,uvalue1);
  value3 = 0x482;
  do {
    UI_SetChildVisibleByID(arg1,value3,uvalue1);
    value3 = value3 + 1;
  } while (value3 < 0x48b);
  return;
}
