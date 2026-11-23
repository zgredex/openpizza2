// Unwind@00558de2: ported from Pizza Connection 2 at 0x558de2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558de2
#include "pc2_port.h"

void Unwind_00558de2(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x118));
  return;
}
