// Unwind@00558a4b: ported from Pizza Connection 2 at 0x558a4b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558a4b
#include "pc2_port.h"

void Unwind_00558a4b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
