// UI_ComposeOverlayWindowFromRecord: ported from Pizza Connection 2 at 0x54bb00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54bb00
#include "pc2_port.h"

void UI_ComposeOverlayWindowFromRecord(void *arg1,int arg2,int arg3)

{
  UI_ComposeOverlayWindow
            (arg1,arg2,*(int *)(arg3 + 0x24),*(void **)(arg3 + 0x34),
             *(int *)(arg3 + 0x2c),*(int *)(arg3 + 0x28),*(int *)(arg3 + 0x30));
  return;
}
