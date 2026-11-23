// Unwind@00558ff0: ported from Pizza Connection 2 at 0x558ff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558ff0
#include "pc2_port.h"

void Unwind_00558ff0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x14));
  return;
}
