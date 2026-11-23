// Unwind@0055ba5c: ported from Pizza Connection 2 at 0x55ba5c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ba5c
#include "pc2_port.h"

void Unwind_0055ba5c(void)

{
  int unaff_EBP;
  
  Thunk_SetVTable55CCA4(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}
