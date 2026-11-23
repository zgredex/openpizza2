// Building_GetRandomResidentCount: ported from Pizza Connection 2 at 0x502c50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502c50
#include "pc2_port.h"

uint32_t __thiscall Building_GetRandomResidentCount(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  
  uvalue1 = Random_RangeFast(0,1);
  value3 = *(int *)((intptr_t)self + 0x44);
  value2 = Game_GetPlayerFieldC20
                    (*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
  if (((0 < value2) && (arg1 == 6)) && (*(int *)((intptr_t)self + 0x44) == 0)) {
    value3 = 1;
  }
  return *(uint32_t *)(&DAT_005727fc + (value3 + (uvalue1 + arg1 * 2) * 4) * 4);
}
