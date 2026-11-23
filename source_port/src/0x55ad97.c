// Unwind@0055ad97: ported from Pizza Connection 2 at 0x55ad97.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ad97
#include "pc2_port.h"

void Unwind_0055ad97(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x344));
  return;
}
