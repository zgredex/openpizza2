// Unwind@00559410: ported from Pizza Connection 2 at 0x559410.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559410
#include "pc2_port.h"

void Unwind_00559410(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
