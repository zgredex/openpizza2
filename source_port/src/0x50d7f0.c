// Object_GetLevelProperty: ported from Pizza Connection 2 at 0x50d7f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d7f0
#include "pc2_port.h"

uint32_t __thiscall Object_GetLevelProperty(void *self,int arg1)

{
  int value1;
  
  value1 = Object_GetClampedLevel((intptr_t)self);
  return *(uint32_t *)(&DAT_0056d0e0 + (arg1 + value1 * 3) * 4);
}
