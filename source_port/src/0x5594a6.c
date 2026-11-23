// Unwind@005594a6: ported from Pizza Connection 2 at 0x5594a6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5594a6
#include "pc2_port.h"

void Unwind_005594a6(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x19c));
  return;
}
