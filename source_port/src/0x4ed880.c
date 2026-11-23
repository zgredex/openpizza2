// Game_GetLinkedObjectExtent: ported from Pizza Connection 2 at 0x4ed880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed880
#include "pc2_port.h"

void * __thiscall Game_GetLinkedObjectExtent(void *self,uint32_t arg1,uint32_t *arg2,uint32_t *arg3)

{
  uint32_t uvalue1;
  void *this_00;
  void *this_01;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  uvalue1 = arg1;
  this_00 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)self + 4),*(int *)(*(int *)(arg1 + 8) + 4)
                                      );
  this_01 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)self + 4),
                                       *(int *)(*(int *)(uvalue1 + 8) + 0x10));
  if (this_00 == (void *)0x0) {
    arg1 = 0;
    local_c = 0;
  }
  else {
    Sprite_GetRenderSize(this_00,&arg1,&local_c);
  }
  if (this_01 == (void *)0x0) {
    local_8 = 0;
    local_4 = 0;
  }
  else {
    Sprite_GetRenderSize(this_01,&local_8,&local_4);
  }
  if ((intptr_t)local_8 < (intptr_t)arg1) {
    local_8 = arg1;
  }
  *arg2 = local_8;
  if ((intptr_t)local_4 < (intptr_t)local_c) {
    *arg3 = local_c;
    return this_01;
  }
  *arg3 = local_4;
  return this_01;
}
