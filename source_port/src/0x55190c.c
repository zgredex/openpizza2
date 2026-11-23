// CRT_WriteString: ported from Pizza Connection 2 at 0x55190c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55190c
#include "pc2_port.h"

void __cdecl CRT_WriteString(char *arg1,int arg2,int *arg3,int *arg4)

{
  char cVar1;
  
  if (0 < arg2) {
    do {
      arg2 = arg2 + -1;
      cVar1 = *arg1;
      arg1 = arg1 + 1;
      CRT_StreamPutc((intptr_t)cVar1,arg3,arg4);
      if (*arg4 == -1) {
        return;
      }
    } while (0 < arg2);
  }
  return;
}
