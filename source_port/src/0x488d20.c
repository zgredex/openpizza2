// Game_ResumeSimulation: ported from Pizza Connection 2 at 0x488d20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488d20
#include "pc2_port.h"

void __fastcall Game_ResumeSimulation(void *arg1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  if (*(int *)((intptr_t)arg1 + 0x1508) != 0) {
    DVar1 = *(DWORD *)(*(int *)((intptr_t)arg1 + 0x90) + 0x10);
    DVar2 = GetCurrentThreadId();
    if ((DVar2 != DVar1) && (*(int *)((intptr_t)arg1 + 0x90) != 0)) {
      Thread_Init(*(int *)((intptr_t)arg1 + 0x90));
    }
    if (*(int *)((intptr_t)arg1 + 0x94) != 0) {
      ThreadSync_Signal(*(int *)((intptr_t)arg1 + 0x94));
    }
    Game_HideAllLinkedElements(DAT_0057c5cc);
    *(uint32_t *)((intptr_t)arg1 + 0x1508) = 0;
    *(uint32_t *)((intptr_t)arg1 + 0x150c) = 1;
    Game_UpdateDateLabels(arg1,(void *)0x0);
  }
  return;
}
