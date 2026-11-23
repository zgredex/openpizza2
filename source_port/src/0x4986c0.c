// GlobalArray_FindInt: ported from Pizza Connection 2 at 0x4986c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4986c0
#include "pc2_port.h"

int __cdecl GlobalArray_FindInt(int arg1,int arg2)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  if (0 < arg2) {
    ptr2 = DAT_0057ca08;
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
