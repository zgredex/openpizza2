// Unwind@00558a2b: ported from Pizza Connection 2 at 0x558a2b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558a2b
#include "pc2_port.h"

void Unwind_00558a2b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}
