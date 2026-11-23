// Unwind@005592d4: ported from Pizza Connection 2 at 0x5592d4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5592d4
#include "pc2_port.h"

void Unwind_005592d4(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x1b8));
  return;
}
