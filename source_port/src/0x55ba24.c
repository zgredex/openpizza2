// Unwind@0055ba24: ported from Pizza Connection 2 at 0x55ba24.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ba24
#include "pc2_port.h"

void Unwind_0055ba24(void)

{
  int unaff_EBP;
  
  CRT_Streambuf_Destroy(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
