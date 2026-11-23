// Unwind@005590be: ported from Pizza Connection 2 at 0x5590be.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5590be
#include "pc2_port.h"

void Unwind_005590be(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0xfc8));
  return;
}
