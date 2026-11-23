// City_ApplyCrimeWave: ported from Pizza Connection 2 at 0x4dca80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dca80
#include "pc2_port.h"

void __fastcall City_ApplyCrimeWave(int arg1)

{
  int value1;
  void *pvVar2;
  int value3;
  uint32_t uvalue4;
  int *ptr5;
  int value6;
  int *ptr7;
  int *ptr8;
  int local_20 [8];
  
                    /* Applies a city crime wave to eligible objects. */
  ptr8 = (int *)(arg1 + 0x6c);
  ptr5 = local_20;
  value6 = 8;
  ptr7 = (int *)(&DAT_0056ca2c + *(int *)(arg1 + 0x10bc) * 0x24);
  do {
    value3 = *ptr8;
    value1 = *ptr7;
    ptr7 = ptr7 + 1;
    ptr8 = ptr8 + 1;
    *ptr5 = (value3 * value1) / 100;
    ptr5 = ptr5 + 1;
    value6 = value6 + -1;
  } while (value6 != 0);
  value6 = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      pvVar2 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value6,(int *)0x0);
      value3 = State_Is2DOr2E((intptr_t)pvVar2);
      if ((((value3 == 0) && (value3 = *(int *)((intptr_t)pvVar2 + 0x30), value3 < 8)) &&
          (*(int *)((intptr_t)pvVar2 + 0x38) != 0x1a)) &&
         (uvalue4 = Random_RangeFast(1,100), (intptr_t)uvalue4 <= local_20[value3])) {
        Person_WatchTVProgram(pvVar2);
      }
      value6 = value6 + 1;
    } while (value6 < *(int *)(DAT_0057c670 + 0x50));
  }
  return;
}
