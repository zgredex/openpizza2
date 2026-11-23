// Unwind@00558090: ported from Pizza Connection 2 at 0x558090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558090
#include "pc2_port.h"

void Unwind_00558090(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
