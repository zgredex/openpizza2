// UI_Child_Destroy: ported from Pizza Connection 2 at 0x520b10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520b10
#include "pc2_port.h"

void __fastcall UI_Child_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_UI_Child_Delete_0055c720;
  UI_DetachChild((intptr_t)arg1);
  if ((LPVOID)arg1[3] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[3]);
  }
  if ((LPVOID)arg1[4] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[4]);
  }
  return;
}
