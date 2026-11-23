// Unwind@00558b1b: ported from Pizza Connection 2 at 0x558b1b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558b1b
#include "pc2_port.h"

void Unwind_00558b1b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
