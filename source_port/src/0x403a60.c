// Timer_Destroy: ported from Pizza Connection 2 at 0x403a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403a60
#include "pc2_port.h"

void __fastcall Timer_Destroy(uint32_t *arg1)

{
  int value1;
  DWORD DVar2;
  DWORD DVar3;
  
                    /* Stops the timer worker and releases its handles and lock. */
  *arg1 = &PTR_TimerClass_ScalarDeletingDestructor_0055c308;
  arg1[1] = 1;
  DVar2 = timeGetTime();
  value1 = arg1[2];
  while ((value1 == 0 && (DVar3 = timeGetTime(), DVar3 < DVar2 + 5000))) {
    Sleep(2);
    value1 = arg1[2];
  }
  CloseHandle((HANDLE)arg1[0x1b]);
  NamedLockable_Destroy(arg1 + 4);
  return;
}
