// SoundPakManager_Destruct: ported from Pizza Connection 2 at 0x53fcc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53fcc0
#include "pc2_port.h"


void __fastcall SoundPakManager_Destruct(uint32_t *arg1)

{
  int value1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_c = ExceptionList;
  puStack_8 = &LAB_0055ae76;
  ExceptionList = &local_c;
  *arg1 = &PTR_LAB_0055c864;
  value1 = arg1[0x8e];
  local_4 = 1;
  while (0 < value1) {
    value1 = value1 + -1;
    arg1[0x8e] = value1;
    if (arg1[value1 * 7 + 8] != 0) {
      CRT_Fclose((FILE *)arg1[value1 * 7 + 2]);
    }
    Mem_Free((LPVOID)arg1[arg1[0x8e] * 7 + 3]);
    value1 = arg1[0x8e];
  }
  value1 = arg1[0x18a];
  while (value1 != 0) {
    value1 = *(int *)((intptr_t)arg1[0x18a] + 0x50);
    Mem_Free((LPVOID)arg1[0x18a]);
    arg1[0x18a] = value1;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(arg1 + 0x8f));
  *arg1 = &PTR_LAB_0055c840;
  ExceptionList = local_c;
  return;
}
