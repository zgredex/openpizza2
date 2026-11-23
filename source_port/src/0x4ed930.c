// Map_SetHoverTile: ported from Pizza Connection 2 at 0x4ed930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed930
#include "pc2_port.h"

void __thiscall Map_SetHoverTile(void *self,uint32_t *arg1)

{
  int value1;
  uint32_t *uptr2;
  uint32_t *uptr3;
  
  **(uint32_t **)((intptr_t)self + 100) = *arg1;
  *(uint32_t *)(*(int *)((intptr_t)self + 100) + 4) = arg1[1];
  uptr2 = (uint32_t *)arg1[2];
  uptr3 = *(uint32_t **)(*(int *)((intptr_t)self + 100) + 8);
  for (value1 = 0xf; value1 != 0; value1 = value1 + -1) {
    *uptr3 = *uptr2;
    uptr2 = uptr2 + 1;
    uptr3 = uptr3 + 1;
  }
  *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 100) + 8) + 4) = *(uint32_t *)((intptr_t)self + 0x68);
  *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 100) + 8) + 0x10) =
       *(uint32_t *)((intptr_t)self + 0x68);
  return;
}
