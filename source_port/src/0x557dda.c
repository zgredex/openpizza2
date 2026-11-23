// Unwind@00557dda: ported from Pizza Connection 2 at 0x557dda.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557dda
#include "pc2_port.h"

void Unwind_00557dda(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x1728));
  return;
}
