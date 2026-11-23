// Unwind@00557e7e: ported from Pizza Connection 2 at 0x557e7e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557e7e
#include "pc2_port.h"

void Unwind_00557e7e(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x1500));
  return;
}
