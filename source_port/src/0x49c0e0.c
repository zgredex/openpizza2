// GlobalArray_FindIndex: ported from Pizza Connection 2 at 0x49c0e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49c0e0
#include "pc2_port.h"

int __cdecl GlobalArray_FindIndex(int arg1,int arg2)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  if (0 < arg2) {
    ptr2 = DAT_0057ca94;
    do {
      if (*ptr2 == arg1) {
        return value1;
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 1;
    } while (value1 < arg2);
  }
  return -1;
}
