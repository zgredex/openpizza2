// Unwind@00557cbe: ported from Pizza Connection 2 at 0x557cbe.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557cbe
#include "pc2_port.h"

void Unwind_00557cbe(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x15c));
  return;
}
