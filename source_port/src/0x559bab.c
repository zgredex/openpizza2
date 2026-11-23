// Unwind@00559bab: ported from Pizza Connection 2 at 0x559bab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559bab
#include "pc2_port.h"

void Unwind_00559bab(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
