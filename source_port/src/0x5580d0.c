// Unwind@005580d0: ported from Pizza Connection 2 at 0x5580d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5580d0
#include "pc2_port.h"

void Unwind_005580d0(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(unaff_EBP + -0x28));
  return;
}
