// Sound_StopThread: ported from Pizza Connection 2 at 0x54c4f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c4f0
#include "pc2_port.h"

void __fastcall Sound_StopThread(uint32_t *arg1)

{
  int value1;
  int *ptr2;
  LPVOID pvVar3;
  uint8_t *uptr4;
  
  if ((HANDLE)arg1[4] != (HANDLE)0x0) {
    SetEvent((HANDLE)arg1[4]);
    if (arg1[6] != 0) {
      value1 = arg1[5];
      while (value1 == 0) {
        Sleep(10);
        value1 = arg1[5];
      }
    }
    CloseHandle((HANDLE)arg1[4]);
    arg1[4] = 0;
  }
  ptr2 = (int *)arg1[9];
  if (ptr2 != (int *)0x0) {
    List_FreeValuesAndObject(ptr2);
    Mem_Free(ptr2);
    arg1[9] = 0;
  }
  pvVar3 = (LPVOID)arg1[1];
  if (pvVar3 != (LPVOID)0x0) {
    Sound_DestroyObject((intptr_t)pvVar3);
    Mem_Free(pvVar3);
    arg1[1] = 0;
  }
  uptr4 = (uint8_t *)*arg1;
  if (uptr4 != (uint8_t *)0x0) {
    Sound_DestroyAllChannels(uptr4);
    Mem_Free(uptr4);
    *arg1 = 0;
  }
  if ((uint32_t *)arg1[7] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[7])(1);
    arg1[7] = 0;
  }
  if ((uint32_t *)arg1[8] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[8])(1);
    arg1[8] = 0;
  }
  return;
}
