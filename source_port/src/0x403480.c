// UI_ListEntry_Destroy: ported from Pizza Connection 2 at 0x403480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403480
#include "pc2_port.h"

void __fastcall UI_ListEntry_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_UI_ListEntry_Delete_0055c2f8;
  if ((LPVOID)arg1[0x11] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x11]);
  }
  if ((LPVOID)arg1[0x12] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x12]);
  }
  return;
}
