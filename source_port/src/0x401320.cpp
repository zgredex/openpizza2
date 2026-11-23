// CS_Enter: ported from Pizza Connection 2 at 0x401320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401320
#include "pc2_port.h"

void __fastcall CS_Enter(int arg1)

{
  DWORD DVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(arg1 + 4));
  DVar1 = GetCurrentThreadId();
  *(DWORD *)(arg1 + 0x50) = DVar1;
  *(int *)(arg1 + 0x54) = *(int *)(arg1 + 0x54) + 1;
  return;
}
