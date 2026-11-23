// Unwind@0055a490: ported from Pizza Connection 2 at 0x55a490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a490
#include "pc2_port.h"

void Unwind_0055a490(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x90));
  return;
}
