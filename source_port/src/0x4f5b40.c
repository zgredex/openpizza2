// Object_CanAssignSlot: ported from Pizza Connection 2 at 0x4f5b40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5b40
#include "pc2_port.h"

uint32_t Object_CanAssignSlot(int arg1,int arg2,int *arg3,uint32_t *arg4)

{
  int *ptr1;
  int value2;
  
  *arg3 = -1;
  if (arg4 != (uint32_t *)0x0) {
    *arg4 = 0;
  }
  ptr1 = *(int **)(arg1 + 8);
  if (ptr1[0xe] != 0) {
    value2 = *ptr1;
    if ((value2 != *(int *)(arg2 + 0x44)) && (value2 != *(int *)(arg2 + 0x48))) {
      if (*(int *)(arg2 + 0x54) < 0xc9) {
        *arg3 = value2;
        return 1;
      }
      ptr1[0xe] = 0;
      if (arg4 != (uint32_t *)0x0) {
        *arg4 = 1;
      }
    }
  }
  return 0;
}
