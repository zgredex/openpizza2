// Unwind@00558d4b: ported from Pizza Connection 2 at 0x558d4b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558d4b
#include "pc2_port.h"

void Unwind_00558d4b(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}
