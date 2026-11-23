// Window_MoveToSidePanel: ported from Pizza Connection 2 at 0x54a820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a820
#include "pc2_port.h"

void __fastcall Window_MoveToSidePanel(int arg1)

{
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_20;
  tagRECT local_10;
  
  if (*(int *)(arg1 + 4) != 0) {
    GetWindowRect(*(HWND *)(arg1 + 8),&local_20);
    lpRect = &local_10;
    hWnd = GetDesktopWindow();
    GetWindowRect(hWnd,lpRect);
    MoveWindow(*(HWND *)(arg1 + 4),local_20.right,local_20.top,
               (local_10.right - local_20.right) - local_10.left,local_20.bottom - local_20.top,1);
  }
  return;
}
