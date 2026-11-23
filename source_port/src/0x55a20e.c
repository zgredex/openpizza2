// Unwind@0055a20e: ported from Pizza Connection 2 at 0x55a20e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a20e
#include "pc2_port.h"

void Unwind_0055a20e(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x130));
  return;
}
