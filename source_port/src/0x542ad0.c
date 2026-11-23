// Sound_QueryBufferFlag: ported from Pizza Connection 2 at 0x542ad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x542ad0
#include "pc2_port.h"

uint32_t __fastcall Sound_QueryBufferFlag(int arg1)

{
  uint32_t uvalue1;
  int *ptr2;
  uint32_t local_4;
  
  ptr2 = *(int **)(arg1 + 0x48);
  if (ptr2 == (int *)0x0) {
    return 0;
  }
  local_4 = 0;
  uvalue1 = (**(code **)(*ptr2 + 0x24))(ptr2,&local_4);
  if ((intptr_t)uvalue1 < 0) {
    return uvalue1 & 0xffffff00;
  }
  return (uint32_t)ptr2 & 1;
}
