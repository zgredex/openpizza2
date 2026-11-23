// UI_GetScrollRatio: ported from Pizza Connection 2 at 0x527dc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527dc0
#include "pc2_port.h"

double __thiscall UI_GetScrollRatio(int arg1,uint32_t arg2,int arg3,uint32_t arg4,int arg5)

{
  if (*(int *)(arg1 + 0x83b0) == 0 && *(int *)(arg1 + 0x83b4) == 0) {
    return (double)0.0;
  }
  return ((double)CONCAT44((arg5 - arg3) - (uint32_t)(arg4 < arg2),arg4 - arg2) *
         (double)1000.0) / (double)*(int64_t *)(arg1 + 0x83b0);
}
