// Language_CopyStringIds: ported from Pizza Connection 2 at 0x514690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514690
#include "pc2_port.h"

void __cdecl Language_CopyStringIds(uint32_t *arg1,int arg2,int arg3)

{
  int value1;
  
  value1 = Language_IndexOfString(arg2);
  if (0 < arg3) {
    value1 = value1 << 2;
    do {
      arg3 = arg3 + -1;
      *arg1 = *(uint32_t *)(value1 + DAT_00580ad4);
      value1 = value1 + 4;
      arg1 = arg1 + 1;
    } while (arg3 != 0);
  }
  return;
}
