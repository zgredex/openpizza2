// Branch_AdvanceWeekStatistics: ported from Pizza Connection 2 at 0x47ef30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ef30
#include "pc2_port.h"

void __thiscall Branch_AdvanceWeekStatistics(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  uint32_t *uptr4;
  int value5;
  uint32_t *uptr6;
  int64_t lvalue7;
  
  value3 = arg1 / 3;
  *(short *)((intptr_t)self + 0x16ec) = (short)*(uint32_t *)(DAT_0057c670 + 0x340);
  *(int *)((intptr_t)self + value3 * 4 + 5000) = *(short *)((intptr_t)self + 0x16c0) * 7;
  *(int *)((intptr_t)self + value3 * 4 + 0x13d0) = (intptr_t)*(short *)((intptr_t)self + 0x16d6);
  if (*(short *)((intptr_t)self + 0x16ec) == 0) {
    *(uint32_t *)((intptr_t)self + value3 * 4 + 0x1460) = 0;
    *(uint32_t *)((intptr_t)self + value3 * 4 + 0x1418) = 0;
  }
  else {
    *(int *)((intptr_t)self + value3 * 4 + 0x1460) =
         (1 - (intptr_t)*(short *)((intptr_t)self + 0x16e0) / (intptr_t)*(short *)((intptr_t)self + 0x16ec)) *
         (intptr_t)*(short *)((intptr_t)self + 0x16c0);
    *(int *)((intptr_t)self + value3 * 4 + 0x1418) =
         (1 - (intptr_t)*(short *)((intptr_t)self + 0x16dc) / (intptr_t)*(short *)((intptr_t)self + 0x16ec)) *
         (intptr_t)*(short *)((intptr_t)self + 0x16c0);
  }
  arg1 = 0;
  if (0 < *(int *)((intptr_t)self + 0x19ac)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x1998),arg1,(int *)0x0);
      if (*(int *)(value1 + 0x1c) != 0) {
        value5 = (*(int *)(value1 + 0xc) / 10 -
                *(int *)(&DAT_005675a0 + *(int *)((intptr_t)self + 0x38) * 4)) + -10 +
                *(int *)(value1 + 4);
        if (value5 < 0) {
          value5 = 0;
        }
        lvalue7 = __ftol();
        if ((intptr_t)lvalue7 < value5) {
          *(int *)(value1 + 4) = value5;
        }
        else {
          Branch_PayConstructionOrder(self,arg1);
        }
      }
      arg1 = arg1 + 1;
    } while (arg1 < *(int *)((intptr_t)self + 0x19ac));
  }
  uvalue2 = value3 - 1U & 7;
  *(uint8_t *)((intptr_t)self + uvalue2 * 0x34 + 0x154e) = 0;
  uptr4 = (uint32_t *)((intptr_t)self + 0x16bc);
  uptr6 = (uint32_t *)((intptr_t)self + uvalue2 * 0x34 + 0x151c);
  for (value3 = 0xd; value3 != 0; value3 = value3 + -1) {
    *uptr6 = *uptr4;
    uptr4 = uptr4 + 1;
    uptr6 = uptr6 + 1;
  }
  uptr4 = (uint32_t *)((intptr_t)self + 0x16bc);
  for (value3 = 0xd; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  *(uint8_t *)((intptr_t)self + uvalue2 * 0x34 + 0x154e) = 1;
  value3 = Game_CountFreeBuildingsByType(*(void **)((intptr_t)self + 0x16f0),0x1b);
  if (0 < value3) {
    Branch_SpawnRandomPedestrian((intptr_t)self);
  }
  return;
}
