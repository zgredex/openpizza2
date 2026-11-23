// Unwind@0055a330: ported from Pizza Connection 2 at 0x55a330.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a330
#include "pc2_port.h"

void Unwind_0055a330(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(unaff_EBP + -0x28));
  return;
}
