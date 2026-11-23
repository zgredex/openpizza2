// SaveList_FindIndex: ported from Pizza Connection 2 at 0x496900.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x496900
#include "pc2_port.h"

int __cdecl SaveList_FindIndex(int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  if (0 < DAT_0057c704) {
    ptr2 = DAT_0057c714;
    do {
      if (*ptr2 == arg1) {
        return value1;
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 1;
    } while (value1 < DAT_0057c704);
  }
  return -1;
}
