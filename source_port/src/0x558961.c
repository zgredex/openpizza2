// Unwind@00558961: ported from Pizza Connection 2 at 0x558961.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558961
#include "pc2_port.h"

void Unwind_00558961(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
