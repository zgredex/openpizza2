// CRT_GetVaArg: ported from Pizza Connection 2 at 0x551944.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551944
#include "pc2_port.h"

uint32_t __cdecl CRT_GetVaArg(int *arg1)

{
  *arg1 = *arg1 + 4;
  return *(uint32_t *)(*arg1 + -4);
}
