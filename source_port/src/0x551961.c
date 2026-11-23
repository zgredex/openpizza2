// CRT_ReadArg16: ported from Pizza Connection 2 at 0x551961.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551961
#include "pc2_port.h"

uint32_t __cdecl CRT_ReadArg16(int *arg1)

{
  *arg1 = *arg1 + 4;
  return CONCAT22((short)((uint32_t)*arg1 >> 0x10),*(uint16_t *)(*arg1 + -4));
}
