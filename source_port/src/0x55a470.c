// Unwind@0055a470: ported from Pizza Connection 2 at 0x55a470.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a470
#include "pc2_port.h"

void Unwind_0055a470(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x48) + 0x48));
  return;
}
