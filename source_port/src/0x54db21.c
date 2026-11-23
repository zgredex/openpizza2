// CRT_Streambuf_Destroy: ported from Pizza Connection 2 at 0x54db21.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54db21
#include "pc2_port.h"

void __fastcall CRT_Streambuf_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_CRT_Streambuf_Delete_0055ccc8;
  CS_DeleteRaw((LPCRITICAL_SECTION)(arg1 + 0xd));
  Stream_ValidateRange((intptr_t)arg1);
  if ((arg1[1] != 0) && ((LPVOID)arg1[4] != (LPVOID)0x0)) {
    Mem_Free((LPVOID)arg1[4]);
  }
  return;
}
