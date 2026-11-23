// Market_ComputeValueAdjustment: ported from Pizza Connection 2 at 0x4d7640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d7640
#include "pc2_port.h"


int __thiscall
Market_ComputeValueAdjustment
          (void *self,char arg1,uint32_t arg2,int arg3,uint32_t *arg4,int *arg5)

{
  uint32_t uvalue1;
  uint8_t flag2;
  uint32_t *uptr3;
  int value4;
  uint32_t uvalue5;
  int value6;
  double fVar7;
  int local_8;
  uint32_t local_4;
  
  uptr3 = arg4;
  value4 = 0;
  value6 = 0;
  flag2 = (char)*(uint32_t *)(arg3 + 0xd0) - 1;
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),flag2);
  local_8 = 0;
  uvalue1 = Market_GetPriceDelta(self,local_4);
  arg4 = (uint32_t *)0x0;
  *uptr3 = uvalue1;
  uvalue5 = arg2 & 0xff;
  arg2 = 6;
  uptr3 = (uint32_t *)((intptr_t)self + uvalue5 * 0x18 + 0xfe4);
  do {
    if (*uptr3 == (uint32_t)flag2) {
      arg4 = (uint32_t *)((intptr_t)arg4 + 10);
    }
    uptr3 = uptr3 + 1;
    arg2 = arg2 - 1;
  } while (arg2 != 0);
  *arg5 = (intptr_t)arg4;
  if (arg1 != '\0') {
    value6 = (intptr_t)*(char *)(arg3 + 0xcd);
    switch(uvalue5 - 2) {
    case 0:
    case 2:
      value6 = value6 * 5;
      break;
    case 1:
    case 4:
      value6 = value6 * -10;
      break;
    case 3:
    case 5:
      value6 = value6 * 10;
      break;
    default:
      value6 = 0;
    }
    switch(uvalue5 - 2) {
    case 0:
    case 4:
      value4 = *(char *)(arg3 + 0xcc) * 5;
      break;
    default:
      value4 = 0;
      break;
    case 2:
    case 3:
      value4 = *(char *)(arg3 + 0xcc) * 10;
    }
    fVar7 = Rating_GetFloat((intptr_t)self,uvalue5);
    if (fVar7 / ((double)*(int *)(&DAT_0056ccec + uvalue5 * 4) * (double)0.01) <
        (double)*(double *)(arg3 + 0xc0)) {
      local_8 = -1000;
    }
  }
  return (intptr_t)arg4 + value6 + value4 + local_8 + uvalue1;
}
