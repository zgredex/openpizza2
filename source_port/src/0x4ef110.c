// Object_InsertSortedByScreenY: ported from Pizza Connection 2 at 0x4ef110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ef110
#include "pc2_port.h"

void __thiscall Object_InsertSortedByScreenY(void *self,int arg1,int *arg2)

{
  int *ptr1;
  int *ptr2;
  int *ptr3;
  int *local_4;
  
  ptr3 = *(int **)(*(int *)(arg1 + 8) + 0x20);
  if (ptr3 == (int *)0x0) {
    *(int **)(*(int *)(arg1 + 8) + 0x20) = arg2;
    arg2[0x1b] = 0;
    return;
  }
  local_4 = (int *)0x0;
  ptr1 = Record_GetScreenSortY(self,ptr3);
  ptr2 = Record_GetScreenSortY(self,arg2);
  if ((intptr_t)ptr1 <= (intptr_t)ptr2) {
    do {
      local_4 = ptr3;
      ptr3 = (int *)local_4[0x1b];
      if (ptr3 == (int *)0x0) {
        local_4[0x1b] = (intptr_t)arg2;
        arg2[0x1b] = 0;
        return;
      }
      ptr1 = Record_GetScreenSortY(self,ptr3);
      ptr2 = Record_GetScreenSortY(self,arg2);
    } while ((intptr_t)ptr1 <= (intptr_t)ptr2);
  }
  arg2[0x1b] = (intptr_t)ptr3;
  if (local_4 == (int *)0x0) {
    *(int **)(*(int *)(arg1 + 8) + 0x20) = arg2;
    return;
  }
  local_4[0x1b] = (intptr_t)arg2;
  return;
}
