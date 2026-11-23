// Surface_Unlock: ported from Pizza Connection 2 at 0x539260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539260
#include "pc2_port.h"

void __fastcall Surface_Unlock(int arg1)

{
  int *ptr1;
  
  ptr1 = *(int **)(*(int *)(arg1 + 0x40) + 0x10);
  (**(code **)(*ptr1 + 0x80))(ptr1,0);
  return;
}
