// Unwind@0055935c: ported from Pizza Connection 2 at 0x55935c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55935c
#include "pc2_port.h"

void Unwind_0055935c(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x148));
  return;
}
