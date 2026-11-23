// Unwind@00557d70: ported from Pizza Connection 2 at 0x557d70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557d70
#include "pc2_port.h"

void Unwind_00557d70(void)

{
  int unaff_EBP;
  
  RegistryKey_CloseThunk((uint32_t *)(unaff_EBP + -0x10));
  return;
}
