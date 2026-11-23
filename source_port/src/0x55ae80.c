// Unwind@0055ae80: ported from Pizza Connection 2 at 0x55ae80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ae80
#include "pc2_port.h"

void Unwind_0055ae80(void)

{
  int unaff_EBP;
  
  CS_LeavePtr((uint32_t *)(unaff_EBP + -0x7c));
  return;
}
