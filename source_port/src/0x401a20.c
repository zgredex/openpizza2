// ResourceManager_Destruct: ported from Pizza Connection 2 at 0x401a20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401a20
#include "pc2_port.h"


void __fastcall ResourceManager_Destruct(uint32_t *arg1)

{
  int value1;
  int value2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Destroys a resource manager, its archives, and its lock. */
  local_c = ExceptionList;
  puStack_8 = &LAB_00557c2e;
  ExceptionList = &local_c;
  *arg1 = &PTR_ResourceManager_ScalarDeletingDestructor_0055c2f0;
  value1 = arg1[0x5a1];
  local_4 = 0;
  while (0 < value1) {
    value2 = value1 + -1;
    arg1[0x5a1] = value2;
    if (arg1[(value1 + 8 + value2 * 8) * 8] != 0) {
      CRT_Fclose((FILE *)arg1[value2 * 0x48 + 1]);
    }
    Mem_Free((LPVOID)arg1[arg1[0x5a1] * 0x48 + 2]);
    value1 = arg1[0x5a1];
  }
  value1 = arg1[0x6ad];
  while (value1 != 0) {
    value1 = *(int *)((intptr_t)arg1[0x6ad] + 0x50);
    Mem_Free((LPVOID)arg1[0x6ad]);
    arg1[0x6ad] = value1;
  }
  local_4 = 0xffffffff;
  NamedLockable_Destroy(arg1 + 0x5a2);
  ExceptionList = local_c;
  return;
}
