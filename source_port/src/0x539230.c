// Surface_Release: ported from Pizza Connection 2 at 0x539230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539230
#include "pc2_port.h"

void __fastcall Surface_Release(int arg1)

{
  int *ptr1;
  
  if (0 < *(int *)(arg1 + 0x2c)) {
    *(uint32_t *)(arg1 + 0x28) = 0;
    ptr1 = *(int **)(*(int *)(arg1 + 0x40) + 0xc);
    (**(code **)(*ptr1 + 0x80))(ptr1,0);
    *(uint32_t *)(arg1 + 0x2c) = 0;
  }
  return;
}
