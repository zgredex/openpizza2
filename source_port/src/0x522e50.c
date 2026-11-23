// ArrayLock_Init: ported from Pizza Connection 2 at 0x522e50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522e50
#include "pc2_port.h"

void ArrayLock_Init(void)

{
                    /* Constructs the global Liste lock used by the array implementation. */
  NamedLockable_Construct(&DAT_00584180,s_Liste_0056313c);
  return;
}
