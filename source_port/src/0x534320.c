// Record_SetRect48: ported from Pizza Connection 2 at 0x534320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534320
#include "pc2_port.h"

uint32_t __thiscall
Record_SetRect48(int arg1,int arg2,int arg3,int arg4,uint64_t arg5)

{
  int *ptr1;
  
  if ((-1 < arg2) && (arg2 < *(int *)(arg1 + 0x48))) {
    ptr1 = (int *)(*(int *)(arg1 + 0x4c) + arg2 * 0x48);
    if (*ptr1 != -1) {
      ptr1[2] = arg3;
      ptr1[3] = arg4;
      *(uint64_t *)(*(int *)(arg1 + 0x4c) + 0x10 + arg2 * 0x48) = arg5;
      return 1;
    }
  }
  return 0;
}
