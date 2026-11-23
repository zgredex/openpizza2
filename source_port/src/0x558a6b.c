// Unwind@00558a6b: ported from Pizza Connection 2 at 0x558a6b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558a6b
#include "pc2_port.h"

void Unwind_00558a6b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
