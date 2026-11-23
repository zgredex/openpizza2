// Unwind@0055b96c: ported from Pizza Connection 2 at 0x55b96c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b96c
#include "pc2_port.h"

void Unwind_0055b96c(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}
