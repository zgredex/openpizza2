// Unwind@0055947c: ported from Pizza Connection 2 at 0x55947c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55947c
#include "pc2_port.h"

void Unwind_0055947c(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x148));
  return;
}
