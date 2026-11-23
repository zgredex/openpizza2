// Unwind@0055a67d: ported from Pizza Connection 2 at 0x55a67d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a67d
#include "pc2_port.h"

void Unwind_0055a67d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
