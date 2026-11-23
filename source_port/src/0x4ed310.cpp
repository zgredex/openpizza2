// Array_SetField4Stride12: ported from Pizza Connection 2 at 0x4ed310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed310
#include "pc2_port.h"

void Array_SetField4Stride12(int arg1,int arg2,uint32_t arg3)

{
  *(uint32_t *)(*(int *)(arg1 + 8) + 4 + arg2 * 0xc) = arg3;
  return;
}
