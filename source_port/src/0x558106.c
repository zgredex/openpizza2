// Unwind@00558106: ported from Pizza Connection 2 at 0x558106.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558106
#include "pc2_port.h"

void Unwind_00558106(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x14) + 0x3c));
  return;
}
