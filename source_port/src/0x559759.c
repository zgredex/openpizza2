// Unwind@00559759: ported from Pizza Connection 2 at 0x559759.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559759
#include "pc2_port.h"

void Unwind_00559759(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
