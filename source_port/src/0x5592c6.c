// Unwind@005592c6: ported from Pizza Connection 2 at 0x5592c6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5592c6
#include "pc2_port.h"

void Unwind_005592c6(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x19c));
  return;
}
