// SaveGame_DestroyList: ported from Pizza Connection 2 at 0x4cde30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cde30
#include "pc2_port.h"

void SaveGame_DestroyList(void)

{
  IDMap_DestroyAllObjects(&DAT_0057df84);
  return;
}
