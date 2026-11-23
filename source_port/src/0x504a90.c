// Game_GetTimeByMode: ported from Pizza Connection 2 at 0x504a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x504a90
#include "pc2_port.h"

void __thiscall Game_GetTimeByMode(void *self,uint32_t arg1)

{
  uint32_t uvalue1;
  int value2;
  
  *(uint32_t *)((intptr_t)self + 0x44) = 0xffffffff;
  switch(arg1) {
  case 0:
    switch(*(uint32_t *)((intptr_t)self + 0x30)) {
    case 0:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x78;
      break;
    case 1:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x96;
      break;
    case 2:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x66;
      break;
    case 3:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x5a;
      break;
    case 4:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x84;
      break;
    case 5:
    case 0xb:
    case 0xf:
      *(uint32_t *)((intptr_t)self + 0x44) = 0xa2;
      break;
    case 6:
      *(uint32_t *)((intptr_t)self + 0x44) = 0xb4;
      break;
    case 7:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x3c;
    }
    uvalue1 = Random_RangeFast(0,0x14);
    value2 = *(int *)((intptr_t)self + 0x44) + (uvalue1 - 10);
    *(int *)((intptr_t)self + 0x44) = value2;
    *(int *)((intptr_t)self + 0x48) = value2;
    return;
  case 1:
    switch(*(uint32_t *)((intptr_t)self + 0x30)) {
    case 0:
switchD_00504ac2_caseD_0:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x6e;
      break;
    case 1:
switchD_00504ac2_caseD_1:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x78;
      break;
    case 2:
switchD_00504ac2_caseD_2:
      *(uint32_t *)((intptr_t)self + 0x44) = 100;
      break;
    case 3:
switchD_00504ac2_caseD_3:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x50;
      break;
    case 4:
switchD_00504ac2_caseD_4:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x46;
      break;
    case 5:
    case 0xb:
    case 0xf:
    case 0x21:
switchD_00504ac2_caseD_5:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x82;
      break;
    case 6:
switchD_00504ac2_caseD_6:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x8c;
      break;
    case 7:
switchD_00504ac2_caseD_7:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x5a;
    default:
      break;
    }
    break;
  case 2:
  case 9:
    *(uint32_t *)((intptr_t)self + 0x48) = 5;
    *(uint32_t *)((intptr_t)self + 0x44) = 5;
    return;
  case 3:
    switch(*(uint32_t *)((intptr_t)self + 0x30)) {
    case 0:
      goto switchD_00504ac2_caseD_0;
    case 1:
      goto switchD_00504ac2_caseD_1;
    case 2:
      goto switchD_00504ac2_caseD_2;
    case 3:
      goto switchD_00504ac2_caseD_3;
    case 4:
      goto switchD_00504ac2_caseD_4;
    case 5:
    case 0xb:
    case 0xf:
    case 0x21:
      goto switchD_00504ac2_caseD_5;
    case 6:
      goto switchD_00504ac2_caseD_6;
    case 7:
      goto switchD_00504ac2_caseD_7;
    default:
      break;
    }
  case 4:
    switch(*(uint32_t *)((intptr_t)self + 0x30)) {
    case 0:
      *(uint32_t *)((intptr_t)self + 0x44) = 0xdc;
      break;
    case 1:
      *(uint32_t *)((intptr_t)self + 0x44) = 0xf0;
      break;
    case 2:
      *(uint32_t *)((intptr_t)self + 0x44) = 200;
      break;
    case 3:
      *(uint32_t *)((intptr_t)self + 0x44) = 0xa0;
      break;
    case 4:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x8c;
      break;
    case 5:
    case 0xb:
    case 0xf:
    case 0x21:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x104;
      break;
    case 6:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x118;
      break;
    case 7:
      *(uint32_t *)((intptr_t)self + 0x44) = 0xb4;
    }
    uvalue1 = Random_RangeFast(0,0x14);
    value2 = *(int *)((intptr_t)self + 0x44) + (uvalue1 - 10);
    *(int *)((intptr_t)self + 0x44) = value2;
    *(int *)((intptr_t)self + 0x48) = value2;
    return;
  default:
    *(uint32_t *)((intptr_t)self + 0x48) = 10;
    *(uint32_t *)((intptr_t)self + 0x44) = 10;
    return;
  case 6:
    if ((*(int *)((intptr_t)self + 0x30) == 0xf) || (*(int *)((intptr_t)self + 0x30) == 0x21)) {
      *(uint32_t *)((intptr_t)self + 0x48) = 0x50;
      *(uint32_t *)((intptr_t)self + 0x44) = 0x50;
      return;
    }
    *(uint32_t *)((intptr_t)self + 0x48) = 0x1e;
    *(uint32_t *)((intptr_t)self + 0x44) = 0x1e;
    return;
  case 8:
    switch(*(uint32_t *)((intptr_t)self + 0x30)) {
    case 0:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x140;
      break;
    case 1:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x154;
      break;
    case 2:
      *(uint32_t *)((intptr_t)self + 0x44) = 300;
      break;
    case 3:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x104;
      break;
    case 4:
      *(uint32_t *)((intptr_t)self + 0x44) = 0xf0;
      break;
    case 5:
    case 0xb:
    case 0xf:
    case 0x21:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x168;
      break;
    case 6:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x17c;
      break;
    case 7:
      *(uint32_t *)((intptr_t)self + 0x44) = 0x118;
    }
    uvalue1 = Random_RangeFast(0,0x14);
    value2 = *(int *)((intptr_t)self + 0x44) + (uvalue1 - 10);
    *(int *)((intptr_t)self + 0x44) = value2;
    *(int *)((intptr_t)self + 0x48) = value2;
    return;
  }
  uvalue1 = Random_RangeFast(0,0x14);
  value2 = *(int *)((intptr_t)self + 0x44) + (uvalue1 - 10);
  *(int *)((intptr_t)self + 0x44) = value2;
  *(int *)((intptr_t)self + 0x48) = value2;
  return;
}
