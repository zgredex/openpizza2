// Unwind@0055ab80: ported from Pizza Connection 2 at 0x55ab80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ab80
#include "pc2_port.h"

void Unwind_0055ab80(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
