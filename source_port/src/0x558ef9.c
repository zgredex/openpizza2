// Unwind@00558ef9: ported from Pizza Connection 2 at 0x558ef9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558ef9
#include "pc2_port.h"

void Unwind_00558ef9(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
