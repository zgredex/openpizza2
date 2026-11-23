// Gfx_RectList_Construct: ported from Pizza Connection 2 at 0x534d60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534d60
#include "pc2_port.h"

uint32_t * __thiscall
Gfx_RectList_Construct(void *self,uint32_t arg1,int arg2,int arg3)

{
  int value1;
  void *pvVar2;
  
  *(uint32_t *)((intptr_t)self + 4) = arg1;
  *(int *)((intptr_t)self + 0xc) = arg3;
  *(uint8_t ***)self = &PTR_Gfx_RectList_Delete_0055c810;
  value1 = arg3 * 2 + 2;
  *(int *)((intptr_t)self + 8) = arg2;
  *(int *)((intptr_t)self + 0x10) = value1;
  pvVar2 = operator_new(value1 * arg2 * 2);
  *(void **)((intptr_t)self + 0x14) = pvVar2;
  Surface_FillFF((intptr_t)self);
  return self;
}
