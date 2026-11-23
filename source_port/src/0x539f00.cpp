// Object_GetRootType: ported from Pizza Connection 2 at 0x539f00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539f00
#include "pc2_port.h"

uint32_t __fastcall Object_GetRootType(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x4c);
  while (value1 == 3) {
    arg1 = *(int *)(arg1 + 0x54);
    value1 = *(int *)(arg1 + 0x4c);
  }
  return *(uint32_t *)(arg1 + 0x4c);
}
