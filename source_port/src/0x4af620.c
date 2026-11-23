// Stats_BuildCategoryMatrix: ported from Pizza Connection 2 at 0x4af620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4af620
#include "pc2_port.h"

void __cdecl Stats_BuildCategoryMatrix(int *arg1,int *arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int *ptr5;
  int *ptr6;
  int *ptr7;
  int *local_534;
  int local_530 [8];
  int local_510 [12];
  int local_4e0;
  int local_480 [96];
  int aiStack_300 [192];
  
  ptr5 = arg1;
  for (value3 = 0x40; value3 != 0; value3 = value3 + -1) {
    *ptr5 = 0;
    ptr5 = ptr5 + 1;
  }
  ptr5 = local_530;
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *ptr5 = 0;
    ptr5 = ptr5 + 1;
  }
  ptr5 = local_510;
  for (value3 = 0x24; value3 != 0; value3 = value3 + -1) {
    *ptr5 = 0;
    ptr5 = ptr5 + 1;
  }
  ptr5 = local_480;
  for (value3 = 0x120; value3 != 0; value3 = value3 + -1) {
    *ptr5 = 0;
    ptr5 = ptr5 + 1;
  }
  value3 = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value3,(int *)0x0);
      if (*(int *)(value2 + 0x30) == DAT_0057d664) {
        value4 = 0;
        ptr5 = (int *)(value2 + 0xd4);
        do {
          value2 = *ptr5;
          value1 = *(int *)(value2 + 4);
          if (value1 == 3) {
            aiStack_300[value4] = aiStack_300[value4] + 1;
            local_4e0 = local_4e0 + 1;
          }
          else {
            value1 = value4 + value1 * 8;
            local_480[value1] = local_480[value1] + 1;
            value2 = *(int *)(value2 + 4);
            local_510[value2] = local_510[value2] + 1;
          }
          ptr5 = ptr5 + 1;
          local_530[value4] = local_530[value4] + 1;
          value4 = value4 + 1;
        } while (value4 < 8);
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)(DAT_0057c670 + 0x50));
  }
  ptr5 = local_480;
  local_534 = (int *)0x24;
  do {
    ptr7 = local_530;
    value3 = 8;
    ptr6 = ptr5;
    do {
      value2 = *ptr7;
      ptr7 = ptr7 + 1;
      ptr5 = ptr6 + 1;
      value3 = value3 + -1;
      *ptr6 = (value2 / 2 + *ptr6 * 100) / value2;
      ptr6 = ptr5;
    } while (value3 != 0);
    local_534 = (int *)((intptr_t)local_534 + -1);
  } while (local_534 != (int *)0x0);
  local_534 = local_510;
  value3 = 0;
  ptr5 = local_480;
  do {
    ptr7 = arg1;
    if (0 < *local_534) {
      *arg2 = value3;
      arg2 = arg2 + 1;
      ptr7 = arg1 + 8;
      ptr6 = ptr5;
      for (value2 = 8; value2 != 0; value2 = value2 + -1) {
        *arg1 = *ptr6;
        ptr6 = ptr6 + 1;
        arg1 = arg1 + 1;
      }
    }
    value3 = value3 + 1;
    local_534 = local_534 + 1;
    ptr5 = ptr5 + 8;
    arg1 = ptr7;
  } while (value3 < 0x24);
  return;
}
