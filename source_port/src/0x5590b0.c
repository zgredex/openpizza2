// Unwind@005590b0: ported from Pizza Connection 2 at 0x5590b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5590b0
#include "pc2_port.h"

void Unwind_005590b0(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0xfac));
  return;
}
