// SaveGameMenu_DestroyList: ported from Pizza Connection 2 at 0x4a0a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a0a60
#include "pc2_port.h"

void SaveGameMenu_DestroyList(void)

{
  IDMap_DestroyAllObjects(&DAT_0057cdb4);
  return;
}
