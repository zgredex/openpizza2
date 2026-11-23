// City_RebuildBuildingSortIndexByMode: ported from Pizza Connection 2 at 0x496930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x496930
#include "pc2_port.h"


void City_RebuildBuildingSortIndexByMode(void)

{
  int value1;
  
  if (DAT_0057c714 != (int *)0x0) {
    Mem_Free(DAT_0057c714);
    DAT_0057c714 = (int *)0x0;
  }
  if (0 < (intptr_t)DAT_0057c704) {
    DAT_0057c714 = operator_new((intptr_t)DAT_0057c704 << 2);
    DAT_0057c6fc = *(uint32_t *)(*(int *)(DAT_0057c670 + 0x9c) + 0x3c);
    switch(DAT_0057c708) {
    case 0:
      if (0 < (intptr_t)DAT_0057c704) {
        value1 = 0;
        if (0 < (intptr_t)DAT_0057c704) {
          do {
            DAT_0057c714[value1] = value1;
            value1 = value1 + 1;
          } while (value1 < (intptr_t)DAT_0057c704);
        }
        CRT_QSort(DAT_0057c714,DAT_0057c704,4,&LAB_00496160);
      }
      return;
    case 1:
      if (0 < (intptr_t)DAT_0057c704) {
        value1 = 0;
        if (0 < (intptr_t)DAT_0057c704) {
          do {
            DAT_0057c714[value1] = value1;
            value1 = value1 + 1;
          } while (value1 < (intptr_t)DAT_0057c704);
        }
        CRT_QSort(DAT_0057c714,DAT_0057c704,4,&LAB_00496200);
      }
      return;
    case 2:
      if (0 < (intptr_t)DAT_0057c704) {
        value1 = 0;
        if (0 < (intptr_t)DAT_0057c704) {
          do {
            DAT_0057c714[value1] = value1;
            value1 = value1 + 1;
          } while (value1 < (intptr_t)DAT_0057c704);
        }
        CRT_QSort(DAT_0057c714,DAT_0057c704,4,&LAB_004969f0);
      }
      return;
    case 3:
      if (0 < (intptr_t)DAT_0057c704) {
        value1 = 0;
        if (0 < (intptr_t)DAT_0057c704) {
          do {
            DAT_0057c714[value1] = value1;
            value1 = value1 + 1;
          } while (value1 < (intptr_t)DAT_0057c704);
        }
        CRT_QSort(DAT_0057c714,DAT_0057c704,4,&LAB_00496ac0);
      }
      return;
    }
  }
  return;
}
