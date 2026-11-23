// Record_GetTypeIndex48: ported from Pizza Connection 2 at 0x534a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534a80
#include "pc2_port.h"

int __thiscall Record_GetTypeIndex48(void *self,int arg1)

{
  int value1;
  
  if (((arg1 < 0) || (*(int *)((intptr_t)self + 0x48) <= arg1)) ||
     (value1 = *(int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48),
     *(char *)(*(int *)((intptr_t)self + 0x50) + 0x80 + value1 * 0x98) == '\0')) {
    return -1;
  }
  return value1;
}
