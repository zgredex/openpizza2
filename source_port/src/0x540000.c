// Stream_Seek: ported from Pizza Connection 2 at 0x540000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540000
#include "pc2_port.h"

void Stream_Seek(int arg1,int arg2,int arg3)

{
  if (arg3 != 0) {
    if (arg3 == 1) {
      arg1 = *(int *)(arg2 + 0x10) + arg1;
    }
    else {
      if (arg3 != 2) goto LAB_00540030;
      arg1 = *(int *)(arg2 + 8) - arg1;
    }
  }
  *(int *)(arg2 + 0x10) = arg1;
LAB_00540030:
  if (*(uint32_t *)(arg2 + 8) < *(uint32_t *)(arg2 + 0x10)) {
    *(uint32_t *)(arg2 + 0x10) = *(uint32_t *)(arg2 + 8);
  }
  return;
}
