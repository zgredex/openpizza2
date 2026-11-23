// Unwind@00558a81: ported from Pizza Connection 2 at 0x558a81.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558a81
#include "pc2_port.h"

void Unwind_00558a81(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
