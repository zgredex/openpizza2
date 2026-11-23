// Win32_PumpMessages: ported from Pizza Connection 2 at 0x539700.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539700
#include "pc2_port.h"

void Win32_PumpMessages(void)

{
  int value1;
  BOOL BVar2;
  tagMSG local_1c;
  
  value1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  while ((value1 != 0 && (BVar2 = GetMessageA(&local_1c,(HWND)0x0,0,0), BVar2 != 0))) {
    TranslateMessage(&local_1c);
    DispatchMessageA(&local_1c);
    value1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  }
  return;
}
