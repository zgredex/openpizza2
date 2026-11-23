// Object_Compare: ported from Pizza Connection 2 at 0x4ed500.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed500
#include "pc2_port.h"

int __thiscall Object_Compare(void *self,int arg1,int arg2)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  
  if (*(int *)((intptr_t)self + 0xc) != 0x10) {
    uvalue1 = *(int *)(arg1 + 0x10) - *(int *)(arg2 + 0x10);
    uvalue3 = (intptr_t)uvalue1 >> 0x1f;
    uvalue2 = *(int *)(arg1 + 0xc) - *(int *)(arg2 + 0xc);
    uvalue4 = (intptr_t)uvalue2 >> 0x1f;
    return ((uvalue2 ^ uvalue4) - uvalue4) * 3 + ((uvalue1 ^ uvalue3) - uvalue3) * 4;
  }
  if ((*(int *)(arg1 + 0xc) == *(int *)(arg2 + 0xc)) ||
     (*(int *)(arg1 + 0x10) == *(int *)(arg2 + 0x10))) {
    return 0xe;
  }
  return 10;
}
