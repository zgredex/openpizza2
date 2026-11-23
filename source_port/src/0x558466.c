// Unwind@00558466: ported from Pizza Connection 2 at 0x558466.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558466
#include "pc2_port.h"

void Unwind_00558466(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
