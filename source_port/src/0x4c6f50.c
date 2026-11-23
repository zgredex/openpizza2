// CharacterSelect_DrawPortrait: ported from Pizza Connection 2 at 0x4c6f50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c6f50
#include "pc2_port.h"

void __cdecl CharacterSelect_DrawPortrait(void *arg1)

{
  UI_ComposeOverlayWindow
            (arg1,0x433,DAT_0057ddac,DAT_0057dda4,DAT_0057ddfc,DAT_0057dda0,DAT_0057ddb8);
  return;
}
