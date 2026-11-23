// Unwind@00558d20: ported from Pizza Connection 2 at 0x558d20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558d20
#include "pc2_port.h"

void Unwind_00558d20(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
