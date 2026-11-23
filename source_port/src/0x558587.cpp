// Unwind@00558587: ported from Pizza Connection 2 at 0x558587.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558587
#include "pc2_port.h"

void Unwind_00558587(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
