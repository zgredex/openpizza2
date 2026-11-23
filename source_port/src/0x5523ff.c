// CRT_FreeThreadData: ported from Pizza Connection 2 at 0x5523ff.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5523ff
#include "pc2_port.h"

void __cdecl CRT_FreeThreadData(LPVOID arg1)

{
  if (DAT_00576ac4 == 0xffffffff) {
    return;
  }
  if ((arg1 != (LPVOID)0x0) || (arg1 = TlsGetValue(DAT_00576ac4), arg1 != (LPVOID)0x0)) {
    if (*(LPVOID *)((intptr_t)arg1 + 0x24) != (LPVOID)0x0) {
      CRT_FreeInternal(*(LPVOID *)((intptr_t)arg1 + 0x24));
    }
    if (*(LPVOID *)((intptr_t)arg1 + 0x28) != (LPVOID)0x0) {
      CRT_FreeInternal(*(LPVOID *)((intptr_t)arg1 + 0x28));
    }
    if (*(LPVOID *)((intptr_t)arg1 + 0x30) != (LPVOID)0x0) {
      CRT_FreeInternal(*(LPVOID *)((intptr_t)arg1 + 0x30));
    }
    if (*(LPVOID *)((intptr_t)arg1 + 0x38) != (LPVOID)0x0) {
      CRT_FreeInternal(*(LPVOID *)((intptr_t)arg1 + 0x38));
    }
    if (*(LPVOID *)((intptr_t)arg1 + 0x40) != (LPVOID)0x0) {
      CRT_FreeInternal(*(LPVOID *)((intptr_t)arg1 + 0x40));
    }
    if (*(LPVOID *)((intptr_t)arg1 + 0x44) != (LPVOID)0x0) {
      CRT_FreeInternal(*(LPVOID *)((intptr_t)arg1 + 0x44));
    }
    if (*(uint8_t **)((intptr_t)arg1 + 0x50) != &DAT_00577040) {
      CRT_FreeInternal(*(uint8_t **)((intptr_t)arg1 + 0x50));
    }
    CRT_FreeInternal(arg1);
  }
  TlsSetValue(DAT_00576ac4,(LPVOID)0x0);
  return;
}
