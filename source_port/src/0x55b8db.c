// Unwind@0055b8db: ported from Pizza Connection 2 at 0x55b8db.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b8db
#include "pc2_port.h"

void Unwind_0055b8db(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}
