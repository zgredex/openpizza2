// Object_SetMarketValueByType: ported from Pizza Connection 2 at 0x4d2b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2b90
#include "pc2_port.h"

void __fastcall Object_SetMarketValueByType(int arg1)

{
  bool flag1;
  uint32_t extraout_var;
  
  flag1 = UI_IsSpriteVisibleInView(arg1);
  if (CONCAT31(extraout_var,flag1) != 0) {
    switch(*(uint32_t *)(arg1 + 4)) {
    case 0:
    case 7:
    case 0x23:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 1000;
      return;
    case 1:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 45000;
      return;
    case 2:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 30000;
      return;
    case 3:
    case 5:
    case 6:
    case 0xb:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x20:
    case 0x22:
      break;
    case 4:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 35000;
      return;
    case 8:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 7000;
      return;
    case 9:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 40000;
      return;
    case 10:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 10000;
      return;
    case 0xc:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 25000;
      return;
    case 0xd:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 50000;
      return;
    case 0xe:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 20000;
      return;
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x1d:
    case 0x1e:
    case 0x1f:
      *(uint32_t *)(arg1 + 0x4c) = 1;
      return;
    case 0x21:
      *(uint32_t *)(arg1 + 0x50) = 1;
      *(uint32_t *)(arg1 + 0x3c) = 60000;
      return;
    default:
      NoOp_Stub();
    }
  }
  return;
}
