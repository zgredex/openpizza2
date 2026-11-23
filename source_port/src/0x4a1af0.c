// SaveGameList_Destroy: ported from Pizza Connection 2 at 0x4a1af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a1af0
#include "pc2_port.h"

void SaveGameList_Destroy(void)

{
  IDMap_DestroyAllObjects(&DAT_0057cfc8);
  return;
}
