// CRT_FindTryBlockRange: ported from Pizza Connection 2 at 0x54e7d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e7d0
#include "pc2_port.h"

int __cdecl CRT_FindTryBlockRange(uint32_t arg1,int arg2,int arg3,uint32_t *arg4,uint32_t *arg5)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t local_8;
  
  uvalue2 = arg1;
  local_8 = *(uint32_t *)(arg1 + 0xc);
  value1 = *(int *)(arg1 + 0x10);
  uvalue3 = local_8;
  arg1 = local_8;
  if (-1 < arg2) {
    do {
      if (uvalue3 == 0xffffffff) {
        CRT_Inconsistency();
      }
      uvalue3 = uvalue3 - 1;
      if (((*(int *)(value1 + 4 + uvalue3 * 0x14) < arg3) &&
          (arg3 <= *(int *)(value1 + uvalue3 * 0x14 + 8))) || (uvalue3 == 0xffffffff)) {
        arg2 = arg2 + -1;
        local_8 = arg1;
        arg1 = uvalue3;
      }
    } while (-1 < arg2);
  }
  uvalue3 = uvalue3 + 1;
  *arg4 = uvalue3;
  *arg5 = local_8;
  if ((*(uint32_t *)(uvalue2 + 0xc) < local_8) || (local_8 < uvalue3)) {
    CRT_Inconsistency();
  }
  return value1 + uvalue3 * 0x14;
}
