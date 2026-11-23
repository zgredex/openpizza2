// Grid_GetRandomRecord28: ported from Pizza Connection 2 at 0x4f3a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3a90
#include "pc2_port.h"

int __fastcall Grid_GetRandomRecord28(int arg1)

{
  uint32_t uvalue1;
  
  if (*(uint32_t **)(arg1 + 0x110) == (uint32_t *)0x0) {
    return 0;
  }
  uvalue1 = Random_RangeFast(1,**(uint32_t **)(arg1 + 0x110));
  if (10 < (intptr_t)uvalue1) {
    uvalue1 = 1;
  }
  return *(int *)(arg1 + 0x9c) + *(int *)(*(int *)(arg1 + 0x110) + uvalue1 * 4) * 0x28;
}
