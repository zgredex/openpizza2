// Sound_ShutdownThread: ported from Pizza Connection 2 at 0x54c9f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c9f0
#include "pc2_port.h"

void __fastcall Sound_ShutdownThread(uint8_t *arg1)

{
  int value1;
  int *ptr2;
  
  if (*(int *)(arg1 + 0x88) != 0) {
    Thread_StopAndDestroy((intptr_t)arg1);
  }
  if (*(int *)(arg1 + 0xa4) == 0) {
    SetEvent(*(HANDLE *)(arg1 + 0x9c));
    SetEvent(*(HANDLE *)(arg1 + 0x98));
    value1 = *(int *)(arg1 + 0xa4);
    while (value1 == 0) {
      Sleep(10);
      value1 = *(int *)(arg1 + 0xa4);
    }
  }
  ptr2 = *(int **)(arg1 + 0x84);
  if (ptr2 != (int *)0x0) {
    (**(code **)(*ptr2 + 0x10))(ptr2);
    (**(code **)(**(int **)(arg1 + 0x84) + 8))(*(int **)(arg1 + 0x84));
    *(uint32_t *)(arg1 + 0x84) = 0;
  }
  CoUninitialize();
  *arg1 = 0;
  return;
}
