// List_Node_Destroy: ported from Pizza Connection 2 at 0x401480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401480
#include "pc2_port.h"

void __fastcall List_Node_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_List_Node_Delete_0055c2ec;
  if ((LPVOID)arg1[1] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[1]);
  }
  if ((LPVOID)arg1[2] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[2]);
  }
  return;
}
