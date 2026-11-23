// FUN_00556ba0: ported from Pizza Connection 2 at 0x556ba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556ba0
#include "pc2_port.h"

uint32_t __cdecl FUN_00556ba0(int arg1,uint32_t arg2)

{
  int *ptr1;
  uint32_t uvalue3;
  uint32_t uvalue2;
  
  uvalue2 = arg2;
  if (*(int *)(arg2 + 4) != arg1) {
    uvalue3 = arg2;
    do {
      uvalue2 = uvalue3 + 0xc;
      if (arg2 + DAT_005770c4 * 0xc <= uvalue2) break;
      ptr1 = (int *)(uvalue3 + 0x10);
      uvalue3 = uvalue2;
    } while (*ptr1 != arg1);
  }
  if ((arg2 + DAT_005770c4 * 0xc <= uvalue2) || (*(int *)(uvalue2 + 4) != arg1)) {
    uvalue2 = 0;
  }
  return uvalue2;
}
