// Unwind@005585ee: ported from Pizza Connection 2 at 0x5585ee.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5585ee
#include "pc2_port.h"

void Unwind_005585ee(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x328));
  return;
}
