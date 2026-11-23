// Unwind@0055ba0c: ported from Pizza Connection 2 at 0x55ba0c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ba0c
#include "pc2_port.h"

void Unwind_0055ba0c(void)

{
  int unaff_EBP;
  
  COM_SetSecondaryVTable(*(int *)(unaff_EBP + -0x14) + 0xc);
  return;
}
