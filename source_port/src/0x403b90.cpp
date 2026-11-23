// List_FindByKey: ported from Pizza Connection 2 at 0x403b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403b90
#include "pc2_port.h"

int __thiscall List_FindByKey(void *self,int arg1)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 0xc);
  while( true ) {
    if (value1 == 0) {
      return 0;
    }
    if (*(int *)(value1 + 0x10) == arg1) break;
    value1 = *(int *)(value1 + 0x14);
  }
  return value1;
}
