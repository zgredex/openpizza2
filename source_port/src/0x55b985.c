// Unwind@0055b985: ported from Pizza Connection 2 at 0x55b985.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b985
#include "pc2_port.h"

void Unwind_0055b985(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0xac));
  return;
}
