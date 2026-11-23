// Unwind@00557d50: ported from Pizza Connection 2 at 0x557d50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557d50
#include "pc2_port.h"

void Unwind_00557d50(void)

{
  int unaff_EBP;
  
  RegistryKey_CloseThunk((uint32_t *)(unaff_EBP + -0x14));
  return;
}
