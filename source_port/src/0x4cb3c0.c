// FreePlaySetup_SetOpponentSlotEnabled: ported from Pizza Connection 2 at 0x4cb3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb3c0
#include "pc2_port.h"

void __cdecl FreePlaySetup_SetOpponentSlotEnabled(void *arg1,int arg2,uint32_t arg3)

{
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  
                    /* Enables or disables a free-play computer-opponent slot. */
  value1 = arg2;
  value2 = arg2 + -1;
  uvalue4 = arg3 & 0xff;
  UI_SetChildVisibleByID(arg1,arg2 + 0x440 + value2,uvalue4);
  UI_SetChildVisibleByID(arg1,arg2 + 0x441 + value2,uvalue4);
  value3 = value2 * 8 + 0x454;
  arg2 = 8;
  do {
    UI_SetChildVisibleByID(arg1,value3,uvalue4);
    value3 = value3 + 1;
    arg2 = arg2 + -1;
  } while (arg2 != 0);
  UI_SetChildVisibleByID(arg1,value2 * 4 + 0x4c0,uvalue4);
  UI_SetChildVisibleByID(arg1,value2 * 4 + 0x4c2,uvalue4);
  UI_SetChildVisibleByID(arg1,value1 + 0x4db,uvalue4);
  UI_SetChildVisibleByID(arg1,*(int *)(&DAT_0056b2dc + value2 * 4),uvalue4);
  UI_SetChildVisibleByID(arg1,*(int *)(&DAT_0056b2f0 + value2 * 4),uvalue4);
  UI_SetChildVisibleByID(arg1,*(int *)(&DAT_0056b304 + value2 * 4),uvalue4);
  return;
}
