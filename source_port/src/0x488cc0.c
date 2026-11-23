// Game_SuspendSimulation: ported from Pizza Connection 2 at 0x488cc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488cc0
#include "pc2_port.h"

void __fastcall Game_SuspendSimulation(void *arg1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  *(uint32_t *)((intptr_t)arg1 + 0x1508) = 1;
  DVar1 = *(DWORD *)(*(int *)((intptr_t)arg1 + 0x90) + 0x10);
  DVar2 = GetCurrentThreadId();
  if (DVar2 != DVar1) {
    *(uint32_t *)((intptr_t)arg1 + 0x2d14) = 1;
    if (*(int *)((intptr_t)arg1 + 0x90) != 0) {
      Thread_IsOwner(*(int *)((intptr_t)arg1 + 0x90));
    }
    *(uint32_t *)((intptr_t)arg1 + 0x2d14) = 0;
  }
  if (*(int *)((intptr_t)arg1 + 0x94) != 0) {
    ThreadSync_Clear(*(int *)((intptr_t)arg1 + 0x94));
  }
  Game_UpdateDateLabels(arg1,(void *)0x0);
  return;
}
