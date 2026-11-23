// Unwind@00557dbe: ported from Pizza Connection 2 at 0x557dbe.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557dbe
#include "pc2_port.h"

void Unwind_00557dbe(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x1500));
  return;
}
