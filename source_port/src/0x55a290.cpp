// Unwind@0055a290: ported from Pizza Connection 2 at 0x55a290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a290
#include "pc2_port.h"

void Unwind_0055a290(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
