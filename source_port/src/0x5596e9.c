// Unwind@005596e9: ported from Pizza Connection 2 at 0x5596e9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5596e9
#include "pc2_port.h"

void Unwind_005596e9(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
