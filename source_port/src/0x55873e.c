// Unwind@0055873e: ported from Pizza Connection 2 at 0x55873e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55873e
#include "pc2_port.h"

void Unwind_0055873e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x230));
  return;
}
