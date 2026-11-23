// Branch_EnqueueConstructionOrder: ported from Pizza Connection 2 at 0x47e0e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e0e0
#include "pc2_port.h"

void __thiscall Branch_EnqueueConstructionOrder(void *self,int arg1,int arg2,int arg3)

{
  *(uint32_t *)((intptr_t)self + 0x1718) = 0;
  List_Add((void *)((intptr_t)self + 0x16f8),arg1);
  *(int *)(arg1 + 0x18) = arg2;
  *(int *)(arg1 + 0x1c) = arg3;
  *(int *)(arg1 + 0x20) = *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0x1c) * arg3 + arg2;
  Game_CheckObjectUpgrade(self);
  return;
}
