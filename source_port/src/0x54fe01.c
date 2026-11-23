// CRT_AmsgExit: ported from Pizza Connection 2 at 0x54fe01.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fe01
#include "pc2_port.h"

void __cdecl CRT_AmsgExit(DWORD arg1)

{
  if (DAT_0058565c == 1) {
    CRT_FFMessageBanner();
  }
  CRT_NMsgWrite(arg1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(0xff);
}
