// List_RemoveByValue: ported from Pizza Connection 2 at 0x539e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539e20
#include "pc2_port.h"

void __thiscall List_RemoveByValue(void *self,int arg1)

{
  int *ptr1;
  int *ptr2;
  int *ptr3;
  
  ptr3 = (int *)0x0;
  ptr1 = *(int **)((intptr_t)self + 0x50);
  if (*(int **)((intptr_t)self + 0x50) != (int *)0x0) {
    while (ptr2 = ptr1, *ptr2 != arg1) {
      ptr1 = (int *)ptr2[1];
      ptr3 = ptr2;
      if ((int *)ptr2[1] == (int *)0x0) {
        return;
      }
    }
    if (ptr2 != (int *)0x0) {
      if (ptr3 == (int *)0x0) {
        *(int *)((intptr_t)self + 0x50) = ptr2[1];
        Mem_Free(ptr2);
        return;
      }
      ptr3[1] = ptr2[1];
      Mem_Free(ptr2);
    }
  }
  return;
}
