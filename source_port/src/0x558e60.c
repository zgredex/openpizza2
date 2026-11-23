// Unwind@00558e60: ported from Pizza Connection 2 at 0x558e60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558e60
#include "pc2_port.h"

void Unwind_00558e60(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
