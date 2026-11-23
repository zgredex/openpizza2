// CRT_NotifyDebugger: ported from Pizza Connection 2 at 0x54e922.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e922
#include "pc2_port.h"

void CRT_NotifyDebugger(void)

{
  uint32_t in_EAX;
  int unaff_EBP;
  
  DAT_00576738 = *(uint32_t *)(unaff_EBP + 8);
  DAT_00576734 = in_EAX;
  DAT_0057673c = unaff_EBP;
  return;
}
