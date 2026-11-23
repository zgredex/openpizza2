// Unwind@00559ced: ported from Pizza Connection 2 at 0x559ced.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559ced
#include "pc2_port.h"

void Unwind_00559ced(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
