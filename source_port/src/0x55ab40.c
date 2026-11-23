// Unwind@0055ab40: ported from Pizza Connection 2 at 0x55ab40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ab40
#include "pc2_port.h"

void Unwind_0055ab40(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x20));
  return;
}
