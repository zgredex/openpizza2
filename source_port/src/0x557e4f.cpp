// Unwind@00557e4f: ported from Pizza Connection 2 at 0x557e4f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557e4f
#include "pc2_port.h"

void Unwind_00557e4f(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
