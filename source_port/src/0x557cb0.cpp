// Unwind@00557cb0: ported from Pizza Connection 2 at 0x557cb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557cb0
#include "pc2_port.h"

void Unwind_00557cb0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x15c));
  return;
}
