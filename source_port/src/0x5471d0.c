// SoundSystem_Destruct: ported from Pizza Connection 2 at 0x5471d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5471d0
#include "pc2_port.h"


void __fastcall SoundSystem_Destruct(int arg1)

{
  int *ptr1;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Destroys the global sound system and its lock. */
  puStack_8 = &LAB_0055b89e;
  pvStack_c = ExceptionList;
  ptr1 = *(int **)(arg1 + 8);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (ptr1 != (int *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)(*ptr1 + 4))(ptr1);
  }
  local_4 = 0xffffffff;
  NamedLockable_Destroy((uint32_t *)(arg1 + 0x178));
  ExceptionList = pvStack_c;
  return;
}
