// Game_GetNextRecordField3C: ported from Pizza Connection 2 at 0x48e790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48e790
#include "pc2_port.h"

uint32_t __cdecl Game_GetNextRecordField3C(int arg1,int arg2)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  
  value4 = 0;
  value2 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value1 = *(int *)(value2 + 0x15c);
  self = (void *)(value2 + 0x148);
  value2 = IDMap_Lookup(self,arg1,(int *)0x0);
  value2 = Map_FindIndex(self,value2);
  while( true ) {
    value2 = value2 + 1;
    if (value1 <= value2) {
      value2 = 0;
    }
    value3 = IDMap_Lookup(self,value2,(int *)0x0);
    if ((arg2 != 0) || (*(int *)(value3 + 0x38) < 2)) break;
    value4 = value4 + 1;
    if (value1 <= value4) {
      return 0;
    }
  }
  return *(uint32_t *)(value3 + 0x3c);
}
