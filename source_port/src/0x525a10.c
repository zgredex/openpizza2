// Window_ProcessMessageQueue: ported from Pizza Connection 2 at 0x525a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x525a10
#include "pc2_port.h"

int64_t __thiscall Window_ProcessMessageQueue(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  void *pvVar3;
  uint32_t uvalue4;
  DWORD DVar5;
  uint32_t extraout_EDX;
  int64_t lvalue6;
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  DVar5 = GetCurrentThreadId();
  *(DWORD *)((intptr_t)self + 0x830c) = DVar5;
  UI_UpdateScene(self);
  if (arg1 != 0) {
    QueryPerformanceCounter(&local_8);
  }
  value1 = *(int *)((intptr_t)self + 0x32b4);
  if (value1 != *(int *)((intptr_t)self + 0x32b8)) {
    uvalue2 = *(uint32_t *)((intptr_t)self + value1 * 0xc + 0x2b4);
    pvVar3 = *(void **)((intptr_t)self + (value1 * 3 + 0xae) * 4);
    uvalue4 = *(uint32_t *)((intptr_t)self + value1 * 0xc + 700);
    *(uint32_t *)((intptr_t)self + 0x32b4) = value1 + 1U & 0x3ff;
    Window_DispatchWindowMessage(self,uvalue2,pvVar3,uvalue4);
    if (*(int *)((intptr_t)self + 0x1b8) != 0) {
      Window_UpdateTooltip(self);
      *(uint32_t *)((intptr_t)self + 0x1b8) = 0;
    }
  }
  UI_ProcessCommandQueue((intptr_t)self);
  Window_UpdateTooltip(self);
  if (arg1 == 0) {
    return (uint64_t)extraout_EDX << 0x20;
  }
  QueryPerformanceCounter(&local_10);
  UI_GetScrollRatio((intptr_t)self,local_8.s.LowPart,local_8.s.HighPart,local_10.s.LowPart,
                    local_10.s.HighPart);
  lvalue6 = __ftol();
  return lvalue6;
}
