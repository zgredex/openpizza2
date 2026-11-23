// Unwind@0055a43b: ported from Pizza Connection 2 at 0x55a43b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a43b
#include "pc2_port.h"

void Unwind_0055a43b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
