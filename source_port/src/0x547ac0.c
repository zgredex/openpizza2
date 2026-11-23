// Sound_SetVolumeSetting: ported from Pizza Connection 2 at 0x547ac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547ac0
#include "pc2_port.h"

bool __thiscall Sound_SetVolumeSetting(void *self,int arg1,int arg2)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  bool flag3;
  
  uvalue2 = (uint32_t)(arg2 * 10000) / 10000;
  if (10000 < uvalue2) {
    uvalue2 = 10000;
  }
  if (arg1 == 1) {
    flag3 = uvalue2 != DAT_00575094;
    DAT_00575094 = uvalue2;
    *(uint32_t *)((intptr_t)self + 0x1d0) = uvalue2;
    uvalue2 = Sound_ConvertVolumeSetting(DAT_00575098);
    *(uint32_t *)((intptr_t)self + 0x1d4) = uvalue2;
    uvalue2 = Sound_ConvertVolumeSetting(DAT_0057509c);
    *(uint32_t *)((intptr_t)self + 0x1d8) = uvalue2;
    return flag3;
  }
  if (arg1 == 2) {
    DAT_00575098 = uvalue2;
    uvalue1 = Sound_ConvertVolumeSetting(uvalue2);
    uvalue2 = *(uint32_t *)((intptr_t)self + 0x1d4);
    *(uint32_t *)((intptr_t)self + 0x1d4) = uvalue1;
    return uvalue1 != uvalue2;
  }
  if (arg1 == 3) {
    DAT_0057509c = uvalue2;
    uvalue1 = Sound_ConvertVolumeSetting(uvalue2);
    uvalue2 = *(uint32_t *)((intptr_t)self + 0x1d8);
    *(uint32_t *)((intptr_t)self + 0x1d8) = uvalue1;
    return uvalue1 != uvalue2;
  }
  return false;
}
