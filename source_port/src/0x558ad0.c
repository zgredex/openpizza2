// Unwind@00558ad0: ported from Pizza Connection 2 at 0x558ad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558ad0
#include "pc2_port.h"

void Unwind_00558ad0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
