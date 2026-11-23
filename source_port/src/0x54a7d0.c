// Dialog_SetItemText: ported from Pizza Connection 2 at 0x54a7d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a7d0
#include "pc2_port.h"

void __fastcall Dialog_SetItemText(int arg1)

{
  HWND hWnd;
  LPCSTR lpString;
  
  if (*(HWND *)(arg1 + 4) != (HWND)0x0) {
    lpString = &DAT_00579aec;
    hWnd = GetDlgItem(*(HWND *)(arg1 + 4),0x3ef);
    SetWindowTextA(hWnd,lpString);
  }
  return;
}
