// Unwind@0055ba52: ported from Pizza Connection 2 at 0x55ba52.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ba52
#include "pc2_port.h"

void Unwind_0055ba52(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x14));
  return;
}
