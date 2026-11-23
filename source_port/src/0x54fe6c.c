// CRT_StackFrameStub: ported from Pizza Connection 2 at 0x54fe6c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fe6c
#include "pc2_port.h"

void CRT_StackFrameStub(void)

{
  uint8_t auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}
