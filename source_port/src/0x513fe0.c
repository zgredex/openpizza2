// Storage_Destroy: ported from Pizza Connection 2 at 0x513fe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513fe0
#include "pc2_port.h"

void __fastcall Storage_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_Storage_Delete_0055c700;
  List_Node_Destroy(arg1 + 0x11);
  return;
}
