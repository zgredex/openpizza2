// List_RemoveObject: ported from Pizza Connection 2 at 0x4f13d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f13d0
#include "pc2_port.h"

uint32_t __thiscall List_RemoveObject(void *self,int arg1)

{
  int value1;
  bool flag2;
  int value3;
  
  flag2 = false;
  if (*(int *)((intptr_t)self + 0xbc) == 0) {
    return 0;
  }
  Object_UpdateState(self,arg1);
  value1 = *(int *)((intptr_t)self + 0xbc);
  if (value1 == arg1) {
    *(uint32_t *)((intptr_t)self + 0xbc) = *(uint32_t *)(value1 + 0x70);
    return 1;
  }
  do {
    value3 = value1;
    value1 = *(int *)(value3 + 0x70);
    while( true ) {
      if (value1 == 0) {
        return 0;
      }
      if (flag2) {
        if (value1 == 0) {
          return 0;
        }
        *(uint32_t *)(value3 + 0x70) = *(uint32_t *)(value1 + 0x70);
        return 1;
      }
      if (value1 != arg1) break;
      flag2 = true;
    }
  } while( true );
}
