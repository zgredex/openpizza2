// Map_LinkCells: ported from Pizza Connection 2 at 0x4f0ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0ab0
#include "pc2_port.h"

void __thiscall Map_LinkCells(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  double dVar2;
  int value3;
  int value4;
  int value5;
  short *psVar6;
  short *psVar7;
  
  value3 = Array_GetRecord28(self,arg1,arg2);
  value4 = Array_GetRecord28(self,arg1,arg3);
  value5 = *(int *)(value3 + 0xc);
  value1 = *(int *)(value4 + 0xc);
  if (value5 == value1) {
    dVar2 = 0.0;
  }
  else {
    dVar2 = (double)(*(int *)(value3 + 0x10) - *(int *)(value4 + 0x10)) / (double)(value5 - value1);
    if ((dVar2 == 0.5) || (dVar2 == -0.5)) goto LAB_004f0b47;
  }
  if ((value5 != value1) && (dVar2 != 0.0)) {
    NoOp_Stub();
    return;
  }
LAB_004f0b47:
  psVar7 = (short *)(value3 + 0x14);
  value5 = 0;
  psVar6 = psVar7;
  do {
    if (*psVar6 == arg3) {
      return;
    }
    value5 = value5 + 1;
    psVar6 = psVar6 + 1;
  } while (value5 < 8);
  value5 = 0;
  do {
    if (*psVar7 == -1) {
      *(short *)(value3 + 0x14 + value5 * 2) = (short)arg3;
      break;
    }
    value5 = value5 + 1;
    psVar7 = psVar7 + 1;
  } while (value5 < 8);
  if (arg1 == 1) {
    value5 = 0;
    psVar7 = (short *)(value4 + 0x14);
    psVar6 = psVar7;
    do {
      if (*psVar6 == arg2) {
        return;
      }
      value5 = value5 + 1;
      psVar6 = psVar6 + 1;
    } while (value5 < 8);
    value5 = 0;
    while (*psVar7 != -1) {
      value5 = value5 + 1;
      psVar7 = psVar7 + 1;
      if (7 < value5) {
        return;
      }
    }
    *(short *)(value4 + 0x14 + value5 * 2) = (short)arg2;
  }
  return;
}
