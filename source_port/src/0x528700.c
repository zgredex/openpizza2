// UI_ContextMenu_Destroy: ported from Pizza Connection 2 at 0x528700.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528700
#include "pc2_port.h"

void __fastcall UI_ContextMenu_Destroy(int *arg1)

{
  int value1;
  
  *arg1 = (intptr_t)&PTR_UI_ContextMenu_Delete_0055c788;
  if ((uint32_t *)arg1[0x14] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x14])(1);
  }
  if ((uint32_t *)arg1[0x15] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x15])(1);
  }
  if ((LPVOID)arg1[0x1a] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x1a]);
  }
  value1 = 9;
  do {
    arg1 = arg1 + 1;
    if ((uint32_t *)*arg1 != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)*arg1)(1);
    }
    *arg1 = 0;
    value1 = value1 + -1;
  } while (value1 != 0);
  return;
}
