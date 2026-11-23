// Unwind@0055b530: ported from Pizza Connection 2 at 0x55b530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b530
#include "pc2_port.h"

void Unwind_0055b530(void)

{
  int unaff_EBP;
  
  CS_LeavePtr((uint32_t *)(unaff_EBP + -0x70));
  return;
}
