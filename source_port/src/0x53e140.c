// Surface_SetPixel: ported from Pizza Connection 2 at 0x53e140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53e140
#include "pc2_port.h"

void __cdecl Surface_SetPixel(int arg1,int arg2,int arg3,uint16_t arg4)

{
  if ((((-1 < arg2) && (arg2 < (intptr_t)(uint32_t)*(uint16_t *)(arg1 + 0x1a))) && (-1 < arg3)) &&
     (arg3 < (intptr_t)(uint32_t)*(uint16_t *)(arg1 + 0x1c))) {
    *(uint16_t *)(*(int *)(arg1 + 0x20) * arg3 + *(int *)(arg1 + 0x28) + arg2 * 3) =
         arg4;
  }
  return;
}
