// UI_SetWaitCursor: ported from Pizza Connection 2 at 0x527d10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527d10
#include "pc2_port.h"

void __thiscall UI_SetWaitCursor(void *self,int arg1)

{
  HCURSOR hCursor;
  DWORD DVar1;
  
  if (arg1 == 0) {
    hCursor = (HCURSOR)0x0;
  }
  else {
    hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  }
  DVar1 = GetCurrentThreadId();
  if (DVar1 == DAT_0057ba14) {
    SetClassLongA(*(HWND *)((intptr_t)self + 0x8320),-0xc,(LONG)hCursor);
    SetCursor(hCursor);
    return;
  }
  ResetEvent(*(HANDLE *)((intptr_t)self + 0x8354));
  do {
    if (DAT_0057c480 != 0) {
      return;
    }
    PostMessageA(*(HWND *)((intptr_t)self + 0x8320),0x400,0,(LPARAM)hCursor);
    DVar1 = WaitForSingleObject(*(HANDLE *)((intptr_t)self + 0x8354),500);
  } while (DVar1 == 0x102);
  return;
}
