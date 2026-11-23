// Renderer_ConstructChild: ported from Pizza Connection 2 at 0x537d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x537d80
#include "pc2_port.h"

uint32_t * __thiscall Renderer_ConstructChild(void *self,void *arg1)

{
  uint32_t *uptr1;
  
  *(uint8_t ***)self = &PTR_Renderer_Delete_0055c818;
  uptr1 = operator_new(0x14);
  *(uint32_t **)((intptr_t)self + 0x40) = uptr1;
  *uptr1 = 0;
  uptr1[1] = 0;
  uptr1[2] = 0;
  uptr1[3] = 0;
  uptr1[4] = 0;
  *(uint8_t *)((intptr_t)self + 0x30) = 0;
  *(uint32_t *)((intptr_t)self + 0x78) = 0;
  *(uint32_t *)((intptr_t)self + 0x7c) = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  *(void **)((intptr_t)self + 0x54) = arg1;
  *(uint32_t *)((intptr_t)self + 0x4c) = 3;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  *(uint32_t *)((intptr_t)self + 0x80) = 1;
  Renderer_InitOrCopyState(self,(intptr_t)arg1);
  if (*(int *)((intptr_t)self + 0x54) != 0) {
    List_PushFront(arg1,self);
  }
  *(uint8_t *)((intptr_t)self + 0x30) = 1;
  return self;
}
