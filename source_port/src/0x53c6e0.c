// SpriteCriticalSection_Init: ported from Pizza Connection 2 at 0x53c6e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53c6e0
#include "pc2_port.h"

void SpriteCriticalSection_Init(void)

{
                    /* Constructs the global SpriteCriticalSection named lock. */
  NamedLockable_Construct(&DAT_00585520,s_SpriteCriticalSection_005747c4);
  return;
}
