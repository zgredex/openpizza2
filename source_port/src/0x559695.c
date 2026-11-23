// Unwind@00559695: ported from Pizza Connection 2 at 0x559695.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559695
#include "pc2_port.h"

void Unwind_00559695(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
