// Array_Destroy: ported from Pizza Connection 2 at 0x522f20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522f20
#include "pc2_port.h"

void __fastcall Array_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_Array_Delete_0055c774;
  if ((LPVOID)arg1[1] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[1]);
  }
  return;
}
