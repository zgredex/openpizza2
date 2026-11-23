// Unwind@00559180: ported from Pizza Connection 2 at 0x559180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559180
#include "pc2_port.h"

void Unwind_00559180(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}
