// Unwind@00558a60: ported from Pizza Connection 2 at 0x558a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558a60
#include "pc2_port.h"

void Unwind_00558a60(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
