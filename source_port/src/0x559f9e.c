// Unwind@00559f9e: ported from Pizza Connection 2 at 0x559f9e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559f9e
#include "pc2_port.h"

void Unwind_00559f9e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x438));
  return;
}
