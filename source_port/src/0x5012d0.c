// Game_AssignPlanStepWeight: ported from Pizza Connection 2 at 0x5012d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5012d0
#include "pc2_port.h"

void __thiscall Game_AssignPlanStepWeight(void *self,uint32_t arg1,uint32_t *arg2)

{
  int value1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  int value6;
  
  uptr2 = arg2;
  value6 = 0;
  uvalue3 = (uint32_t)*(uint16_t *)(arg2 + 2);
  arg2 = (uint32_t *)0x0;
  value1 = *(int *)(*(int *)((intptr_t)self + uvalue3 * 0x168 + 0x70) + 0x15c);
  uptr2[3] = arg1;
  switch(arg1) {
  case 4:
    uptr2[1] = 0x50;
    return;
  case 5:
    arg2 = (uint32_t *)0x14;
    if (0 < value1) {
      do {
        Game_GetPlayerSubrecord(self,(uint32_t)*(uint16_t *)(uptr2 + 2),value6,1);
        value6 = value6 + 1;
      } while (value6 < value1);
      uptr2[1] = 0x14;
      return;
    }
    break;
  case 6:
    if (0 < value1) {
      uvalue4 = Game_GetRandomPlayerRecordValue(self,uvalue3);
      *uptr2 = uvalue4;
      uptr2[1] = value1 * 0x14;
      return;
    }
    break;
  case 7:
    uptr2[1] = 0;
    return;
  case 8:
    if (0 < value1) {
      while ((value5 = Game_GetPlayerSubrecord(self,(uint32_t)*(uint16_t *)(uptr2 + 2),value6,1),
             value5 == 0 || ((*(uint8_t *)(value5 + 0x28) & 4) == 0))) {
        value6 = value6 + 1;
        if (value1 <= value6) {
          uptr2[1] = 0;
          return;
        }
      }
      *uptr2 = *(uint32_t *)(value5 + 0x3c);
      uptr2[1] = 100;
      return;
    }
    break;
  case 10:
    if (0 < value1) {
      while ((value5 = Game_GetPlayerSubrecord(self,(uint32_t)*(uint16_t *)(uptr2 + 2),value6,1),
             value5 == 0 || ((*(uint8_t *)(value5 + 0x28) & 0x10) != 0))) {
        value6 = value6 + 1;
        if (value1 <= value6) {
          uptr2[1] = 0;
          return;
        }
      }
      *uptr2 = *(uint32_t *)(value5 + 0x3c);
      uptr2[1] = 200;
      return;
    }
    break;
  case 0xb:
    uptr2[1] = 0x28;
    return;
  case 0xc:
    if (0 < value1) {
      do {
        value5 = Game_GetPlayerSubrecord(self,(uint32_t)*(uint16_t *)(uptr2 + 2),value6,1);
        if ((value5 != 0) && ((*(uint8_t *)(value5 + 0x28) & 8) == 0)) {
          uptr2[1] = 200;
          return;
        }
        value6 = value6 + 1;
      } while (value6 < value1);
    }
  case 9:
  case 0xd:
  case 0xf:
    uptr2[1] = 0x14;
    return;
  case 0xe:
    if (0 < value1) {
      uvalue4 = Game_GetRandomPlayerRecordValue(self,uvalue3);
      *uptr2 = uvalue4;
      uptr2[1] = value1 * 5;
      return;
    }
    break;
  case 0x10:
  case 0x11:
    uptr2[1] = 0x32;
    return;
  case 0x12:
    uptr2[1] = 10;
    return;
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
    uptr2[1] = 0x1e;
    return;
  default:
    Game_GetPlanName(arg1);
    NoOp_Stub();
  }
  uptr2[1] = arg2;
  return;
}
