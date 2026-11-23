// Clear_Ptr: ported from Pizza Connection 2 at 0x403190.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403190
#include "pc2_port.h"

void __fastcall Clear_Ptr(uint32_t *arg1)

{
  *arg1 = 0;
  return;
}
