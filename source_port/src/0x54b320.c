// Array_FindEntryByKeys: ported from Pizza Connection 2 at 0x54b320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b320
#include "pc2_port.h"

int __thiscall Array_FindEntryByKeys(void *self,int arg1,int arg2)

{
  int value1;
  void *this_00;
  int value2;
  int value3;
  int value4;
  
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                 (int *)0x0);
  value2 = Array_FindIndexByPtr(this_00,arg2);
  value1 = *(int *)((intptr_t)self + 0x18);
  value4 = 0;
  if (0 < value1) {
    do {
      value3 = IDMap_Lookup((void *)((intptr_t)self + 4),value4,(int *)0x0);
      if ((*(int *)(value3 + 0x34) == arg1) && (*(int *)(value3 + 0x30) == value2)) {
        return value3;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  return 0;
}
