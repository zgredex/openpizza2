// Chart_DrawGroupMatrix: ported from Pizza Connection 2 at 0x491c80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x491c80
#include "pc2_port.h"

void __cdecl Chart_DrawGroupMatrix(void *arg1,int arg2,int arg3,int arg4)

{
  int value1;
  int *ptr2;
  int value3;
  int *ptr4;
  int *ptr5;
  int *local_104;
  int local_100 [64];
  
  if (arg4 != 0) {
    value3 = 0x636;
    ptr4 = local_100;
    for (value1 = 0x40; value1 != 0; value1 = value1 + -1) {
      *ptr4 = 0;
      ptr4 = ptr4 + 1;
    }
    local_104 = local_100;
    ptr4 = (int *)(arg4 + 0x189c);
    ptr5 = local_100 + arg3;
    do {
      value1 = 0;
      *ptr5 = ptr4[-1] + *ptr4;
      ptr2 = local_104;
      do {
        if (value1 != arg3) {
          *ptr2 = *(int *)(arg4 + (value3 + value1) * 4);
        }
        value1 = value1 + 1;
        ptr2 = ptr2 + 1;
      } while (value1 < 6);
      value3 = value3 + 6;
      ptr5 = ptr5 + 8;
      ptr4 = ptr4 + 2;
      local_104 = local_104 + 8;
    } while (value3 < 0x666);
    Chart_DrawCustomerGroups(arg1,arg2,arg3,local_100);
  }
  return;
}
