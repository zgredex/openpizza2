// Unwind@00557e8c: ported from Pizza Connection 2 at 0x557e8c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557e8c
#include "pc2_port.h"

void Unwind_00557e8c(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x16f8));
  return;
}
