// Unwind@00559919: ported from Pizza Connection 2 at 0x559919.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559919
#include "pc2_port.h"

void Unwind_00559919(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
