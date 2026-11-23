// Stats_SumRecordCounts: ported from Pizza Connection 2 at 0x4fb600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fb600
#include "pc2_port.h"

void Stats_SumRecordCounts(void *arg1,int *arg2,int *arg3)

{
  int value1;
  int value2;
  int value3;
  
  *arg2 = 0;
  value3 = 0;
  *arg3 = 0;
  value1 = *(int *)((intptr_t)arg1 + 0x14);
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup(arg1,value3,(int *)0x0);
      *arg3 = *arg3 + *(int *)(value2 + 4);
      if (*(int *)(value2 + 0x1c) != 0) {
        *arg2 = *arg2 + *(int *)(value2 + 4);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return;
}
