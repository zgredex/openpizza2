// Unwind@0055973d: ported from Pizza Connection 2 at 0x55973d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55973d
#include "pc2_port.h"

void Unwind_0055973d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
