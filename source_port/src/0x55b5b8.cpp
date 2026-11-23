// Unwind@0055b5b8: ported from Pizza Connection 2 at 0x55b5b8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b5b8
#include "pc2_port.h"

void Unwind_0055b5b8(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
