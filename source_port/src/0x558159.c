// Unwind@00558159: ported from Pizza Connection 2 at 0x558159.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558159
#include "pc2_port.h"

void Unwind_00558159(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
