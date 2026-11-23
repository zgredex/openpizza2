// Thread_DestroyListNode50: ported from Pizza Connection 2 at 0x54cb60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cb60
#include "pc2_port.h"

void __fastcall Thread_DestroyListNode50(int arg1)

{
  List_Node_Destroy((uint32_t *)(arg1 + 0x50));
  return;
}
