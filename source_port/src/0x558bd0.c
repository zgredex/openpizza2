// Unwind@00558bd0: ported from Pizza Connection 2 at 0x558bd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558bd0
#include "pc2_port.h"

void Unwind_00558bd0(void)

{
  int unaff_EBP;
  
  RegistryKey_CloseThunk((uint32_t *)(unaff_EBP + -0x10));
  return;
}
