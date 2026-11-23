// UI_ClearTransientEntries: ported from Pizza Connection 2 at 0x528090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528090
#include "pc2_port.h"

void __thiscall UI_ClearTransientEntries(void *self,int arg1,int arg2)

{
  uint32_t uvalue1;
  bool flag2;
  bool flag3;
  uint32_t uvalue4;
  
  if ((arg1 != 0) || (arg2 != 0)) {
    if ((*(uint32_t *)((intptr_t)self + 0x32b4) != *(uint32_t *)((intptr_t)self + 0x32b8)) &&
       (uvalue4 = *(uint32_t *)((intptr_t)self + 0x32b4) + 1 & 0x3ff, uvalue4 != *(uint32_t *)((intptr_t)self + 0x32b8)))
    {
      do {
        flag2 = false;
        flag3 = false;
        uvalue1 = *(uint32_t *)((intptr_t)self + uvalue4 * 0xc + 0x2b4);
        if (uvalue1 < 0x203) {
          if (uvalue1 < 0x201) {
            if (((uvalue1 == 0x100) || (uvalue1 == 0x102)) || (uvalue1 == 0x104)) {
              flag2 = true;
            }
          }
          else {
LAB_0052811d:
            flag3 = true;
          }
        }
        else if ((0x203 < uvalue1) && ((uvalue1 < 0x206 || (uvalue1 == 0x20a)))) goto LAB_0052811d;
        if (((arg1 != 0) && (flag2)) || ((arg2 != 0 && (flag3)))) {
          *(uint32_t *)((intptr_t)self + uvalue4 * 0xc + 0x2b4) = 0;
        }
        uvalue4 = uvalue4 + 1 & 0x3ff;
      } while (uvalue4 != *(uint32_t *)((intptr_t)self + 0x32b8));
    }
  }
  return;
}
