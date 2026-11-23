// Unwind@005592b8: ported from Pizza Connection 2 at 0x5592b8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5592b8
#include "pc2_port.h"

void Unwind_005592b8(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x180));
  return;
}
