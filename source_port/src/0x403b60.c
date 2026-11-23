// Input_CompleteEvent: ported from Pizza Connection 2 at 0x403b60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403b60
#include "pc2_port.h"

uint32_t __thiscall Input_CompleteEvent(void *self,int arg1)

{
  int value1;
  
  value1 = List_FindByKey(self,arg1);
  if (value1 == 0) {
    return 0;
  }
  *(uint32_t *)(value1 + 0xc) = 0;
  SetEvent(*(HANDLE *)((intptr_t)self + 0x6c));
  return 1;
}
