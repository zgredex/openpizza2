// CRT_TypeInfoDtor: ported from Pizza Connection 2 at 0x54fe25.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fe25
#include "pc2_port.h"

void __fastcall CRT_TypeInfoDtor(uint32_t *arg1)

{
  *arg1 = &type_info_vftable;
  CRT_Lock(0x1b);
  if ((LPVOID)arg1[1] != (LPVOID)0x0) {
    CRT_FreeInternal((LPVOID)arg1[1]);
  }
  CS_LeaveIndexed(0x1b);
  return;
}
