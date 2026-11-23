// Object_ClearFieldsA: ported from Pizza Connection 2 at 0x521180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521180
#include "pc2_port.h"

void __fastcall Object_ClearFieldsA(int arg1)

{
  *(uint32_t *)(arg1 + 0x54) = 0;
  *(uint32_t *)(arg1 + 0x58) = 0;
  *(uint32_t *)(arg1 + 0x70) = 0;
  *(uint32_t *)(arg1 + 0x9c) = 0;
  *(uint32_t *)(arg1 + 0x78) = 0;
  *(uint32_t *)(arg1 + 0x6c) = 0;
  *(uint32_t *)(arg1 + 100) = 0;
  return;
}
