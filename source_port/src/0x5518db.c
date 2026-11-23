// CRT_WriteMultiChar: ported from Pizza Connection 2 at 0x5518db.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5518db
#include "pc2_port.h"

void __cdecl CRT_WriteMultiChar(uint32_t arg1,int arg2,int *arg3,int *arg4)

{
  do {
    if (arg2 < 1) {
      return;
    }
    arg2 = arg2 + -1;
    CRT_StreamPutc(arg1,arg3,arg4);
  } while (*arg4 != -1);
  return;
}
