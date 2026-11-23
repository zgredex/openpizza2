// Unwind@00559abd: ported from Pizza Connection 2 at 0x559abd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559abd
#include "pc2_port.h"

void Unwind_00559abd(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
