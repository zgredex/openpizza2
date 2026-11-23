// UI_Tooltip_Destroy: ported from Pizza Connection 2 at 0x52e530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e530
#include "pc2_port.h"

void __fastcall UI_Tooltip_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_UI_Tooltip_Delete_0055c804;
  if (arg1[6] != 0) {
    UI_ReleaseRefCount((void *)arg1[0xe],arg1[6]);
  }
  if ((LPVOID)arg1[0xc] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0xc]);
  }
  if ((uint32_t *)arg1[7] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[7])(1);
  }
  return;
}
