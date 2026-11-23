// Unwind@0055b040: ported from Pizza Connection 2 at 0x55b040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b040
#include "pc2_port.h"

void Unwind_0055b040(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x88));
  return;
}
