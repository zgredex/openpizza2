// UI_SetChildState: ported from Pizza Connection 2 at 0x507550.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507550
#include "pc2_port.h"

void __thiscall UI_SetChildState(void *self,uint16_t arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 200);
  if (value1 != 0) {
    *(uint16_t *)((intptr_t)self + 0x40) = arg1;
    switch(arg1) {
    case 0:
      *(uint16_t *)(value1 + 8) = 0x19;
      return;
    case 1:
      *(uint16_t *)(value1 + 8) = 0x29;
      return;
    case 2:
      *(uint16_t *)(value1 + 8) = 0x3f;
      return;
    case 3:
      *(uint16_t *)(value1 + 8) = 0x4f;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 4:
    case 0x18:
      *(uint16_t *)(value1 + 8) = 0x7e;
      return;
    case 5:
      *(uint16_t *)(value1 + 8) = 0x50;
      return;
    case 6:
      *(uint16_t *)(value1 + 8) = 0x60;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 7:
      *(uint16_t *)(value1 + 8) = 0x87;
      return;
    case 8:
      *(short *)(value1 + 8) = (short)*(uint32_t *)((intptr_t)self + 0x9c);
      return;
    case 10:
      *(uint16_t *)(value1 + 8) = 0x79;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 0xc:
      *(uint16_t *)(value1 + 8) = 100;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 0xd:
      *(uint16_t *)(value1 + 8) = 0x12;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 0xe:
      *(uint16_t *)(value1 + 8) = 0x11;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 0xf:
      *(uint16_t *)(value1 + 8) = 0x6c;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 0x10:
      *(uint16_t *)(value1 + 8) = 0x2b;
      return;
    case 0x11:
      *(uint16_t *)(value1 + 8) = 0x2a;
      return;
    case 0x12:
      *(uint16_t *)(value1 + 8) = 0x7a;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 0x13:
      *(uint16_t *)(value1 + 8) = 0x7b;
      return;
    case 0x14:
      *(uint16_t *)(value1 + 8) = 0x61;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 0x15:
      *(uint16_t *)(value1 + 8) = 0x2f;
      return;
    case 0x16:
      *(uint16_t *)(value1 + 8) = 0x10;
      return;
    case 0x17:
      *(uint16_t *)(value1 + 8) = 0x7f;
      return;
    case 0x19:
      *(uint16_t *)(value1 + 8) = 0x7d;
      return;
    case 0x1a:
      *(uint16_t *)(value1 + 8) = 0x82;
      return;
    case 0x1b:
      *(uint16_t *)(value1 + 8) = 0x81;
      return;
    case 0x1c:
      *(uint16_t *)(value1 + 8) = 0x80;
      return;
    case 0x1d:
      *(uint16_t *)(value1 + 8) = 0x86;
      return;
    case 0x1e:
      *(uint16_t *)(value1 + 8) = 0x62;
      return;
    case 0x1f:
      *(uint16_t *)(value1 + 8) = 0x6a;
      return;
    case 0x20:
      *(uint16_t *)(value1 + 8) = 99;
      return;
    case 0x21:
      *(uint16_t *)(value1 + 8) = 0x76;
      return;
    case 0x22:
      *(uint16_t *)(value1 + 8) = 0x18;
      return;
    case 0x23:
      *(uint16_t *)(value1 + 8) = 0x9a;
      *(uint16_t *)((intptr_t)self + 0x40) = 0xb;
      return;
    case 0x24:
      *(uint16_t *)(value1 + 8) = 0x75;
      return;
    case 0x25:
      *(uint16_t *)(value1 + 8) = 0x78;
      return;
    case 0x26:
switchD_00507578_caseD_26:
      *(uint16_t *)(value1 + 8) = 0x74;
      return;
    case 0x27:
      *(uint16_t *)(value1 + 8) = 0x77;
      break;
    case 0xffff:
      value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)((intptr_t)self + 0x50),(int *)0x0);
      if ((value1 != 0) && (*(char *)((intptr_t)self + 0x104) != '\0')) {
        uvalue2 = State_IsNegative(value1);
        if ((char)uvalue2 != '\0') {
          *(uint16_t *)(*(int *)((intptr_t)self + 200) + 8) = 0x78;
          return;
        }
        value3 = Rating_AdjustB(value1);
        if (value3 < 0x14) {
          *(uint16_t *)(*(int *)((intptr_t)self + 200) + 8) = 0x75;
          return;
        }
        if (*(int *)(value1 + 0xc) < 0x14) {
          value1 = *(int *)((intptr_t)self + 200);
          goto switchD_00507578_caseD_26;
        }
        uvalue2 = State_HasFlags(value1);
        if ((char)uvalue2 != '\0') {
          *(uint16_t *)(*(int *)((intptr_t)self + 200) + 8) = 0x76;
          return;
        }
        uvalue2 = State_HasPositive(value1);
        if ((char)uvalue2 != '\0') {
          *(uint16_t *)(*(int *)((intptr_t)self + 200) + 8) = 0x77;
          return;
        }
      }
      value1 = *(int *)((intptr_t)self + 200);
    case 9:
      *(uint16_t *)(value1 + 8) = 0xffff;
      return;
    }
  }
  return;
}
