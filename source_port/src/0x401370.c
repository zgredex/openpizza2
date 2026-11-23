// ListLock_Init: ported from Pizza Connection 2 at 0x401370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401370
#include "pc2_port.h"

void ListLock_Init(void)

{
                    /* Constructs the global Liste lock used by the list/ID-map module. */
  NamedLockable_Construct(&DAT_00579af0,s_Liste_0056313c);
  return;
}
