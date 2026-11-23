// Game_CanAffordWithCurrency: ported from Pizza Connection 2 at 0x4e0b60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0b60
#include "pc2_port.h"

uint32_t __thiscall
Game_CanAffordWithCurrency(void *self,int arg1,float arg2,char arg3,uint32_t arg4)

{
  double dVar1;
  int value2;
  void *this_00;
  float fVar3;
  int in_EAX;
  int value4;
  int64_t lvalue5;
  
  if (arg4 == 0xffffffff) {
    arg4 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
    in_EAX = DAT_0057c670;
  }
  if (arg3 != '\0') {
    fVar3 = (float)*(double *)((intptr_t)self + 0x108) - arg2;
    if (fVar3 < 0.0) {
      return CONCAT22((short)((uint32_t)in_EAX >> 0x10),
                      (uint16_t)(fVar3 < 0.0) << 8 | (uint16_t)NAN(fVar3) << 10 |
                      (uint16_t)(fVar3 == 0.0) << 0xe);
    }
  }
  value4 = Game_FindRecordByField4(self,arg4);
  if (value4 != 0) {
    *(double *)((intptr_t)self + 0x108) = (double)((float)*(double *)((intptr_t)self + 0x108) - arg2);
    *(float *)(value4 + 0x78 + arg1 * 4) = arg2 + *(float *)(value4 + 0x78 + arg1 * 4);
  }
  value4 = *(int *)(DAT_0057c670 + 600);
  if (*(int *)(DAT_0057c670 + 600) == 0) {
    value2 = *(int *)((intptr_t)self + 0x48);
    value4 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    if (value4 == value2) {
      this_00 = *(void **)(DAT_0057c670 + 0x2d9c);
      value4 = DAT_0057c670;
      if (this_00 != (void *)0x0) {
        dVar1 = (double)(arg2 + (float)*(double *)((intptr_t)self + 0x108));
        Sound_SetListenerPosition(this_00,SUB84(dVar1,0),(intptr_t)((uint64_t)dVar1 >> 0x20),0);
        value4 = 1;
        lvalue5 = __ftol();
        value4 = Sound_UpdateListener
                          (this_00,*(uint32_t *)((intptr_t)this_00 + 0x1b0) - (uint32_t)lvalue5,
                           (*(int *)((intptr_t)this_00 + 0x1b4) - (intptr_t)((uint64_t)lvalue5 >> 0x20)) -
                           (uint32_t)(*(uint32_t *)((intptr_t)this_00 + 0x1b0) < (uint32_t)lvalue5),value4);
      }
    }
  }
  return CONCAT31((int3)((uint32_t)value4 >> 8),1);
}
