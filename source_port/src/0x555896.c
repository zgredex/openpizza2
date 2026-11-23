// FUN_00555896: ported from Pizza Connection 2 at 0x555896.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555896
#include "pc2_port.h"

void __cdecl FUN_00555896(int arg1,uint32_t *arg2)

{
  int value1;
  int value2;
  
  value1 = arg1 - (intptr_t)arg2;
  value2 = 3;
  do {
    *(uint32_t *)(value1 + (intptr_t)arg2) = *arg2;
    arg2 = arg2 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
