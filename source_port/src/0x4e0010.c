// Company_ComputeTotals: ported from Pizza Connection 2 at 0x4e0010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0010
#include "pc2_port.h"

void Company_ComputeTotals(int *arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  int value9;
  
  value1 = *arg1;
  value2 = *(int *)(value1 + 300) + *(int *)(value1 + 0x128) + *(int *)(value1 + 0x124) +
          *(int *)(value1 + 0x120);
  *(int *)(value1 + 0xfc) = value2;
  value1 = *arg1;
  value3 = *(int *)(value1 + 0x14c) + *(int *)(value1 + 0x148) + *(int *)(value1 + 0x144) +
          *(int *)(value1 + 0x140);
  *(int *)(value1 + 0x100) = value3;
  value1 = *arg1;
  value4 = *(int *)(value1 + 0x17c) + *(int *)(value1 + 0x178) + *(int *)(value1 + 0x174) +
          *(int *)(value1 + 0x170);
  *(int *)(value1 + 0x104) = value4;
  value1 = *arg1;
  value5 = *(int *)(value1 + 0x19c) + *(int *)(value1 + 0x198) + *(int *)(value1 + 0x194) +
          *(int *)(value1 + 400);
  *(int *)(value1 + 0x108) = value5;
  value1 = *arg1;
  value6 = *(int *)(value1 + 0x16c) + *(int *)(value1 + 0x168) + *(int *)(value1 + 0x164) +
          *(int *)(value1 + 0x160);
  *(int *)(value1 + 0x10c) = value6;
  value1 = *arg1;
  value7 = *(int *)(value1 + 0x15c) + *(int *)(value1 + 0x158) + *(int *)(value1 + 0x154) +
          *(int *)(value1 + 0x150);
  *(int *)(value1 + 0x110) = value7;
  value1 = *arg1;
  value8 = *(int *)(value1 + 0x13c) + *(int *)(value1 + 0x138) + *(int *)(value1 + 0x134) +
          *(int *)(value1 + 0x130);
  *(int *)(value1 + 0x114) = value8;
  value1 = *arg1;
  value9 = *(int *)(value1 + 0x18c) + *(int *)(value1 + 0x188) + *(int *)(value1 + 0x184) +
          *(int *)(value1 + 0x180);
  *(int *)(value1 + 0x118) = value9;
  *(int *)(*arg1 + 0x11c) = value9 + value2 + value3 + value4 + value5 + value6 + value7 + value8;
  return;
}
