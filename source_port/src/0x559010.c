// Unwind@00559010: ported from Pizza Connection 2 at 0x559010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559010
#include "pc2_port.h"

void Unwind_00559010(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
