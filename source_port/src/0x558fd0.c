// Unwind@00558fd0: ported from Pizza Connection 2 at 0x558fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558fd0
#include "pc2_port.h"

void Unwind_00558fd0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x14));
  return;
}
