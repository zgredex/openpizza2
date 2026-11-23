// Map_MissingNameFallback: ported from Pizza Connection 2 at 0x4eb8e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eb8e0
#include "pc2_port.h"

uint32_t Map_MissingNameFallback(void)

{
  Debug_WarningMessageBox();
  return 0xffffffff;
}
