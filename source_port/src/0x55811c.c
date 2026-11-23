// Unwind@0055811c: ported from Pizza Connection 2 at 0x55811c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55811c
#include "pc2_port.h"

void Unwind_0055811c(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x14) + 0x74));
  return;
}
