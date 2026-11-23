// Unwind@00558ed8: ported from Pizza Connection 2 at 0x558ed8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558ed8
#include "pc2_port.h"

void Unwind_00558ed8(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
