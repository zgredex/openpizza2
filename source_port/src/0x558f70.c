// Unwind@00558f70: ported from Pizza Connection 2 at 0x558f70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558f70
#include "pc2_port.h"

void Unwind_00558f70(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x50));
  return;
}
