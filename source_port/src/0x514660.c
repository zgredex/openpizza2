// Language_IndexOfString: ported from Pizza Connection 2 at 0x514660.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514660
#include "pc2_port.h"

int __cdecl Language_IndexOfString(int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  if (0 < DAT_00580ad0) {
    ptr2 = DAT_00580ad4;
    do {
      if (*ptr2 == arg1) {
        return value1;
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 1;
    } while (value1 < DAT_00580ad0);
  }
  return 0;
}
