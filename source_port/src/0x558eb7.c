// Unwind@00558eb7: ported from Pizza Connection 2 at 0x558eb7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558eb7
#include "pc2_port.h"

void Unwind_00558eb7(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
