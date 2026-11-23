// Input_HandleMapClickAtCell: ported from Pizza Connection 2 at 0x4893a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4893a0
#include "pc2_port.h"

uint32_t __thiscall Input_HandleMapClickAtCell(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  
  if (arg1 == 9) {
    if (((DAT_0057c670 != 0) && (*(int *)((intptr_t)self + 0x290) == 4)) &&
       ((*(int *)((intptr_t)self + 0x2a8) == 3 || (*(int *)((intptr_t)self + 0x2d8) == 0xb)))) {
      DAT_0057c640 = *(uint32_t *)(*(int *)((intptr_t)self + 0x2fc) + 0x24);
      DAT_0057c644 = *(uint32_t *)(*(int *)((intptr_t)self + 0x2fc) + 0x28);
      return 1;
    }
  }
  else if (((((arg1 == 10) && (DAT_0057c670 != 0)) && (*(int *)((intptr_t)self + 0x290) == 4)) &&
           ((*(int *)((intptr_t)self + 0x2a8) == 3 || (*(int *)((intptr_t)self + 0x2d8) == 0xb)))) &&
          (*(int *)((intptr_t)self + 0x344) != -1)) {
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0x74),*(int *)((intptr_t)self + 0x344),(int *)0x0);
    uvalue2 = DAT_0057c640 - *(int *)(*(int *)((intptr_t)self + 0x2fc) + 0x24);
    uvalue3 = (intptr_t)uvalue2 >> 0x1f;
    if (((intptr_t)((uvalue2 ^ uvalue3) - uvalue3) < 10) &&
       (uvalue2 = DAT_0057c644 - *(int *)(*(int *)((intptr_t)self + 0x2fc) + 0x28),
       uvalue3 = (intptr_t)uvalue2 >> 0x1f, (intptr_t)((uvalue2 ^ uvalue3) - uvalue3) < 10)) {
      CS_Enter(*(int *)((intptr_t)self + 0x240));
      Game_AdvanceAnimFrame((intptr_t)self);
      *(int *)(*(int *)((intptr_t)self + 0x2fc) + 0x68) =
           (intptr_t)*(short *)(value1 + (*(int *)((intptr_t)self + 0x350) +
                                   (*(int *)((intptr_t)self + 0x354) + 10) * 6) * 2);
      CS_Leave(*(int *)((intptr_t)self + 0x240));
    }
    return 1;
  }
  return 0;
}
