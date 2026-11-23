// Unwind@0055b993: ported from Pizza Connection 2 at 0x55b993.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b993
#include "pc2_port.h"

void Unwind_0055b993(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 200));
  return;
}
