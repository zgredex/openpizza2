// City_RemovePersonAndMaintainPopulation: ported from Pizza Connection 2 at 0x4d6c10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6c10
#include "pc2_port.h"

uint32_t __thiscall City_RemovePersonAndMaintainPopulation(void *self,int arg1)

{
  uint8_t flag1;
  int *ptr2;
  int value3;
  uint32_t uvalue4;
  int value5;
  uint32_t local_8;
  
  value3 = *(int *)((intptr_t)self + 0xfdc);
  value5 = 0;
  local_8 = 0;
  if (0 < value3) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0xfc8),value5,(int *)0x0);
      if (*ptr2 == arg1) {
        local_8 = IDMap_RemoveByKey((void *)((intptr_t)self + 0xfc8),(intptr_t)ptr2);
        break;
      }
      value5 = value5 + 1;
    } while (value5 < value3);
  }
  flag1 = *(uint8_t *)(arg1 + 0x824);
  value3 = Game_CountObjectsByType2(self,(uint32_t)flag1);
  if ((value3 == 0) || (uvalue4 = Random_RangeFast(0,99), (intptr_t)uvalue4 < value3 * -0x1e + 100)) {
    City_SpawnPerson(self,(uint32_t)flag1);
  }
  return local_8;
}
