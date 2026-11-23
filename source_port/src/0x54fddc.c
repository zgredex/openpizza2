// __amsg_exit: ported from Pizza Connection 2 at 0x54fddc.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fddc
#include "pc2_port.h"

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int arg1)

{
  if (DAT_0058565c == 1) {
    CRT_FFMessageBanner();
  }
  CRT_NMsgWrite(arg1);
  (*(code *)PTR___exit_00576740)(0xff);
  return;
}
