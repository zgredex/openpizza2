// Unwind@00558cc0: ported from Pizza Connection 2 at 0x558cc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558cc0
#include "pc2_port.h"

void Unwind_00558cc0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
