// Window_SetVisible: ported from Pizza Connection 2 at 0x54a770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a770
#include "pc2_port.h"

void __thiscall Window_SetVisible(void *self,int arg1)

{
  HWND hWnd;
  
  hWnd = *(HWND *)((intptr_t)self + 4);
  if (hWnd != (HWND)0x0) {
    if (arg1 != 0) {
      ShowWindow(hWnd,1);
      *(uint32_t *)((intptr_t)self + 0x20) = 1;
      return;
    }
    ShowWindow(hWnd,0);
    *(uint32_t *)((intptr_t)self + 0x20) = 0;
  }
  return;
}
