// Unwind@00558c52: ported from Pizza Connection 2 at 0x558c52.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558c52
#include "pc2_port.h"

void Unwind_00558c52(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
