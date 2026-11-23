// CRT_QueryProcessorFeature: ported from Pizza Connection 2 at 0x5519bf.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5519bf
#include "pc2_port.h"

void CRT_QueryProcessorFeature(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  Stub_ReturnZero();
  return;
}
