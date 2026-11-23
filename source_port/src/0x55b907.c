// Unwind@0055b907: ported from Pizza Connection 2 at 0x55b907.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b907
#include "pc2_port.h"

void Unwind_0055b907(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x90));
  return;
}
