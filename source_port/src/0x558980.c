// Unwind@00558980: ported from Pizza Connection 2 at 0x558980.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558980
#include "pc2_port.h"

void Unwind_00558980(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}
