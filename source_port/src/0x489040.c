// Map_GetTileByte: ported from Pizza Connection 2 at 0x489040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489040
#include "pc2_port.h"

uint32_t __thiscall Map_GetTileByte(void *self,int arg1,int arg2)

{
  int value1;
  
  value1 = *(int *)(*(int *)((intptr_t)self + 0xa0) + 0x18) + arg2 * 800;
  return CONCAT31((int3)((uint32_t)value1 >> 8),*(uint8_t *)(value1 + arg1));
}
