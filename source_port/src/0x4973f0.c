// Supplier_GetValuePlusOne: ported from Pizza Connection 2 at 0x4973f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4973f0
#include "pc2_port.h"

int __cdecl Supplier_GetValuePlusOne(int arg1)

{
  if (arg1 == 0) {
    return 0;
  }
  return *(int *)(&DAT_0057c718 + arg1 * 4) + 1;
}
