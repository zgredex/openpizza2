// CRT_FindExceptionHandler: ported from Pizza Connection 2 at 0x553b9e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553b9e
#include "pc2_port.h"

int * __cdecl CRT_FindExceptionHandler(int arg1,int *arg2)

{
  int *ptr1;
  
  ptr1 = arg2;
  if (*arg2 != arg1) {
    do {
      ptr1 = ptr1 + 3;
      if (arg2 + DAT_005770c4 * 3 <= ptr1) break;
    } while (*ptr1 != arg1);
  }
  if ((arg2 + DAT_005770c4 * 3 <= ptr1) || (*ptr1 != arg1)) {
    ptr1 = (int *)0x0;
  }
  return ptr1;
}
