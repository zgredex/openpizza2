// UI_GetFirstEnabledIndex: ported from Pizza Connection 2 at 0x535690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535690
#include "pc2_port.h"

uint8_t __fastcall UI_GetFirstEnabledIndex(int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  ptr2 = (int *)(arg1 + 0x460);
  do {
    if (*ptr2 != 0) {
      return *(uint8_t *)(value1 + 0x1c0 + arg1);
    }
    value1 = value1 + 1;
    ptr2 = ptr2 + 1;
  } while (value1 < 0xe0);
  return 0;
}
