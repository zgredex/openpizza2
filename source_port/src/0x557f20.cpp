// Unwind@00557f20: ported from Pizza Connection 2 at 0x557f20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557f20
#include "pc2_port.h"

void Unwind_00557f20(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
