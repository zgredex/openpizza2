// Window_ToggleVisibility: ported from Pizza Connection 2 at 0x54a7b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a7b0
#include "pc2_port.h"

void __fastcall Window_ToggleVisibility(void *arg1)

{
  BOOL BVar1;
  
  if (*(HWND *)((intptr_t)arg1 + 4) != (HWND)0x0) {
    BVar1 = IsWindowVisible(*(HWND *)((intptr_t)arg1 + 4));
    Window_SetVisible(arg1,(uint32_t)(BVar1 == 0));
  }
  return;
}
