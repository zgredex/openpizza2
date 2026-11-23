// Object_GetActiveValue: ported from Pizza Connection 2 at 0x521b10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521b10
#include "pc2_port.h"

uint32_t __fastcall Object_GetActiveValue(int arg1)

{
  if (*(uint32_t *)(arg1 + 0x6c) == 0) {
    return *(uint32_t *)(arg1 + 0x68);
  }
  return ~-(uint32_t)(*(int *)(arg1 + 0x78) != 0) & *(uint32_t *)(arg1 + 0x6c);
}
