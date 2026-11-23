// Thread_IsOwner: ported from Pizza Connection 2 at 0x4f7020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7020
#include "pc2_port.h"

void __fastcall Thread_IsOwner(int arg1)

{
  DWORD DVar1;
  int value2;
  
  value2 = 0x96;
  DVar1 = GetCurrentThreadId();
  if ((DVar1 != *(DWORD *)(arg1 + 0x10)) && (*(int *)(arg1 + 0xc) == 0)) {
    *(uint32_t *)(arg1 + 0xc) = 0;
    *(uint32_t *)(arg1 + 8) = 1;
    do {
      if (value2 < 1) {
        return;
      }
      if ((*(int *)(arg1 + 0x38) == 0) && (*(int *)(DAT_0057c670 + 0x250) == 0)) {
        return;
      }
      value2 = value2 + -1;
      Sleep(0x32);
    } while (*(int *)(arg1 + 0xc) == 0);
  }
  return;
}
