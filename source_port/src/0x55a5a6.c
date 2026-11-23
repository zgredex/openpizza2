// Unwind@0055a5a6: ported from Pizza Connection 2 at 0x55a5a6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a5a6
#include "pc2_port.h"

void Unwind_0055a5a6(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x1c));
  return;
}
