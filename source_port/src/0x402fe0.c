// FileObject_Destroy: ported from Pizza Connection 2 at 0x402fe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402fe0
#include "pc2_port.h"

void __fastcall FileObject_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_FileObject_Delete_0055c2f4;
  if ((LPVOID)arg1[1] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[1]);
  }
  if ((LPVOID)arg1[2] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[2]);
  }
  if ((LPVOID)arg1[3] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[3]);
  }
  return;
}
