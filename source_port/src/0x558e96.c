// Unwind@00558e96: ported from Pizza Connection 2 at 0x558e96.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558e96
#include "pc2_port.h"

void Unwind_00558e96(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
