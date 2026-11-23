// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x4817c0.c:12:3: error: use of undeclared identifier '_MEMORYSTATUS'
// System_QueryMemoryInfo: ported from Pizza Connection 2 at 0x4817c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4817c0
#include "pc2_port.h"

void __fastcall System_QueryMemoryInfo(int arg1)

{
  int *ptr1;
  int value2;
  uint32_t *uptr3;
  _MEMORYSTATUS local_18c;
  uint32_t local_16c [12];
  int iStack_13c;
  
  GlobalMemoryStatus(&local_18c);
  *(SIZE_T *)(arg1 + 0x2e1c) = local_18c.dwTotalPhys + 0xfffff >> 0x14;
  if ((*(int **)(DAT_0057c5c8 + 0x40) != (int *)0x0) &&
     (ptr1 = (int *)**(int **)(DAT_0057c5c8 + 0x40), ptr1 != (int *)0x0)) {
    uptr3 = local_16c;
    for (value2 = 0x5b; value2 != 0; value2 = value2 + -1) {
      *uptr3 = 0;
      uptr3 = uptr3 + 1;
    }
    local_16c[0] = 0x16c;
    (**(code **)(*ptr1 + 0x2c))(ptr1,local_16c,0);
    *(uint32_t *)(arg1 + 0x2e20) = iStack_13c + 0xfffffU >> 0x14;
  }
  return;
}
