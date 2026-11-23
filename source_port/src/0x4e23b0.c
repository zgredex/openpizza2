// Player_FindRecordByCityId: ported from Pizza Connection 2 at 0x4e23b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e23b0
#include "pc2_port.h"

void * __thiscall Player_FindRecordByCityId(void *self,int arg1)

{
  int value1;
  int value2;
  bool flag3;
  void *this_00;
  int value4;
  
  value1 = *(int *)(arg1 + 0x3c);
  value2 = *(int *)((intptr_t)self + 0x194);
  value4 = 0;
  if (0 < value2) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x180),value4,(int *)0x0);
      flag3 = LookupTable_HasKey(this_00,value1);
      if (flag3) {
        return this_00;
      }
      value4 = value4 + 1;
    } while (value4 < value2);
  }
  return (void *)0x0;
}
