// Unwind@00559447: ported from Pizza Connection 2 at 0x559447.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559447
#include "pc2_port.h"

void Unwind_00559447(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
