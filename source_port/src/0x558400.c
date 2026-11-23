// Unwind@00558400: ported from Pizza Connection 2 at 0x558400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558400
#include "pc2_port.h"

void Unwind_00558400(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x23c));
  return;
}
