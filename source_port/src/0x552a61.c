// CRT_LoctoTime64: ported from Pizza Connection 2 at 0x552a61.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552a61
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
CRT_LoctoTime64(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6,int arg7)

{
  bool flag1;
  uint32_t extraout_var;
  int value2;
  uint32_t uvalue3;
  int value4;
  int local_28 [2];
  int local_20;
  int local_18;
  uint32_t local_14;
  int local_c;
  
  uvalue3 = arg1 - 0x76c;
  if (((intptr_t)uvalue3 < 0x46) || (0x8a < (intptr_t)uvalue3)) {
    return -1;
  }
  value4 = *(int *)(&DAT_005771d0 + arg2 * 4) + arg3;
  if (((uvalue3 & 3) == 0) && (2 < arg2)) {
    value4 = value4 + 1;
  }
  CRT_TzsetInit();
  local_20 = arg4;
  local_18 = arg2 + -1;
  value2 = ((arg4 + (uvalue3 * 0x16d + value4 + (arg1 + -0x76d >> 2)) * 0x18) * 0x3c + arg5) *
          0x3c + DAT_00576a30 + 0x7c558180 + arg6;
  if ((arg7 == 1) ||
     (((arg7 == -1 && (DAT_00576a34 != 0)) &&
      (local_14 = uvalue3, local_c = value4, flag1 = CRT_IsIndst(local_28),
      CONCAT31(extraout_var,flag1) != 0)))) {
    value2 = value2 + _DAT_00576a38;
  }
  return value2;
}
