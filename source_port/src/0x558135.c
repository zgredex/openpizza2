// Unwind@00558135: ported from Pizza Connection 2 at 0x558135.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558135
#include "pc2_port.h"

void Unwind_00558135(void)

{
  int unaff_EBP;
  
  Timer_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x14) + 0x2d1c));
  return;
}
