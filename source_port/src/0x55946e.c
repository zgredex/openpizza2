// Unwind@0055946e: ported from Pizza Connection 2 at 0x55946e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55946e
#include "pc2_port.h"

void Unwind_0055946e(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 300));
  return;
}
