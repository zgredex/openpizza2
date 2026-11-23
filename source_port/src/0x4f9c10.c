// City_FindMatchingCity: ported from Pizza Connection 2 at 0x4f9c10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f9c10
#include "pc2_port.h"

int City_FindMatchingCity(int *arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value3 = -1;
  value4 = 0;
  value1 = *(int *)(*arg1 + 0x24);
  if (0 < *(int *)(DAT_0057c670 + 0x88)) {
    do {
      value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),value4,(int *)0x0);
      if ((((*(int *)(value2 + 0xc) == 5) && ((arg1[7] == 0 || (*(char *)(value2 + 0x14) == '\0')))
           ) && ((value1 == 4 || (*(int *)(value2 + 0x10) == value1)))) &&
         ((value3 = value4, arg1[5] != -1 && ((uint32_t)*(uint8_t *)(value2 + 0x14) == arg1[6])))) {
        return value4;
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)(DAT_0057c670 + 0x88));
  }
  return value3;
}
