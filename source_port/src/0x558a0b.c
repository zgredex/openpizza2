// Unwind@00558a0b: ported from Pizza Connection 2 at 0x558a0b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558a0b
#include "pc2_port.h"

void Unwind_00558a0b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
