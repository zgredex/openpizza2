// MapObject_PlaceAtPoint: ported from Pizza Connection 2 at 0x4d3560.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3560
#include "pc2_port.h"

void __thiscall MapObject_PlaceAtPoint(void *self,int arg1)

{
  Record_SetDoubles48((void *)(*(int **)((intptr_t)self + 8))[0x16],**(int **)((intptr_t)self + 8),
                      *(int *)(arg1 + 0xc) + -0xa0,*(int *)(arg1 + 0x10) + -0xd0);
  *(int *)(*(int *)((intptr_t)self + 8) + 0x20) = arg1;
  return;
}
