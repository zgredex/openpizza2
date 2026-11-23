// Gfx_RectList_Destroy: ported from Pizza Connection 2 at 0x534dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534dd0
#include "pc2_port.h"

void __fastcall Gfx_RectList_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_Gfx_RectList_Delete_0055c810;
  Mem_Free((LPVOID)arg1[5]);
  return;
}
