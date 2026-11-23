// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x554203.c:12:22: error: called object type 'intptr_t' (aka 'int') is not a function or function pointer
// CRT_FFMessageBanner: ported from Pizza Connection 2 at 0x554203.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x554203
#include "pc2_port.h"

void CRT_FFMessageBanner(void)

{
  if ((DAT_0058565c == 1) || ((DAT_0058565c == 0 && (DAT_00576744 == 1)))) {
    CRT_NMsgWrite(0xfc);
    if (DAT_005858ec != (code *)0x0) {
      (*DAT_005858ec)();
    }
    CRT_NMsgWrite(0xff);
  }
  return;
}
