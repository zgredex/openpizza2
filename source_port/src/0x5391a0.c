// Thread_WaitForExit: ported from Pizza Connection 2 at 0x5391a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5391a0
#include "pc2_port.h"

uint32_t __fastcall Thread_WaitForExit(int arg1)

{
  int *ptr1;
  bool flag2;
  DWORD DVar3;
  int value4;
  
  flag2 = true;
  DVar3 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar3 == 0x102) {
    while( true ) {
      ptr1 = *(int **)(*(int *)(arg1 + 0x40) + 0x10);
      value4 = (**(code **)(*ptr1 + 0x6c))(ptr1);
      if (value4 == 0) {
        ptr1 = *(int **)(*(int *)(arg1 + 0x40) + 8);
        if (ptr1 != (int *)0x0) {
          (**(code **)(*ptr1 + 0x6c))(ptr1);
        }
        return 1;
      }
      if (!flag2) break;
      flag2 = false;
      if (value4 == -0x7789ff1f) {
        (**(code **)(*(int *)**(uint32_t **)(arg1 + 0x40) + 0x50))
                  ((int *)**(uint32_t **)(arg1 + 0x40),*(uint32_t *)(arg1 + 0x44),0x13);
      }
      Sleep(1);
    }
  }
  return 0;
}
