// Array_GetField4Stride12: ported from Pizza Connection 2 at 0x4f3b10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3b10
#include "pc2_port.h"

uint32_t Array_GetField4Stride12(int arg1,int arg2)

{
  return *(uint32_t *)(*(int *)(arg1 + 8) + 4 + arg2 * 0xc);
}
