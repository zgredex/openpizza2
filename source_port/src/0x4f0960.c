// Map_LinkObjects: ported from Pizza Connection 2 at 0x4f0960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0960
#include "pc2_port.h"

void Map_LinkObjects(int arg1,int arg2,int arg3)

{
  uint16_t uvalue1;
  int value2;
  double dVar3;
  int value4;
  short *psVar5;
  short *psVar6;
  
  value4 = *(int *)(arg3 + 0xc);
  value2 = *(int *)(arg2 + 0xc);
  uvalue1 = *(uint16_t *)(arg2 + 4);
  if (value2 == value4) {
    dVar3 = 0.0;
  }
  else {
    dVar3 = (double)(*(int *)(arg2 + 0x10) - *(int *)(arg3 + 0x10)) / (double)(value2 - value4);
    if ((dVar3 == 0.5) || (dVar3 == -0.5)) goto LAB_004f09f7;
  }
  if ((value2 != value4) && (dVar3 != 0.0)) {
    NoOp_Stub();
    return;
  }
LAB_004f09f7:
  psVar6 = (short *)(arg2 + 0x14);
  value4 = 0;
  psVar5 = psVar6;
  do {
    if ((intptr_t)*psVar5 == (uint32_t)*(uint16_t *)(arg3 + 4)) {
      return;
    }
    value4 = value4 + 1;
    psVar5 = psVar5 + 1;
  } while (value4 < 8);
  value4 = 0;
  do {
    if (*psVar6 == -1) {
      *(uint16_t *)(arg2 + 0x14 + value4 * 2) = *(uint16_t *)(arg3 + 4);
      break;
    }
    value4 = value4 + 1;
    psVar6 = psVar6 + 1;
  } while (value4 < 8);
  if (value4 == 8) {
    NoOp_Stub();
  }
  if (arg1 == 1) {
    psVar6 = (short *)(arg3 + 0x14);
    value4 = 0;
    psVar5 = psVar6;
    do {
      if ((intptr_t)*psVar5 == (uint32_t)uvalue1) {
        return;
      }
      value4 = value4 + 1;
      psVar5 = psVar5 + 1;
    } while (value4 < 8);
    value4 = 0;
    do {
      if (*psVar6 == -1) {
        *(uint16_t *)(arg3 + 0x14 + value4 * 2) = uvalue1;
        break;
      }
      value4 = value4 + 1;
      psVar6 = psVar6 + 1;
    } while (value4 < 8);
    if (value4 == 8) {
      NoOp_Stub();
    }
  }
  NoOp_2();
  return;
}
