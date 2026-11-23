// CRT_ReadArg64: ported from Pizza Connection 2 at 0x551951.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551951
#include "pc2_port.h"

uint64_t __cdecl CRT_ReadArg64(int *arg1)

{
  *arg1 = *arg1 + 8;
  return *(uint64_t *)(*arg1 + -8);
}
