// Unwind@00559aaf: ported from Pizza Connection 2 at 0x559aaf.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559aaf
#include "pc2_port.h"

void Unwind_00559aaf(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
