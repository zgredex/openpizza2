// RegistryKey_CloseThunk: ported from Pizza Connection 2 at 0x4031a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4031a0
#include "pc2_port.h"

void __fastcall RegistryKey_CloseThunk(uint32_t *arg1)

{
  if ((HKEY)*arg1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*arg1);
  }
  *arg1 = 0;
  return;
}
