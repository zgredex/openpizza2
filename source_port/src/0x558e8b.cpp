// Unwind@00558e8b: ported from Pizza Connection 2 at 0x558e8b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558e8b
#include "pc2_port.h"

void Unwind_00558e8b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
