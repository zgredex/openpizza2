// UI_CloseLoadingScreen: ported from Pizza Connection 2 at 0x406a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x406a60
#include "pc2_port.h"

void UI_CloseLoadingScreen(void)

{
  UI_ReplaceActiveObject(DAT_0057c5e0,0);
  Clear_Field228((intptr_t)DAT_0057c5e0);
  Window_DestroyChild(DAT_0057c5e0,DAT_0057c5f4);
  return;
}
