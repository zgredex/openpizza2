// Stats_SumValuesByCategory: ported from Pizza Connection 2 at 0x510030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510030
#include "pc2_port.h"

double __thiscall Stats_SumValuesByCategory(int arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int value3;
  float local_4;
  
  local_4 = 0.0;
  if (*(int *)(arg1 + 0x304) == 0) {
    return (double)0.0;
  }
  value1 = *(int *)(*(int *)(arg1 + 0x304) + 0x14);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup(*(void **)(arg1 + 0x304),value3,(int *)0x0);
      if (((*(int *)(value2 + 0x10) == arg2) || (arg2 == -1)) &&
         ((arg3 == -1 || (*(int *)(value2 + 0x14) == arg3)))) {
        local_4 = local_4 + *(float *)(value2 + 8);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return (double)local_4;
}
