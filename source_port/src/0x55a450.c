// Unwind@0055a450: ported from Pizza Connection 2 at 0x55a450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a450
#include "pc2_port.h"

void Unwind_0055a450(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}
