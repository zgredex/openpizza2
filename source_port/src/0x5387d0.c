// Renderer_ReleaseTargets: ported from Pizza Connection 2 at 0x5387d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5387d0
#include "pc2_port.h"

void __fastcall Renderer_ReleaseTargets(void *arg1)

{
  int *ptr1;
  
  if ((**(int **)((intptr_t)arg1 + 0x40) != 0) &&
     (*(uint8_t *)((intptr_t)arg1 + 0x30) = 0, *(int *)((intptr_t)arg1 + 0x48) == 0)) {
    ptr1 = (int *)(*(int **)((intptr_t)arg1 + 0x40))[2];
    if (ptr1 != (int *)0x0) {
      (**(code **)(*ptr1 + 8))(ptr1);
      *(uint32_t *)(*(int *)((intptr_t)arg1 + 0x40) + 8) = 0;
    }
    ptr1 = *(int **)(*(int *)((intptr_t)arg1 + 0x40) + 4);
    if (ptr1 != (int *)0x0) {
      (**(code **)(*ptr1 + 8))(ptr1);
      *(uint32_t *)(*(int *)((intptr_t)arg1 + 0x40) + 4) = 0;
    }
    if (*(int *)((intptr_t)arg1 + 0x4c) == 0) {
      (**(code **)(*(int *)**(uint32_t **)((intptr_t)arg1 + 0x40) + 0x4c))
                ((int *)**(uint32_t **)((intptr_t)arg1 + 0x40));
      (**(code **)(*(int *)**(uint32_t **)((intptr_t)arg1 + 0x40) + 0x50))
                ((int *)**(uint32_t **)((intptr_t)arg1 + 0x40),*(uint32_t *)((intptr_t)arg1 + 0x44),
                 8);
    }
    (**(code **)(*(int *)**(uint32_t **)((intptr_t)arg1 + 0x40) + 8))
              ((int *)**(uint32_t **)((intptr_t)arg1 + 0x40));
    **(uint32_t **)((intptr_t)arg1 + 0x40) = 0;
    Renderer_InitOrCopyState(arg1,0);
    Renderer_CopyStateToChildren((intptr_t)arg1);
  }
  return;
}
