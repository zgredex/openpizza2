// Window_Destroy: ported from Pizza Connection 2 at 0x537350.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x537350
#include "pc2_port.h"

void __fastcall Window_Destroy(uint32_t *arg1)

{
  uint32_t *uptr1;
  
  *arg1 = &PTR_Window_Delete_0055c814;
  if ((LPVOID)arg1[6] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[6]);
  }
  uptr1 = (uint32_t *)arg1[5];
  if (uptr1 != (uint32_t *)0x0) {
    Palette_Free(uptr1);
    Mem_Free(uptr1);
  }
  return;
}
