// UI_RenderScene: ported from Pizza Connection 2 at 0x523e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523e20
#include "pc2_port.h"

uint32_t __fastcall UI_RenderScene(int arg1)

{
  int value1;
  int local_4;
  
  local_4 = arg1;
  if ((*(void **)(arg1 + 0x83ac) != (void *)0x0) && (*(int *)(arg1 + 0x83b8) != 0)) {
    UI_EnsureBackBufferWindow(*(void **)(arg1 + 0x83ac),*(void **)(arg1 + 0xc));
    return 1;
  }
  if (*(int *)(arg1 + 0x1b4) != 0) {
    value1 = Surface_LockAndMark(*(void **)(arg1 + 0xc));
    if (value1 == 0) {
      return 0;
    }
    value1 = *(int *)(*(int *)(arg1 + 0xc) + 0x40);
    if (value1 == 0) {
      Surface_IsReady((int *)0x0);
      return 1;
    }
    Surface_IsReady(*(int **)(value1 + 8));
    return 1;
  }
  if (*(void **)(arg1 + 0x1bc) != (void *)0x0) {
    Surface_ConfigureFromOwner(*(void **)(arg1 + 0x1bc),*(void **)(arg1 + 0xc));
    return 1;
  }
  if (*(int *)(arg1 + 0x1c0) == 0) {
    NoOp_Stub();
  }
  value1 = Surface_GetDescription(*(void **)(arg1 + 0xc),*(int **)(arg1 + 0x1c0),&local_4);
  if (value1 == 0) {
    return 0;
  }
  Surface_InitFromBuffer
            (*(void **)(arg1 + 0xc),value1,(uint16_t)*(uint32_t *)(arg1 + 0x270),
             (uint16_t)*(uint32_t *)(arg1 + 0x274),local_4);
  Surface_IsReady(*(int **)(arg1 + 0x1c0));
  return 1;
}
