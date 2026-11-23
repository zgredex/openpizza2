// Unwind@00557e04: ported from Pizza Connection 2 at 0x557e04.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557e04
#include "pc2_port.h"

void Unwind_00557e04(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x1998));
  return;
}
