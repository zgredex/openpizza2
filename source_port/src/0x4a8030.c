// StringTable_SortIndexArray: ported from Pizza Connection 2 at 0x4a8030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a8030
#include "pc2_port.h"

void __cdecl StringTable_SortIndexArray(int *arg1,int *arg2)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  uint8_t *local_88;
  uint8_t *local_84;
  uint8_t local_80 [64];
  uint8_t local_40 [64];
  
  value1 = 0;
  value3 = (intptr_t)arg1 - (intptr_t)arg2;
  do {
    *(int *)(value3 + (intptr_t)arg2) = value1;
    *arg2 = value1;
    value1 = value1 + 1;
    arg2 = arg2 + 1;
  } while (value1 < 0x5a);
  value1 = 0x55;
  do {
    if (0 < value1) {
      ptr4 = arg1;
      value3 = value1;
      do {
        String_Format(local_80,&DAT_005630d0,(&DAT_00583544)[*ptr4]);
        String_Format(local_40,&DAT_005630d0,(&DAT_00583544)[ptr4[1]]);
        local_88 = local_80;
        local_84 = local_40;
        value2 = String_CompareLocalizedNoCase(&local_88,(int *)&local_84);
        if (0 < value2) {
          value2 = *ptr4;
          *ptr4 = ptr4[1];
          ptr4[1] = value2;
        }
        ptr4 = ptr4 + 1;
        value3 = value3 + -1;
      } while (value3 != 0);
    }
    value1 = value1 + -1;
  } while (-1 < value1);
  return;
}
