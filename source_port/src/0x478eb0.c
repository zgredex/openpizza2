// Stats_ComputeWeightedTotals: ported from Pizza Connection 2 at 0x478eb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478eb0
#include "pc2_port.h"

void __fastcall Stats_ComputeWeightedTotals(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int *ptr4;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
  value3 = 8;
  ptr2 = (int *)(arg1 + 0x17dc);
  ptr4 = (int *)(value1 + 0x220);
  do {
    value1 = ptr4[-8] * *(int *)(arg1 + 0x183c);
    *ptr2 = value1;
    value1 = value1 + *(int *)(arg1 + 0x1844) * *ptr4;
    *ptr2 = value1;
    value1 = value1 + ptr4[8] * *(int *)(arg1 + 0x1840);
    *ptr2 = value1;
    value1 = (ptr4[0x10] * *(int *)(arg1 + 0x1848) + value1) / 100;
    *ptr2 = value1 * 3;
    value3 = value3 + -1;
    *ptr2 = (value1 * 9 + *(int *)(arg1 + 0x1a04) + *(int *)(arg1 + 0x19fc)) / 5;
    ptr2 = ptr2 + 1;
    ptr4 = ptr4 + 1;
  } while (value3 != 0);
  return;
}
