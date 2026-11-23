// Unwind@005582eb: ported from Pizza Connection 2 at 0x5582eb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5582eb
#include "pc2_port.h"

void Unwind_005582eb(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}
