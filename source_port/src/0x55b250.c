// Unwind@0055b250: ported from Pizza Connection 2 at 0x55b250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b250
#include "pc2_port.h"

void Unwind_0055b250(void)

{
  int unaff_EBP;
  
  CS_LeavePtr((uint32_t *)(unaff_EBP + 4));
  return;
}
