// Unwind@00557cee: ported from Pizza Connection 2 at 0x557cee.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557cee
#include "pc2_port.h"

void Unwind_00557cee(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x144));
  return;
}
