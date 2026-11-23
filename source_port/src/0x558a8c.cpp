// Unwind@00558a8c: ported from Pizza Connection 2 at 0x558a8c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558a8c
#include "pc2_port.h"

void Unwind_00558a8c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
