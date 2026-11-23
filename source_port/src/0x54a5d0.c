// Window_GetChildAndNotify: ported from Pizza Connection 2 at 0x54a5d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a5d0
#include "pc2_port.h"

int * __fastcall Window_GetChildAndNotify(int arg1)

{
  int *ptr1;
  int local_4;
  
  ptr1 = *(int **)(arg1 + 8);
  if (ptr1 == (int *)0x0) {
    return (int *)0x0;
  }
  local_4 = arg1;
  (**(code **)(*ptr1 + 8))(ptr1,&local_4);
  return ptr1;
}
