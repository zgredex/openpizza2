// Entity_ApplyTypeProperties: ported from Pizza Connection 2 at 0x4d2b40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2b40
#include "pc2_port.h"

void __thiscall Entity_ApplyTypeProperties(void *self,int arg1)

{
  int *ptr1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  int value4;
  
  value4 = 0;
  *(int *)((intptr_t)self + 0x20) = arg1;
  if (DAT_0056b468 != arg1) {
    uptr3 = &DAT_0056b468;
    do {
      ptr1 = uptr3 + 4;
      uptr3 = uptr3 + 4;
      value4 = value4 + 4;
      if (*ptr1 == -1) {
        return;
      }
    } while (*ptr1 != arg1);
  }
  uvalue2 = (&DAT_0056b470)[value4];
  *(uint32_t *)((intptr_t)self + 0x40) = (&DAT_0056b46c)[value4];
  *(uint32_t *)((intptr_t)self + 0x44) = uvalue2;
  *(uint32_t *)((intptr_t)self + 0x48) = (&DAT_0056b474)[value4];
  return;
}
