// Unwind@00558260: ported from Pizza Connection 2 at 0x558260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558260
#include "pc2_port.h"

void Unwind_00558260(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
