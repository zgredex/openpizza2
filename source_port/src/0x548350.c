// Sound_UpdateVolumeByCitySize: ported from Pizza Connection 2 at 0x548350.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548350
#include "pc2_port.h"

void __thiscall Sound_UpdateVolumeByCitySize(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  
  if ((*(int *)((intptr_t)self + 0x1d0) != 0) && (*(int *)(DAT_0057c670 + 0x9c) == arg1)) {
    value1 = Game_CountRecordsWithFieldA0(arg1);
    uvalue2 = (value1 * 10000) / 0x28;
    if (10000 < uvalue2) {
      uvalue2 = 10000;
    }
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x7c))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0x8c),
               (uvalue2 * *(int *)((intptr_t)self + 0x1d0)) / 10000);
  }
  return;
}
