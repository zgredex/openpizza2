// Tilemap_GetCell: ported from Pizza Connection 2 at 0x53e190.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53e190
#include "pc2_port.h"

uint32_t __cdecl Tilemap_GetCell(uint32_t arg1,int arg2,int arg3)

{
  uint32_t in_EAX;
  
  if ((((arg2 < 0) || (in_EAX = arg1, (intptr_t)(uint32_t)*(uint16_t *)(arg1 + 0x1a) <= arg2)) ||
      (arg3 < 0)) || ((intptr_t)(uint32_t)*(uint16_t *)(arg1 + 0x1c) <= arg3)) {
    return in_EAX & 0xffff0000;
  }
  return CONCAT22((short)((uint32_t)(arg2 * 3) >> 0x10),
                  *(uint16_t *)
                   (*(int *)(arg1 + 0x20) * arg3 + *(int *)(arg1 + 0x28) + arg2 * 3));
}
