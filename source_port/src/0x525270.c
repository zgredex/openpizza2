// Window_DefaultProc: ported from Pizza Connection 2 at 0x525270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x525270
#include "pc2_port.h"

void Window_DefaultProc(HWND arg1,UINT arg2,WPARAM arg3,HCURSOR arg4)

{
  void *self;
  
  if (arg2 == 2) {
    SetEvent(DAT_0057c0d8);
    PostQuitMessage(0);
  }
  else if (arg2 == 0x1c) {
    DAT_00584504 = arg3;
  }
  self = (void *)GetWindowLongA(arg1,-0x15);
  if (self == (void *)0x0) {
    DefWindowProcA(arg1,arg2,arg3,(LPARAM)arg4);
    return;
  }
  Window_HandleMessage(self,arg1,arg2,arg3,arg4);
  return;
}
