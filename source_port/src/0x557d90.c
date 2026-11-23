// Unwind@00557d90: ported from Pizza Connection 2 at 0x557d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557d90
#include "pc2_port.h"

void Unwind_00557d90(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(unaff_EBP + -0x28));
  return;
}
