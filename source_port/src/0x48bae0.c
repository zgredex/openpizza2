// Game_ShowFindPersonPrompt: ported from Pizza Connection 2 at 0x48bae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48bae0
#include "pc2_port.h"

void __fastcall Game_ShowFindPersonPrompt(void *arg1)

{
  int value1;
  uint32_t *uptr2;
  uint32_t local_40 [16];
  
                    /* Shows the find-person prompt. */
  uptr2 = local_40;
  for (value1 = 0x10; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  UI_ShowAmountEntryDialog(arg1,'\x01',0xfffe79e6,DAT_00582ab4,DAT_00582420,local_40,0,0,0);
  return;
}
